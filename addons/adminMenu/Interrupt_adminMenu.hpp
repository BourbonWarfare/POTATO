class ctrlCheckbox;
class RscPicture;
class RscFrame;
class RscText;
class RscListBox;
class RscControlsGroup;
class RscCombo;
class RscButton;
class RscStructuredText;
class RscButtonMenu;
class RscEdit;
class RscShortcutButton;


// Add Button to escape menu (borowed from AGM)

class POTATO_EscapeButton_Base1: RscShortcutButton {
    class ShortcutPos {
        left = 0;
        top = 0;
        w = 0;
        h = 0;
    };
    class TextPos {
        left = 0.01;
        top = 0;
        right = 0;
        bottom = 0;
    };
    animTextureDefault = "#(argb,8,8,3)color(1,1,1,1)";
    animTextureDisabled = "#(argb,8,8,3)color(1,1,1,1)";
    animTextureFocused = "#(argb,8,8,3)color(1,1,1,1)";
    animTextureNormal = "#(argb,8,8,3)color(1,1,1,1)";
    animTextureOver = "#(argb,8,8,3)color(1,1,1,1)";
    animTexturePressed = "#(argb,8,8,3)color(1,1,1,1)";
    color2[] = {0,0,0,1};
    color[] = {1,1,1,1};
    colorBackground[] = {1, 0.647, 0, 0.5};
    colorBackground2[] = {1, 0.647, 0, 0.5};
    colorBackgroundFocused[] = {1, 1, 1, 0};
    colorDisabled[] = {1,1,1,0.25};
    colorFocused[] = {0,0,0,1};
    colorText[] = {1,1,1,1};
    shadow = 0;
    style = "0x02 + 0xC0";
    text = "Server Admin Menu";
    x = "1 * (((safezoneW / safezoneH) min 1.2) / 40) + (safezoneX)";
    y = "2.3 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + safezoneY";
    w = "13.4 * (((safezoneW / safezoneH) min 1.2) / 40)";
    h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
    action = QUOTE((findDisplay 49) closeDisplay 0; [] call FUNC(openAdminMenu););
};
class POTATO_EscapeButton_Base2: RscShortcutButton {
    class ShortcutPos {
        left = 0;
        top = 0;
        w = 0;
        h = 0;
    };
    class TextPos {
        left = 0.01;
        top = 0;
        right = 0;
        bottom = 0;
    };
    animTextureDefault = "#(argb,8,8,3)color(1,1,1,1)";
    animTextureDisabled = "#(argb,8,8,3)color(1,1,1,1)";
    animTextureFocused = "#(argb,8,8,3)color(1,1,1,1)";
    animTextureNormal = "#(argb,8,8,3)color(1,1,1,1)";
    animTextureOver = "#(argb,8,8,3)color(1,1,1,1)";
    animTexturePressed = "#(argb,8,8,3)color(1,1,1,1)";
    color2[] = {0,0,0,1};
    color[] = {1,1,1,1};
    colorBackground[] = {1, 0.647, 0, 0.5};
    colorBackground2[] = {1, 0.647, 0, 0.5};
    colorBackgroundFocused[] = {1, 1, 1, 0};
    colorDisabled[] = {1,1,1,0.25};
    colorFocused[] = {0,0,0,1};
    colorText[] = {1,1,1,1};
    shadow = 0;
    style = "0x02 + 0xC0";
    text = "R";
    tooltip = "Respawn";
    x = "14.5 * (((safezoneW / safezoneH) min 1.2) / 40) + (safezoneX)";
    y = "2.3 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + safezoneY";
    w = "1.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
    h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
    action = QUOTE([] call FUNC(openRespawn););
};

class RscStandardDisplay;
class RscDisplayMPInterrupt: RscStandardDisplay {
    class controls {
        class POTATO_EscapeButton1: POTATO_EscapeButton_Base1{};
        class POTATO_EscapeButton2: POTATO_EscapeButton_Base2{};
    };
};
class RscDisplayInterrupt: RscStandardDisplay {
    class controls {
        class POTATO_EscapeButton1: POTATO_EscapeButton_Base1{};
        class POTATO_EscapeButton2: POTATO_EscapeButton_Base2{};
    };
};
class RscDisplayInterruptEditor3D: RscStandardDisplay {
    class controls {
        class POTATO_EscapeButton1: POTATO_EscapeButton_Base1{};
        class POTATO_EscapeButton2: POTATO_EscapeButton_Base2{};
    };
};
class RscDisplayInterruptEditorPreview: RscStandardDisplay {
    class controls {
        class POTATO_EscapeButton1: POTATO_EscapeButton_Base1{};
        class POTATO_EscapeButton2: POTATO_EscapeButton_Base2{};
    };
};

//define the main gui
class GVAR(adminMenuDialog) {
    idd = 6969;
    movingEnable = 1;
    enableSimulation = 1;
    enableDisplay = 1;
    onLoad = QUOTE(with uiNamespace do {GVAR(adminMenuDialog) = _this select 0;};);
    duration = 2147483647;
    fadein = 0;
    fadeout = 0;
    class controlsBackground {
        class RscPicturexxxxx: RscPicture {
            idc = -1;
            text = "#(argb,8,8,3)color(0,0,0,0.5)";
            x = QUOTE(0.2 * safezoneW + safezoneX);
            y = QUOTE(0.2 * safezoneH + safezoneY);
            w = QUOTE(0.7 * safezoneW);
            h = QUOTE(0.6 * safezoneH);
        };
        class RscFramexxxx: RscFrame {
            idc = -1;
            text = ""; //--- ToDo: Localize;
            x = QUOTE(0.2 * safezoneW + safezoneX);
            y = QUOTE(0.2 * safezoneH + safezoneY);
            w = QUOTE(0.7 * safezoneW);
            h = QUOTE(0.6 * safezoneH);
        };
        class RscText_1000: RscText {
            idc = -1;
            style = 2;
            text = "POTATO (from BourbonWarfare)"; //--- ToDo: Localize;
            x = QUOTE(0.2 * safezoneW + safezoneX);
            y = QUOTE(0.78 * safezoneH + safezoneY);
            w = QUOTE(0.13 * safezoneW);
            h = QUOTE(0.02 * safezoneH);
            sizeEx = QUOTE(0.01 * safezoneH);
        };
        class ServerMonitor: RscStructuredText {
            idc = 1102;
            text = "";
            x = QUOTE(0 * safezoneW + safezoneX);
            y = QUOTE(0 * safezoneH + safezoneY);
            w = QUOTE(0.2 * safezoneW);
            h = QUOTE(1 * safezoneH);
        };
    };
    class controls {
        class RscListbox_1500: RscListBox {
            idc = 1500;
            x = QUOTE(0.21 * safezoneW + safezoneX);
            y = QUOTE(0.205 * safezoneH + safezoneY);
            w = QUOTE(0.125 * safezoneW);
            h = QUOTE(0.58 * safezoneH);
            onLBSelChanged = QUOTE(_this call FUNC(uihook_tabChange));
        };
        class CONTROL_ZEUS: RscControlsGroup {
            idc = 2300;
            x = QUOTE(0.35 * safezoneW + safezoneX);
            y = QUOTE(0.205 * safezoneH + safezoneY);
            w = QUOTE(0.54 * safezoneW);
            h = QUOTE(0.58 * safezoneH);
            class controls {
                class RscCombo_2100: RscListBox {
                    idc = 2100;
                    x = QUOTE(0.01 * safezoneW);
                    y = QUOTE(0.01 * safezoneH);
                    w = QUOTE(0.2 * safezoneW);
                    h = QUOTE(0.56 * safezoneH);
                    sizeEx = QUOTE(0.025 * safezoneH);
                };
                class RscButton_160440: RscButton {
                    idc = -1;
                    text = "Toggle Zeus Control"; //--- ToDo: Localize;
                    x = QUOTE(0.22 * safezoneW);
                    y = QUOTE(0.01 * safezoneH);
                    w = QUOTE(0.27 * safezoneW);
                    h = QUOTE(0.05 * safezoneH);
                    action = QUOTE([] call FUNC(uihook_zeusConnectPlayer));
                };
            };
        };
        class CONTROL_ENDMISSION: RscControlsGroup {
            idc = 2303;
            x = QUOTE(0.35 * safezoneW + safezoneX);
            y = QUOTE(0.205 * safezoneH + safezoneY);
            w = QUOTE(0.54 * safezoneW);
            h = QUOTE(0.58 * safezoneH);
            class controls {
                class RscButton_unlockEnd: RscButton {
                    idc = 1101;
                    text = "Unlock"; //--- ToDo: Localize;
                    x = QUOTE(0.01 * safezoneW);
                    y = QUOTE(0.01 * safezoneH);
                    w = QUOTE(0.52 * safezoneW);
                    h = QUOTE(0.05 * safezoneH);
                    action = QUOTE([] call FUNC(uiHook_openEndMission));
                };
                class RscStructuredText_1100: RscStructuredText {
                    idc = 1100;
                    x = QUOTE(0.01 * safezoneW);
                    y = QUOTE(0.07 * safezoneH);
                    w = QUOTE(0.52 * safezoneW);
                    h = QUOTE(0.39 * safezoneH);
                };
                class RscButton_16055: RscButton {
                    idc = -1;
                    text = "West Victory"; //--- ToDo: Localize;
                    x = QUOTE(0.05 * safezoneW);
                    y = QUOTE(0.48 * safezoneH);
                    w = QUOTE(0.2 * safezoneW);
                    h = QUOTE(0.044 * safezoneH);
                    action = QUOTE([west] call FUNC(uihook_endMission));
                };
                class RscButton_1611: RscButton {
                    idc = -1;
                    text = "East Victory"; //--- ToDo: Localize;
                    x = QUOTE(0.25 * safezoneW);
                    y = QUOTE(0.48 * safezoneH);
                    w = QUOTE(0.2 * safezoneW);
                    h = QUOTE(0.044 * safezoneH);
                    action = QUOTE([east] call FUNC(uihook_endMission));
                };
                class RscButton_1612: RscButton {
                    idc = -1;
                    text = "Ind Victory"; //--- ToDo: Localize;
                    x = QUOTE(0.05 * safezoneW);
                    y = QUOTE(0.52 * safezoneH);
                    w = QUOTE(0.2 * safezoneW);
                    h = QUOTE(0.044 * safezoneH);
                    action = QUOTE([resistance] call FUNC(uihook_endMission));
                };
                class RscButton_1613: RscButton {
                    idc = -1;
                    text = "Civ Victory"; //--- ToDo: Localize;
                    x = QUOTE(0.25 * safezoneW);
                    y = QUOTE(0.52 * safezoneH);
                    w = QUOTE(0.2 * safezoneW);
                    h = QUOTE(0.044 * safezoneH);
                    action = QUOTE([civilian] call FUNC(uihook_endMission));
                };
            };
        };
        class CONTROL_SUPPLY: RscControlsGroup {
            idc = 2301;
            x = QUOTE(0.35 * safezoneW + safezoneX);
            y = QUOTE(0.205 * safezoneH + safezoneY);
            w = QUOTE(0.54 * safezoneW);
            h = QUOTE(0.58 * safezoneH);
            class controls {
                class RscCombo_21xx00: RscListBox {
                    idc = 2120;
                    x = QUOTE(0.01 * safezoneW);
                    y = QUOTE(0.01 * safezoneH);
                    w = QUOTE(0.2 * safezoneW);
                    h = QUOTE(0.56 * safezoneH);
                    sizeEx = QUOTE(0.025 * safezoneH);
                };
                class RscCombo_21xx01: RscListBox {
                    idc = 2121;
                    x = QUOTE(0.22 * safezoneW);
                    y = QUOTE(0.01 * safezoneH);
                    w = QUOTE(0.31 * safezoneW);
                    h = QUOTE(0.51 * safezoneH);
                    sizeEx = QUOTE(0.025 * safezoneH);
                };
                class RscButton_1xxx60055: RscButton {
                    idc = -1;
                    text = "Spawn Supplies"; //--- ToDo: Localize;
                    x = QUOTE(0.255 * safezoneW);
                    y = QUOTE(0.52 * safezoneH);
                    w = QUOTE(0.26 * safezoneW);
                    h = QUOTE(0.05 * safezoneH);
                    action = QUOTE([] call FUNC(uihook_supplySpawn));
                };
            };
        };
        class CONTROL_TELEPORT: RscControlsGroup {
            idc = 2302;
            x = QUOTE(0.35 * safezoneW + safezoneX);
            y = QUOTE(0.205 * safezoneH + safezoneY);
            w = QUOTE(0.54 * safezoneW);
            h = QUOTE(0.58 * safezoneH);
            class controls {
                class RscCombo_2100: RscListBox {
                    idc = 2130;
                    x = QUOTE(0.01 * safezoneW);
                    y = QUOTE(0.01 * safezoneH);
                    w = QUOTE(0.2 * safezoneW);
                    h = QUOTE(0.56 * safezoneH);
                    sizeEx = QUOTE(0.025 * safezoneH);
                };
                class RscCombo_2101: RscListBox {
                    idc = 2131;
                    x = QUOTE(0.22 * safezoneW);
                    y = QUOTE(0.01 * safezoneH);
                    w = QUOTE(0.31 * safezoneW);
                    h = QUOTE(0.51 * safezoneH);
                    sizeEx = QUOTE(0.025 * safezoneH);
                };
                class RscButton_160055: RscButton {
                    idc = -1;
                    text = "Move to Group"; //--- ToDo: Localize;
                    x = QUOTE(0.255 * safezoneW);
                    y = QUOTE(0.52 * safezoneH);
                    w = QUOTE(0.26 * safezoneW);
                    h = QUOTE(0.05 * safezoneH);
                    action = QUOTE([] call FUNC(uihook_teleportButton));
                };
            };
        };
        class CONTROL_SAFESTART: RscControlsGroup {
            idc = 2305;
            x = QUOTE(0.35 * safezoneW + safezoneX);
            y = QUOTE(0.205 * safezoneH + safezoneY);
            w = QUOTE(0.54 * safezoneW);
            h = QUOTE(0.58 * safezoneH);
            class controls {
                class RscButton_1605412: RscButton {
                    idc = -1;
                    text = "Turn ON (Make Safe)"; //--- ToDo: Localize;
                    x = QUOTE(0.01 * safezoneW);
                    y = QUOTE(0.01 * safezoneH);
                    w = QUOTE(0.52 * safezoneW);
                    h = QUOTE(0.05 * safezoneH);
                    action = QUOTE([true] call FUNC(uihook_safeStart));
                };
                class RscButton_164122223: RscButton {
                    idc = -1;
                    text = "Turn OFF (Start Mission)"; //--- ToDo: Localize;
                    x = QUOTE(0.01 * safezoneW);
                    y = QUOTE(0.08 * safezoneH);
                    w = QUOTE(0.52 * safezoneW);
                    h = QUOTE(0.05 * safezoneH);
                    action = QUOTE([false] call FUNC(uihook_safeStart));
                    tooltip = "Overrides Safe Start safety below"; //--- ToDo: Localize;
                };
                class ctrlCheckbox_2410720: ctrlCheckbox {
                    idc = -1;
                    checked = 0;
                    fade = 0.4;
                    onCheckedChanged = QUOTE((_this#0) cbSetChecked EGVAR(safeStart,safeStartForceEnd));
                    onLoad = QUOTE((_this#0) cbSetChecked EGVAR(safeStart,safeStartForceEnd));
                    tooltip = "Will the mission forcibly end the initial safe start after time expires"; //--- ToDo: Localize
                    soundClick[] = {};
                    soundEnter[] = {};
                    soundEscape[] = {};
                    soundPush[] = {};
                    x = QUOTE(0.08 * safezoneW);
                    y = QUOTE(0.16 * safezoneH);
                    w = QUOTE(0.016 * safezoneW);
                    h = QUOTE(0.028 * safezoneH);
                };
                class RscText_2410720: RscText {
                    idc = -1;
                    text = "Force end Safe Start once time elapses"; //--- ToDo: Localize
                    x = QUOTE(0.10 * safezoneW);
                    y = QUOTE(0.148 * safezoneH);
                    w = QUOTE(0.19 * safezoneW);
                    h = QUOTE(0.05 * safezoneH);
                };
                class DOUBLES(ctrlCheckbox,IDC_CHECKBOX_SAFESTARTSAFETY): ctrlCheckbox {
                    idc = IDC_CHECKBOX_SAFESTARTSAFETY;
                    checked = 0;
                    onCheckedChanged = QUOTE(_this call FUNC(uihook_checkboxes));
                    onLoad = QUOTE((_this#0) cbSetChecked EGVAR(safeStart,safeStartSafetyOn));
                    tooltip = "Should the mission be held in Safe Start even if time expires"; //--- ToDo: Localize
                    x = QUOTE(0.31 * safezoneW);
                    y = QUOTE(0.16 * safezoneH);
                    w = QUOTE(0.016 * safezoneW);
                    h = QUOTE(0.028 * safezoneH);
                };
                class RscText_2410071120: RscText {
                    idc = -1;
                    text = "Delay force end Safe Start"; //--- ToDo: Localize
                    x = QUOTE(0.33 * safezoneW);
                    y = QUOTE(0.148 * safezoneH);
                    w = QUOTE(0.14 * safezoneW);
                    h = QUOTE(0.05 * safezoneH);
                };
            };
        };
        class CONTROL_VERIFYMODS: RscControlsGroup {
            idc = 2306;
            x = QUOTE(0.35 * safezoneW + safezoneX);
            y = QUOTE(0.205 * safezoneH + safezoneY);
            w = QUOTE(0.54 * safezoneW);
            h = QUOTE(0.58 * safezoneH);
            class controls {
                class RscButton_1605412: RscButton {
                    idc = -1;
                    text = "Verify Mods (experimental, might lag)"; //--- ToDo: Localize;
                    x = QUOTE(0.01 * safezoneW);
                    y = QUOTE(0.01 * safezoneH);
                    w = QUOTE(0.52 * safezoneW);
                    h = QUOTE(0.05 * safezoneH);
                    action = QUOTE([] call FUNC(uihook_checkMods););
                };
                class RscButton_160055444: RscButton {
                    idc = -1;
                    text = "Weapons Test"; //--- ToDo: Localize;
                    x = QUOTE(0.01 * safezoneW);
                    y = QUOTE(0.08 * safezoneH);
                    w = QUOTE(0.52 * safezoneW);
                    h = QUOTE(0.05 * safezoneH);
                    action = QUOTE([] call FUNC(uihook_weaponTest));
                };
                class RscButton_MissionTesting: RscButton {
                    idc = -1;
                    text = "Enable Mission Checklist"; //--- ToDo: Localize;
                    x = QUOTE(0.01 * safezoneW);
                    y = QUOTE(0.15 * safezoneH);
                    w = QUOTE(0.52 * safezoneW);
                    h = QUOTE(0.05 * safezoneH);
                    action = QUOTE([] call FUNC(uihook_enableMissionTesting));
                };
            };
        };
        class CONTROL_MISSIONHINT: RscControlsGroup {
            idc = 2307;
            x = QUOTE(0.35 * safezoneW + safezoneX);
            y = QUOTE(0.205 * safezoneH + safezoneY);
            w = QUOTE(0.54 * safezoneW);
            h = QUOTE(0.58 * safezoneH);
            class controls {
                class RscCombo_side: RscListBox {
                    idc = 23071;
                    x = QUOTE(0.01 * safezoneW);
                    y = QUOTE(0.01 * safezoneH);
                    w = QUOTE(0.3 * safezoneW);
                    h = QUOTE(0.2 * safezoneH);
                    sizeEx = QUOTE(0.02 * safezoneH);
                };
                class RscCombo_rank: RscListBox {
                    idc = 23072;
                    x = QUOTE(0.32 * safezoneW);
                    y = QUOTE(0.01 * safezoneH);
                    w = QUOTE(0.21 * safezoneW);
                    h = QUOTE(0.2 * safezoneH);
                    sizeEx = QUOTE(0.02 * safezoneH);
                };
                class RscEdit_textInput: RscEdit {
                    idc = 23073;
                    x = QUOTE(0.01 * safezoneW);
                    y = QUOTE(0.22 * safezoneH);
                    w = QUOTE(0.52 * safezoneW);
                    h = QUOTE(0.29 * safezoneH);
                    sizeEx = QUOTE(0.02 * safezoneH);
                };
                class RscButton_1605412: RscButton {
                    idc = -1;
                    text = "Send Hint";
                    x = QUOTE(0.01 * safezoneW);
                    y = QUOTE(0.52 * safezoneH);
                    w = QUOTE(0.52 * safezoneW);
                    h = QUOTE(0.05 * safezoneH);
                    action = QUOTE([] call FUNC(uihook_missionHint););
                };
            };
        };
        class CONTROL_FIX_UNITS: RscControlsGroup {
            idc = 2308;
            x = QUOTE(0.35 * safezoneW + safezoneX);
            y = QUOTE(0.205 * safezoneH + safezoneY);
            w = QUOTE(0.54 * safezoneW);
            h = QUOTE(0.58 * safezoneH);
            class controls {
                class PlayerList: RscListBox {
                    idc = 2180;
                    x = QUOTE(0.01 * safezoneW);
                    y = QUOTE(0.01 * safezoneH);
                    w = QUOTE(0.2 * safezoneW);
                    h = QUOTE(0.56 * safezoneH);
                    sizeEx = QUOTE(0.025 * safezoneH);
                };
                class ResetGearButton: RscButton {
                    idc = -1;
                    text = "Reset Gear";
                    x = QUOTE(0.255 * safezoneW);
                    y = QUOTE(0.52 * safezoneH);
                    w = QUOTE(0.125 * safezoneW);
                    h = QUOTE(0.05 * safezoneH);
                    action = QUOTE([] call FUNC(uihook_resetGearButton));
                };
                class ResetGearList: RscCombo {
                    idc = 2181;
                    x = QUOTE(0.387 * safezoneW);
                    y = QUOTE(0.52 * safezoneH);
                    w = QUOTE(0.12 * safezoneW);
                    h = QUOTE(0.05 * safezoneH);
                };
                class ResetSpectatorButton: RscButton {
                    idc = -1;
                    text = "Reset Spectator";
                    x = QUOTE(0.255 * safezoneW);
                    y = QUOTE(0.42 * safezoneH);
                    w = QUOTE(0.26 * safezoneW);
                    h = QUOTE(0.05 * safezoneH);
                    action = QUOTE([] call FUNC(uihook_resetSpectateButton));
                };
                class ResetMedicalButton: RscButton {
                    idc = -1;
                    text = "Reset Medical (Full Heal)";
                    x = QUOTE(0.255 * safezoneW);
                    y = QUOTE(0.22 * safezoneH);
                    w = QUOTE(0.26 * safezoneW);
                    h = QUOTE(0.05 * safezoneH);
                    action = QUOTE([] call FUNC(uihook_resetMedicalButton));
                };
                class ResetMarkersButton: RscButton {
                    idc = -1;
                    text = "Backup - Reset Markers";
                    x = QUOTE(0.255 * safezoneW);
                    y = QUOTE(0.32 * safezoneH);
                    w = QUOTE(0.26 * safezoneW);
                    h = QUOTE(0.05 * safezoneH);
                    action = QUOTE([] call FUNC(uihook_resetMarkersButton));
                };
            };
        };
        class CONTROL_GIVE_ITEMS: RscControlsGroup {
            idc = 2309;
            x = QUOTE(0.35 * safezoneW + safezoneX);
            y = QUOTE(0.205 * safezoneH + safezoneY);
            w = QUOTE(0.54 * safezoneW);
            h = QUOTE(0.58 * safezoneH);
            class controls {
                class GiveAdminGun: RscButton {
                    idc = -1;
                    text = "Give Admin Gun"; //--- ToDo: Localize;
                    x = QUOTE(0.01 * safezoneW);
                    y = QUOTE(0.01 * safezoneH);
                    w = QUOTE(0.52 * safezoneW);
                    h = QUOTE(0.05 * safezoneH);
                    action = QUOTE([] call FUNC(uihook_giveAdminGun));
                };
            };
        };
        class CONTROL_MARKERS: RscControlsGroup {
            idc = 2310;
            x = QUOTE(0.35 * safezoneW + safezoneX);
            y = QUOTE(0.205 * safezoneH + safezoneY);
            w = QUOTE(0.54 * safezoneW);
            h = QUOTE(0.58 * safezoneH);
            class controls {
                class GiveAdminGun: RscButton {
                    idc = -1;
                    text = "Give Admin Gun";
                    x = QUOTE(0.01 * safezoneW);
                    y = QUOTE(0.01 * safezoneH);
                    w = QUOTE(0.52 * safezoneW);
                    h = QUOTE(0.05 * safezoneH);
                    action = QUOTE([] call FUNC(uihook_giveAdminGun));
                };
            };
        };
    };
};
