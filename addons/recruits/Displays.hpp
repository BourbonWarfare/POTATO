class RscStructuredText;

//Safe Start Overlay:
class RscTitles {
    class GVAR(message) {
        idd = -1;
        onLoad = QUOTE(with uiNamespace do { GVAR(message) = _this select 0; };);
        movingEnable = 0;
        duration = 2147483647;
        fadeIn = 0.5;
        fadeOut = 0.5;
        name = QGVAR(message);

        class controls {
            class GVAR(message): RscStructuredText {
                idc = MESSAGE_IDC;
                colorText[] = {1, 1, 1, 1};
                colorBackground[] = {0, 0, 0, 0.5};
                x = QUOTE(0.88 * safezoneW + safezoneX);
                y = QUOTE(0.15 * safezoneH + safezoneY);
                w = QUOTE(0.105 * safezoneW);
                h = 0;
                font = "RobotoCondensed";
            };
        };
    };
};



class RscButton;
class RscStandardDisplay;
class RscDisplayLogin: RscStandardDisplay {
	class controls {
        class CopyName: RscButton {
            colorBackground[] = {1,0,0,0.1};
            colorBackgroundActive[] = {1,0,0,0.2};
            text = "Copy Name";
            tooltip = "Copies your profile name";
            onButtonClick = "copyToClipboard profileName;";
			x="(22+18) * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y="4.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w="3.95 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
        };
        class CopyID: RscButton {
            colorBackground[] = {0,1,0,0.1};
            colorBackgroundActive[] = {0,1,0,0.2};
            text = "Copy ID";
            tooltip = "Copies your ArmA player ID (steam id)";
            onButtonClick = "private _display = ctrlParent (_this select 0); private _valuePlayerID = _display displayCtrl 111; copyToClipboard ctrlText _valuePlayerID;";
			x="(22+18+4.05) * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y="4.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w="3.95 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
        };
        class PasteBW: RscButton {
            colorBackground[] = {0,0,1,0.1};
            colorBackgroundActive[] = {0,0,1,0.2};
            text = "< - Insert BW URL";
            tooltip = "Auto Paste BW's URL into the squad box\n1. Click Unit Tab\n2. Hit Edit button\n3. Set Unit: Custom\n4. Click this button\n5. Hit Apply";
            onButtonClick = "private _display = ctrlParent (_this select 0); private _squad = _display displayCtrl 112; _squad ctrlSetText 'https://squad.bourbonwarfare.com';";
			x="(22+18) * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y="5.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w="8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
        };
    };
};
