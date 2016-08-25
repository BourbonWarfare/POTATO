#include "script_component.hpp"

/*
if (isServer) then {
    [] call FUNC(setAcreGlobalSettings);
    [] call FUNC(setAcreSideSettings);
};
*/

// Remove by october
if (isNil "acre_api_fnc_ignoreAntennaDirection") then {
    INFO_1("Setting omnidirectional for acre pre-904",true);
    acre_sys_signal_omnidirectionalRadios = true;
} else {
    INFO_1("Setting omnidirectional for acre post-904",true);
    [true] call acre_api_fnc_ignoreAntennaDirection;
};

// set global settings, see script_component.hpp for default values

["ace_settingsInitialized", {
    TRACE_3("",GVAR(enabled),hasInterface,EGVAR(assignGear,usePotato));

    if (GVAR(enabled) && hasInterface) then {

        if (hasInterface) then {

        };

        if !(missionNamespace getVariable [QEGVAR(assignGear,usePotato), false]) exitWith {
            ERROR("Radios enabled, but gear assign is not running");
        };

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
