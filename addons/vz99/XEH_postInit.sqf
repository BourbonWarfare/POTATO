#include "script_component.hpp"

if (!hasInterface) exitWith {};

GVAR(nextReload) = QGVAR(HE);

// Add keybinds
[QUOTE(PREFIX), QGVAR(reload), "Reload VZ99",
{
    private _mortarVeh = vehicle ACE_player;
    if ((_mortarVeh == ACE_player) || {!(_mortarVeh isKindOf QGVAR(mortar))}) exitWith {false};
    if !([ACE_player, _mortarVeh, []] call ACEFUNC(common,canInteractWith)) exitWith {false};
    
    [_mortarVeh, ACE_player] call FUNC(doReload);

    true
},
{false},
[19, [false, false, false]], false] call CBA_fnc_addKeybind; //R Key

["vehicle", {_this call FUNC(handlePlayerVehicleChanged);}, true] call CBA_fnc_addPlayerEventHandler;
