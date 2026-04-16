#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function adds children to change active radio for a player using zeus
 * ACE interactions.
 *
 * Arguments:
 * passed by initializer
 *
 * Return Value:
 * Array of actions
 *
 * Examples:
 * [] call potato_zeusUtils_fnc_insertActiveRadioChildren;
 *
 * Public: No
 */
params ["_target"];

private _weapons = [ace_player] call acre_sys_core_fnc_getGear;
private _radioList = _weapons select {_x call acre_sys_radio_fnc_isUniqueRadio && {!(_x call acre_sys_external_fnc_isExternalRadioUsed)}};
if (ACRE_ACTIVE_RADIO != "") then {
    _radioList pushBackUnique ACRE_ACTIVE_RADIO;
};
_radioList append ACRE_ACCESSIBLE_RACK_RADIOS;
if (_radioList isEqualTo []) exitWith {[]};
private _actions = [];
private _cfgWeapons = configFile >> "CfgWeapons";
{
    if (_x isEqualTo ACRE_ACTIVE_RADIO) then {continue};
    private _action = [
        _x,
        getText (_cfgWeapons >> ([_x] call acre_api_fnc_getBaseRadio) >> "displayName"),
        "",
        {(_this#2) call acre_api_fnc_setCurrentRadio},
        {true},
        {},
        [_x]
    ] call ACEFUNC(interact_menu,createAction);
    _actions pushBack [_action, [], _target];
} forEach _radioList;
_actions
