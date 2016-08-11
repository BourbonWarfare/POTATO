/*
 *
 */

#include "script_component.hpp"
TRACE_3("params",_this,_this getVariable QGVAR(setBabel),_this getVariable QGVAR(selectedLanguages));

if (_this getVariable [QGVAR(setBabel), false]) then {
    _this getVariable [QGVAR(selectedLanguages), []]
} else {
    true
}
