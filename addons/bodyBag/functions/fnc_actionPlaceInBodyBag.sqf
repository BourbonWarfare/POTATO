/*
 * Author: AACO
 * Put a body in a bag
 *
 * Arguments:
 * 0: The mortician <OBJECT>
 * 1: The dead <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [player, cursorTarget] call potato_bodyBag_fnc_actionPlaceInBodyBag
 *
 * Public: No
 */

#include "script_component.hpp"

params ["_caller", "_target"];
TRACE_2("params",_caller,_target);

if (alive _target) then {
    TRACE_1("manually killing with setDead",_target);
    [_target, true] call ACEFUNC(medical,setDead);
};

private _position = (getPosASL _target) vectorAdd [0, 0, 0.2];

private _headPos  = _target modelToWorldVisual (_target selectionPosition "head");
private _spinePos = _target modelToWorldVisual (_target selectionPosition "Spine3");
private _dirVect = _headPos vectorFromTo _spinePos;
private _direction = _dirVect call CBA_fnc_vectDir;

//move the body away now, so it won't physX the bodyBag object (this setPos seems to need to be called where object is local)
_target setPosASL [-5000, -5000, 0];

// move the inventory into the body bag if needed
private _bodyBag = if (GVAR(moveInventoryToBodyBag)) then {
    private _bodyBagHolder = createVehicle ["POTATO_bodyBagHolderObject", _position, [], 0, ""];
    [_target, _bodyBagHolder] call CFUNC(addUnitLoadoutToContainer);
    _bodyBagHolder
} else {
    createVehicle ["ACE_bodyBagObject", _position, [], 0, ""]
};

// prevent body bag from flipping
_bodyBag setPosASL _position;
_bodyBag setDir _direction;

["ace_placedInBodyBag", [_target, _bodyBag]] call CBA_fnc_globalEvent; //hide and delete body on server

_bodyBag
