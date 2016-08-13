/*
 *
 */
#include "script_component.hpp"

params ["_object",["_languageString","",["",false]]];
TRACE_2("params",_object,_languageString);

if ((_languageString isEqualType true && {_languageString}) || {_languageString isEqualTo ""}) exitWith { LOG("languages not set, or in strange state, exiting early"); };

[{
    params ["_object","_languageString"];
    private _languageArray = _languageString splitString ",";
    _object setVariable [QGVAR(assignedLanguages), _languageArray, true];
}, [_object, _languageString]] call CBA_fnc_execNextFrame;
