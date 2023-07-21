#include "script_component.hpp"

if (!hasInterface) exitWith {};

GVAR(soundList) = [QGVAR(hit_01),QGVAR(hit_02),QGVAR(hit_03),QGVAR(hit_04),QGVAR(hit_05),QGVAR(hit_06),QGVAR(hit_07),QGVAR(hit_08),QGVAR(hit_09),QGVAR(hit_10)];

["ace_unconscious", {
    params ["_unit", "_state"];
    if (!_state || { !alive _unit } || { !isNull objectParent _unit }) exitWith {};
    if (!(missionNamespace getVariable [QGVAR(enabled), true])) exitWith {};
    _unit say3D [(selectRandom GVAR(soundList)), 200, 1, false];
}] call CBA_fnc_addEventHandler;
