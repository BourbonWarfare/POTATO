#include "script_component.hpp"

TRACE_1("params",_this);

_selectedPersonIndex = lbCurSel UI_TAB_TELEPORT_PERSON;
if ((_selectedPersonIndex < 0) || (_selectedPersonIndex >= (count PABST_ADMIN_ui_teleportPersons))) exitWith {};

_selectedPerson = PABST_ADMIN_ui_teleportPersons select _selectedPersonIndex;
if (isNull _selectedPerson) exitWith {};

_selectedGroupIndex = lbCurSel UI_TAB_TELEPORT_GROUP;
if ((_selectedGroupIndex < 0) || (_selectedGroupIndex >= (count GVAR(groupsArray)))) exitWith {};

_selectedGroup = GVAR(groupsArray) select _selectedGroupIndex;

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
    [_selctedPerson, (vehicle _leader)] remoteExec ["moveInAny", _selctedPerson];
    _return = "Moving In Vic (no guarentes)";
};

_selectedPerson setPos (getPos leader _selectedGroup);
_debugMsg = format ["Teleporting %1 to group %2 [%3]", (name _selectedPerson), _selectedGroup, _return];
["potato_adminMsg", [_debugMsg, profileName]] call ACEFUNC(common,globalEvent);
