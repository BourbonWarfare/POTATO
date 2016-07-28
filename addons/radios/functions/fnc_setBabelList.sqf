/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlBabel"];

{
    if ((_x select 0) in GVAR(selectedLanguages)) then {
        _ctrlBabel lbSetSelected [_forEachIndex, true];
    } else {
        _ctrlBabel lbSetSelected [_forEachIndex, false];
    };
} forEach GVAR(availableLanguages);
