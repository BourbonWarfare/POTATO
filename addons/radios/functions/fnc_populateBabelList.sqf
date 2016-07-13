/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlBabel"];

lnbClear _ctrlBabel;
{
    _x params ["_short", "_long"];
    _ctrlBabel lnbAddRow [_short, _long];
} forEach GVAR(availableLanguages);
