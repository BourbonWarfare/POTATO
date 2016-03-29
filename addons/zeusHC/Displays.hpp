#define GUI_GRID_X -0.1
#define GUI_GRID_Y -0.1
#define GUI_GRID_W 0.025
#define GUI_GRID_H 0.04
#define GUI_GRID_WAbs 1.2
#define GUI_GRID_HAbs 1.2

class IGUIBack;
class RscFrame;
class RscButtonMenuCancel;
class RscButtonMenuOK;
class RscCombo;
class RscListbox;
class RscButton;

class GVAR(build_a_group_dialog) {
    idd = BUILD_GROUP_IDD;
    movingEnable = false;
    onLoad = QUOTE([] spawn FUNC(buildAGroupDialogLoad));
    class controls {
        class GVAR(build_a_group_bg): IGUIBack {
            idc = BUILD_GROUP_BG_IDC;
            x = 0 * GUI_GRID_W + GUI_GRID_X;
            y = 0 * GUI_GRID_H + GUI_GRID_Y;
            w = 48 * GUI_GRID_W;
            h = 30 * GUI_GRID_H;
        };
        class GVAR(build_a_group_frame): RscFrame {
            idc = BUILD_GROUP_FRAME_IDC;
            text = "Build-a-Group";
            x = 0.5 * GUI_GRID_W + GUI_GRID_X;
            y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
            w = 47 * GUI_GRID_W;
            h = 29 * GUI_GRID_H;
            colorBackground[] = {0,0,0,0.8};
            sizeEx = 1 * GUI_GRID_H;
        };
        class GVAR(build_a_group_cancel_btn): RscButtonMenuCancel {
            idc = BUILD_GROUP_CANCEL_IDC;
            x = 43 * GUI_GRID_W + GUI_GRID_X;
            y = 28 * GUI_GRID_H + GUI_GRID_Y;
            w = 4 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
            colorBackground[] = {0.5,0,0,1};
            colorBackground2[] = {0.4,0,0,1};
            colorBackgroundFocused[] = {0.8,0,0,1};
            tooltip = "Cancel creating the group";
            action = "closeDialog 2;";
        };
        class GVAR(build_a_group_okay_btn): RscButtonMenuOK {
            idc = BUILD_GROUP_OK_IDC;
            x = 40 * GUI_GRID_W + GUI_GRID_X;
            y = 28 * GUI_GRID_H + GUI_GRID_Y;
            w = 2 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
            colorBackground[] = {0,0.5,0,1};
            colorBackground2[] = {0,0.4,0,1};
            colorBackgroundFocused[] = {0,0.8,0,1};
            tooltip = "Add group";
            action = QUOTE([] call FUNC(buildAGroupDialogSpawn));
        };
        class GVAR(build_a_group_factions): RscCombo {
            idc = BUILD_GROUP_FACTIONS_IDC;
            x = 19.5 * GUI_GRID_W + GUI_GRID_X;
            y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
            w = 8 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
            tooltip = "Select a faction";
            sizeEx = 1 * GUI_GRID_H;
            onLBSelChanged  = QUOTE([_this select 1] call FUNC(buildAGroupDialogFactionChange));
        };
        class GVAR(build_a_group_unit_list): RscListbox {
            idc = BUILD_GROUP_UNITS_IDC;
            x = 1.5 * GUI_GRID_W + GUI_GRID_X;
            y = 3 * GUI_GRID_H + GUI_GRID_Y;
            w = 18 * GUI_GRID_W;
            h = 24.5 * GUI_GRID_H;
            onLBDblClick = QUOTE([_this select 1] call FUNC(buildAGroupDialogAdd));
        };
        class GVAR(build_a_group_list_to_add): RscListbox {
            idc = BUILD_GROUP_TO_ADD_IDC;
            x = 27.5 * GUI_GRID_W + GUI_GRID_X;
            y = 3 * GUI_GRID_H + GUI_GRID_Y;
            w = 19 * GUI_GRID_W;
            h = 24.5 * GUI_GRID_H;
            onLBDblClick = QUOTE([_this select 1] call FUNC(buildAGroupDialogRemove));
        };
        class GVAR(build_a_group_add_btn): RscButton {
            idc = BUILD_GROUP_ADD_IDC;
            text = "Add ->";
            x = 21.5 * GUI_GRID_W + GUI_GRID_X;
            y = 9.5 * GUI_GRID_H + GUI_GRID_Y;
            w = 4 * GUI_GRID_W;
            h = 2.5 * GUI_GRID_H;
            tooltip = "Add unit to the group";
            sizeEx = 1.5 * GUI_GRID_H;
            action = QUOTE([] call FUNC(buildAGroupDialogAdd));
        };
        class GVAR(build_a_group_remove_btn): RscButton {
            idc = BUILD_GROUP_REMOVE_IDC;
            text = "Remove";
            x = 21.5 * GUI_GRID_W + GUI_GRID_X;
            y = 16 * GUI_GRID_H + GUI_GRID_Y;
            w = 4 * GUI_GRID_W;
            h = 2.5 * GUI_GRID_H;
            sizeEx = 1.25 * GUI_GRID_H;
            action = QUOTE([] call FUNC(buildAGroupDialogRemove));
        };
    };
};
