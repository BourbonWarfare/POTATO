#include "script_component.hpp"
TRACE_1("Params",_this);

if (isNil QGVAR(spawnVicCache)) then {
    [] call FUNC(spawnACache);

    TRACE_1("Cache populated",GVAR(spawnVicCache));
};

waitUntil {dialog}; // wait until the dialog is fully loaded before we do any population

{
    private _side = switch (getNumber (configfile >> "CfgFactionClasses" >> _x >> "side")) do { case 0: {"OpFor"}; case 1: {"BluFor"}; case 2: {"Indy"}; case 3: {"Civ"}; };
    private _displayName = format ["%1, (%2)", getText (configfile >> "CfgFactionClasses" >> _x >> "displayName"), _side];
    private _index = lbAdd [SPAWN_VIC_FACTIONS_IDC, _displayName];
    lbSetData [SPAWN_VIC_FACTIONS_IDC, _index, _x];
    lbSetPicture [SPAWN_VIC_FACTIONS_IDC, _index, getText (configfile >> "CfgFactionClasses" >> _x >> "icon")];
    nil
} count (GVAR(spawnVicCache) select 0);

lbSetCurSel [SPAWN_VIC_FACTIONS_IDC, if (isNil QGVAR(lastVicFactionIndex)) then { 0 } else { GVAR(lastVicFactionIndex) }];

if (!isNil QGVAR(lastVicIndex)) then {
    lbSetCurSel [SPAWN_VIC_LIST_IDC, GVAR(lastVicIndex)];
};
