#include "\a3\ui_f\hpp\defineCommonGrids.inc"
class RscButtonMenuCancel;
class RscButtonMenuOK;
class RscCombo;
class RscListBox;
class RscText;
class RscMapControl;
class RscShortcutButton;
class RscListNBox;
#define safeZoneW_POT 2.83769
#define safezoneH_POT 2.12733


class GVAR(zeusParadropCargo) {
    idd = IDD_AIRDROP_DIALOG;
    x = -0.3;
    y = 0.05;
    w = 1.475;
    h = 1.05;
    onUnload = QUOTE([ARR_2(true,_this)] call FUNC(ui_zeusCargoDialog));
    onLoad = QUOTE([ARR_2(false,_this)] call FUNC(ui_zeusCargoDialog));
    class ControlsBackground {
        class Background : RscText {
            idc = -1;
            x = -0.3;
            y = 0.05;
            w = 1.475;
            h = 1.05;
            colorBackground[] = {0,0,0,0.7};
        };
    };
    class Controls {
        class RscMap_UIInterface: RscMapControl {
            idc = IDC_AIRDROP_MAP;
            x = -0.275;
            y = 0.2;
            w = 0.6875;
            h = 0.86;
        };
        class RscText_Side: RscText {
            text = "Side";
            style = 1;
            x = 0.42;
            y = 0.2;
            w = 0.11;
            h = 0.06;
        };
        // fuck if I know why this conflicts with specificly RscText_title
        class RscText_Side2: RscText_Side {};
        class RscText_title: RscText_Side {
            text = "Potato Cargo/Vehicle Airdrop";
            style = 2;
            x = -0.3;
            y = 0.05;
            w = 1.475;
            h = 0.11;
            sizeEx = 0.1;
        };
        class RscCombo_Side: RscCombo {
            idc = IDC_AIRDROP_SIDE;
            x = 0.55;
            y = 0.2;
            w = 0.3;
            h = 0.06;
            onLBSelChanged = QUOTE([ARR_2(_this,IDC_AIRDROP_SIDE)] call FUNC(ui_zeusCargoUpdate););
            tooltip = "Side of Group";
            class Items {
                class west {
                    default = 1;
                    text = "BluFor";
                    value = 0;
                };
                class east {
                    text = "OpFor";
                    value = 1;
                };
                class resistance {
                    text = "Indy";
                    value = 2;
                };
                class civilian {
                    text = "Civ";
                    value = 3;
                };
            };
        };
        class RscText_objList: RscListBox {
            idc = IDC_AIRDROP_DROPOPTIONS;
            x = 0.45;
            y = 0.3;
            w = 0.3;
            h = 0.5;
            colorBackground[] = {1, 1, 1, 0.1};
        };
        class RscShortcutButton_addVic: RscShortcutButton {
            idc = IDC_AIRDROP_ADDVIC;
            x = 0.76;
            y = 0.4;
            w = 0.03;
            h = 0.04;
            onButtonClick = QUOTE([ARR_2(_this,IDC_AIRDROP_ADDVIC)] call FUNC(ui_zeusCargoUpdate););
	        colorBackground[] = {0,0,0,1};
            textureNoShortcut = "\a3\ui_f\data\gui\rsccommon\rschtml\arrow_right_ca.paa";
            tooltip = "Add vehicle or box";
        };
        class RscShortcutButton_addVicParaFail: RscShortcutButton_addVic {
            idc = IDC_AIRDROP_ADDVIC_PARAFAIL;
            y = 0.5;
            onButtonClick = QUOTE([ARR_2(_this,IDC_AIRDROP_ADDVIC_PARAFAIL)] call FUNC(ui_zeusCargoUpdate););
            textureNoShortcut = "\a3\ui_f\data\igui\rscingameui\rscunitinfo\arrow_right_ca.paa";
            tooltip = "Add vehicle or box with failing parachute";
        };
        class RscShortcutButton_removeVic: RscShortcutButton_addVic {
            idc = IDC_AIRDROP_REMOVEVIC;
            y = 0.6;
            onButtonClick = QUOTE([ARR_2(_this,IDC_AIRDROP_REMOVEVIC)] call FUNC(ui_zeusCargoUpdate););
            textureNoShortcut = "\a3\ui_f\data\gui\rsccommon\rschtml\arrow_left_ca.paa";
            tooltip = "Remove selected item.";
        };
        class ListBackground: RscText {
            idc = -1;
            x = 0.8;
            y = 0.3;
            w = 0.35;
            h = 0.5;
            colorBackground[] = {1, 1, 1, 0.1};
        };
        class RscText_spawnList: RscListNBox {
            idc = IDC_AIRDROP_SPAWNVIC;
            x = 0.8;
            y = 0.3;
            w = 0.35;
            h = 0.5;
            columns[] = {0, 0.6};
            disableOverflow = 1;
        };
        class RscText_finalWP: RscText_Side {
            idc = -1;
            text = "Drop Vehicle";
            style = 1;
            x = 0.45;
            y = 0.9;
            w = 0.12;
            h = 0.06;
        };
        class RscCombo_finalWP: RscCombo {
            idc = IDC_AIRDROP_PLANETYPE;
            x = 0.58;
            y = 0.9;
            w = 0.3;
            h = 0.06;
            tooltip = "Vehicle that will paradrop cargo";
            class Items {};
        };
        class RscButtonMenuOK_exit: RscButtonMenuOK {
            x = 1;
            y = 0.98;
            w = 0.15;
            h = 0.08;
            text = "Create";
            class Attributes {
                font = "PuristaLight";
                color = "#E5E5E5";
                align = "center";
                shadow = "false";
            };
            class TextPos {
                bottom = 0;
                left = QUOTE(0.25 * (((safeZoneW_POT / safezoneH_POT) min 1.2) / 40));
                right = 0.005;
                top = QUOTE((((((safeZoneW_POT / safezoneH_POT) min 1.2) / 1.2) / 25) - (((((safeZoneW_POT / safezoneH_POT) min 1.2) / 1.2) / 25) * 1)) / 2);
                forceMiddle = 1;
            };
        };
        class RscButtonMenuCancel_exit: RscButtonMenuCancel {
            x = 0.45;
            y = 0.98;
            w = 0.15;
            h = 0.08;
            text = "Cancel";
            class Attributes {
                font = "PuristaLight";
                color = "#E5E5E5";
                align = "center";
                shadow = "false";
            };
            class TextPos {
                bottom = 0;
                left = QUOTE(0.25 * (((safeZoneW_POT / safezoneH_POT) min 1.2) / 40));
                right = 0.005;
                top = QUOTE((((((safeZoneW_POT / safezoneH_POT) min 1.2) / 1.2) / 25) - (((((safeZoneW_POT / safezoneH_POT) min 1.2) / 1.2) / 25) * 1)) / 2);
                forceMiddle = 1;
            };
        };
    };
};
