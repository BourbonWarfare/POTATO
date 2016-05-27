#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

private _returnEnemy = _unit getVariable [VQGVAR(cachedNearestEnemy), objNull];
if !(isNull (_returnEnemy)) exitWith { _returnEnemy };

_returnEnemy = _unit findNearestEnemy _unit;
if !(isNull _returnEnemy) exitWith { _returnEnemy };

private _minRange = 0;
private _unitSide = (side _unit);
{
    private _xSide = side _x;
	if (_xSide != _unitSide && !(_xSide isEqualTo CIVILIAN)) then {
        private _range = abs (_unit distance _x);
        if (_range < _minRange || {isNull _returnEnemy}) then {
            _minRange = _range;
            _returnEnemy = _x;
        };
    };
    nil
} count allUnits;

_returnEnemy
