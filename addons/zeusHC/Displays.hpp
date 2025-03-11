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
class RscListBox;
class RscButton;
class RscEdit;
class RscSlider;
class RscText;
class RscCheckBox;

class GVAR(bg): IGUIBack {
    idc = BG_IDC;
    x = 0 * GUI_GRID_W + GUI_GRID_X;
    y = 0 * GUI_GRID_H + GUI_GRID_Y;
    w = 48 * GUI_GRID_W;
    h = 30 * GUI_GRID_H;
};
class GVAR(base_frame): RscFrame {
    idc = FRAME_IDC;
    x = 0.5 * GUI_GRID_W + GUI_GRID_X;
    y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
    w = 47 * GUI_GRID_W;
    h = 29 * GUI_GRID_H;
    colorBackground[] = {0,0,0,0.8};
    sizeEx = 1 * GUI_GRID_H;
};

class GVAR(build_a_group_dialog) {
    idd = BUILD_GROUP_IDD;
    movingEnable = 0;
    onLoad = QUOTE([] spawn FUNC(buildAGroupDialogLoad));
    class controls {
        class GVAR(group_bg): GVAR(bg) {};
        class GVAR(build_a_group_frame): GVAR(base_frame) {
            text = "Build-a-Group";
        };
        class GVAR(build_a_group_cancel_btn): RscButtonMenuCancel {
            idc = CANCEL_IDC;
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
            idc = OK_IDC;
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
        class GVAR(build_a_group_unit_list): RscListBox {
            idc = BUILD_GROUP_UNITS_IDC;
            x = 1.5 * GUI_GRID_W + GUI_GRID_X;
            y = 3 * GUI_GRID_H + GUI_GRID_Y;
            w = 18 * GUI_GRID_W;
            h = 24.5 * GUI_GRID_H;
            onLBDblClick = QUOTE([_this select 1] call FUNC(buildAGroupDialogAdd));
        };
        class GVAR(build_a_group_list_to_add): RscListBox {
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

class GVAR(spawn_a_vic_dialog) {
    idd = SPAWN_VIC_IDD;
    movingEnable = 0;
    onLoad = QUOTE([] spawn FUNC(spawnAVicDialogLoad));
    class controls {
        class GVAR(vic_bg): GVAR(bg) {};
        class GVAR(spawn_a_vic_frame): GVAR(base_frame) {
            text = "Spawn-a-Vic";
        };
        class GVAR(spawn_a_vic_cancel_btn): RscButtonMenuCancel {
            idc = CANCEL_IDC;
            x = 43 * GUI_GRID_W + GUI_GRID_X;
            y = 28 * GUI_GRID_H + GUI_GRID_Y;
            w = 4 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
            colorBackground[] = {0.5,0,0,1};
            colorBackground2[] = {0.4,0,0,1};
            colorBackgroundFocused[] = {0.8,0,0,1};
            tooltip = "Cancel spawning a vehicle";
            action = "closeDialog 2;";
        };
        class GVAR(spawn_a_vic_okay_btn): RscButtonMenuOK {
            idc = OK_IDC;
            x = 40 * GUI_GRID_W + GUI_GRID_X;
            y = 28 * GUI_GRID_H + GUI_GRID_Y;
            w = 2 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
            colorBackground[] = {0,0.5,0,1};
            colorBackground2[] = {0,0.4,0,1};
            colorBackgroundFocused[] = {0,0.8,0,1};
            tooltip = "Add vehicle";
            action = QUOTE([] call FUNC(spawnAVicDialogSpawn));
        };
        class GVAR(spawn_a_vic_faction_list): RscListBox {
            idc = SPAWN_VIC_FACTIONS_IDC;
            x = 1.5 * GUI_GRID_W + GUI_GRID_X;
            y = 2 * GUI_GRID_H + GUI_GRID_Y;
            w = 21.5 * GUI_GRID_W;
            h = 25.5 * GUI_GRID_H;
            onLBSelChanged = QUOTE([_this select 1] call FUNC(spawnAVicDialogFactionChange));
        };
        class GVAR(spawn_a_vic_list): RscListBox {
            idc = SPAWN_VIC_LIST_IDC;
            x = 24.5 * GUI_GRID_W + GUI_GRID_X;
            y = 2 * GUI_GRID_H + GUI_GRID_Y;
            w = 22 * GUI_GRID_W;
            h = 25.5 * GUI_GRID_H;
            onLBDblClick = QUOTE([_this select 1] call FUNC(spawnAVicDialogSpawn));
        };
    };
};

class GVAR(garrison_dialog) {
    idd = GARRISON_IDD;
    movingEnable = 0;
    onLoad = QUOTE([] spawn FUNC(garrisonDialogLoad));
    class controls {
        class GVAR(garrison_bg): GVAR(bg) {};
        class GVAR(garrison_frame): GVAR(base_frame) {
            text = "Garrison";
        };
        class GVAR(garrison_cancel_btn): RscButtonMenuCancel {
            idc = CANCEL_IDC;
            x = 43 * GUI_GRID_W + GUI_GRID_X;
            y = 28 * GUI_GRID_H + GUI_GRID_Y;
            w = 4 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
            colorBackground[] = {0.5,0,0,1};
            colorBackground2[] = {0.4,0,0,1};
            colorBackgroundFocused[] = {0.8,0,0,1};
            tooltip = "Cancel garrisoning";
            action = "closeDialog 2;";
        };
        class GVAR(garrison_okay_btn): RscButtonMenuOK {
            idc = OK_IDC;
            x = 40 * GUI_GRID_W + GUI_GRID_X;
            y = 28 * GUI_GRID_H + GUI_GRID_Y;
            w = 2 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
            colorBackground[] = {0,0.5,0,1};
            colorBackground2[] = {0,0.4,0,1};
            colorBackgroundFocused[] = {0,0.8,0,1};
            tooltip = "Garrison";
            action = QUOTE([] spawn FUNC(garrisonDialogSpawn));
        };
        class GVAR(garrison_enable_lambs_checkbox): RscCheckBox {
            idc = GARRISON_ENABLE_LAMBS_IDC;
            x = 1 * GUI_GRID_W + GUI_GRID_X;
            y = 28 * GUI_GRID_H + GUI_GRID_Y;
            w = 1 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
            tooltip = "Enable LAMBS so these enemy can respond to contact";
        };
        class GVAR(garrison_enable_lambs_text): RscText {
            idc = -1;
            x = 2 * GUI_GRID_W + GUI_GRID_X;
            y = 28 * GUI_GRID_H + GUI_GRID_Y;
            w = 13 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
            text = "Enable LAMBS for garrisoned units";
        };
        class GVAR(garrison_factions): RscCombo {
            idc = GARRISON_FACTIONS_IDC;
            x = 19.5 * GUI_GRID_W + GUI_GRID_X;
            y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
            w = 8 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
            tooltip = "Select a faction";
            sizeEx = 1 * GUI_GRID_H;
        };
        class GVAR(garrison_units_slider): RscSlider {
            idc = GARRISON_UNITS_SLIDER_IDC;
            text = "Maximum Units to Spawn";
            x = 10 * GUI_GRID_W + GUI_GRID_X;
            y = 6 * GUI_GRID_H + GUI_GRID_Y;
            w = 24.5 * GUI_GRID_W;
            h = 2 * GUI_GRID_H;
            colorText[] = {1,1,1,1};
            tooltip = "The maximum units that will be spawned";
            sizeEx = 1 * GUI_GRID_H;
            onSliderPosChanged = QUOTE([ARR_2(true,4)] call FUNC(garrisonDialogControlChange));
        };
        class GVAR(garrison_chance_slider): RscSlider {
            idc = GARRISON_CHANCE_SLIDER_IDC;
            text = "Occupy Building Chance";
            x = 10 * GUI_GRID_W + GUI_GRID_X;
            y = 10 * GUI_GRID_H + GUI_GRID_Y;
            w = 24.5 * GUI_GRID_W;
            h = 2 * GUI_GRID_H;
            colorText[] = {1,1,1,1};
            tooltip = "The chance a building will be garrisoned";
            sizeEx = 1 * GUI_GRID_H;
            onSliderPosChanged = QUOTE([ARR_2(true,0)] call FUNC(garrisonDialogControlChange));
        };
        class GVAR(garrison_radius_slider): RscSlider {
            idc = GARRISON_RADIUS_SLIDER_IDC;
            text = "Occupy Radius";
            x = 10 * GUI_GRID_W + GUI_GRID_X;
            y = 14 * GUI_GRID_H + GUI_GRID_Y;
            w = 24.5 * GUI_GRID_W;
            h = 2 * GUI_GRID_H;
            colorText[] = {1,1,1,1};
            tooltip = "The radius from the placed module that the buildings will be occupied (meters)";
            sizeEx = 1 * GUI_GRID_H;
            onSliderPosChanged = QUOTE([ARR_2(true,1)] call FUNC(garrisonDialogControlChange));
        };
        class GVAR(garrison_min_slider): RscSlider {
            idc = GARRISON_MIN_SLIDER_IDC;
            text = "Occupy Min Units";
            x = 10 * GUI_GRID_W + GUI_GRID_X;
            y = 18 * GUI_GRID_H + GUI_GRID_Y;
            w = 24.5 * GUI_GRID_W;
            h = 2 * GUI_GRID_H;
            colorText[] = {1,1,1,1};
            tooltip = "Minimum units to occupy a building with";
            sizeEx = 1 * GUI_GRID_H;
            onSliderPosChanged = QUOTE([ARR_2(true,2)] call FUNC(garrisonDialogControlChange));
        };
        class GVAR(garrison_max_slider): RscSlider {
            idc = GARRISON_MAX_SLIDER_IDC;
            text = "Occupy Max Units";
            x = 10 * GUI_GRID_W + GUI_GRID_X;
            y = 22 * GUI_GRID_H + GUI_GRID_Y;
            w = 24.5 * GUI_GRID_W;
            h = 2 * GUI_GRID_H;
            colorText[] = {1,1,1,1};
            tooltip = "Maximum units to occupy a building with";
            sizeEx = 1 * GUI_GRID_H;
            onSliderPosChanged = QUOTE([ARR_2(true,3)] call FUNC(garrisonDialogControlChange));
        };
        class GVAR(garrison_unit_edit): RscEdit {
            idc = GARRISON_UNITS_EDIT_IDC;
            x = 36.5 * GUI_GRID_W + GUI_GRID_X;
            y = 5.5 * GUI_GRID_H + GUI_GRID_Y;
            w = 3.5 * GUI_GRID_W;
            h = 2 * GUI_GRID_H;
            tooltip = "The maximum units that will be spawned";
            onKillFocus = QUOTE([ARR_2(false,4)] call FUNC(garrisonDialogControlChange));
        };
        class GVAR(garrison_chance_edit): RscEdit {
            idc = GARRISON_CHANCE_EDIT_IDC;
            x = 36.5 * GUI_GRID_W + GUI_GRID_X;
            y = 9.5 * GUI_GRID_H + GUI_GRID_Y;
            w = 3.5 * GUI_GRID_W;
            h = 2 * GUI_GRID_H;
            tooltip = "The chance a building will be garrisoned";
            onKillFocus = QUOTE([ARR_2(false,0)] call FUNC(garrisonDialogControlChange));
        };
        class GVAR(garrison_radius_edit): RscEdit {
            idc = GARRISON_RADIUS_EDIT_IDC;
            x = 36.5 * GUI_GRID_W + GUI_GRID_X;
            y = 13.5 * GUI_GRID_H + GUI_GRID_Y;
            w = 3.5 * GUI_GRID_W;
            h = 2 * GUI_GRID_H;
            tooltip = "The radius from the placed module that the buildings will be occupied (meters)";
            onKillFocus = QUOTE([ARR_2(false,1)] call FUNC(garrisonDialogControlChange));
        };
        class GVAR(garrison_min_edit): RscEdit {
            idc = GARRISON_MIN_EDIT_IDC;
            x = 36.5 * GUI_GRID_W + GUI_GRID_X;
            y = 17.5 * GUI_GRID_H + GUI_GRID_Y;
            w = 3.5 * GUI_GRID_W;
            h = 2 * GUI_GRID_H;
            tooltip = "Minimum units to occupy a building with";
            onKillFocus = QUOTE([ARR_2(false,2)] call FUNC(garrisonDialogControlChange));
        };
        class GVAR(garrison_max_edit): RscEdit {
            idc = GARRISON_MAX_EDIT_IDC;
            x = 36.5 * GUI_GRID_W + GUI_GRID_X;
            y = 21.5 * GUI_GRID_H + GUI_GRID_Y;
            w = 3.5 * GUI_GRID_W;
            h = 2 * GUI_GRID_H;
            tooltip = "Maximum units to occupy a building with";
            onKillFocus = QUOTE([ARR_2(false,3)] call FUNC(garrisonDialogControlChange));
        };
    };
};
