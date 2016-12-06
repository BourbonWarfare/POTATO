#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

GVAR(usePotato) = ((getNumber (missionConfigFile >> "CfgLoadouts" >> "usePotato")) == 1);

if (GVAR(usePotato)) then {
    GVAR(loadoutCache) = call CBA_fnc_createNamespace;
    GVAR(classnameCache) = call CBA_fnc_createNamespace;

    GVAR(allowMagnifiedOptics) = ((getNumber (missionConfigFile >> "CfgLoadouts" >> "allowMagnifiedOptics")) == 1);
    GVAR(useFallback) = ((getNumber (missionConfigFile >> "CfgLoadouts" >> "useFallback")) == 1);
    GVAR(maxRandomization) = if (isNumber (missionConfigFile >> "CfgLoadouts" >> "maxRandomization")) then { getNumber (missionConfigFile >> "CfgLoadouts" >> "maxRandomization") } else { 5 };
    GVAR(setVehicleLoadouts) = if (isNumber (missionConfigFile >> "CfgLoadouts" >> "setVehicleLoadouts")) then {getNumber (missionConfigFile >> "CfgLoadouts" >> "setVehicleLoadouts")} else { 1 };
    GVAR(prefixes) = if (isArray (missionConfigFile >> "CfgLoadouts" >> "prefixes")) then { getArray (missionConfigFile >> "CfgLoadouts" >> "prefixes") } else { [] };

    if (isServer) then {
        [ // assign gear to man
            "CAManBase",
            "init",
            { [FUNC(assignGearMan), _this] call CBA_fnc_execNextFrame; },
            true, // allow inheritence
            [], // don't exclude classes
            true // run on existing units (shouldn't be any, but belts/suspenders)
        ] call CBA_fnc_addClassEventHandler;

        {
            [ // assign gear to vehicles
                _x,
                "init",
                { [FUNC(assignGearVehicle), _this select 0, _x] call CBA_fnc_execNextFrame; },
                true,
                [],
                true
            ] call CBA_fnc_addClassEventHandler;
        } forEach ['Car', 'Tank', 'Helicopter', 'Plane', 'Ship_F'];
    };

    diag_log text format ["[POTATO-assignGear] Enabled [useFallback:%1 allowMagnifiedOptics:%2 maxRandomization:%3 setVehicleLoadouts:%4, prefixes: %5]", GVAR(useFallback), GVAR(allowMagnifiedOptics), GVAR(maxRandomization), GVAR(setVehicleLoadouts), GVAR(prefixes)];
} else {
    diag_log text format ["[POTATO-assignGear] Disabled"];
};

ADDON = true;
