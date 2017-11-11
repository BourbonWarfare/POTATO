#define DEBUG_MODE_FULL
#include "script_component.hpp"
LOG("Post init start");

[
    {
        ACEGVAR(common,settingsInitFinished)
            && {!isNull player}
            && {!isNull (group player)}
            && {(missionNamespace getVariable [QEGVAR(miscFixes,groupCleanupRan), false]) || {diag_tickTime > (_this select 0)}}
    },
    {
        TRACE_2("ACE Settings initilized",GVAR(groupAndUnitEnabled),GVAR(intraFireteamEnabled));
        if (isNil QEGVAR(miscFixes,groupCleanupRan)) then {ERROR_1("Server never set %1", QEGVAR(miscFixes,groupCleanupRan));};
        if (hasInterface && {GVAR(groupAndUnitEnabled) || {GVAR(intraFireteamEnabled)}}) then {
            GVAR(skipInstallingEH) = false;

            // To custom define these for your mission just define them in init.sqf:
            // e.g.: potato_markers_viewBluForMarkers = [west, civilian]

            if (isNil QGVAR(viewBluForMarkers)) then {GVAR(viewBluForMarkers) = [west]};
            if (isNil QGVAR(viewOpForMarkers)) then {GVAR(viewBluForMarkers) = [east]};
            if (isNil QGVAR(viewIndyMarkers)) then {GVAR(viewBluForMarkers) = [resistance]};
            if (isNil QGVAR(viewCivMarkers)) then {GVAR(viewBluForMarkers) = [civilian]};

            // add draw marker eh to the microdagr, the GPS/Map are handled by adding XEHs to their displays
            ACEGVAR(microDAGR,miniMapDrawHandlers) pushBack {_this call FUNC(drawMarkers)};

            // only setup event handlers when they'd be used
            if (GVAR(groupAndUnitEnabled)) then {
                // check JIPed/changed players for markers
                [QGVAR(checkPlayerForMarkers), FUNC(handleCheckPlayerForMarkers)] call CBA_fnc_addEventHandler;

                // catch local player changed event, transmit global event
                ["unit", {
                    params ["_newPlayer", "_oldPlayer"];

                    [] call FUNC(checkForMapMarkerColor);

                    if (side (group _newPlayer) != side (group _oldPlayer)) then {
                        [] call FUNC(initMarkerHash);
                    };

                    [QGVAR(checkPlayerForMarkers), [_newPlayer]] call CBA_fnc_globalEvent;
                }] call CBA_fnc_addPlayerEventHandler;

                [] call FUNC(initMarkerHash);
                [] call FUNC(checkForMapMarkerColor);
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
