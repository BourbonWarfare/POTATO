#include "script_component.hpp"

// set global settings, see script_component.hpp for default values
GVAR(enabled) = getMissionConfigValue [QGVAR(enabled), RADIOS_ENABLED];
GVAR(radioInterference) = getMissionConfigValue [QGVAR(radioInterference), RADIO_INTERFERENCE];
GVAR(terrainInterference) = getMissionConfigValue [QGVAR(terrainInterference), TERRAIN_INTERFERENCE];
GVAR(addCommonChannelName) = getMissionConfigValue [QGVAR(addCommonChannelName), COMMON_CHANNEL_NAME];
GVAR(addCommonChannelNumber) = getMissionConfigValue [QGVAR(addCommonChannelNumber), COMMON_CHANNEL_NUMBER];
GVAR(addCommonChannelAllMR) = getMissionConfigValue [QGVAR(addCommonChannelAllMR), ADD_COMMON_CHANNEL_ALL_MR];
GVAR(addCommonChannelAllLR) = getMissionConfigValue [QGVAR(addCommonChannelAllLR), ADD_COMMON_CHANNEL_ALL_LR];

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
