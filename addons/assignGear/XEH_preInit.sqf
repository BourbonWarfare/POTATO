#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

GVAR(usePotato) = [missionConfigFile >> "CfgLoadouts" >> "usePotato"] call CFUNC(getBool);

if (GVAR(usePotato)) then {
    GVAR(loadoutCache) = call CBA_fnc_createNamespace;
    GVAR(classnameCache) = call CBA_fnc_createNamespace;
    GVAR(magnifiedOpticCache) = call CBA_fnc_createNamespace;

    GVAR(allowMagnifiedOptics) = [missionConfigFile >> "CfgLoadouts" >> "allowMagnifiedOptics"] call CFUNC(getBool);
    GVAR(allowChangeableOptics) = [missionConfigFile >> "CfgLoadouts" >> "allowChangeableOptics"] call CFUNC(getBool);
    GVAR(useFallback) = [missionConfigFile >> "CfgLoadouts" >> "useFallback"] call CFUNC(getBool);
    GVAR(maxRandomization) = [missionConfigFile >> "CfgLoadouts" >> "maxRandomization", 5] call CFUNC(getNumber);
    GVAR(setVehicleLoadouts) = [missionConfigFile >> "CfgLoadouts" >> "setVehicleLoadouts", 1] call CFUNC(getNumber);
    GVAR(setSupplyBoxLoadouts) = [missionConfigFile >> "CfgLoadouts" >> "setSupplyBoxLoadouts", 1] call CFUNC(getNumber);
    GVAR(alwaysAddToolkits) = [missionConfigFile >> "CfgLoadouts" >> "alwaysAddToolkits", true] call CFUNC(getBool);
    GVAR(alwaysAddLandRopes) = [missionConfigFile >> "CfgLoadouts" >> "alwaysAddLandRopes", true] call CFUNC(getBool);
    GVAR(prefixes) = [missionConfigFile >> "CfgLoadouts" >> "prefixes"] call CFUNC(getArray);
    GVAR(resupplyBoxMarkerIndex) = 0;

    if (isServer) then {
        if (is3DEN) then {
            diag_log text format ["[POTATO-assignGear] Running assign gear for the 3den entities at load"];

            [ // assign gear to man
                "CAManBase",
                "init",
                FUNC(assignGearMan),
                true, // allow inheritence
                [], // don't exclude classes
                false // don't run on existing units
            ] call CBA_fnc_addClassEventHandler;

            {
                if (_x isKindOf "CAManBase") then {
                    [_x] call FUNC(assignGearMan);
                };
            } forEach (all3DENEntities select 0);

        } else {
            [ // assign gear to man
                "CAManBase",
                "initPost",
                FUNC(assignGearMan),
                true, // allow inheritence
                [], // don't exclude classes
                true // run on existing units (shouldn't be any, but belts/suspenders)
            ] call CBA_fnc_addClassEventHandler;

            [ // assign gear to car
                "Car",
                "initPost",
                { [_this select 0, "Car"] call FUNC(assignGearVehicle); },
                true,
                [],
                true
            ] call CBA_fnc_addClassEventHandler;

            [ // assign gear to tank
                "Tank",
                "initPost",
                { [_this select 0, "Tank"] call FUNC(assignGearVehicle); },
                true,
                [],
                true
            ] call CBA_fnc_addClassEventHandler;

            [ // assign gear to helicopter
                "Helicopter",
                "initPost",
                { [_this select 0, "Helicopter"] call FUNC(assignGearVehicle); },
                true,
                ["ace_fastroping_helper", "ACE_friesBase"],
                true
            ] call CBA_fnc_addClassEventHandler;

            [ // assign gear to plane
                "Plane",
                "initPost",
                { [_this select 0, "Plane"] call FUNC(assignGearVehicle); },
                true,
                [],
                true
            ] call CBA_fnc_addClassEventHandler;

            [ // assign gear to ship
                "Ship_F",
                "initPost",
                { [_this select 0, "Ship_F"] call FUNC(assignGearVehicle); },
                true,
                [],
                true
            ] call CBA_fnc_addClassEventHandler;

            [ // assign gear to supply drops
                QGVAR(supply),
                "initPost",
                { call FUNC(assignGearPotatoBox); },
                true,
                [],
                true
            ] call CBA_fnc_addClassEventHandler;

            [ // assign gear to any supply box
                "ReammoBox_F",
                "initPost",
                { [_this select 0] call FUNC(assignGearSupplyBox); },
                true,
                [],
                true
            ] call CBA_fnc_addClassEventHandler;
        };
    };

    diag_log text format ["[POTATO-assignGear] Enabled [useFallback: %1, allowMagnifiedOptics: %2, allowChangeableOptics: %3, maxRandomization: %4, setVehicleLoadouts: %5, setSupplyBoxLoadouts: %6, prefixes: %7]", GVAR(useFallback), GVAR(allowMagnifiedOptics), GVAR(allowChangeableOptics), GVAR(maxRandomization), GVAR(setVehicleLoadouts), GVAR(setSupplyBoxLoadouts), GVAR(prefixes)];
} else {
    GVAR(allowChangeableOptics) = false;
    diag_log text format ["[POTATO-assignGear] Disabled"];
};

ADDON = true;
