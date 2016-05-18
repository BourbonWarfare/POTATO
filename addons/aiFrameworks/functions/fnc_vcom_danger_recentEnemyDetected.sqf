#include "script_component.hpp"
TRACE_1("params",_this);

private ["_KnownEnemy"];

_KnownEnemy = _this findNearestEnemy _this;
_KnownEnemy
