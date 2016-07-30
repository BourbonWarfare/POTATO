/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

[{
    params ["_object",["_radioArray",[],[[]]]];
    _radioArray params [["_setChannels", false, [false]], ["_channelsArray", [], [[]]]];
    TRACE_3("",_object,_setChannels,_channelsArray);


    if !(_setChannels) exitWith { LOG("No channels set, exiting"); };

    _channelsArray params [["_srChannel", 0, [0]], ["_mrChannel", 0, [0]], ["_lrChannel", 0, [0]]];

    _object setVariable [QGVAR(srChannel), _srChannel + 1, true];
    _object setVariable [QGVAR(mrChannel), _mrChannel + 1, true];
    _object setVariable [QGVAR(lrChannel), _lrChannel + 1, true];
}, _this] call CBA_fnc_execNextFrame;
