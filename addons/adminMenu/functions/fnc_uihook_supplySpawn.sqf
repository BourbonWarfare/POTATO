#include "script_component.hpp"

TRACE_1("params",_this);

private _selectedIndexClass = lbCurSel UI_TAB_SUPPLIES_TYPE;
if ((_selectedIndexClass < 0) || (_selectedIndexClass >= (count GVAR(supplyClassNames)))) exitWith {};

private _selectedClass = GVAR(supplyClassNames) select _selectedIndexClass;
private _selectedGroupIndex = lbCurSel UI_TAB_SUPPLIES_GROUP;
if ((_selectedGroupIndex < 0) || (_selectedGroupIndex >= (count GVAR(groupsArray)))) exitWith {};

private _selectedGroup = GVAR(groupsArray) select _selectedGroupIndex;
private _spawnedSupport = createVehicle [_selectedClass,(getPos leader _selectedGroup), [], 0, "NONE"];

private _debugMsg = format ["Supply dropping %1 to %2", _selectedClass, _selectedGroup];
["potato_adminMsg", [_debugMsg, profileName]] call CBA_fnc_globalEvent;
