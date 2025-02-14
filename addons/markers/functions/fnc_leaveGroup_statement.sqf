#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function handles a unit leaving a group and is used
 * for the ACE "leave group" action statemnt override
 *
 * Arguments:
 * 0: The unit attempting to leave a group <OBJECT>
 *
 * Examples:
 * [cursorObject] call potato_markers_fnc_leaveGroup_statement;
 *
 * Public: No
 */
//IGNORE_PRIVATE_WARNING["_target", "_player"];

private _group = group _player;
private _groupSide = side _group;
private _hashKey = str _groupSide + groupId _group;
private _oldGroup = units _group;
private _newGroup = createGroup _groupSide;
[_player] joinSilent _newGroup;
{_player reveal _x} forEach _oldGroup;
if !(GVAR(groupAndUnitEnabled)) exitWith {};
private _markerArray = GVAR(markerHash) getOrDefault [_hashKey, [objNull]];
if (_markerArray#0 == _player && _hashKey != "") then {
    [_hashKey] remoteExecCall [QFUNC(transferMarker)];
};
