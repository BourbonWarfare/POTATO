#define DEBUG_MODE_FULL
#include "script_component.hpp"
LOG("Post init start");

[
    {
        (ACEGVAR(common,settingsInitFinished) && missionNamespace getVariable [QEGVAR(miscFixes,groupCleanupRan), false]) || diag_tickTime > (_this select 0)
    },
    {
        TRACE_2("ACE Settings initilized",GVAR(groupAndUnitEnabled),GVAR(intraFireteamEnabled));
        if (hasInterface && {GVAR(groupAndUnitEnabled) || {GVAR(intraFireteamEnabled)}}) then {
            GVAR(skipInstallingEH) = false;

            // convert all the string arrays, to arrays of type side
            [GVAR(viewBluForMarkers)] call EFUNC(core,stringArrayToSideArray);
            [GVAR(viewOpForMarkers)] call EFUNC(core,stringArrayToSideArray);
            [GVAR(viewIndyMarkers)] call EFUNC(core,stringArrayToSideArray);
            [GVAR(viewCivMarkers)] call EFUNC(core,stringArrayToSideArray);

            // add draw marker eh to the microdagr, the GPS/Map are handled by adding XEHs to their displays
            ACEGVAR(microDAGR,miniMapDrawHandlers) pushBack {_this call FUNC(drawMarkers)};

            // only setup event handlers when they'd be used
            if (GVAR(groupAndUnitEnabled)) then {
                // check JIPed/changed players for markers
                [QGVAR(checkPlayerForMarkers), FUNC(handleCheckPlayerForMarkers)] call CBA_fnc_addEventHandler;

                // catch local player changed event, transmit global event
                ["unit", {
                    params ["_newPlayer", "_oldPlayer"];

                    if (side _newPlayer != side _oldPlayer) then {
                        GVAR(drawHash) = [[],[]];
                        [] call FUNC(initMarkerHash);
                    };

                    [QGVAR(checkPlayerForMarkers), [_newPlayer]] call CBA_fnc_globalEvent;
                }] call CBA_fnc_addPlayerEventHandler;

                [] call FUNC(initMarkerHash);
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
