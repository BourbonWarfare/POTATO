#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

["CBA_settingsInitialized", { // Move to post init in ace after a few weeks
    if !(GVAR(enableCarDamage)) then {
        ["gm_wheeled_APC_base", "Init", ACEFUNC(vehicle_damage,addEventHandler), true, [], true] call CBA_fnc_addClassEventHandler;
    };
}] call CBA_fnc_addEventHandler;

ADDON = true;
