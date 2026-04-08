#include "script_component.hpp"

if (!hasInterface) exitWith {};

["CBA_settingsInitialized", {
    ["unit", { call FUNC(syncPlayer) }, true] call CBA_fnc_addPlayerEventHandler;
    true call FUNC(updateUnit); // update all now
    GVAR(ready) = true;
    [QGVAR(updateUnit), { call FUNC(updateUnit)}] call CBA_fnc_addEventHandler; // update any new incoming units
    ["potato_safeStartOn", { true call FUNC(updateUnit) }] call CBA_fnc_addEventHandler; // update on safe start toggle
    ["potato_safeStartOff", { true call FUNC(updateUnit) }] call CBA_fnc_addEventHandler;
}] call CBA_fnc_addEventHandler;
