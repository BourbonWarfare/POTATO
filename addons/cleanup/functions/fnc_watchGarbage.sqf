/*
 * Author: AACO
 * Function used watch garbage objects in a per-frame fashion for later cleanup
 *
 * Arguments:
 * 0: Object to delete <OBJECT>
 *
 * Examples:
 * [player] call potato_cleanup_fnc_watchGarbage;
 *
 * Public: No
 */

#include "script_component.hpp"

TRACE_1("params",_this);
params [["_object", objNull, [objNull]]];

GVAR(garbageToWatch) pushBack _object;
if (!isNil QGVAR(watchPFID)) exitWith {};

GVAR(watchPFID) = [{
    params ["_args"];
    _args params ["_index"];
    TRACE_1("args",_args);

    // at the end of the array clear garbage array of nulls, reset index, exit if there is nothing left
    if (_index >= count GVAR(garbageToWatch)) exitWith {
        GVAR(garbageToWatch) = (GVAR(garbageToWatch) arrayIntersect GVAR(garbageToWatch)) - [objNull];
        _args set [0, 0];

        if (GVAR(garbageToWatch) isEqualTo []) exitWith {
            [GVAR(watchPFID)] call CBA_fnc_removePerFrameHandler;
            GVAR(watchPFID) = nil;
        };
    };

    // if the object to check is null just skip it
    private _object = GVAR(garbageToWatch)#_index;
    TRACE_1("object",_object);
    if (isNull _object) exitWith {
        _args set [0, _index + 1];
    };

    // if the object has not been dead long enough, reset index.
    private _timeDead = CBA_missionTime - (_object getVariable [QGVAR(killedAt), 0]);
    if (_timeDead < GVAR(minTime)) exitWith {
        _args set [0, 0];
    };

    if (_timeDead > GVAR(maxTime) || {[_object] call DFUNC(canCollect)}) then {
        [_object] call FUNC(cleanGarbage);
        GVAR(garbageToWatch) set [_index, objNull];
    };

    // increment the index for the next run
    _args set [0, _index + 1];
}, 0, [0]] call CBA_fnc_addPerFrameHandler;
