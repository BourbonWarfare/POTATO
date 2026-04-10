#include "..\..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This fucntion handles sliders in the mission menu changing.
*
* Arguments:
* BIS onSliderPosChanged EH arguments
*
* Only called via callback
*//***************************************************************************/
params ["_control", "_newValue"];
private _controlIDC = ctrlIDC _control;
switch (_controlIDC) do {
    case IDC_MISSION_AISKILLMIN: {
        private _aiSkillMax = GVAR(menuOptions) getOrDefault ["AIskillMax", _newValue];
        _newValue = _newValue min _aiSkillMax;
        GVAR(menuOptions) set ["AIskillMin", _newValue];
    };
    case IDC_MISSION_AISKILLMAX: {
        private _aiSkillMin = GVAR(menuOptions) getOrDefault ["AIskillMin", _newValue];
        _newValue = _newValue max _aiSkillMin;
        GVAR(menuOptions) set ["AIskillMax", _newValue];
    };
    case IDC_MISSION_OPTION0: {
        private _control = (ctrlParent _control) displayCtrl IDC_MISSION_OPTION0_TEXT;
        if (GET_MENU_OPTION(operationType) == BW_TRAINING_OPERATION_DEFEND) then {
            _control ctrlSetText format ["Max Spawn Radius: %1m", round _newValue];
            GVAR(missionFirstPositionMarker) setMarkerSizeLocal [_newValue, _newValue];
        } else {
            _control ctrlSetText format ["Min Units Per Building: %1", round (6 * _newValue)];
        };
        GVAR(menuOptions) set ["option0", _newValue];
    };
    case IDC_MISSION_OPTION1: {
        private _control = (ctrlParent _control) displayCtrl IDC_MISSION_OPTION1_TEXT;
        if (GET_MENU_OPTION(operationType) == BW_TRAINING_OPERATION_DEFEND) then {
            _newValue = round _newValue;
            _control ctrlSetText format ["Units per Player: %1", _newValue];
        } else {
            _control ctrlSetText format ["Max Units: %1", round (BW_AI_MAX_SPAWN * _newValue)];
        };
        GVAR(menuOptions) set ["option1", _newValue];
    };
    case IDC_MISSION_OPTION2: {
        private _control = (ctrlParent _control) displayCtrl IDC_MISSION_OPTION2_TEXT;
        if (GET_MENU_OPTION(operationType) == BW_TRAINING_OPERATION_DEFEND) then {
            _newValue = round _newValue;
            _control ctrlSetText format ["Defense Length: %1s", _newValue];
        } else {
            _control ctrlSetText "Chance to de-Garrison";
        };
        GVAR(menuOptions) set ["option2", _newValue];
    };
    case IDC_MISSION_OPTION3: {
        if (GET_MENU_OPTION(operationType) == BW_TRAINING_OPERATION_DEFEND) then {
            private _textControl = (ctrlParent _control) displayCtrl IDC_MISSION_OPTION3_TEXT;
            private _secondAngle = GET_MENU_OPTION(option4);
            if (_newValue > _secondAngle) then {
                _newValue = _secondAngle;
                _control sliderSetPosition _newValue;
            };
            _textControl ctrlSetText format ["Approach Arc 1: %1", round _newValue];
        };
        GVAR(menuOptions) set ["option3", _newValue];
    };
    case IDC_MISSION_OPTION4: {
        if (GET_MENU_OPTION(operationType) == BW_TRAINING_OPERATION_DEFEND) then {
            private _textControl = (ctrlParent _control) displayCtrl IDC_MISSION_OPTION4_TEXT;
            private _firstAngle = GET_MENU_OPTION(option3);
            if (_newValue < _firstAngle) then {
                _newValue = _firstAngle;
                _control sliderSetPosition _newValue;
            };
            _textControl ctrlSetText format ["Approach Arc 2: %1", round _newValue];
        };
        GVAR(menuOptions) set ["option4", _newValue];
    };
    case IDC_MISSION_OPTION5: {
        GVAR(menuOptions) set ["option5", _newValue];
    };
    case IDC_MISSION_OPTION6: {
        GVAR(menuOptions) set ["option6", _newValue];
    };
    default {
        diag_log formatText ["[SEED][Mission] SLIDER ERROR: Invalid control IDC: %1", _controlIDC];
    };
};
