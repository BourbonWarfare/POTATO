#include "script_component.hpp"

TRACE_1("params",_this);

private _selectedPersonIndex = lbCurSel UI_TAB_TELEPORT_PERSON;
if ((_selectedPersonIndex < 0) || (_selectedPersonIndex >= (count GVAR(teleportPersonList)))) exitWith {};

private _selectedPerson = GVAR(teleportPersonList) select _selectedPersonIndex;
if (isNull _selectedPerson) exitWith {};

private _selectedGroupIndex = lbCurSel UI_TAB_TELEPORT_GROUP;
if ((_selectedGroupIndex < 0) || (_selectedGroupIndex >= (count GVAR(groupsArray)))) exitWith {};

private _selectedGroup = GVAR(groupsArray) select _selectedGroupIndex;

private _leader = leader _selectedGroup;
if (!alive _leader) exitWith { TRACE_1("dead leader",_leader); };

private _return = "null";

if ((vehicle _leader) == _leader) then {
    private _freeSpot = (getPos _leader) findEmptyPosition [1,30];
    if (_freeSpot isEqualTo []) then {
        _return = "No empty Pos";
    } else {
        _selectedPerson setPos _freeSpot;
        _return = "Moving to pos";
    };
} else {
    [_selectedPerson, (vehicle _leader)] remoteExec ["moveInAny", _selectedPerson];
    _return = "Moving In Vic (no guarentes)";
};

private _debugMsg = format ["Teleporting %1 to group %2 [%3]", (name _selectedPerson), _selectedGroup, _return];
["potato_adminMsg", [_debugMsg, profileName]] call ACEFUNC(common,globalEvent);
