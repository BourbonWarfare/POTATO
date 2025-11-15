#include "script_component.hpp"

private _side = side group ACE_player;
private _key = format [QGVAR(briefing_coyIntent_%1), _side];
(missionNamespace getVariable [_key, ["", ""]]) params ["", "_currentText"];

private _display = createDialog [QGVAR(coy_intent), true];
private _ctrlBackground = _display ctrlCreate ["RscText", -1];
private _ctrlHeader = _display ctrlCreate ["RscText", -1];
private _ctrlTextInput = _display ctrlCreate ["RscEditMulti", 55001];
private _ctrlButtonOK = _display ctrlCreate ["RscButton", -1];

_ctrlBackground ctrlSetPosition [0, 0, 1, 1];
_ctrlBackground ctrlSetBackgroundColor [0, 0, 0, 0.7];
_ctrlBackground ctrlCommit 0;

_ctrlHeader ctrlSetPosition [0, 0, 0.9, 0.1];
_ctrlHeader ctrlSetText "Set Intent (SHIFT + Enter to add a new line)";
_ctrlHeader ctrlCommit 0;

_ctrlTextInput ctrlSetText _currentText;
_ctrlTextInput ctrlSetPosition [0, 0.1, 1, 0.9];
_ctrlTextInput ctrlCommit 0;

_ctrlButtonOK ctrlSetText "OK";
_ctrlButtonOK ctrlSetPosition [0.9, 0, 0.1, 0.1];
_ctrlButtonOK ctrlCommit 0;
_ctrlButtonOK ctrlAddEventHandler ["ButtonClick", {
    params ["_ctrlButtonOk"];
    private _display = ctrlParent _ctrlButtonOk;
    private _ctrlTextInput = _display displayCtrl 55001;

    private _newText = ctrlText _ctrlTextInput;

    private _side = side group ACE_player;
    private _key = format [QGVAR(briefing_coyIntent_%1), _side];
    (missionNamespace getVariable [_key, ["", ""]]) params ["", "_currentText"];

    TRACE_3("",_newText==_currentText,_newText,_currentText);
    if (_newText != _currentText) then {
        missionNamespace setVariable [_key, [profileName, _newText], true];
        [QGVAR(coyIntentChanged), _side] call CBA_fnc_globalEvent;
    };

    closeDialog 0;
}];
