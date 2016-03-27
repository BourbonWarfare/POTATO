#include "script_component.hpp"

params ["_logic"];
TRACE_1("params",_logic);

private _posATL = getPosATL _logic;
private _typeOf = typeOf _logic;

disableSerialization;

createDialog QGVAR(build_a_group_dialog);
private _dialog = findDisplay BUILD_GROUP_IDD;

deleteVehicle _logic;
