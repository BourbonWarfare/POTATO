#include "script_component.hpp"

TRACE_1("params",_this);

params [_object, objNull [objNull]];

if (isNull _object || {_object getVariable [QGVAR(wasPlayer), false]} || {_object getVariable [QGVAR(ignore), false]}) exitWith {};

_object setVariable [QGVAR(killedAt), CBA_missionTime];
GVAR(garbageToWatch) pushBack _object

[] call FUNC(watchGarbage);
