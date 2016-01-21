#include "script_component.hpp"

TRACE_1("params",_this);

_selectedIndexClass = lbCurSel UI_TAB_SUPPLIES_TYPE;
if ((_selectedIndexClass < 0) || (_selectedIndexClass >= (count GVAR(supplyClassNames)))) exitWith {};

_selectedClass = GVAR(supplyClassNames) select _selectedIndexClass;
_selectedGroupIndex = lbCurSel UI_TAB_SUPPLIES_GROUP;
if ((_selectedGroupIndex < 0) || (_selectedGroupIndex >= (count GVAR(groupsArray)))) exitWith {};

_selectedGroup = GVAR(groupsArray) select _selectedGroupIndex;
_spawnedSupport = createVehicle [_selectedClass,(getPos leader _selectedGroup), [], 0, "NONE"];

_debugMsg = format ["Supply dropping %1 to %2", _selectedClass, _selectedGroup];
["potato_adminMsg", [_debugMsg, profileName]] call ACEFUNC(common,globalEvent);
