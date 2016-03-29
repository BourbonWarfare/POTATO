#include "script_component.hpp"

params [["_index", lbCurSel BUILD_GROUP_FACTIONS_IDC]];
TRACE_1("params",_index);

// clear both list boxes
lbClear BUILD_GROUP_UNITS_IDC;
lbClear BUILD_GROUP_TO_ADD_IDC;

TRACE_1("Cache",GVAR(buildFactionCache));

if (isNil QGVAR(buildFactionCache)) then {
    GVAR(buildFactionCache) = [[], []];
    private _relivantUnits = "(configName _x) isKindOf 'Man' && getNumber (_x >> 'scope') > 1" configClasses (configFile >> "CfgVehicles");
    [_relivantUnits] call FUNC(buildACache);
    TRACE_1("Cache populated",GVAR(buildFactionCache));
};


private _factionIndex = (GVAR(buildFactionCache) select 0) find (lbData [BUILD_GROUP_FACTIONS_IDC, _index]);
if (_factionIndex > -1) then {
    private _unitArray = (GVAR(buildFactionCache) select 1) select _factionIndex;
    TRACE_1("Unit Array",_unitArray);
    {
        _x params ["_classname", "_displayName", "_icon"];
        private _unitIndex = lbAdd [BUILD_GROUP_UNITS_IDC, _displayName];
        lbSetPicture [BUILD_GROUP_UNITS_IDC, _unitIndex, getText(configfile >> "CfgVehicleIcons" >> _icon)];
        lbSetData [BUILD_GROUP_UNITS_IDC, _unitIndex, _classname];
        nil
    } count _unitArray;
};
