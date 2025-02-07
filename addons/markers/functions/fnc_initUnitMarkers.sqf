#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function will initialize markers for a local unit.
 * This function is mainly used for when a unit is switch (i.e., respawns)
 *
 * Argument:
 * 0: The unit to init <OBJECT>
 *
 * Example:
 * [cursorObject] call potato_markers_fnc_initUnitMarkers;
 *
 * Public: No
 */
params [["_unit", objNull, [objNull]]];

if (!local _unit || {!(_unit isKindOf "CAManBase")}) exitWith {
    TRACE_2("Unit is not of valid type",_unit,typeOf _unit);
};

[_unit] call FUNC(addMarkerInfoToHash);
[group _unit] call FUNC(addMarkerInfoToHash);
