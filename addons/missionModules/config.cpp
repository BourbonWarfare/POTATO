#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {QGVAR(test), QGVAR(sideMarker)};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core"};
        author[] = {"PabstMirror"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"

class RscControlsGroupNoScrollbars;
class RscText;
class RscListbox;
class RscEdit;

class RscDisplayAttributes {
    class Controls {
        class Background;
        class Title;
        class Content;
        class ButtonOK;
        class ButtonCancel;
    };
};
class GVAR(RscDisplayAttributes_missionHint): RscDisplayAttributes {
    // scriptName = "RscDisplayAttributesModuleEndMission";
    // scriptPath = "CuratorDisplays";
    onLoad = QUOTE([ARR_3('onLoad', _this, QUOTE(QGVAR(RscDisplayAttributes_missionHint)))] call FUNC(zeusAttributes));
    onUnload = QUOTE([ARR_3('onUnload', _this, QUOTE(QGVAR(RscDisplayAttributes_missionHint)))] call FUNC(zeusAttributes));
    class Controls: Controls {
        class Background: Background {};
        class Title: Title {};
        class Content: Content {
            class Controls {
                class missionHintAttributes: RscControlsGroupNoScrollbars {
                    onSetFocus = QUOTE(_this call FUNC(zeusAttributes_missionHint));
                    idc = 26422;
                    x = "0";
                    y = "0";
                    w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
                    h = "9 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                    class controls {
                        class RscCombo_side: RscListbox {
                            idc = 23071;
                            x = "0.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
                            y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                            w = "12 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
                            h = "7 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                        };
                        class RscCombo_rank: RscListbox {
                            idc = 23072;
                            x = "13.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
                            y = "0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                            w = "12 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
                            h = "7 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                        };
                        class RscEdit_textInput: RscEdit {
                            idc = 23073;
                            x = "0.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
                            y = "7.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                            w = "26 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
                            h = "1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
                        };
                    };
                };
            };
        };
        class ButtonOK: ButtonOK {};
        class ButtonCancel: ButtonCancel {};
    };
};
