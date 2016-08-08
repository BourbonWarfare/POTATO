/*
 *
 */

#include "script_component.hpp"
TRACE_3("params",_this,_this getVariable QGVAR(setBabel),_this getVariable QGVAR(selectedLanguages));

private _setBabel = _this getVariable [QGVAR(setBabel), false];
if (_setBabel) then {
    _this getVariable [QGVAR(selectedLanguages), []]
} else {
    true
}
