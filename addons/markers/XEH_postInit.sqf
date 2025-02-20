//#define DEBUG_MODE_FULL
#include "script_component.hpp"

call compileScript [QPATHTOF(vehicleTags\init.sqf)];

LOG("Post init start");

[
    {
        ACEGVAR(common,settingsInitFinished)
            && {(missionNamespace getVariable [QEGVAR(miscFixes,groupCleanupRan), false]) || {diag_tickTime > (_this select 0)}}
    },
    {
        TRACE_2("ACE Settings initialized",GVAR(groupAndUnitEnabled),GVAR(intraFireteamEnabled));
        if (GVAR(groupAndUnitEnabled)) then {[] call FUNC(initLocalMarkers);}; // we always want everyone to submit markers
        if (isNil QEGVAR(miscFixes,groupCleanupRan)) then {ERROR_1("Server never set %1",QEGVAR(miscFixes,groupCleanupRan));};
        if (hasInterface && GVAR(groupAndUnitEnabled) || GVAR(intraFireteamEnabled)) then {
            GVAR(skipInstallingEH) = false;

            // To custom define these for your mission just define them in init.sqf:
            // e.g.: potato_markers_viewBluForMarkers = [west, civilian]

            if (isNil QGVAR(viewBluForMarkers)) then {GVAR(viewBluForMarkers) = [west]};
            if (isNil QGVAR(viewOpForMarkers)) then {GVAR(viewOpForMarkers) = [east]};
            if (isNil QGVAR(viewIndyMarkers)) then {GVAR(viewIndyMarkers) = [resistance]};
            if (isNil QGVAR(viewCivMarkers)) then {GVAR(viewCivMarkers) = [civilian]};

            // add draw marker eh to the microdagr, the GPS/Map are handled by adding XEHs to their displays
            ACEGVAR(microDAGR,miniMapDrawHandlers) pushBack {call FUNC(drawMarkers)};

            // only setup event handlers when they'd be used
            if (GVAR(groupAndUnitEnabled)) then {
                // catch local player changed event, transmit global event
                ["unit", {
                    params ["_newPlayer", "_oldPlayer"];

                    [] call FUNC(checkForMapMarkerColor);

                    // force reconstructino of drawHash
                    if (side (group _newPlayer) != side (group _oldPlayer)) then {
                        GVAR(drawHash) = createHashMap;
                        GVAR(nextUpdateDrawHash) = -1;
                    };
                    // not a fan of waiting here, is there a better way?
                    // the respawn setVariable seems to happen/propagate after this event
                    [{
                        (_this#0) getVariable [QGVAR(addMarker), false] ||
                        (group (_this#0)) getVariable [QGVAR(addMarker), false]
                    }, {call FUNC(initUnitMarkers);},[_newplayer], 10, {
                        call FUNC(initUnitMarkers);
                    }] call CBA_fnc_waitUntilAndExecute;
                }] call CBA_fnc_addPlayerEventHandler; // no-retro flag set, this will only run for units that respawn
                if (didJIP) then {
                    [true] call FUNC(reinitMarkerHash);
                };
                // In an attempt to catch those who join in map screen and
                // miss the reinitMarkerHash call we call it after mission start
                // without the network sync
                [{
                    if (GVAR(drawHash) isEqualTo createHashMap) then {
                        [] call FUNC(reinitMarkerHash);
                    };
                }, 0, 0.1] call CBA_fnc_waitAndExecute;
                };
            [] call FUNC(checkForMapMarkerColor);

        } else {
            GVAR(skipInstallingEH) = true; // skip installing marker EHs
        };

        if (isServer && !hasInterface && GVAR(groupAndUnitEnabled)) then {
            [{
                TRACE_1("Updating server marker positions",CBA_missionTime);
                {
                    _y params ["_drawObject", "", "", "", "", "_posATL"];
                    if !(isNull _drawObject) then {
                        if (_drawObject isEqualType grpNull) then {
                            if (isNull (leader _drawObject)) exitWith {};
                            _posATL = getPosATL (leader _drawObject);
                        } else {
                            _posATL = getPosATL _drawObject;
                        };
                        _y set [5, _posATL];
                    };
                } forEach GVAR(markerHash);
            }, GVAR(groupAndUnitUpdateDelay)] call CBA_fnc_addPerFrameHandler;
        };

        GVAR(settingsInitialized) = true;
        // run any functions waiting for marker settings to finish
        {
            (_x select 1) call (_x select 0);
        } forEach GVAR(settingsDelayedFunctions);
    },
    [diag_tickTime + 5]
] call CBA_fnc_waitUntilAndExecute;

if !(isServer) then {
    QGVAR(markerPosSync) addPublicVariableEventHandler {
        params ["", ["_markerPosHash", createHashMap]];
        private _markerHash = GVAR(markerHash);
        {
            private _markerArray = _markerHash getOrDefault [_x, []];
            if (_markerArray isEqualTo []) then {continue};
            _markerArray set [5, _y];
        } forEach _markerPosHash;
    };
};
