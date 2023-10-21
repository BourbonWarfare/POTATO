#include "script_component.hpp"
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

TRACE_1("updateInfo",_this);

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

        private _wounds = _unit getVariable [QACEGVAR(medical,openWounds), []];

        if (_wounds isEqualType []) then {
            {
                _x params ["", "_selectionIndex", "_amountOf", "_x4"];
                // Find how much this bodypart is bleeding
                if (_amountOf > 0) then {
                    private _bodySelection = _bodyInfo select _selectionIndex;
                    _bodySelection set [0, true];
                    _bodySelection set [1, (_bodySelection select 1) + (20 * _x4 * _amountOf)];
                };
            } forEach _wounds;
        } else {
            // hashmaps for ace 3.16.0
            {
                private _selectionIndex = ["head", "body", "leftarm", "rightarm", "leftleg", "rightleg"] find _x;
                private _woundsOnPart = _y;
                {
                    _x params ["", "_amountOf", "_x4"];
                    // Find how much this bodypart is bleeding
                    if (_amountOf > 0) then {
                        private _bodySelection = _bodyInfo select _selectionIndex;
                        _bodySelection set [0, true];
                        _bodySelection set [1, (_bodySelection select 1) + (20 * _x4 * _amountOf)];
                    };
                } forEach _woundsOnPart;
            } forEach _wounds;
        };

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

        private _bloodVol = _unit getVariable [QACEGVAR(medical,bloodVolume), 6];
        private _pain = _unit getVariable [QACEGVAR(medical,pain), 0];
        private _painSuppress = _unit getVariable [QACEGVAR(medical,painSuppress), 0];
        private _heartRate = _unit getVariable [QACEGVAR(medical,heartRate), -1];
        private _watches = {_x == "ItemWatch"} count items _unit; // note: Doesn't count the one you wear
        FOCUS_MEDICAL_RATIO_BLOOD progressSetPosition linearConversion [0,6,_bloodVol,0,1,true];
        FOCUS_MEDICAL_RATIO_PAIN progressSetPosition linearConversion [0,1,_pain,0,1,true];
        FOCUS_MEDICAL_RATIO_PAINSUPPRESS progressSetPosition linearConversion [0,1,_painSuppress,0,1,true];
        FOCUS_MEDICAL_INFO_HR ctrlSetText (if (_heartRate == -1) then { "" } else { str floor _heartRate });
        FOCUS_MEDICAL_INFO_WATCHES ctrlSetText str _watches;

    } else {
        FOCUS_VEHICLE ctrlSetText (getText (configOf (vehicle _unit) >> "Picture"));
        FOCUS_VEHICLE ctrlShow true;

        FOCUS_UNIT ctrlSetText "";
        FOCUS_UNIT ctrlShow false;

        FOCUS_MEDICAL_GC ctrlShow false;
    };
} else {
    FOCUS_GROUP ctrlShow false;
};
