// #define DEBUG_MODE_FULL
#include "script_component.hpp"

TRACE_1("addToCuratorServer",_this);

{
    TRACE_2("",typeOf _x,isPlayer _x);
    _x setVariable [QGVAR(addToCurators), true]; // var only set on server
} forEach _this;

{
    _x addCuratorEditableObjects [_this, false];
} forEach allCurators;
