#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function handles the transfer for the ACE "become group leader"
 * action statement override.
 *
 * Arguments:
 * 0: The unit attempting to become leader of a group <OBJECT>
 *
 * Examples:
 * [cursorObject] call potato_markers_fnc_becomeGroupLeader_statement;
 *
 * Public: No
 */
if (_this call ACEFUNC(interaction,canBecomeLeader)) then {
    _this call ACEFUNC(interaction,doBecomeLeader);
};

if (!GVAR(groupAndUnitEnabled)) exitWith {};

private _hashKey = groupId group _player;
private _markerArray = GVAR(markerHash) getOrDefault [_hashKey, []];
if (_markerArray isNotEqualTo [] &&
    _hashKey != "" &&
    (_markerArray#0 isEqualType grpNull || {_markerArray#0 != _player})) then {
    [_hashKey, _player] remoteExecCall [QFUNC(transferMarker)];
};
