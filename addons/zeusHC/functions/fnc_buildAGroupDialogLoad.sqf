#include "script_component.hpp"

// setup faction dropdown, and populate possible unit list
{
  private _index = lbAdd [BUILD_GROUP_FACTIONS_IDC, getText (configfile >> "CfgFactionClasses" >> _x >> "displayName")];
  lbSetData [BUILD_GROUP_FACTIONS_IDC, _index, _x];
  lbSetPicture [BUILD_GROUP_FACTIONS_IDC, _index, getText (configfile >> "CfgFactionClasses" >> _x >> "icon")];
  nil
} count GVAR(groupFactionWhiteList);

private _factionIndex =  if (isNil QGVAR(lastGroupFactionIndex)) then { 0 } else { QGVAR(lastGroupFactionIndex) };
lbSetCurSel [BUILD_GROUP_FACTIONS_IDC, _factionIndex];
[_factionIndex] call FUNC(buildAGroupFactionChange);

// todo: check for last unit array, set to add lb with provided units
//GVAR(lastGroupUnitArray);
