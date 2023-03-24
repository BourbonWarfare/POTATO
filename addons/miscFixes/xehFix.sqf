// Fix CBA XEH Fallback Code for misc logic/objects that don't support it:
diag_log text format ["--- Dumping XEH ---"];

private _reqAddons = [];
private _defined = [];

private _problems = [true] call CBA_fnc_supportMonitor;
{
    _x params ["_vehType", "_addon"];
    private _parent = configName inheritsFrom (configFile >> "CfgVehicles" >> _vehType);
    if (!(_parent in _defined)) then {
        diag_log text format ["class %1;", _parent];
        _defined pushBack _parent;
    };
    private _displayName = getText (configFile >> "CfgVehicles" >> _vehType >> "displayName");
    private _sourceAddons = configSourceAddonList (configFile >> "CfgVehicles" >> _vehType);
    _reqAddons append _sourceAddons;
    diag_log text format ["class %1: %2 { XEH_ENABLED; }; // ""%3"" %4", _vehType, _parent, _displayName, _addon];
} forEach _problems;

diag_log text format ["_reqAddons %1", _reqAddons arrayIntersect _reqAddons];
