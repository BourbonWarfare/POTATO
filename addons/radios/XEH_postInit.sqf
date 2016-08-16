#include "script_component.hpp"

/*
if (isServer) then {
    [] call FUNC(setAcreGlobalSettings);
    [] call FUNC(setAcreSideSettings);
};
*/

// Remove by october
diag_log text "[POTATO-radios] Setting acre_sys_signal_omnidirectionalRadios to true";
acre_sys_signal_omnidirectionalRadios = true;


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
