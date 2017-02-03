#include "script_component.hpp"

/*
if (isServer) then {
    [] call FUNC(setAcreGlobalSettings);
    [] call FUNC(setAcreSideSettings);
};
*/

// Remove by october
INFO_1("Setting omnidirectional for acre post-904",true);
[true] call acre_api_fnc_ignoreAntennaDirection;


// set global settings, see script_component.hpp for default values

["ace_settingsInitialized", {
    TRACE_3("",GVAR(enabled),hasInterface,EGVAR(assignGear,usePotato));

    if (GVAR(enabled)) then {
        if !(missionNamespace getVariable [QEGVAR(assignGear,usePotato), false]) exitWith {
            ERROR("Radios enabled, but gear assign is not running");
        };

        // Make sure to create presets all machines;    from ACRE API:
        // Warning All presets must exist and match on all clients and especially the server; regardless of where the presets are used.
        // If you create a preset, copy a preset or modify a presets data information; these changes must occur on all clients and the server.
        // If they do not, ACRE may not work.

        [] call FUNC(initializeRadios);

        if (!hasInterface) exitWith {
            GVAR(initState) = 999;
            INFO_2("%1 - [InitState %2] DONE (Non Interface)", diag_frameNo, GVAR(initState));
        };
        
        ["unit", {_this call FUNC(setupPlayer)}, true] call CBA_fnc_addPlayerEventHandler; 
    } else {
        INFO("Disabled");
        if (isServer) then { // Warn if not enabled
            [{
                ["potato_adminMsg", ["Warning: Potato Radios Setting Disabled", "Server"]] call CBA_fnc_globalEvent;
            }, [], 5] call CBA_fnc_waitAndExecute
        };
    };
}] call CBA_fnc_addEventHandler;
