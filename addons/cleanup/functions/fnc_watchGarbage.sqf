#include "script_component.hpp"

TRACE_1("params",_this);

if (!isNil QGVAR(watchPFID)) exitWith { LOG("Trying to start garbage watching while it is already running"); };

GVAR(watchPFID) = [{
    params ["_args"];
    _args params ["_index"];

    // at the end of the array clear garbage array of nulls, reset index, exit if there is nothing left
    if (_index >= count GVAR(garbageToWatch)) exitWith {
        GVAR(garbageToWatch) = GVAR(garbageToWatch) arrayIntersect GVAR(garbageToWatch);
        _args set [0, 0];

        if (GVAR(garbageToWatch) isEqualTo []) exitWith {
            [GVAR(watchPFID)] call CBA_fnc_removePerFrameHandler;
            GVAR(watchPFID) = nil;
        };
    };

    // if the object to check is null just skip it
    private _object = GVAR(garbageToWatch) # _index;
    if (isNull _object) exitWith {
        _args set [0, _index + 1];
    };

    // if the object has not been dead long enough, reset index.
    private _timeDead = CBA_missionTime - (_object getVariable [QGVAR(killedAt), 0]);
    if (_timeDead < GVAR(minTime)) exitWith {
        _args set [0, 0];
    };

    if (_timeDead > GVAR(maxTime) || {[_object] call DFUNC(canCollect)}) then {
        [_object] call FUNC(takeOutTrash);
        GVAR(garbageToWatch) set [_index, objNull];
    };

    // increment the index for the next run
    _args set [0, _index + 1];
}, 0, [0]] call CBA_fnc_addPerFrameHandler;
