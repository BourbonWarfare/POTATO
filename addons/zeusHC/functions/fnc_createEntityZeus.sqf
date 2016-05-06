#include "script_component.hpp"

params ["_logic"];
TRACE_1("params",_logic);
if (isNull _logic) exitWith {};

private _posATL = getPosATL _logic;
private _typeOf = typeOf _logic;
private _attachedVehicle = _logic getVariable ["bis_fnc_curatorAttachObject_object",objnull];
private _placerOwner = owner _logic;
TRACE_4("",_posATL,_typeOf,_attachedVehicle,_placerOwner);

if (time > 0) then {
    [_posATL, _typeOf, _attachedVehicle, _placerOwner] remoteExecCall [QFUNC(createEntityLocal), ([] call FUNC(getSpawnMachineId))];
} else {
    [{
        (diag_tickTime > (_this select 4)) || {time > 0}
    }, {
        [
            _this select [0,4],
            QFUNC(createEntityLocal)
        ] call FUNC(hcPassthroughServer);
    },
    [_posATL, _typeOf, _attachedVehicle, _placerOwner, (diag_tickTime + 10 + random 10)]] call ACEFUNC(common,waitUntilAndExecute);
};

deleteVehicle _logic;
