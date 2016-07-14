#include "script_component.hpp"

disableSerialization;

params ["_control"];
TRACE_1("params",_control);

private _display = ctrlparent _control;
private _ctrlButtonOK = _display displayctrl 1; //IDC_OK
private _logicObject = missionNamespace getVariable ["BIS_fnc_initCuratorAttributes_target", objnull];
TRACE_1("logicObject",_logicObject);

_control ctrlRemoveAllEventHandlers "setFocus";



lbClear (_display displayCtrl 23071);
lbClear (_display displayCtrl 23072);
{
    private _sideText = if (_x isEqualType 0) then {
        ["Dead", "All Players"] select _x;
    } else {
        str _x;
    };
    (_display displayCtrl 23071) lbAdd _sideText;
} forEach MISSION_HINT_SIDES;
(_display displayCtrl 23071) lbSetCurSel 0;
{
    private _rankText = switch (_x) do {
    case (0): {"Private or higher"};
    case (1): {"Corporal or higher"};
    case (2): {"Sergeant or higher"};
    case (3): {"Lieutenant or higher"};
        default {"All Ranks"};
    };
    (_display displayCtrl 23072) lbAdd _rankText;
} forEach MISSION_HINT_RANKS;
(_display displayCtrl 23072) lbSetCurSel 0;



private _fnc_onUnload = {
    params [["_display", displayNull, [displayNull]]];
    TRACE_1("_fnc_onUnload params",_display);

    private _logicObject = missionnamespace getVariable ["BIS_fnc_initCuratorAttributes_target", objnull];
    if (isNull _logicObject) exitWith {};

    deleteVehicle _logicObject;
};

private _fnc_onConfirm = {
    params [["_ctrlButtonOK", controlNull, [controlNull]]];
    TRACE_1("_fnc_onConfirm params",_this);
    private _display = ctrlparent _ctrlButtonOK;
    if (isNull _display) exitWith {};

    private _logicObject = missionnamespace getvariable ["BIS_fnc_initCuratorAttributes_target", objnull];
    if (isNull _logicObject) exitWith {diag_log text format ["[POTATO] - ERROR Logic [%1] is null on confirm", _logicObject];};

    private _selectedIndexSide = lbCurSel (_display displayCtrl 23071);
    private _selectedRankIndex = lbCurSel (_display displayCtrl 23072);
    private _textInput = ctrlText (_display displayCtrl 23073);

    if ((_selectedIndexSide < 0) || (_selectedIndexSide >= (count MISSION_HINT_SIDES))) exitWith {};
    private _selectedSide = MISSION_HINT_SIDES select _selectedIndexSide;
    if ((_selectedRankIndex < 0) || (_selectedRankIndex >= (count MISSION_HINT_RANKS))) exitWith {};
    private _selectedRank = MISSION_HINT_RANKS select _selectedRankIndex;

    TRACE_3("sel",_selectedSide,_selectedRank,_textInput);

    //Debug trace to admin log:
    private _debugMsg = format ["Sending Hint to %1", _selectedSide];
    ["potato_adminMsg", [_debugMsg, profileName]] call CBA_fnc_globalEvent;

    //Actual misison hint event:
    private _debugMsg = format ["Sending Hint to %1", _selectedSide];
    ["potato_missionHint", [_textInput, _selectedSide, _selectedRank]] call CBA_fnc_globalEvent;

};

_display displayaddeventhandler ["unload", _fnc_onUnload];
_ctrlButtonOK ctrladdeventhandler ["buttonclick", _fnc_onConfirm];
