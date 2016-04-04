#include "script_component.hpp"
TRACE_1("Params",_this);

if (isNil QGVAR(garrisonCache)) then {
    [] call FUNC(garrisonCache);
};

waitUntil {dialog}; // wait until the dialog is fully loaded before we do any population

// setup faction dropdown, and populate possible unit list
{
    private _index = lbAdd [GARRISON_FACTIONS_IDC, getText (configfile >> "CfgFactionClasses" >> _x >> "displayName")];
    lbSetData [GARRISON_FACTIONS_IDC, _index, _x];
    lbSetPicture [GARRISON_FACTIONS_IDC, _index, getText (configfile >> "CfgFactionClasses" >> _x >> "icon")];

    nil
} count (GVAR(garrisonCache) select 0);

lbSetCurSel [GARRISON_FACTIONS_IDC, if (isNil QGVAR(lastGarrisonFactionIndex)) then { 0 } else { GVAR(lastGarrisonFactionIndex) }];
