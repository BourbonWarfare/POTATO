/*
 *
 */

#include "script_component.hpp"
TRACE_3("params",_this,_this getVariable QGVAR(setChannel),_this getVariable QGVAR(selectedChannels));

private _setChannel = _this getVariable [QGVAR(setChannel), false];
if (_setChannel) then {
    _this getVariable [QGVAR(selectedChannels), [0,0,0]]
} else {
    true
}
