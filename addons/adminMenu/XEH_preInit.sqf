#include "script_component.hpp"

ADDON = false;

PREP(checkMods);
PREP(checkModsWriteDiary);
PREP(endMission);
PREP(openAdminMenu);

PREP(uihook_checkMods);
PREP(uihook_endMission);
PREP(uihook_openEndMission);
PREP(uihook_safeStart);
PREP(uihook_tabChange);


DFUNC(uihook_teleportButton) = {
    _selectedPersonIndex = lbCurSel UI_TAB_TELEPORT_PERSON;
    if ((_selectedPersonIndex < 0) || (_selectedPersonIndex >= (count PABST_ADMIN_ui_teleportPersons))) exitWith {};
    _selectedPerson = PABST_ADMIN_ui_teleportPersons select _selectedPersonIndex;
    _selectedGroupIndex = lbCurSel UI_TAB_TELEPORT_GROUP;
    if ((_selectedGroupIndex < 0) || (_selectedGroupIndex >= (count GVAR(groupsArray)))) exitWith {};
    _selectedGroup = GVAR(groupsArray) select _selectedGroupIndex;
    _selectedPerson setPos (getPos leader _selectedGroup);
    _debugMsg = format ["PABST_ADMIN: %1 is teleporting %2 to group %3", (profileName), (name _selectedPerson), _selectedGroup];
    ["potato_adminMsg", [_debugMsg]] call ACEFUNC(common,globalEvent);
};
DFUNC(uihook_supplySpawn) = {
    _selectedIndexClass = lbCurSel UI_TAB_SUPPLIES_TYPE;
    if ((_selectedIndexClass < 0) || (_selectedIndexClass >= (count PABST_ADMIN_ui_supplyClassNames))) exitWith {};
    _selectedClass = PABST_ADMIN_ui_supplyClassNames select _selectedIndexClass;
    _selectedGroupIndex = lbCurSel UI_TAB_SUPPLIES_GROUP;
    if ((_selectedGroupIndex < 0) || (_selectedGroupIndex >= (count GVAR(groupsArray)))) exitWith {};
    _selectedGroup = GVAR(groupsArray) select _selectedGroupIndex;
    _spawnedSupport = createVehicle [_selectedClass,(getPos leader _selectedGroup), [], 0, "NONE"];
    _debugMsg = format ["PABST_ADMIN: %1 is supply dropping %2", (profileName), _selectedClass];
    ["potato_adminMsg", [_debugMsg]] call ACEFUNC(common,globalEvent);
};

PREP(uihook_weaponTest);
PREP(uihook_zeusConnectPlayer);
PREP(zeusConnectCurator);

ADDON = true;
