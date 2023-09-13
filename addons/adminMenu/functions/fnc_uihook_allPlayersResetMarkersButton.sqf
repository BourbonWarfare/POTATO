#include "script_component.hpp"

["potato_adminMsg", ["Resetting markers on all players"] call CBA_fnc_globalEvent;

private _count = 0;
{
    if !(hasinterface _x) exitwith {};

    [QGVAR(resetMarkers), [_x], [_x]] call CBA_fnc_targetEvent;

    _count = _count + 1;

} ForEach allPlayers;

["potato_adminMsg", [format ["Resetting markers on %1 players", _count]] call CBA_fnc_globalEvent;
