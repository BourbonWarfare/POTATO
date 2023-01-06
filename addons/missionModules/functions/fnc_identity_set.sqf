#include "script_component.hpp"

params ["_initArgs", "_index"];
_initArgs params ["_unit"];
if (!alive _unit) exitWith {};
if (isPlayer _unit) exitWith {};

private _voice = selectRandom (GVAR(voiceArray) select _index);
TRACE_2("setting global",_unit, _voice);
["ace_common_setSpeaker", [_unit, _voice]] call CBA_fnc_globalEvent; // should be jip compatible?
