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
class RscButton;
class RscText;

class GVAR(bg): IGUIBack {
    x = 0 * GUI_GRID_W + GUI_GRID_X;
    y = 0 * GUI_GRID_H + GUI_GRID_Y;
    w = 48 * GUI_GRID_W;
    h = 30 * GUI_GRID_H;
};
class GVAR(base_frame): RscFrame {
    x = 0.5 * GUI_GRID_W + GUI_GRID_X;
    y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
    w = 47 * GUI_GRID_W;
    h = 29 * GUI_GRID_H;
    colorBackground[] = {0,0,0,0.8};
    sizeEx = 1 * GUI_GRID_H;
};

class GVAR(reinforcement_dialog) {
    idd = REINFORCEMENT_IDD;
    movingEnable = 0;
    onLoad = QUOTE([] spawn FUNC(reinforcementsDialogLoad));
    class controls {
        class GVAR(reinforcement_bg): GVAR(bg) {};
        class GVAR(reinforcement_frame): GVAR(base_frame) {
            text = "Reinforcements";
        };
        class GVAR(reinforcement_cancel_btn): RscButtonMenuCancel {
            x = 43 * GUI_GRID_W + GUI_GRID_X;
            y = 28 * GUI_GRID_H + GUI_GRID_Y;
            w = 4 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
            colorBackground[] = {0.5,0,0,1};
            colorBackground2[] = {0.4,0,0,1};
            colorBackgroundFocused[] = {0.8,0,0,1};
            tooltip = "Cancel reinforcements";
            action = "closeDialog 2;";
        };
        class GVAR(reinforcement_okay_btn): RscButtonMenuOK {
            x = 40 * GUI_GRID_W + GUI_GRID_X;
            y = 28 * GUI_GRID_H + GUI_GRID_Y;
            w = 2 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
            colorBackground[] = {0,0.5,0,1};
            colorBackground2[] = {0,0.4,0,1};
            colorBackgroundFocused[] = {0,0.8,0,1};
            tooltip = "Create reinforcements";
            action = QUOTE([] call FUNC(reinforcementsDialogSpawn));
        };
        class GVAR(reinforcement_factions): RscCombo {
            idc = REINFORCEMENT_FACTIONS_IDC;
            x = 23.5 * GUI_GRID_W + GUI_GRID_X;
            y = 3.5 * GUI_GRID_H + GUI_GRID_Y;
            w = 17 * GUI_GRID_W;
            h = 1.5 * GUI_GRID_H;
            tooltip = "Select a faction";
            sizeEx = 1 * GUI_GRID_H;
            onLBSelChanged  = QUOTE([] call FUNC(reinforcementsDialogChange));
        };
        class GVAR(reinforcement_veh_type): RscCombo {
            idc = REINFORCEMENT_TYPE_IDC;
            x = 23.5 * GUI_GRID_W + GUI_GRID_X;
            y = 6.5 * GUI_GRID_H + GUI_GRID_Y;
            w = 17 * GUI_GRID_W;
            h = 1.5 * GUI_GRID_H;
            tooltip = "Select a vehicle type";
            sizeEx = 1 * GUI_GRID_H;
            onLBSelChanged  = QUOTE([] call FUNC(reinforcementsDialogChange));
        };
        class GVAR(reinforcement_veh): RscCombo {
            idc = REINFORCEMENT_VEHICLE_IDC;
            x = 23.5 * GUI_GRID_W + GUI_GRID_X;
            y = 10 * GUI_GRID_H + GUI_GRID_Y;
            w = 17 * GUI_GRID_W;
            h = 1.5 * GUI_GRID_H;
            tooltip = "Select a vehicle";
            sizeEx = 1 * GUI_GRID_H;
        };
        class GVAR(reinforcement_veh_behavior): RscCombo {
            idc = REINFORCEMENT_VEHICLE_BEHAVIOR_IDC;
            x = 23.5 * GUI_GRID_W + GUI_GRID_X;
            y = 13.5 * GUI_GRID_H + GUI_GRID_Y;
            w = 17 * GUI_GRID_W;
            h = 1.5 * GUI_GRID_H;
            tooltip = "Select a vehicle behavior";
            sizeEx = 1 * GUI_GRID_H;
        };
        class GVAR(reinforcement_veh_lz): RscCombo {
            idc = REINFORCEMENT_VEHICLE_LZ_IDC;
            x = 23.5 * GUI_GRID_W + GUI_GRID_X;
            y = 17 * GUI_GRID_H + GUI_GRID_Y;
            w = 17 * GUI_GRID_W;
            h = 1.5 * GUI_GRID_H;
            tooltip = "Select a vehicle dismount point";
            sizeEx = 1 * GUI_GRID_H;
        };
        class GVAR(reinforcement_unit_rp): RscCombo {
            idc = REINFORCEMENT_UNIT_RP_IDC;
            x = 23.5 * GUI_GRID_W + GUI_GRID_X;
            y = 20.5 * GUI_GRID_H + GUI_GRID_Y;
            w = 17 * GUI_GRID_W;
            h = 1.5 * GUI_GRID_H;
            tooltip = "Select a rally point for dismounts";
            sizeEx = 1 * GUI_GRID_H;
        };
        class GVAR(reinforcement_unit_behavior): RscCombo {
            idc = REINFORCEMENT_UNIT_BEHAVIOR_IDC;
            x = 23.5 * GUI_GRID_W + GUI_GRID_X;
            y = 24 * GUI_GRID_H + GUI_GRID_Y;
            w = 17 * GUI_GRID_W;
            h = 1.5 * GUI_GRID_H;
            tooltip = "Select unit agression level";
            sizeEx = 1 * GUI_GRID_H;
        };
        class GVAR(reinforcement_faction_text): RscText {
            text = "Select a reinforcement faction:";
            x = 8.4 * GUI_GRID_W + GUI_GRID_X;
            y = 3.7 * GUI_GRID_H + GUI_GRID_Y;
            w = 11 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
        };
        class GVAR(reinforcement_type_text): RscText {
            text = "Select a vehicle group:";
            x = 11.2 * GUI_GRID_W + GUI_GRID_X;
            y = 6.8 * GUI_GRID_H + GUI_GRID_Y;
            w = 8 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
        };
        class GVAR(reinforcement_vehicle_text): RscText {
            text = "Select a vehicle:";
            x = 13.21 * GUI_GRID_W + GUI_GRID_X;
            y = 10.29 * GUI_GRID_H + GUI_GRID_Y;
            w = 6 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
        };
        class GVAR(reinforcement_vehicle_behavior_text): RscText {
            text = "Select a vehicle behavior:";
            x = 10.2 * GUI_GRID_W + GUI_GRID_X;
            y = 13.7 * GUI_GRID_H + GUI_GRID_Y;
            w = 9 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
        };
        class GVAR(reinforcement_dismount_text): RscText {
            text = "Select a vehicle dismount point:";
            x = 8.1 * GUI_GRID_W + GUI_GRID_X;
            y = 17.3 * GUI_GRID_H + GUI_GRID_Y;
            w = 11 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
        };
        class GVAR(reinforcement_rp_text): RscText {
            text = "Select a rally point for dismounts:";
            x = 7.6 * GUI_GRID_W + GUI_GRID_X;
            y = 20.8 * GUI_GRID_H + GUI_GRID_Y;
            w = 11.5 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
        };
        class GVAR(reinforcement_dismount_behavior_text): RscText {
            text = "Select unit agression level:";
            x = 9.8 * GUI_GRID_W + GUI_GRID_X;
            y = 24.3 * GUI_GRID_H + GUI_GRID_Y;
            w = 9.5 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
        };
    };
};
