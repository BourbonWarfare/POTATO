#include "script_component.hpp"

if (!hasInterface) exitWith {};

["CBA_settingsInitialized", {
    ["unit", { call FUNC(syncPlayer) }, true] call CBA_fnc_addPlayerEventHandler;

    GVAR(setOn) = [];
    call FUNC(loop);
}] call CBA_fnc_addEventHandler;
