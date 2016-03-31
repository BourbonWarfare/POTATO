#include "script_component.hpp"

params ["_logic"];
TRACE_1("params",_logic);
if (isNull _logic) exitWith {};

private _posATL = getPosATL _logic;
private _typeOf = typeOf _logic;
private _attached = _logic getVariable ["bis_fnc_curatorAttachObject_object",objnull];
TRACE_3("",_posATL,_typeOf,_attached);

if (time > 0) then {
    [FUNC(createEntityServer), [_posATL, _typeOf, _attached]] call CBA_fnc_directCall;
} else {
    [{
        (diag_tickTime > (_this select 3)) || {time > 0}
    }, {
        _this call FUNC(createEntityServer);
    },
    [_posATL, _typeOf, _attached, (diag_tickTime + 10 + random 10)]] call ACEFUNC(common,waitUntilAndExecute);
};

deleteVehicle _logic;
