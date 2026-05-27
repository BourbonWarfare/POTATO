#include "..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
*
*
* Arguments:
*
*
* Return:
* The diaphragm hitpoint armor
*
* Example:
* [vest ace_player] call potato_missionTesting_fnc_shootUnit;
*//***************************************************************************/
params [["_unit", objNull], "_ammo", "_speed", ["_pos", SHOTPOS_CHEST, [0]]];
if (!alive _unit || {_unit getVariable [QGVAR(ended), false]}) exitWith {};
if (_unit == ace_player) exitWith {
    WARNING_3("Unit variable corrupted for [%1] [%2], [%3]",_ammo,_speed,_pos);
};
if (_unit getVariable [QGVAR(hits), 0] > 9) exitWith {
    _unit setDamage 1;
    _unit setVariable [QGVAR(ended), true];
};
private _posRelative = switch (_pos) do {
	case (SHOTPOS_FACE): {[0, 0, -0.1] vectorAdd (_unit selectionPosition ["head", "HitPoints", "AveragePoint"])};
	case (SHOTPOS_HEAD): {_unit selectionPosition ["head", "HitPoints", "AveragePoint"]};
	default {
		_unit selectionPosition ["spine3", "HitPoints", "AveragePoint"]
	};
};
_posRelative = _unit modelToWorldVisual _posRelative;
private _bullet = createVehicle [_ammo, _posRelative vectorAdd [0, -0.3, 0], [], 0, "CAN_COLLIDE"];
_bullet setVectorDirAndUp [[0, 1, 0], [0, 0, 1]];
_bullet setVelocity [0, _speed, 0];
_unit setVariable [QGVAR(hits), 1 + (_unit getVariable [QGVAR(hits), 0])];

[{call FUNC(shootUnit)}, _this, 0.1] call CBA_fnc_waitAndExecute;
