#include "script_component.hpp"

params ["_logic", "_units", "_activated"];
TRACE_1("params",_this);

if (!_activated) exitWith {};
if (!hasInterface) exitWith {};

private _pos = getPos _logic;
private _sideIndex = _logic getVariable ["side", 0];
private _text = _logic getVariable ["text", ""];
private _colorIndex = _logic getVariable ["color", "0"];

if ((_sideIndex < 0) || {_sideIndex > 4}) exitWith {};
if ((_colorIndex < 0) || {_colorIndex > 3}) exitWith {};

[{
    (!isNull player) && {alive player}
},
{
    TRACE_3("player ready",player,playerSide,_this);
    params ["_pos", "_sideIndex", "_text", "_colorIndex"];

    if ((_sideIndex != 4) && {playerSide != ([west, east, resistance, civilian] select _sideIndex)}) exitWith {};

    private _color = ["ColorBlack", "ColorRed", "ColorGreen", "ColorBlue"] select _colorIndex;    
    [_pos, _text, _color] call FUNC(createLocalMarker);

}, [_pos, _sideIndex, _text, _colorIndex]] call CBA_fnc_waitUntilAndExecute;
