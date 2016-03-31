#include "script_component.hpp"
TRACE_1("Params",_this);

waitUntil {dialog};

if (isNil QGVAR(spawnVicCache)) then {
    GVAR(spawnVicCache) = [[], []];

    private _configFilter = {
        private _filter = [];
        {
            _filter pushBack format ["(configName _x) isKindOf '%1'", _x];
            nil
        } count _this;

        format ["(%1) && getNumber (_x >> 'scope') > 1", _filter joinString " || "];
    };

    private _relivantUnits = (["Air","Car","Tank","Wheeled_APC","Wheeled_APC_F"] call _configFilter) configClasses (configFile >> "CfgVehicles");
    [_relivantUnits] call FUNC(spawnACache);

    TRACE_1("Cache populated",GVAR(spawnVicCache));
};

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
