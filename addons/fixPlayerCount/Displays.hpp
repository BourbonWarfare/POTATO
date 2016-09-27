class RscText;
class RscStandardDisplay;

class RscDisplayMultiplayerSetup: RscStandardDisplay {
    class controls {
        class GVAR(ValueListedPlayers): RscText {
            idc = PLAYER_DISPLAY_IDC;
            sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
            style = 1;
            x = "37 * (((safezoneW / safezoneH) min 1.2) / 40) + (SafezoneX) + 1 * (safezoneW - ((safezoneW / safezoneH) min 1.2))";
            y = "2.3 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY)";
            w = "2 * (((safezoneW / safezoneH) min 1.2) / 40)";
            h = "0.8 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
        };
    };
};
