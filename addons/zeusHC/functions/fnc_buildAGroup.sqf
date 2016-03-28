#include "script_component.hpp"

params ["_logic"];
TRACE_1("params",_logic);

private _posATL = getPosATL _logic;
private _typeOf = typeOf _logic;

createDialog QGVAR(build_a_group_dialog);

deleteVehicle _logic;
