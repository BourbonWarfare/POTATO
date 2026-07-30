#include "..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This function is used as part of the armor testing system.
* This function checks to see if a unit is alive or if testing has ended.
* It creates a single projectile intended to hit a standing arma unit in the
* chest, face or head headpoint. The head hitpoint can be difficult given how
* animations affect this choice. The projectile is given the speed specified
* and a counter on the unit is incremented. Finally the function recursively
* calls itself. If the player is selected to be shot the function exists.
* If the unit has been shot at 10 or more times it exits.
*
*
* Arguments:
* _unit - The unit that will be tested against (default objNull)
* _ammo - The class of the ammo to be used
* _speed - The speed of the projectile to be created
* _pos - The position index to shoot the unit in (NUMBER, default SHOTPOS_CHEST)
*
* Return:
* None
*
* Example:
* [ace_player, "B_45ACP_BallB_bullet_F", 300] call potato_missionTesting_fnc_shootUnit;
*//***************************************************************************/
params [["_unit", objNull], "_ammo", "_speed", ["_pos", SHOTPOS_CHEST, [0]]];
if (!alive _unit || {_unit getVariable [QGVAR(ended), false]}) exitWith {};
if (isPlayer _unit) exitWith {
    WARNING_3("Unit variable corrupted for [%1] [%2], [%3]",_ammo,_speed,_pos);
};
if (_unit getVariable [QGVAR(hits), 0] > 9) exitWith {
    _unit setDamage 1;
    _unit setVariable [QGVAR(ended), true];
};
private _posRelative = switch (_pos) do {
    case (SHOTPOS_FACE): {
        [0, 0, -0.1] vectorAdd (_unit selectionPosition ["head", "HitPoints", "AveragePoint"])
    };
    case (SHOTPOS_HEAD): {
        _unit selectionPosition ["head", "HitPoints", "AveragePoint"]
    };
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
