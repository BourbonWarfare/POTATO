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

    private _nextIndex = missionNamespace getVariable [QGVAR(nextMarkerIndex), 0];
    _markerName = format [QGVAR(sideMarker_%1), _nextIndex];
    missionNamespace setVariable [QGVAR(nextMarkerIndex), (_nextIndex + 1)];

    createmarker [_markerName,_pos];
    TRACE_1("Creating Marker",_markerName);
    _markerName setMarkerShapeLocal "ICON";
    _markerName setMarkerTypeLocal "mil_dot";
    _markerName setMarkerTextLocal _text;
    _markerName setMarkerColorLocal (["ColorBlack", "ColorRed", "ColorGreen", "ColorBlue"] select _colorIndex);


}, [_pos, _sideIndex, _text, _colorIndex]] call ace_common_fnc_waitUntilAndExecute;
