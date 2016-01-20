#include "script_component.hpp"

_selectedPersonIndex = lbCurSel UI_TAB_TELEPORT_PERSON;
if ((_selectedPersonIndex < 0) || (_selectedPersonIndex >= (count PABST_ADMIN_ui_teleportPersons))) exitWith {};

_selectedPerson = PABST_ADMIN_ui_teleportPersons select _selectedPersonIndex;
if (isNull _selectedPerson) exitWith {};

_selectedGroupIndex = lbCurSel UI_TAB_TELEPORT_GROUP;
if ((_selectedGroupIndex < 0) || (_selectedGroupIndex >= (count GVAR(groupsArray)))) exitWith {};

_selectedGroup = GVAR(groupsArray) select _selectedGroupIndex;
_selectedPerson setPos (getPos leader _selectedGroup);
_debugMsg = format ["PABST_ADMIN: %1 is teleporting %2 to group %3", (profileName), (name _selectedPerson), _selectedGroup];
["potato_adminMsg", [_debugMsg]] call ACEFUNC(common,globalEvent);