#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function will take a group or object and check whether it has a
 * marker attached to it.
 *
 * Arguments:
 * 0: Object/Group to check if it has a marker attached <OBJECT/GROUP>
 *
 * Example:
 * [cursorObject] call potato_markers_fnc_hasMarkerAttached;
 *
 * Public: Yes
 */
params [
    ["_object", objNull, [grpNull, objNull]]
];

if (_object isEqualType grpNull) then {
    private _hashValue = groupId _object;
    private _array = GVAR(drawHash) getOrDefault [_hashValue, [grpNull]];
    _array#0 isEqualTo _object
} else {
    private _hashValue = str _object;
    private _array = GVAR(drawHash) getOrDefaultCall [_hashValue, {
        _hashValue = groupId group _object;
        GVAR(drawHash) getOrDefault [_hashValue, [grpNull]]
    }];
    _array#0 isEqualTo _object
}
