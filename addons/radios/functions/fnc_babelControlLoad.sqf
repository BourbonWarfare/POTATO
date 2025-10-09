/*
 *
 */

#include "script_component.hpp"
TRACE_3("params",_this,get3DENSelected "object",get3DENSelected "group");

params ["_ctrlGroup"];

// get controls
private _ctrlSet = _ctrlGroup controlsGroupCtrl RADIO_SET_IDC;
private _ctrlBabel = _ctrlGroup controlsGroupCtrl BABEL_LIST_IDC;

// determine selected objects, prioritize groups
private _selectedGroups = get3DENSelected "group";
private _babelSelected = if (_selectedGroups isNotEqualTo []) then {
    _selectedGroups
} else {
    get3DENSelected "object"
};

// determine side of unit(s)/group(s) bail if there is a mix of sides
private _side = side (_babelSelected select 0);
private _babelInvalid = false;
{
    if (side _x != _side) exitWith { _babelInvalid = true };
} forEach _babelSelected;

_ctrlGroup setVariable [QGVAR(babelInvalid), _babelInvalid];
_ctrlGroup setVariable [QGVAR(setBabel), false];

// there's either nothing selected, or a mix of sides, bail out
if (_babelInvalid || {count _babelSelected < 0}) exitWith {
    [false, [_ctrlBabel, _ctrlSet]] call EFUNC(core,setControlFade);
};

private _selectedLanguages = switch (_side) do {
    case (west): { missionNamespace getVariable [QGVAR(westDefaultLanguages), [DEFAULT_WEST_LANGS]] };
    case (east): { missionNamespace getVariable [QGVAR(eastDefaultLanguages), [DEFAULT_EAST_LANGS]] };
    case (independent): { missionNamespace getVariable [QGVAR(indyDefaultLanguages), [DEFAULT_INDY_LANGS]] };
    default { missionNamespace getVariable [QGVAR(civDefaultLanguages), [DEFAULT_CIV_LANGS]] };
};

[_ctrlBabel] call FUNC(populateBabelList);
[_ctrlBabel, _selectedLanguages] call FUNC(setBabelList);

// register event handlers
_ctrlSet ctrlAddEventHandler ["ToolBoxSelChanged", {call FUNC(babelControlSetChange);}];
_ctrlSet lbSetCurSel 0;
[_ctrlSet, 0] call FUNC(babelControlSetChange);
