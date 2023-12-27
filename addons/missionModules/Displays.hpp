#define GUI_GRID_X -0.1
#define GUI_GRID_Y -0.1
#define GUI_GRID_W 0.025
#define GUI_GRID_H 0.04
#define GUI_GRID_WAbs 1.2
#define GUI_GRID_HAbs 1.2

class IGUIBack;
class RscButtonMenuCancel;
class RscButtonMenuOK;
class RscCheckBox;
class RscControlsGroup;
class RscControlsGroupNoScrollbars;
class RscEdit;
class RscFrame;
class RscListBox;
class RscText;
class RscXSliderH;

class RscDisplayAttributes {
    class Controls {
        class Background;
        class Title;
        class Content;
        class ButtonOK;
        class ButtonCancel;
    };
};
class GVAR(RscDisplayAttributes_missionHint): RscDisplayAttributes {
    onLoad = QUOTE([ARR_3('onLoad',_this,QUOTE(QGVAR(RscDisplayAttributes_missionHint)))] call FUNC(zeusAttributes));
    onUnload = QUOTE([ARR_3('onUnload',_this,QUOTE(QGVAR(RscDisplayAttributes_missionHint)))] call FUNC(zeusAttributes));
    class Controls: Controls {
        class Background: Background {};
        class Title: Title {};
        class Content: Content {
            class Controls {
                class missionHintAttributes: RscControlsGroupNoScrollbars {
                    onSetFocus = QUOTE(_this call FUNC(zeusAttributes_missionHint));
                    idc = 26422;
                    x = "0";
                    y = "0";
                    w = "26 * (((safezoneW / safezoneH) min 1.2) / 40)";
                    h = "9 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                    class controls {
                        class RscCombo_side: RscListBox {
                            idc = 23071;
                            x = "0.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            y = "0 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                            w = "12 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            h = "7 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                        };
                        class RscCombo_rank: RscListBox {
                            idc = 23072;
                            x = "13.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            y = "0 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                            w = "12 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            h = "7 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                        };
                        class RscEdit_textInput: RscEdit {
                            idc = 23073;
                            x = "0.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            y = "7.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                            w = "26 * (((safezoneW / safezoneH) min 1.2) / 40)";
                            h = "1.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                        };
                    };
                };
            };
        };
        class ButtonOK: ButtonOK {};
        class ButtonCancel: ButtonCancel {};
    };
};
class GVAR(setSkills) {
    idd = SET_SKILLS_IDD;
    movingEnable = 0;
    onLoad = QUOTE([] spawn FUNC(setSkillsDialogLoad));
    class controls {
        class GVAR(setSkills_bg): IGUIBack {
            x = QUOTE(0 * GUI_GRID_W + GUI_GRID_X);
            y = QUOTE(0 * GUI_GRID_H + GUI_GRID_Y);
            w = QUOTE(48 * GUI_GRID_W);
            h = QUOTE(30 * GUI_GRID_H);
        };
        class GVAR(setSkills_frame): RscFrame {
            x = QUOTE(0.5 * GUI_GRID_W + GUI_GRID_X);
            y = QUOTE(0.5 * GUI_GRID_H + GUI_GRID_Y);
            w = QUOTE(47 * GUI_GRID_W);
            h = QUOTE(29 * GUI_GRID_H);
            colorBackground[] = {0,0,0,0.8};
            sizeEx = QUOTE(1 * GUI_GRID_H);
            text = "Set AI Skills and Behaviors";
        };
        class GVAR(setSkills_settingsContainer): RscControlsGroup {
            x = QUOTE(2 * GUI_GRID_W + GUI_GRID_X);
            y = QUOTE(1.5 * GUI_GRID_H + GUI_GRID_Y);
            w = QUOTE(45.5 * GUI_GRID_W);
            h = QUOTE(26 * GUI_GRID_H);
            class controls {
                class GVAR(setSkills_master_txt): RscText {
                    x = QUOTE(2 * GUI_GRID_W + GUI_GRID_X);
                    y = QUOTE(3 * GUI_GRID_H + GUI_GRID_Y);
                    w = QUOTE(20 * GUI_GRID_W);
                    h = QUOTE(1 * GUI_GRID_H);
                    text = "Master Enable";
                    tooltip = "Enable/disable setting AI skills/behaviors on unit creation";
                    style = 1; // Right
                };
                class GVAR(setSkills_master_bx): RscCheckBox {
                    idc = SET_SKILLS_MASTER_BX_IDC;
                    x = QUOTE(22 * GUI_GRID_W + GUI_GRID_X);
                    y = QUOTE(3 * GUI_GRID_H + GUI_GRID_Y);
                    w = QUOTE(1.25 * GUI_GRID_W);
                    h = QUOTE(1 * GUI_GRID_H);
                    tooltip = "Enable/disable setting AI skills/behaviors on unit creation";
                    style = 0; // Left
                };
                class GVAR(setSkills_aimingAccuracy_min_txt): GVAR(setSkills_master_txt) {
                    y = QUOTE(4.5 * GUI_GRID_H + GUI_GRID_Y);
                    text = "Aiming Accuracy Floor";
                    tooltip = "Minimum aiming accuracy for a spawned unit";
                };
                class GVAR(setSkills_aimingAccuracy_min_slider): RscXSliderH {
                    idc = SET_SKILLS_AIM_ACC_MIN_SLIDER_IDC;
                    x = QUOTE(22 * GUI_GRID_W + GUI_GRID_X);
                    y = QUOTE(4.5 * GUI_GRID_H + GUI_GRID_Y);
                    w = QUOTE(24.5 * GUI_GRID_W);
                    h = QUOTE(1 * GUI_GRID_H);
                    colorText[] = {1,1,1,1};
                    sizeEx = QUOTE(1 * GUI_GRID_H);
                    onSliderPosChanged = QUOTE([ARR_3(_this select 1,'aimingAccuracy',false)] call FUNC(setSkillsDialogSliderChange));
                };
                class GVAR(setSkills_aimingAccuracy_max_txt): GVAR(setSkills_master_txt) {
                    y = QUOTE(6 * GUI_GRID_H + GUI_GRID_Y);
                    text = "Aiming Accuracy Ceiling";
                    tooltip = "Maximum aiming accuracy for a spawned unit";
                };
                class GVAR(setSkills_aimingAccuracy_max_slider): GVAR(setSkills_aimingAccuracy_min_slider) {
                    idc = SET_SKILLS_AIM_ACC_MAX_SLIDER_IDC;
                    y = QUOTE(6 * GUI_GRID_H + GUI_GRID_Y);
                    onSliderPosChanged = QUOTE([ARR_3(_this select 1,'aimingAccuracy',true)] call FUNC(setSkillsDialogSliderChange));
                };
                class GVAR(setSkills_aimingShake_min_txt): GVAR(setSkills_master_txt) {
                    y = QUOTE(7.5 * GUI_GRID_H + GUI_GRID_Y);
                    text = "Aiming Shake Floor";
                    tooltip = "Minimum aiming shake for a spawned unit";
                };
                class GVAR(setSkills_aimingShake_min_slider): GVAR(setSkills_aimingAccuracy_min_slider) {
                    idc = SET_SKILLS_AIM_SHK_MIN_SLIDER_IDC;
                    y = QUOTE(7.5 * GUI_GRID_H + GUI_GRID_Y);
                    onSliderPosChanged = QUOTE([ARR_3(_this select 1,'aimingShake',false)] call FUNC(setSkillsDialogSliderChange));
                };
                class GVAR(setSkills_aimingShake_max_txt): GVAR(setSkills_master_txt) {
                    y = QUOTE(9 * GUI_GRID_H + GUI_GRID_Y);
                    text = "Aiming Shake Ceiling";
                    tooltip = "Maximum aiming shake for a spawned unit";
                };
                class GVAR(setSkills_aimingShake_max_slider): GVAR(setSkills_aimingAccuracy_min_slider) {
                    idc = SET_SKILLS_AIM_SHK_MAX_SLIDER_IDC;
                    y = QUOTE(9 * GUI_GRID_H + GUI_GRID_Y);
                    onSliderPosChanged = QUOTE([ARR_3(_this select 1,'aimingShake',true)] call FUNC(setSkillsDialogSliderChange));
                };
                class GVAR(setSkills_aimingSpeed_min_txt): GVAR(setSkills_master_txt) {
                    y = QUOTE(10.5 * GUI_GRID_H + GUI_GRID_Y);
                    text = "Aiming Speed Floor";
                    tooltip = "Minimum aiming speed for a spawned unit";
                };
                class GVAR(setSkills_aimingSpeed_min_slider): GVAR(setSkills_aimingAccuracy_min_slider) {
                    idc = SET_SKILLS_AIM_SPD_MIN_SLIDER_IDC;
                    y = QUOTE(10.5 * GUI_GRID_H + GUI_GRID_Y);
                    onSliderPosChanged = QUOTE([ARR_3(_this select 1,'aimingSpeed',false)] call FUNC(setSkillsDialogSliderChange));
                };
                class GVAR(setSkills_aimingSpeed_max_txt): GVAR(setSkills_master_txt) {
                    y = QUOTE(12 * GUI_GRID_H + GUI_GRID_Y);
                    text = "Aiming Speed Ceiling";
                    tooltip = "Maximum aiming speed for a spawned unit";
                };
                class GVAR(setSkills_aimingSpeed_max_slider): GVAR(setSkills_aimingAccuracy_min_slider) {
                    idc = SET_SKILLS_AIM_SPD_MAX_SLIDER_IDC;
                    y = QUOTE(12 * GUI_GRID_H + GUI_GRID_Y);
                    onSliderPosChanged = QUOTE([ARR_3(_this select 1,'aimingSpeed',true)] call FUNC(setSkillsDialogSliderChange));
                };
                class GVAR(setSkills_commanding_min_txt): GVAR(setSkills_master_txt) {
                    y = QUOTE(13.5 * GUI_GRID_H + GUI_GRID_Y);
                    text = "Commanding Floor";
                    tooltip = "Minimum commanding for a spawned unit";
                };
                class GVAR(setSkills_commanding_min_slider): GVAR(setSkills_aimingAccuracy_min_slider) {
                    idc = SET_SKILLS_CMDING_MIN_SLIDER_IDC;
                    y = QUOTE(13.5 * GUI_GRID_H + GUI_GRID_Y);
                    onSliderPosChanged = QUOTE([ARR_3(_this select 1,'commanding',false)] call FUNC(setSkillsDialogSliderChange));
                };
                class GVAR(setSkills_commanding_max_txt): GVAR(setSkills_master_txt) {
                    y = QUOTE(15 * GUI_GRID_H + GUI_GRID_Y);
                    text = "Commanding Ceiling";
                    tooltip = "Maximum commanding for a spawned unit";
                };
                class GVAR(setSkills_commanding_max_slider): GVAR(setSkills_aimingAccuracy_min_slider) {
                    idc = SET_SKILLS_CMDING_MAX_SLIDER_IDC;
                    y = QUOTE(15 * GUI_GRID_H + GUI_GRID_Y);
                    onSliderPosChanged = QUOTE([ARR_3(_this select 1,'commanding',true)] call FUNC(setSkillsDialogSliderChange));
                };
                class GVAR(setSkills_courage_min_txt): GVAR(setSkills_master_txt) {
                    y = QUOTE(16.5 * GUI_GRID_H + GUI_GRID_Y);
                    text = "Courage Floor";
                    tooltip = "Minimum courage for a spawned unit";
                };
                class GVAR(setSkills_courage_min_slider): GVAR(setSkills_aimingAccuracy_min_slider) {
                    idc = SET_SKILLS_CRG_MIN_SLIDER_IDC;
                    y = QUOTE(16.5 * GUI_GRID_H + GUI_GRID_Y);
                    onSliderPosChanged = QUOTE([ARR_3(_this select 1,'courage',false)] call FUNC(setSkillsDialogSliderChange));
                };
                class GVAR(setSkills_courage_max_txt): GVAR(setSkills_master_txt) {
                    y = QUOTE(18 * GUI_GRID_H + GUI_GRID_Y);
                    text = "Courage Ceiling";
                    tooltip = "Maximum courage for a spawned unit";
                };
                class GVAR(setSkills_courage_max_slider): GVAR(setSkills_aimingAccuracy_min_slider) {
                    idc = SET_SKILLS_CRG_MAX_SLIDER_IDC;
                    y = QUOTE(18 * GUI_GRID_H + GUI_GRID_Y);
                    onSliderPosChanged = QUOTE([ARR_3(_this select 1,'courage',true)] call FUNC(setSkillsDialogSliderChange));
                };
                class GVAR(setSkills_general_min_txt): GVAR(setSkills_master_txt) {
                    y = QUOTE(19.5 * GUI_GRID_H + GUI_GRID_Y);
                    text = "General Floor";
                    tooltip = "Minimum general for a spawned unit";
                };
                class GVAR(setSkills_general_min_slider): GVAR(setSkills_aimingAccuracy_min_slider) {
                    idc = SET_SKILLS_GNRL_MIN_SLIDER_IDC;
                    y = QUOTE(19.5 * GUI_GRID_H + GUI_GRID_Y);
                    onSliderPosChanged = QUOTE([ARR_3(_this select 1,'general',false)] call FUNC(setSkillsDialogSliderChange));
                };
                class GVAR(setSkills_general_max_txt): GVAR(setSkills_master_txt) {
                    y = QUOTE(21 * GUI_GRID_H + GUI_GRID_Y);
                    text = "General Ceiling";
                    tooltip = "Maximum general for a spawned unit";
                };
                class GVAR(setSkills_general_max_slider): GVAR(setSkills_aimingAccuracy_min_slider) {
                    idc = SET_SKILLS_GNRL_MAX_SLIDER_IDC;
                    y = QUOTE(21 * GUI_GRID_H + GUI_GRID_Y);
                    onSliderPosChanged = QUOTE([ARR_3(_this select 1,'general',true)] call FUNC(setSkillsDialogSliderChange));
                };
                class GVAR(setSkills_reloadSpeed_min_txt): GVAR(setSkills_master_txt) {
                    y = QUOTE(22.5 * GUI_GRID_H + GUI_GRID_Y);
                    text = "Reload Speed Floor";
                    tooltip = "Minimum reload speed for a spawned unit";
                };
                class GVAR(setSkills_reloadSpeed_min_slider): GVAR(setSkills_aimingAccuracy_min_slider) {
                    idc = SET_SKILLS_RLD_SPD_MIN_SLIDER_IDC;
                    y = QUOTE(22.5 * GUI_GRID_H + GUI_GRID_Y);
                    onSliderPosChanged = QUOTE([ARR_3(_this select 1,'reloadSpeed',false)] call FUNC(setSkillsDialogSliderChange));
                };
                class GVAR(setSkills_reloadSpeed_max_txt): GVAR(setSkills_master_txt) {
                    y = QUOTE(24 * GUI_GRID_H + GUI_GRID_Y);
                    text = "Reload Speed Ceiling";
                    tooltip = "Maximum reload speed for a spawned unit";
                };
                class GVAR(setSkills_reloadSpeed_max_slider): GVAR(setSkills_aimingAccuracy_min_slider) {
                    idc = SET_SKILLS_RLD_SPD_MAX_SLIDER_IDC;
                    y = QUOTE(24 * GUI_GRID_H + GUI_GRID_Y);
                    onSliderPosChanged = QUOTE([ARR_3(_this select 1,'reloadSpeed',true)] call FUNC(setSkillsDialogSliderChange));
                };
                class GVAR(setSkills_spotDistance_min_txt): GVAR(setSkills_master_txt) {
                    y = QUOTE(25.5 * GUI_GRID_H + GUI_GRID_Y);
                    text = "Spot Distance Floor";
                    tooltip = "Minimum spot distance for a spawned unit";
                };
                class GVAR(setSkills_spotDistance_min_slider): GVAR(setSkills_aimingAccuracy_min_slider) {
                    idc = SET_SKILLS_SPT_DST_MIN_SLIDER_IDC;
                    y = QUOTE(25.5 * GUI_GRID_H + GUI_GRID_Y);
                    onSliderPosChanged = QUOTE([ARR_3(_this select 1,'spotDistance',false)] call FUNC(setSkillsDialogSliderChange));
                };
                class GVAR(setSkills_spotDistance_max_txt): GVAR(setSkills_master_txt) {
                    y = QUOTE(27 * GUI_GRID_H + GUI_GRID_Y);
                    text = "Spot Distance Ceiling";
                    tooltip = "Maximum spot distance for a spawned unit";
                };
                class GVAR(setSkills_spotDistance_max_slider): GVAR(setSkills_aimingAccuracy_min_slider) {
                    idc = SET_SKILLS_SPT_DST_MAX_SLIDER_IDC;
                    y = QUOTE(27 * GUI_GRID_H + GUI_GRID_Y);
                    onSliderPosChanged = QUOTE([ARR_3(_this select 1,'spotDistance',true)] call FUNC(setSkillsDialogSliderChange));
                };
                class GVAR(setSkills_spotTime_min_txt): GVAR(setSkills_master_txt) {
                    y = QUOTE(28.5 * GUI_GRID_H + GUI_GRID_Y);
                    text = "Spot Time Floor";
                    tooltip = "Minimum spot time for a spawned unit";
                };
                class GVAR(setSkills_spotTime_min_slider): GVAR(setSkills_aimingAccuracy_min_slider) {
                    idc = SET_SKILLS_SPT_TM_MIN_SLIDER_IDC;
                    y = QUOTE(28.5 * GUI_GRID_H + GUI_GRID_Y);
                    onSliderPosChanged = QUOTE([ARR_3(_this select 1,'spotTime',false)] call FUNC(setSkillsDialogSliderChange));
                };
                class GVAR(setSkills_spotTime_max_txt): GVAR(setSkills_master_txt) {
                    y = QUOTE(30 * GUI_GRID_H + GUI_GRID_Y);
                    text = "Spot Time Ceiling";
                    tooltip = "Maximum spot time for a spawned unit";
                };
                class GVAR(setSkills_spotTime_max_slider): GVAR(setSkills_aimingAccuracy_min_slider) {
                    idc = SET_SKILLS_SPT_TM_MAX_SLIDER_IDC;
                    y = QUOTE(30 * GUI_GRID_H + GUI_GRID_Y);
                    onSliderPosChanged = QUOTE([ARR_3(_this select 1,'spotTime',true)] call FUNC(setSkillsDialogSliderChange));
                };
                class GVAR(setSkills_autocombat_txt): GVAR(setSkills_master_txt) {
                    y = QUOTE(31.5 * GUI_GRID_H + GUI_GRID_Y);
                    text = "Autocombat";
                    tooltip = "Enable/disable AI automatically changing to combat mode";
                };
                class GVAR(setSkills_autocombat_bx): GVAR(setSkills_master_bx) {
                    idc = SET_SKILLS_AUTOCOMBAT_BX_IDC;
                    y = QUOTE(31.5 * GUI_GRID_H + GUI_GRID_Y);
                    tooltip = "Enable/disable AI automatically changing to combat mode";
                };
                class GVAR(setSkills_cover_txt): GVAR(setSkills_master_txt) {
                    y = QUOTE(33 * GUI_GRID_H + GUI_GRID_Y);
                    text = "Cover";
                    tooltip = "Enable/disable AI moving into cover when in combat";
                };
                class GVAR(setSkills_cover_bx): GVAR(setSkills_master_bx) {
                    idc = SET_SKILLS_COVER_BX_IDC;
                    y = QUOTE(33 * GUI_GRID_H + GUI_GRID_Y);
                    tooltip = "Enable/disable AI moving into cover when in combat";
                };
                class GVAR(setSkills_path_txt): GVAR(setSkills_master_txt) {
                    y = QUOTE(34.5 * GUI_GRID_H + GUI_GRID_Y);
                    text = "Path";
                    tooltip = "Enable/disable AI from moving, but not engaging/looking";
                };
                class GVAR(setSkills_path_bx): GVAR(setSkills_master_bx) {
                    idc = SET_SKILLS_PATH_BX_IDC;
                    y = QUOTE(34.5 * GUI_GRID_H + GUI_GRID_Y);
                    tooltip = "Enable/disable AI from moving, but not engaging/looking";
                };
                class GVAR(setSkills_suppression_txt): GVAR(setSkills_master_txt) {
                    y = QUOTE(36 * GUI_GRID_H + GUI_GRID_Y);
                    text = "Suppression";
                    tooltip = "Enable/disable AI from being suppressed";
                };
                class GVAR(setSkills_suppression_bx): GVAR(setSkills_master_bx) {
                    idc = SET_SKILLS_SUPPRESSION_BX_IDC;
                    y = QUOTE(36 * GUI_GRID_H + GUI_GRID_Y);
                    tooltip = "Enable/disable AI from being suppressed";
                };
            };
        };
        class GVAR(setSkills_okay_btn): RscButtonMenuOK {
            x = QUOTE(40 * GUI_GRID_W + GUI_GRID_X);
            y = QUOTE(28 * GUI_GRID_H + GUI_GRID_Y);
            w = QUOTE(2 * GUI_GRID_W);
            h = QUOTE(1 * GUI_GRID_H);
            colorBackground[] = {0,0.5,0,1};
            colorBackground2[] = {0,0.4,0,1};
            colorBackgroundFocused[] = {0,0.8,0,1};
            tooltip = "Set";
            action = QUOTE([] call FUNC(setSkillsDialogSet));
        };
        class GVAR(setSkills_cancel_btn): RscButtonMenuCancel {
            x = QUOTE(43 * GUI_GRID_W + GUI_GRID_X);
            y = QUOTE(28 * GUI_GRID_H + GUI_GRID_Y);
            w = QUOTE(4 * GUI_GRID_W);
            h = QUOTE(1 * GUI_GRID_H);
            colorBackground[] = {0.5,0,0,1};
            colorBackground2[] = {0.4,0,0,1};
            colorBackgroundFocused[] = {0.8,0,0,1};
            tooltip = "Cancel";
            action = "closeDialog 2;";
        };
    };
};
