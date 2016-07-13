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
private _selectedObjects = get3DENSelected "object";
private _selectedGroups = get3DENSelected "group";
GVAR(babelSelected) = if (count _selectedGroups > 0) then {
    _selectedGroups;
} else {
    _selectedObjects
};

// determine side of unit(s)/group(s) bail if there is a mix of sides
private _side = side (GVAR(babelSelected) select 0);
GVAR(babelInvalid) = false;
{
    if (side _x != _side) exitWith { GVAR(babelInvalid) = true };
} forEach GVAR(babelSelected);

GVAR(setBabel) = false;

// there's either nothing selected, or a mix of sides, bail out
if (GVAR(babelInvalid) || {count GVAR(babelSelected) < 0}) exitWith {
    _ctrlBabel ctrlEnable false;
    _ctrlSet ctrlEnable false;

    _ctrlBabel ctrlSetFade FADE_DISABLED;
    _ctrlSet ctrlSetFade FADE_DISABLED;

    _ctrlBabel ctrlCommit FADE_LENGTH;
    _ctrlSet ctrlCommit FADE_LENGTH;
};

GVAR(selectedLanguages) = switch (_side) do {
    case (west): { GVAR(westDefaultLanguages) };
    case (east): { GVAR(eastDefaultLanguages) };
    case (independent): { GVAR(indyDefaultLanguages) };
    default { GVAR(civDefaultLanguages) };
};

[_ctrlBabel] call FUNC(populateBabelList);
[_ctrlBabel] call FUNC(setBabelList);

// register event handlers
_ctrlSet ctrlAddeventHandler ["toolboxselchanged",{_this call FUNC(babelControlSetChange);}];
_ctrlSet lbSetCurSel 0;
[_ctrlSet,0] call FUNC(babelControlSetChange);

_ctrlBabel ctrlAddEventHandler ["lbselchanged",{_this spawn FUNC(babelControlBabelChange);}];
