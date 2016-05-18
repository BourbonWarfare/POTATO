#include "script_component.hpp"
TRACE_1("params",_this);

private ["_Unit", "_WayPointPosition", "_UnitPos", "_direction", "_SetPosition"];

_Unit = _this select 0;
_WayPointPosition = _this select 1;

_UnitPos = getpos _Unit;

_direction = [_UnitPos,_WayPointPosition] call BIS_fnc_dirTo;
_SetPosition = [_UnitPos,60,_direction] call BIS_fnc_relPos;
_SetPosition
