#include "script_component.hpp"

#define SINK_DIST 0.25

TRACE_1("params",_this);

params ["_object"];

(boundingBox _object) params ["_p1", "_p2"];
GVAR(garbageToClean) pushBack [_object, abs (_p2#2 - _p1#2)];


if (!isNil QGVAR(cleanPFID)) exitWith { LOG("Trying to start garbage cleanup while it is already running"); };

GVAR(cleanPFID) = [{
    if (GVAR(garbageToClean) isEqualTo []) exitWith {
        [GVAR(cleanPFID)] call CBA_fnc_removePerFrameHandler;
        GVAR(cleanPFID) = nil;
    };

    (GVAR(garbageToClean)#0) params [["_object", objNull, [objNull]], "_distanceToSink"];

    if (isNull _object) exitWith {
        GVAR(garbageToClean) deleteAt 0;
    };

    if (GVAR(simpleCleanup)) then {
        deleteVehicle _object;
        GVAR(garbageToClean) deleteAt 0;
    } else {
        if (_distanceToSink <= 0) then {
            deleteVehicle _object;
            GVAR(garbageToClean) deleteAt 0;
        } else {
            (getPosWorld _object) params ["_x", "_y", "_z"];
            _object setPosWorld [_x, _y, _z - SINK_DIST];
            (GVAR(garbageToClean)#0) set [1, _distanceToSink - SINK_DIST];
        };
    };
}, GVAR(deletionDelay)] call CBA_fnc_addPerFrameHandler;
