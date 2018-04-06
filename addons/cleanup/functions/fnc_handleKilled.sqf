#include "script_component.hpp"

TRACE_1("params",_this);

params [_object, objNull [objNull]];

if (isNull _object || {_object getVariable [QGVAR(wasPlayer), false]} || {_object getVariable [QGVAR(ignore), false]}) exitWith {};

_object setVariable [QGVAR(killedAt), CBA_missionTime];
GVAR(garbage) pushBack _object

if (isNil QGVAR(cleanupPFID)) then {
    [] call FUNC(garbageCollect);
};
