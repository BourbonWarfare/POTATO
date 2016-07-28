/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_object",["_radioArray",[],[[]]],["_public",false,[false]]];
_radioArray params [
    ["_setChannels", false, [false]],
    ["_channelsArray", [], [[]]]
];

if !(_setChannels) exitWith { LOG("No channels set, exiting"); };

_channelsArray params [
    ["_srChannel", 0, [0]],
    ["_mrChannel", 0, [0]],
    ["_lrChannel", 0, [0]]
];

_object setVariable [QGVAR(srChannel), _srChannel + 1, _public];
_object setVariable [QGVAR(mrChannel), _mrChannel + 1, _public];
_object setVariable [QGVAR(lrChannel), _lrChannel + 1, _public];
