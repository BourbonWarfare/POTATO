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
class RscActiveText;

class RscStandardDisplay;

// Add Text to escape menu (borowed from AGM)

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
class GVAR(chatList): RscListBox {
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
    tooltip = "Select a message in the log to reply to that user";
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
    };
};
class RscDisplayInterrupt: RscStandardDisplay {
    class controls {
        class GVAR(background): GVAR(background) {};
        class GVAR(textInput): GVAR(textInput) {};
        class GVAR(chatList): GVAR(chatList) {};
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
    };
};
class RscDisplayInterruptEditorPreview: RscStandardDisplay {
    class controls {
        class GVAR(background): GVAR(background) {};
        class GVAR(textInput): GVAR(textInput) {};
        class GVAR(sendMessageToAdmin): GVAR(sendMessageToAdmin){};
        class GVAR(sendMessageToUser): GVAR(sendMessageToUser) {};
        class GVAR(chatList): GVAR(chatList) {};
    };
};
