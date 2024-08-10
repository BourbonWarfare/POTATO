/*
 * Author: AACO
 * Function to set map gesture color mapping on a group
 * Should only be called through 3DEN
 * Note, needed as a JIP safe function as the groups ids can be empty (throws reserved variable error in addGroupColorMapping)
 *
 * Arguments:
 * 0: Object/Group to add attributes to <GROUP>
 * 1: Color array <ARRAY>
 *
 * Example:
 * [player, [1,1,1,1]] call potato_markers_fnc_addGestureColor;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params [
    ["_object", grpNull, [grpNull, objNull]],
    ["_colorArray", [], [[]]]
];

if (isNull _object || count _colorArray != 4) exitWith { WARNING_2("Bad input parameters",_object,_colorArray); };

if (_object isEqualType grpNull && {groupId _object != ""}) then {
    [toLower groupId _object, _colorArray, _colorArray] call ACEFUNC(map_gestures,addGroupColorMapping);
} else {
    private _groupId = toLower groupId (group _object);
    if (_groupId != "" && {!(_groupId in ACEGVAR(map_gestures,GroupColorCfgMappingNew))}) then {
        [_groupId, _colorArray, _colorArray] call ACEFUNC(map_gestures,addGroupColorMapping);
    };
};
