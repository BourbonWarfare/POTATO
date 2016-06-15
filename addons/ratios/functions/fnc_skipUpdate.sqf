#include "script_component.hpp"

params ["","_radioInput1","_radioInput2","_radioInput3","_radioInput4"];

if (_radioInput1 == "" && {_radioInput2 == ""} && {_radioInput3 == ""} && {_radioInput4 == ""}) exitWith { true };

private _lastValues = GET_UI_VAR(lastValues);
if (isNil "_lastValues") exitWith { SET_UI_VAR(lastValues,_this); false };
if (_this isEqualTo _lastValues) exitWith { true };

SET_UI_VAR(lastValues,_this);
false
