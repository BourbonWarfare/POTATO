#include "script_component.hpp"

params ["_winningSide"];
TRACE_1("params",_this);

[format ["Mission ended. Now slotting next mission"], "sessionLog"] call A3Log;

if ((!hasInterface) || {EGVAR(core,playerStartingSide) == _winningSide}) then {
    ["", true, 1] call BIS_fnc_endMission;
} else {
    ["", false, 1] call BIS_fnc_endMission;
};
