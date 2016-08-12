/*
 *
 */
#include "script_component.hpp"

params ["_thing",["_languageString","",["",false]]];
TRACE_2("params",_thing,_languageString);

if ((_languageString isEqualType true && {_languageString}) || {_languageString isEqualTo ""}) exitWith { LOG("languages not set, or in strange state, exiting early"); };

[{
    params ["_thing","_languageString"];
    private _languageArray = _languageString splitString ",";
    _thing setVariable [QGVAR(assignedLanguages), _languageArray, true];
}, [_thing, _languageString]] call CBA_fnc_execNextFrame;
