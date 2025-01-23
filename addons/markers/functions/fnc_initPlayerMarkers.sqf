#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function will initialize both markers for a unit, and for their
 * group if they are the leader of said group. The marker information is
 * broadcast globally and saved into the JIP queue.
 *
 * Arguments:
 * 0: Unit to check if it has a marker attached <OBJECT>
 *
 * Example:
 * [cursorObject] call potato_markers_fnc_hasMarkerAttached;
 *
 * Public: No
 */
params [["_unit", objNull, [objNull]]];

if (!local _unit || {!(_unit isKindOf "CAManBase")}) exitWith {
    TRACE_2("Unit is not of valid type",_unit,typeOf _unit);
};

[_unit] call FUNC(addMarkerInfoToHash);

if (_unit == leader _unit) then {
    [group _unit] call FUNC(addMarkerInfoToHash);
};
