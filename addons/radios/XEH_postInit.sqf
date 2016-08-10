#include "script_component.hpp"

// Could 3den this later, but for now we want it running on old missions
diag_log text "[POTATO-radios] Setting acre_sys_signal_omnidirectionalRadios to true";
acre_sys_signal_omnidirectionalRadios = true;


// set global settings, see script_component.hpp for default values
GVAR(enabled) = getMissionConfigValue [QGVAR(enabled), GVAR(enabled)];
GVAR(radioInterference) = getMissionConfigValue [QGVAR(radioInterference), GVAR(radioInterference)];
GVAR(terrainInterference) = getMissionConfigValue [QGVAR(terrainInterference), GVAR(terrainInterference)];
GVAR(addCommonChannelName) = getMissionConfigValue [QGVAR(addCommonChannelName), GVAR(addCommonChannelName)];
GVAR(addCommonChannelNumber) = getMissionConfigValue [QGVAR(addCommonChannelNumber), GVAR(addCommonChannelNumber)];
GVAR(addCommonChannelAllMR) = getMissionConfigValue [QGVAR(addCommonChannelAllMR), GVAR(addCommonChannelAllMR)];
GVAR(addCommonChannelAllLR) = getMissionConfigValue [QGVAR(addCommonChannelAllLR), GVAR(addCommonChannelAllLR)];

["ace_settingsInitialized", {
    TRACE_3("",GVAR(enabled),hasInterface,EGVAR(assignGear,usePotato));
    if (GVAR(enabled) && {!(missionNamespace getVariable [QEGVAR(assignGear,usePotato), false])}) exitWith {
        diag_log text format ["[POTATO-radios] - ERROR: Radios enabled, but gear assign is not running"];
    };

    if (GVAR(enabled) && hasInterface) then {
        [FUNC(initializeRadios)] call CBA_fnc_execNextFrame;

        [
            {
                GVAR(initialized) && {player getVariable [QEGVAR(assignGear,gearSetup), false]}
            },
            {
                [] call FUNC(addAcreBriefing);
                [{[player] call ACRE_FUNC(isInitialized)}, FUNC(configureRadios)] call CBA_fnc_waitUntilAndExecute;
            }
        ] call CBA_fnc_waitUntilAndExecute;
    };
}] call CBA_fnc_addEventHandler;
