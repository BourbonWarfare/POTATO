class RscPicture;
class RscFrame;
class RscText;
class RscListbox;
class RscControlsGroup;
class RscCombo;
class RscButton;
class RscStructuredText;
class RscButtonMenu;
class RscEdit;
class RscShortcutButton;
class RscActiveText;

class RscStandardDisplay;

// Add Text to escape menu (borowed from AGM)

//borowed from CBA, mouse trap, blocks screen until disabled onMouseEnter (automatic)
class GVAR(mouseCatch): RscActiveText {
    style = 48;
    idc = -1; //template
    x = safezoneX;
    y = safezoneY;
    w = safezoneX + safezoneW;
    h = safezoneY + safezoneH;
    text = "#(argb,8,8,3)color(1,0,0,0)";
    onMouseEnter = QUOTE((_this select 0) ctrlEnable false; (_this select 0) ctrlShow false; _this call FUNC(mouseCatch););
};
class GVAR(background): RscPicture {
    idc = -1;
    text = "#(argb,8,8,3)color(0,0,0,0.7)";
    x = "1 * (((safezoneW / safezoneH) min 1.2) / 40) + safezoneX";
    y = "3.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + safezoneY";
    w = "15 * (((safezoneW / safezoneH) min 1.2) / 40)";
    h = "1.2 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
};
class GVAR(textInput): RscEdit {
    idc = 840430;
    x = "1.1 * (((safezoneW / safezoneH) min 1.2) / 40) + safezoneX";
    y = "3.6 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + safezoneY";
    w = "14.8 * (((safezoneW / safezoneH) min 1.2) / 40)";
    h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
    sizeEx = "0.7 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
    colorBackground[] = {0,0,0,0};
    colorText[] = {0.95, 0.95, 0.95, 1};
    font = "EtelkaMonospacePro";
};
class GVAR(sendMessageToAdmin): RscButtonMenu {
    text = "MSG Admins";
    tooltip = "Send message to all admins (for teleport, something broke, or mission conditions changed)";
    x = "8.5 * (((safezoneW / safezoneH) min 1.2) / 40) + safezoneX";
    y = "4.9 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + safezoneY";
    w = "7.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
    h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
    action = QUOTE([] spawn FUNC(sendMessageToAdmin););
};
class GVAR(chatList): RscListbox {
    idc = 840431;
    x = "1 * (((safezoneW / safezoneH) min 1.2) / 40) + safezoneX";
    y = "6 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + safezoneY";
    w = "15 * (((safezoneW / safezoneH) min 1.2) / 40)";
    h = "5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
    sizeEx = "0.0175 * safeZoneH";
    font = "EtelkaMonospacePro";
    onLBSelChanged = QUOTE(_this call FUNC(logListBoxChanged););
};
class GVAR(sendMessageToUser): RscButtonMenu {
    idc = 840432;
    text = "Reply: ";
    tooltip = "Select a message in the log to replay to that user";
    x = "1 * (((safezoneW / safezoneH) min 1.2) / 40) + safezoneX";
    y = "4.9 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + safezoneY";
    w = "7.4 * (((safezoneW / safezoneH) min 1.2) / 40)";
    h = "1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
    sizeEx = "0.0175 * safeZoneH";
    size = "0.0175 * safeZoneH";
    action = QUOTE([] spawn FUNC(sendMessageToUser););
};

class RscDisplayMPInterrupt: RscStandardDisplay {
    class controls {
        class GVAR(background): GVAR(background) {};
        class GVAR(textInput): GVAR(textInput) {};
        class GVAR(sendMessageToAdmin): GVAR(sendMessageToAdmin) {};
        class GVAR(sendMessageToUser): GVAR(sendMessageToUser) {};
        class GVAR(chatList): GVAR(chatList) {};
        class GVAR(mouseCatch): GVAR(mouseCatch) {};
    };
};
class RscDisplayInterrupt: RscStandardDisplay {
    class controls {
        class GVAR(background): GVAR(background) {};
        class GVAR(textInput): GVAR(textInput) {};
        class GVAR(chatList): GVAR(chatList) {};
        class GVAR(mouseCatch): GVAR(mouseCatch) {};
        class GVAR(sendMessageToAdmin): GVAR(sendMessageToAdmin) {};
        class GVAR(sendMessageToUser): GVAR(sendMessageToUser) {};
    };
};
class RscDisplayInterruptEditor3D: RscStandardDisplay {
    class controls {
        class GVAR(background): GVAR(background) {};
        class GVAR(textInput): GVAR(textInput) {};
        class GVAR(sendMessageToAdmin): GVAR(sendMessageToAdmin) {};
        class GVAR(sendMessageToUser): GVAR(sendMessageToUser) {};
        class GVAR(chatList): GVAR(chatList) {};
        class GVAR(mouseCatch): GVAR(mouseCatch) {};
    };
};
class RscDisplayInterruptEditorPreview: RscStandardDisplay {
    class controls {
        class GVAR(background): GVAR(background) {};
        class GVAR(textInput): GVAR(textInput) {};
        class GVAR(sendMessageToAdmin): GVAR(sendMessageToAdmin){};
        class GVAR(sendMessageToUser): GVAR(sendMessageToUser) {};
        class GVAR(chatList): GVAR(chatList) {};
        class GVAR(mouseCatch): GVAR(mouseCatch) {};
    };
};
