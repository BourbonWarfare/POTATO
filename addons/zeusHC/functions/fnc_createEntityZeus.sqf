#include "script_component.hpp"

params ["_logic"];
TRACE_1("params",_logic);

private _posATL = getPosATL _logic;
private _typeOf = typeOf _logic;

TRACE_2("",_posATL,_typeOf);
[_posATL, _typeOf] call FUNC(createEntityServer);

deleteVehicle _logic;
