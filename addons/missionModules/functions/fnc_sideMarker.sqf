/*
 * Author: MikeMatrix, AACO
 * Function used to update tooltips to new values and update min/maxes
 * should only be called from UI events
 *
 * Public: No
 */

#include "script_component.hpp"

TRACE_1("params",_this);
params ["_logic", "_units", "_activated"];

if (!_activated || !hasInterface) exitWith {};

TRACE_1("",allVariables _logic);

private _sideArray = [];
if (_logic getVariable ["east", false]) then { _sideArray pushBack east; };
if (_logic getVariable ["west", false]) then { _sideArray pushBack west; };
if (_logic getVariable ["independent", false]) then { _sideArray pushBack independent; };
if (_logic getVariable ["civilian", false]) then { _sideArray pushBack civilian; };

TRACE_1("sides",_sideArray);
if (count _sideArray < 1) exitWith { ERROR("No sides in the side array - exiting"); };

private _pos = getPos _logic;
private _dir = _logic getVariable ["direction", 0];
private _text = _logic getVariable ["text", ""];
private _color = _logic getVariable ["color", "ColorBlack"];
private _icon = _logic getVariable ["icon", "mil_dot_noShadow"];

[
    { (!isNull player) && {alive player} && {diag_tickTime > _this select 6} },
    {
        TRACE_3("player ready",player,playerSide,_this);
        params ["_pos", "_dir", "_sideArray", "_text", "_color", "_icon"];

        if !(playerSide in _sideArray) exitWith { LOG("Player side not in side array, exiting"); };

        private _nextIndex = missionNamespace getVariable [QGVAR(nextMarkerIndex), 0];
        missionNamespace setVariable [QGVAR(nextMarkerIndex), (_nextIndex + 1)];
        private _markerName = createMarkerLocal [format [QGVAR(%1), _nextIndex], _pos];

        TRACE_1("Creating Marker",_markerName);
        _markerName setMarkerShapeLocal "ICON";
        _markerName setMarkerDirLocal _dir;
        _markerName setMarkerTextLocal _text;
        _markerName setMarkerColorLocal _color;
        _markerName setMarkerTypeLocal _icon;
    },
    [_pos, _dir, _sideArray, _text, _color, _icon, diag_tickTime + 5]
] call CBA_fnc_waitUntilAndExecute;
