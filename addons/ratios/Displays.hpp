class RscEdit;
class RscListBox;
class RscCheckBox;
class RscStandardDisplay;


class RscDisplayMultiplayerSetup: RscStandardDisplay {
    class controls {
        class TextListedPlayers;
        class ValueListedPlayers;

        class GVAR(PlayerOverride): TextListedPlayers {
            x = "25.8 * (((safezoneW / safezoneH) min 1.2) / 40) +(safezoneX) + 1 * (safezoneW - ((safezoneW / safezoneH) min 1.2))";
            idc = RATIO_PLAYER_OVERRIDE_IDC;
            text = "Player count:";
        };

        class GVAR(PlayerOverrideInput): RscEdit {
            idc = RATIO_PLAYER_OVERRIDE_INPUT_IDC;
            shadow = 0;
            size = 0.2;
            sizeEx = "0.55 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            w = "1.3 * (((safezoneW / safezoneH) min 1.2) / 40)";
            h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            x = "29.5 * (((safezoneW / safezoneH) min 1.2) / 40) +safezoneX + 1 * (safezoneW - ((safezoneW / safezoneH) min 1.2))";
            y = "2.3 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + safezoneY";
        };

        class GVAR(RatioInput_1): RscEdit {
            idc = RATIO_INPUT_1_IDC;
            shadow = 0;
            size = 0.2;
            sizeEx = "0.55 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            w = "1.2 * (((safezoneW / safezoneH) min 1.2) / 40)";
            h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            x = "32.3 * (((safezoneW / safezoneH) min 1.2) / 40) + (SafezoneX) + 1 * (safezoneW - ((safezoneW / safezoneH) min 1.2))";
            y = "3.3 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY)";
        };
        class GVAR(RatioInput_2): GVAR(RatioInput_1) {
            idc = RATIO_INPUT_2_IDC;
            x = "34.8 * (((safezoneW / safezoneH) min 1.2) / 40) + safezoneX + 1 * (safezoneW - ((safezoneW / safezoneH) min 1.2))";
        };
        class GVAR(RatioInput_3): GVAR(RatioInput_1) {
            idc = RATIO_INPUT_3_IDC;
            x = "37.3 * (((safezoneW / safezoneH) min 1.2) / 40) + safezoneX + 1 * (safezoneW - ((safezoneW / safezoneH) min 1.2))";
        };

        class GVAR(RatioCheck_1): RscCheckBox {
            idc = RATIO_CHECK_1_IDC;
            shadow = 0;
            sizeEx = "0.55 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            w = "1 * (((safezoneW / safezoneH) min 1.2) / 40)";
            h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            x = "31.2 * (((safezoneW / safezoneH) min 1.2) / 40) + (SafezoneX) + 1 * (safezoneW - ((safezoneW / safezoneH) min 1.2))";
            y = "3.3 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY)";
        };
        class GVAR(RatioCheck_2): GVAR(RatioCheck_1) {
            idc = RATIO_CHECK_2_IDC;
            x = "33.7 * (((safezoneW / safezoneH) min 1.2) / 40) + (SafezoneX) + 1 * (safezoneW - ((safezoneW / safezoneH) min 1.2))";
        };
        class GVAR(RatioCheck_3): GVAR(RatioCheck_1) {
            idc = RATIO_CHECK_3_IDC;
            x = "36.2 * (((safezoneW / safezoneH) min 1.2) / 40) + (SafezoneX) + 1 * (safezoneW - ((safezoneW / safezoneH) min 1.2))";
        };

        class GVAR(RatioOutput_1): RscListBox {
            idc = RATIO_OUTPUT_1_IDC;
            canDrag = 0;
            rows = 1;
            size = 1; //0.175;
            sizeEx = "0.6 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            x = "31.4 * (((safezoneW / safezoneH) min 1.2) / 40) + safezoneX + 1 * (safezoneW - ((safezoneW / safezoneH) min 1.2))";
            w = "2.3 * (((safezoneW / safezoneH) min 1.2) / 40)";
            h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
            colorBackground[] = {0,0,0,0};
            colorSelectBackground[] = {0,0,0,0};
            colorSelectBackground2[] = {0,0,0,0};
            colorPictureSelected[] = {0,0,0,0};
            y = "4.6 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + safezoneY";
        };
        class GVAR(RatioOutput_2): GVAR(RatioOutput_1) {
            idc = RATIO_OUTPUT_2_IDC;
            x = "33.9 * (((safezoneW / safezoneH) min 1.2) / 40) + safezoneX + 1 * (safezoneW - ((safezoneW / safezoneH) min 1.2))";
        };
        class GVAR(RatioOutput_3): GVAR(RatioOutput_1) {
            idc = RATIO_OUTPUT_3_IDC;
            x = "36.4 * (((safezoneW / safezoneH) min 1.2) / 40) + safezoneX + 1 * (safezoneW - ((safezoneW / safezoneH) min 1.2))";
        };
    };
};
