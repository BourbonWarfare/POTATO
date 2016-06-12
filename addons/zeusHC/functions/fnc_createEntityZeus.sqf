/*
 * Author: PabstMirror
 * logic called when a premade group/vehicle module is placed
 */

#include "script_component.hpp"

params ["_logic"];
TRACE_2("params",_logic,_this select 1);
if (isNull _logic) exitWith {};

private _posATL = getPosATL _logic;
private _typeOf = typeOf _logic;
private _attachedVehicle = _logic getVariable ["bis_fnc_curatorAttachObject_object",objnull];
private _placerOwner = owner _logic;
TRACE_4("",_posATL,_typeOf,_attachedVehicle,_placerOwner);

if (time > 0) then {
    [
        [_posATL, _typeOf, _attachedVehicle, _placerOwner],
        QFUNC(createEntityLocal)
    ] call FUNC(hcPassthrough);
} else {
    [{
        (diag_tickTime > (_this select 4)) || {time > 0}
    }, {
        [
            _this select [0,4],
            QFUNC(createEntityLocal)
        ] call FUNC(hcPassthrough);
    },
    [_posATL, _typeOf, _attachedVehicle, _placerOwner, (diag_tickTime + 10 + random 10)]] call CBA_fnc_waitUntilAndExecute;
};

deleteVehicle _logic;
