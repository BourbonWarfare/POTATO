#include "script_component.hpp"

#define SINK_DIST 0.25

TRACE_1("params",_this);

params ["_object"];

(boundingBox _object) params ["_p1", "_p2"];

[{
    params ["_args", "_handle"];
    _args params ["_object", "_distanceToSink"];

    if (isNull _object) exitWith {
        [_handle] call CBA_fnc_removePerFrameHandler;
    };

    if (_distanceToSink <= 0) exitWith {
        deleteVehicle _object;
    };

    (getPosWorld _object) params ["_x", "_y", "_z"];
    _object setPosWorld [_x, _y, _z - SINK_DIST];

    _args set [1, _distanceToSink - SINK_DIST];
}, 0, [_object, abs (_p2 # 2 - _p1 # 2)]] call CBA_fnc_addPerFrameHandler;
