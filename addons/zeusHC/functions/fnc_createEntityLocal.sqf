#include "script_component.hpp"

params ["_posATL"];
TRACE_1("params",_posATL);

private _unitTypeArray = ["O_soldier_SL_F", "O_soldier_F","O_soldier_F","O_soldier_LAT_F","O_soldier_F"]; //todo:

private _newGroup = createGroup east;
TRACE_2("",_newGroup,_unitTypeArray);
{
    _unit = _newGroup createUnit [_x, _posATL, [], 0, "FORM"];

    TRACE_1("",_unit);
} forEach _unitTypeArray;
