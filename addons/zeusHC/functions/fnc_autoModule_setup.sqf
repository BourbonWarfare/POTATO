#include "script_component.hpp"
/*
 * Author: PabstMirror
 * Called when opening zeus interface ("zen_curatorDisplayLoaded" Event)
 * Adds existing vehicles to the placeable modules list
 *
 * Examples:
 * [] call potato_zeusHC_fnc_autoModule_setup
 */

TRACE_1("autoModule_setup",_this);
if (isNil "zen_custom_modules_fnc_register") exitWith { ERROR("zen_custom_modules_fnc_register undefined"); };
if (isNil QGVAR(vehicleList)) then { GVAR(vehicleList) = []; };

{
    if ((count GVAR(vehicleList)) > 50) exitWith {};
    private _veh = _x;
    if ((alive _veh) && {(["Car", "Tank", "Air", "Ship"] findIf {_veh isKindOf _x}) != -1}) then {
        if ((getNumber (configOf _veh >> "scope")) != 2) exitWith {};
        private _type = typeOf _veh;

        // Determine side by crew or nearest mans
        private _nearMan = (crew _veh) param [0, objNull];
        if (!alive _nearMan) then { _nearMan = nearestObject [_veh, "CaManBase"]; };
        private _side = side group _nearMan;

        private _index = GVAR(vehicleList) pushBackUnique [_type, _side];
        if (_index == -1) exitWith {}; // ignore duplicates

        private _category = "";
        switch (_side) do {
            case west: { 
                _side = "west";
                _category = getText (configFile >> "CfgFactionClasses" >> QGVAR(west) >> "displayName");
            };
            case east: { 
                _side = "east";
                _category =getText (configFile >> "CfgFactionClasses" >> QGVAR(east) >> "displayName"); 
            };
            case resistance: {
                _side = "resistance";
                _category = getText (configFile >> "CfgFactionClasses" >> QGVAR(ind) >> "displayName"); 
            };
        };
        if (_category == "") exitWith {};

        private _displayName = format [">>> %1", getText (configOf _veh >> "displayName")];
        private _code = compile format [QUOTE([ARR_3(_this select 0, '%1', %2)] call DFUNC(autoModule_module)), _type, _side];
        private _icon = getText (configOf _veh >> "icon");
        private _ret = [_category, _displayName, _code, _icon] call zen_custom_modules_fnc_register;
        TRACE_3("added custom",_type,_side,_ret);
    };
} forEach vehicles;
INFO_1("autoModule - Total %1", count GVAR(vehicleList));
