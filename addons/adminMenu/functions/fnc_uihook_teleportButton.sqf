#include "script_component.hpp"

TRACE_1("params",_this);

private _selectedUnit = missionNamespace getVariable [
    UI_TAB_FIX_UNIT_LIST lbData (lbCurSel UI_TAB_TELEPORT_PERSON),
    objNull
];

TRACE_1("Selected unit: ",_selectedUnit);

if (isNull _selectedUnit) exitWith {WARNING_1("Bad unit, disconnect?", _selectedUnit);};

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
        _selectedUnit setPos _freeSpot;
        _return = "Moving to pos";
    };
} else {
    [_selectedUnit, (vehicle _leader)] remoteExec ["moveInAny", _selectedUnit];
    _return = "Moving In Vic (no guarentes)";
};

private _debugMsg = format ["Teleporting %1 to group %2 [%3]", (name _selectedUnit), _selectedGroup, _return];
["potato_adminMsg", [_debugMsg, profileName]] call CBA_fnc_globalEvent;
