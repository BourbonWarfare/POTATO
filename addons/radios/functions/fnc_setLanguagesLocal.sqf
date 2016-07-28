/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_object",["_languageArray",[],[[]]],["_public",false,[false]]];
if (isNil "_languageArray" || {_languageArray isEqualTo []}) exitWith { LOG("No languages set, exiting"); };

_object setVariable [QGVAR(assignedLanguages), _languageArray, _public];
