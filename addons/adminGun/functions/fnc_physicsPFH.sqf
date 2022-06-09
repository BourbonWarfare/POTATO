#include "script_component.hpp"
/*
 * Author: Dani (TCVM)
 * Called when a player fires a physics magazine. Does physics gun stuff
 *
 * Arguments:
 * 0: Unit that fired
 * 1: Weapon that fired
 * 2: Muzzle
 * 3: Mode
 * 4: Ammo used
 * 5: Magazine used
 * 6: Projectile
 * 7: Gunner whose weapon fired
 *
 * Examples:
 * _this call potato_adminGun_fnc_onFired;
 *
 * Public: No
 */
params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];
deleteVehicle _projectile;

private _startPos = eyePos _unit;
private _direction = _unit weaponDirection currentWeapon _unit;
private _objects = lineIntersectsSurfaces [_startPos, _startPos vectorAdd (_direction vectorMultiply 1000), _unit, objNull, true, 1, "FIRE"];

private _firstIntersect = _objects select 0;
_firstIntersect params ["_intersectPos", "", "_intersectObject"];

private _initialDistance = _startPos vectorDistance _intersectPos;
private _intersectOffset = _intersectPos vectorDiff (getPosASLVisual _intersectObject);

[{
    params ["_args", "_handle"];
    _args params ["_intersect", "_distance", "_offset", "_lastDirection", "_lastTime", "_unit"];
    _intersect params ["_intersectPos", "", "_intersectObject"];

    private _direction = _unit weaponDirection currentWeapon _unit;
    private _startPos = eyePos _unit;

    // gross way to do this, but it works
    private _scrollIn = inputAction "nextAction";
    private _scrollOut = inputAction "prevAction";

    private _distanceModifier = (_distance / SCROLL_DAMPER_RANGE) min 1;

    if (_scrollOut > 0) then {
        _distance = _distance + _distanceModifier * 30 * _scrollOut;
    };

    if (_scrollIn > 0) then {
        _distance = _distance - _distanceModifier * 30 * _scrollIn;
    };

    _distance = 2 max (_distance min MAX_RANGE);

    _args set [1, _distance];

    if (0 == inputMouse 0) exitWith {
        if (_lastDirection isNotEqualTo [0, 0, 0]) then {
            // set velocity

            private _d0 = _lastDirection vectorMultiply _distance;
            private _d1 = _direction vectorMultiply _distance;

            private _diff = _d1 vectorDiff _d0;
            private _dt = CBA_missionTime - _lastTime;

            if (_dt != 0) then {
                private _velocity = _diff vectorMultiply (1 / _dt);
                [QGVAR(setVelocity), [_intersectObject, _velocity], _intersectObject] call CBA_fnc_targetEvent;
            };

        };

        [_handle] call CBA_fnc_removePerFrameHandler;
    };

    if (isNil "_intersectObject" || { isNull _intersectObject }) then {
        private _objects = lineIntersectsSurfaces [_startPos, _startPos vectorAdd (_direction vectorMultiply MAX_RANGE), _unit, objNull, true, 1, "FIRE"];
        if (_objects isNotEqualTo []) then {
            private _firstIntersect = _objects select 0;
            _firstIntersect params ["_newPos", "", "_newObject"];

            if !(isNull _newObject) then {
                private _initialDistance = _startPos vectorDistance _newPos;
                private _intersectOffset = _newPos vectorDiff (getPosASLVisual _newObject);

                _args set [0, _firstIntersect];
                _args set [1, _initialDistance];
                _args set [2, _intersectOffset];
            };
        };

    } else {
        private _desiredPosition = _startPos vectorAdd (_direction vectorMultiply _distance);
        _intersectObject setPosASL (_desiredPosition vectorDiff _offset);
    };

    drawLaser [_startPos vectorAdd (_direction vectorMultiply 0.1), _direction, [500, 0, 0], [], 0, 1, MAX_RANGE, false];

    _args set [3, _direction];
    _args set [4, CBA_missionTime];

}, 0, [_firstIntersect, _initialDistance, _intersectOffset, [0, 0, 0], CBA_missionTime, _unit]] call CBA_fnc_addPerFrameHandler;

