/*
 * Author: AACO
 * Function used to mass add/remove event handlers to/from all curretnly active units
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [true] call potato_spectate_fnc_setEventsOnActiveUnits;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params [["_add", true, [true]]];

// only evaluate add/remove once, instead of per-unit
private _fnc_dealWithUnit = if (_add) then {
    FUNC(addEventHandlers)
} else {
    FUNC(removeEventHandlers)
};

{
    // we should only need to check for alive, but belts/suspenders
    if (!isNil "_x" && {!isNull _x} && {alive _x}) then {
        [_x] call _fnc_dealWithUnit;
    };
} forEach allUnits;
