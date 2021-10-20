/*
 * Author: AACO
 * Function used to update the info widget
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [] call potato_spectate_fnc_updateInfo;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

if (GVAR(uiVisible) && GVAR(showInfo)) then {
    if (isNull GVAR(camTarget)) then {
        [player getVariable [QGVAR(oldUnit), player], acex_killTracker_outputText]
    } else {
        [GVAR(camTarget), GVAR(camTarget) getVariable [QACEGVAR(killtracker,output), "None"]]
    } params ["_unit", "_killFeed"];
    TRACE_1("Kill Feed", _killFeed);

    if !(ctrlShown FOCUS_GROUP) then {
        FOCUS_GROUP ctrlShow true;
    };

    FOCUS_NAME ctrlSetText ([_unit] call FUNC(getName));
    FOCUS_KILL ctrlSetStructuredText parseText format ["%1%2%3", "<t size='0.75'>", _killFeed, "</t>"];
    private _killPos = ctrlPosition FOCUS_KILL;
    _killPos set [3, ctrlTextHeight FOCUS_KILL];
    FOCUS_KILL ctrlSetPosition _killPos;
    FOCUS_KILL ctrlCommit 0;

    if (vehicle _unit == _unit) then {
        FOCUS_UNIT ctrlSetText ([_unit] call ACEFUNC(common,getVehicleIcon));
        FOCUS_UNIT ctrlShow true;

        FOCUS_VEHICLE ctrlSetText "";
        FOCUS_VEHICLE ctrlShow false;

        FOCUS_MEDICAL_GC ctrlShow true;

        private _bodyInfo = [
            [false, 0, FOCUS_MEDICAL_HEAD_IDC],
            [false, 0, FOCUS_MEDICAL_TORSO_IDC],
            [false, 0, FOCUS_MEDICAL_LEFT_ARM_IDC],
            [false, 0, FOCUS_MEDICAL_RIGHT_ARM_IDC],
            [false, 0, FOCUS_MEDICAL_LEFT_LEG_IDC],
            [false, 0, FOCUS_MEDICAL_RIGHT_LEG_IDC]
        ];

        {
            _x params ["", "_selectionIndex", "_amountOf", "_x4"];
            // Find how much this bodypart is bleeding
            if (_amountOf > 0) then {
                private _bodySelection = _bodyInfo select _selectionIndex;
                _bodySelection set [0, true];
                _bodySelection set [1, (_bodySelection select 1) + (20 * _x4 * _amountOf)];
            };
            nil
        } count (_unit getVariable [QACEGVAR(medical,openWounds), []]); // count used here for speed, ensure nil above this line

        {
            _x params ["_damaged", "_bloodLoss", "_idc"];

            if (_bloodLoss > 0) then {
                if (_damaged) then {
                    private _greenAndBlue = (0.9 - _bloodLoss) max 0;
                    (OVERLAY displayCtrl _idc) ctrlSetTextColor [1, _greenAndBlue, _greenAndBlue, 1];
                } else {
                    private _redAndGreen = (0.9 - _bloodLoss) max 0;
                    (OVERLAY displayCtrl _idc) ctrlSetTextColor [_redAndGreen, _redAndGreen, 1, 1];
                };
            } else {
                (OVERLAY displayCtrl _idc) ctrlSetTextColor [1, 1, 1, 1];
            };
            nil
        } count _bodyInfo; // count used here for speed, ensure nil above this line
    } else {
        FOCUS_VEHICLE ctrlSetText (getText (configFile >> "CfgVehicles" >> typeOf (vehicle _unit) >> "Picture"));
        FOCUS_VEHICLE ctrlShow true;

        FOCUS_UNIT ctrlSetText "";
        FOCUS_UNIT ctrlShow false;

        FOCUS_MEDICAL_GC ctrlShow false;
    };
} else {
    FOCUS_GROUP ctrlShow false;
};
