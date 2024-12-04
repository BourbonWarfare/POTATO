#include "script_component.hpp"
/*
 * Author: AACO, PabstMirror
 * Gets possible optic choices
 *
 * Arguments:
 * 0: Player <OBJECT>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [player] call potato_assignGear_fnc_changeableOptics_getChildren
 *
 * Public: Yes
 */

params ["_player"];
TRACE_1("getChangeableOpticsChildren",_player);

private _actions = [];

// ToDo: update _path for "potato_loadouts"
private _path = (
    missionConfigFile >>
    "CfgLoadouts" >>
    (faction _player) >>
    (player getVariable ["F_Gear", [typeOf player] call FUNC(cleanPrefix)])
);

private _possibleAttachments = [primaryWeapon _player] call CBA_fnc_compatibleItems; // in config-case
private _opticClassnames = [];
{
    private _xConfig = configFile >> "CfgWeapons" >> _x;
    private _xConfigName = configName _xConfig;
    if ((isNumber (_xConfig >> "ItemInfo" >> "optics"))
        && {GVAR(allowMagnifiedOptics) || {!([_xConfigName] call FUNC(isOpticMagnified))}}
        && {_xConfigName in _possibleAttachments}
    ) then {
        _opticClassnames pushBackUnique _xConfigName;
    };
} forEach ((getArray (_path >> "opticChoices")) + (getArray (_path >> "attachments")));
private _showAllOptics = GVAR(showAllOptics);
{
    if (_showAllOptics || _x != (primaryWeaponItems _player)#2) then {
        private _xConfig = configFile >> "CfgWeapons" >> _x;
        private _picture = QPATHTOF(data\scope.paa);
        if (isText (_xConfig >> "picture")) then { _picture = getText (_xConfig >> "picture"); };
        private _name = _x;
        if (isText (_xConfig >> "displayName")) then { _name = getText (_xConfig >> "displayName"); };
        private _action = [
            _x,
            _name,
            _picture,
            FUNC(changeableOptics_setOptic),
            {true},
            {},
            [_x, _opticClassnames]
        ] call ACEFUNC(interact_menu,createAction);

        _actions pushBack [_action, [], _player];
    };
} forEach _opticClassnames;

if (_opticClassnames isNotEqualTo [] &&
    {_showAllOptics || "" != (primaryWeaponItems _player)#2}) then {
    private _action = [
        "NoOptic",
        "None",
        "\a3\ui_f\data\gui\rsc\rscdisplayarcademap\icon_exit_cross_ca.paa",
        {_player removePrimaryWeaponItem ((primaryWeaponItems _player)#2)},
        {true},
        {}
    ] call ACEFUNC(interact_menu,createAction);
    _actions pushBack [_action, [], _player];
};

_actions
