#define DEBUG_MODE_FULL
#include "script_component.hpp"

call compileScript [QPATHTOF(vehicleTags\init.sqf)];

LOG("Post init start");

[
    {
        ACEGVAR(common,settingsInitFinished)
            && {!isNull player}
            && {!isNull (group player)}
            && {(missionNamespace getVariable [QEGVAR(miscFixes,groupCleanupRan), false]) || {diag_tickTime > (_this select 0)}}
    },
    {
        TRACE_2("ACE Settings initialized",GVAR(groupAndUnitEnabled),GVAR(intraFireteamEnabled));
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
            ACEGVAR(microDAGR,miniMapDrawHandlers) pushBack {_this call FUNC(drawMarkers)};

            // only setup event handlers when they'd be used
            if (GVAR(groupAndUnitEnabled)) then {
                // catch local player changed event, transmit global event
                ["unit", {
                    params ["_newPlayer", "_oldPlayer"];

                    [] call FUNC(checkForMapMarkerColor);

                    if (side (group _newPlayer) != side (group _oldPlayer)) then {
                        GVAR(drawHash) = createHashMap;
                    };
                    [_newPlayer] call FUNC(initPlayerMarkers);
                }] call CBA_fnc_addPlayerEventHandler;

                [] call FUNC(checkForMapMarkerColor);
            };
            if (GVAR(intraFireteamEnabled)) then {
                [] call FUNC(initLocalMarkers);
            };
        } else {
            GVAR(skipInstallingEH) = true; // skip installing marker EHs
        };

        GVAR(settingsInitialized) = true;
        // run any functions waiting for marker settings to finish
        {
            (_x select 1) call (_x select 0);
        } forEach GVAR(settingsDelayedFunctions);
    },
    [diag_tickTime + 5]
] call CBA_fnc_waitUntilAndExecute;

[
    {
        ACEGVAR(common,settingsInitFinished)
            && {(missionNamespace getVariable [QEGVAR(miscFixes,groupCleanupRan), false]) ||
            {diag_tickTime > (_this select 0)}}
    },
    {
        TRACE_2("Server ACE Settings initialized",GVAR(groupAndUnitEnabled),GVAR(intraFireteamEnabled));
        if (isNil QEGVAR(miscFixes,groupCleanupRan)) then {ERROR_1("Server never set %1",QEGVAR(miscFixes,groupCleanupRan));};
        if (GVAR(groupAndUnitEnabled)) then {
            [] call FUNC(initLocalMarkers);
        };
    },
    [diag_tickTime + 5]
] call CBA_fnc_waitUntilAndExecute;