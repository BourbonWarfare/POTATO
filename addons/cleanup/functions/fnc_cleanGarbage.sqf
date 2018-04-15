/*
 * Author: AACO
 * Function used delete objects in a delayed fashion
 *
 * Arguments:
 * 0: Object to delete <OBJECT>
 *
 * Examples:
 * [player] call potato_cleanup_fnc_cleanGarbage;
 *
 * Public: No
 */

#include "script_component.hpp"

TRACE_1("params",_this);
params [["_object", objNull, [objNull]]];

GVAR(garbageToClean) pushBack _object;
if (!isNil QGVAR(cleanPFID)) exitWith {};

GVAR(cleanPFID) = [{
    if (GVAR(garbageToClean) isEqualTo []) exitWith {
        [GVAR(cleanPFID)] call CBA_fnc_removePerFrameHandler;
        GVAR(cleanPFID) = nil;
    };

    private _object = GVAR(garbageToClean) deleteAt 0;
    TRACE_1("object",_object);
    if !(isNull _object) then {
        deleteVehicle _object;
    };
}, GVAR(deletionDelay)] call CBA_fnc_addPerFrameHandler;
