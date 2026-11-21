class RscButtonMenuCancel;
class RscButtonMenuOK;
class RscShortcutButton;
class RscListBox;
class RscEdit;
class RscText;

class GVAR(saveMarkersDialog) {
    idd = IDD_RECALL_MARKERS_MAIN;
    x = 0.3;
    y = 0.2;
    w = 0.4;
    h = 0.6;
    onUnload = "saveProfileNamespace;";
    onLoad = QUOTE(call FUNC(ui_saveMarkersUpdateList));
    class ControlsBackground {
        class Background : RscText {
            x = 0.3;
            y = 0.2;
            w = 0.4;
            h = 0.6;
            colorBackground[] = {0,0,0,0.8};
        };
    };
    class Controls {
        class RscListBox_saveList: RscListBox {
            idc = IDC_RECALL_MARKERS_LISTBOX;
            x = 0.3 + 0.02;
            y = 0.22;
            w = 0.36;
            h = 0.6 - 0.02 * 2 -0.01 * 2 - 0.05 * 2;
            colorBackground[] = {1, 1, 1, 0.1};
        };
        class RscButton_clear: RscShortcutButton {
            idc = IDC_RECALL_MARKERS_BUTTON_CLEAR;
            onButtonClick = QUOTE(call FUNC(ui_saveMarkersButton));
            animTextureDefault = "#(argb,8,8,3)color(1,1,1,1)";
            animTextureDisabled = "#(argb,8,8,3)color(1,1,1,1)";
            animTextureFocused = "#(argb,8,8,3)color(1,1,1,1)";
            animTextureNormal = "#(argb,8,8,3)color(1,1,1,1)";
            animTextureOver = "#(argb,8,8,3)color(1,1,1,1)";
            animTexturePressed = "#(argb,8,8,3)color(1,1,1,1)";
            color[] = {1,1,1,1};
            color2[] = {0,0,0,1};
            colorBackground[] = {0, 0, 0, 0.7};
            colorBackground2[] = {0.75,0.75,0.75,1};
            colorBackgroundFocused[] = {1, 1, 1, 1};
            x = 0.3 + 0.01;
            y = 0.2 + 0.6 - 0.01 * 2 - 0.05 * 2;
            w = 0.12;
            h = 0.05;
            shadow = 0;
            style = 2;
            text = "Clear Map";
            tooltip = "Clear the map of all markers placed by the user or loaded by this interface.";
            class Attributes {
                font = "PuristaLight";
                color = "#E5E5E5";
                align = "center";
                shadow = "false";
            };
            class TextPos {
                bottom = 0;
                left = 0;
                right = 0.005;
                top = 0;
                forceMiddle = 1;
            };
        };
        class RscButton_load: RscButton_clear {
            idc = IDC_RECALL_MARKERS_BUTTON_LOAD;
            x = 0.3 + 0.12 + 0.01 * 2;
            text = "Load Save";
            tooltip = "Load saved markers to the current map, uses your current set channel.";
        };
        class RscButton_save: RscButton_clear {
            idc = IDC_RECALL_MARKERS_BUTTON_SAVE;
            x = 0.3 + 0.12 * 2 + 0.01 * 3;
            text = "Save";
            tooltip = "Save the current markers to the selected entry.";
        };
        class RscButton_delete: RscButton_clear {
            idc = IDC_RECALL_MARKERS_BUTTON_DELETE;
            x = 0.3 + 0.12 + 0.01 * 2;
            y = 0.2 + 0.6 - 0.01 - 0.05;
            text = "Delete Save";
            tooltip = "Delete the selected saved marker set.";
        };
        class RscButton_saveas: RscButton_clear {
            idc = IDC_RECALL_MARKERS_BUTTON_SAVEAS;
            x = 0.3 + 0.12 * 2 + 0.01 * 3;
            y = 0.2 + 0.6 - 0.01 - 0.05;
            text = "Save As";
            tooltip = "Save the current markers as a name you will enter.";
        };
        class RscButtonMenuCancel_exit: RscButtonMenuCancel {
            colorBackground[] = {0,0,0,0.7};
            x = 0.3 + 0.01;
            y = 0.2 + 0.6 - 0.01 - 0.05;
            w = 0.12;
            h = 0.05;
            style = 2;
            text = "Close";
            tooltip = "Close the interface.";
            class Attributes {
                font = "PuristaLight";
                color = "#E5E5E5";
                align = "center";
                shadow = "false";
            };
            class TextPos {
                bottom = 0;
                left = 0;
                right = 0.005;
                top = 0;
                forceMiddle = 1;
            };
        };
    };
};
class GVAR(saveMarkersConfirmBox) {
    idd = IDD_RECALL_MARKERS_CONFIRM;
    x = 0.2;
    y = 0.46;
    w = 0.6;
    h = 0.08;
    onUnload = QUOTE(call FUNC(ui_saveMarkersConfirmBox));
    class ControlsBackground {
        class Background : RscText {
            x = 0.2;
            y = 0.46;
            w = 0.6;
            h = 0.08;
            colorBackground[] = {0,0,0,1};
        };
    };
    class Controls {
        class RscText_text: RscText {
            idc = IDC_RECALL_MARKERS_CONFIRM_TEXT;
            style = 0;
            text = "Confirm the last choice";
            x = 0.21;
            y = 0.46;
            w = 0.2 + 0.6 - 0.01 * 2;
            h = 0.08;
        };
        class RscButtonMenuOK_exit: RscButtonMenuOK {
            colorBackground[] = {0,0,0,1};
            x = 0.65;
            y = 0.55;
            w = 0.15;
            h = 0.05;
            style = 2;
            text = "Yes";
            class Attributes {
                font = "PuristaLight";
                color = "#E5E5E5";
                align = "center";
                shadow = "false";
            };
            class TextPos {
                bottom = 0;
                left = 0;
                right = 0.005;
                top = 0;
                forceMiddle = 1;
            };
        };
        class RscButtonMenuCancel_exit: RscButtonMenuCancel {
            colorBackground[] = {0,0,0,1};
            x = 0.2;
            y = 0.55;
            w = 0.15;
            h = 0.05;
            style = 2;
            text = "No";
            class Attributes {
                font = "PuristaLight";
                color = "#E5E5E5";
                align = "center";
                shadow = "false";
            };
            class TextPos {
                bottom = 0;
                left = 0;
                right = 0.005;
                top = 0;
                forceMiddle = 1;
            };
        };
    };
};
class GVAR(saveMarkersAsBox) {
    idd = IDD_RECALL_MARKERS_SAVEAS;
    x = 0.2;
    y = 0.46;
    w = 0.6;
    h = 0.08;
    onUnload = QUOTE(call FUNC(ui_saveMarkersAsBox));
    class ControlsBackground {
        class Background : RscText {
            x = 0.2;
            y = 0.46;
            w = 0.6;
            h = 0.08;
            colorBackground[] = {0,0,0,1};
        };
    };
    class Controls {
        class RscText_text: RscText {
            style = 1;
            text = "Save Name";
            x = 0.21;
            y = 0.46;
            w = 0.13;
            h = 0.08;
        };
        class RscEdit_text: RscEdit {
            idc = IDC_RECALL_MARKERS_SAVEAS_TEXT;
            x = 0.35;
            y = 0.48;
            w = 0.44;
            h = 0.04;
        };
        class RscButtonMenuOK_exit: RscButtonMenuOK {
            colorBackground[] = {0,0,0,1};
            x = 0.65;
            y = 0.55;
            w = 0.15;
            h = 0.05;
            style = 2;
            text = "Save As";
            class Attributes {
                font = "PuristaLight";
                color = "#E5E5E5";
                align = "center";
                shadow = "false";
            };
            class TextPos {
                bottom = 0;
                left = 0;
                right = 0.005;
                top = 0;
                forceMiddle = 1;
            };
        };
        class RscButtonMenuCancel_exit: RscButtonMenuCancel {
            colorBackground[] = {0,0,0,1};
            x = 0.2;
            y = 0.55;
            w = 0.15;
            h = 0.05;
            style = 2;
            text = "Cancel";
            class Attributes {
                font = "PuristaLight";
                color = "#E5E5E5";
                align = "center";
                shadow = "false";
            };
            class TextPos {
                bottom = 0;
                left = 0;
                right = 0.005;
                top = 0;
                forceMiddle = 1;
            };
        };
    };
};
