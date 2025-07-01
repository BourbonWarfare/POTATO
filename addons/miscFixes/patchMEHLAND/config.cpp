#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchMEHLAND

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "mehland", "rnc_main", "rnc_misc" }; // mehland and Really Useless Objects Pack
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

// fix broken XEH
class CfgVehicles {
    class thing;
    class Rnc_Particle_BigFire_F: thing { XEH_ENABLED; }; // "" 2954960408
};

// try to fix main menu being violated
class RscActivePictureKeepAspect;
class RscButton;
class RscPicture;
class RscPictureKeepAspect;
class RscStandardDisplay;
class RscStructuredText;
class RscText;
class RscVideo;

class RscControlsGroup;
class RscControlsGroupNoScrollbars: RscControlsGroup {};
class RscMainMenuSpotlight: RscControlsGroupNoScrollbars {
    class Controls {
        class Button: RscButton {};
        class GroupHover: RscControlsGroupNoScrollbars {
            class Controls {
                class LineLeft: RscText {};
                class LineRight: LineLeft {};
                class LineTop: LineLeft {};
                class LineBottomn: LineTop {};
                class Overlay: RscPicture {};
            };
        };
        class GroupPicture: RscControlsGroupNoScrollbars {
            class Controls {
                class Picture: RscPictureKeepAspect {};
                class Video: RscVideo {};
            };
        };
        class Text: RscStructuredText {};
        class TextBackground: RscPicture {};
    };
};

class RscDisplayMain: RscStandardDisplay {
    enableDisplay = 1;
    class controls {
        class BackgroundSpotlight: RscPicture {
            text = "#(argb,8,8,3)color(1,1,1,1)";
            colorText[] = {0,0,0,0.9};
            x = "0.5 - (1.5 * 10) * (pixelW * pixelGridNoUIScale * 2) - 2 * (2 * pixelW)";
            y = "0.5 - ( 10 / 2) * (pixelH * pixelGridNoUIScale * 2) - (2 * pixelH)";
            w = "3 * 10 * (pixelW * pixelGridNoUIScale * 2) + 4 * (2 * pixelW)";
            h = "( 10) * (pixelH * pixelGridNoUIScale * 2) + 2 * (2 * pixelH)";
        };
        class BackgroundSpotlightLeft: BackgroundSpotlight {
            text = "\a3\Ui_f\data\GUI\Rsc\RscDisplayMain\gradient_ca.paa";
            angle = 180;
            x = "safezoneX";
            w = "(safezoneW - (3 * 10 * (pixelW * pixelGridNoUIScale * 2) + 4 * (2 * pixelW))) / 2";
        };
        class BackgroundSpotlightRight: BackgroundSpotlightLeft {
            text = "\a3\Ui_f\data\GUI\Rsc\RscDisplayMain\gradient_ca.paa";
            angle = 0;
            x = "0.5 + (1.5 * 10) * (pixelW * pixelGridNoUIScale * 2) + 2 * (2 * pixelW)";
        };
        class Spotlight1: RscMainMenuSpotlight {
            idc = 1021;
            x = "0.5 - (1.5 * 10) * (pixelW * pixelGridNoUIScale * 2) - (2 * pixelW)";
            class Controls: Controls {
                class GroupPicture: GroupPicture {
                    class Controls: Controls {
                        class Picture: Picture {
                            text = "\a3\Ui_f\data\GUI\Rsc\RscDisplayMain\spotlight_2_ca.paa";
                        };
                        class Video: Video {
                            text = "\a3\Ui_f\Video\spotlight_2.ogv";
                        };
                    };
                };
                class GroupHover: GroupHover {
                    class Controls: Controls {
                        class Overlay;
                        class LineLeft: LineLeft {};
                        class LineRight;
                        class LineTop: LineTop {
                            text = "$STR_A3_RSCDISPLAYMAIN_SPOTLIGHT_OPEN";
                        };
                        class LineBottom;
                    };
                };
                class TextBackground: TextBackground {};
                class Text: Text {
                    text = "$STR_A3_RSCDISPLAYMAIN_GROUPMULTIPLAYER_QUICKPLAY_TEXT";
                };
                class Button: Button {};
            };
        };
        class Spotlight3: RscMainMenuSpotlight {
            idc = 1022;
            x = "0.5 + (0.5 * 10) * (pixelW * pixelGridNoUIScale * 2) + (2 * pixelW)";
            class Controls: Controls {
                class GroupPicture: GroupPicture {
                    class Controls: Controls {
                        class Picture: Picture {
                            text = "\a3\Ui_f\data\GUI\Rsc\RscDisplayMain\spotlight_3_ca.paa";
                        };
                        class Video: Video {
                            text = "\a3\Ui_f\Video\spotlight3.ogv";
                        };
                    };
                };
                class GroupHover: GroupHover {
                    class Controls: Controls {
                        class LineLeft: LineLeft {};
                        class LineTop: LineTop {
                            text = "$STR_A3_RSCDISPLAYMAIN_SPOTLIGHT_CREATE";
                        };
                    };
                };
                class Text: Text {
                    text = "$STR_A3_RSCDISPLAYMAIN_BUTTONEDITOR";
                };
                class TextBackground: TextBackground {};
                class Button: Button {};
            };
        };
        class SpotlightPrev: RscActivePictureKeepAspect {
            idc = 1060;
            text = "\a3\Ui_f\data\GUI\Rsc\RscDisplayMain\spotlightPrev_ca.paa";
            color[] = {1,1,1,0.25};
            fade = 1;
            x = "0.5 - (0.5 * 10) * (pixelW * pixelGridNoUIScale * 2)";
            y = "0.5 - ( 10 / 2 + ( 10 / 8)) * (pixelH * pixelGridNoUIScale * 2)";
            w = "10 * (pixelW * pixelGridNoUIScale * 2)";
            h = "( 10 / 8) * (pixelH * pixelGridNoUIScale * 2)";
        };
        class SpotlightNext: SpotlightPrev {
            idc = 1061;
            text = "\a3\Ui_f\data\GUI\Rsc\RscDisplayMain\spotlightNext_ca.paa";
            y = "0.5 + ( 10 / 2) * (pixelH * pixelGridNoUIScale * 2)";
            angle = 180;
        };
        class Spotlight2: RscText {
            idc = 1020;
            x = "0.5 - (0.5 * 10) * (pixelW * pixelGridNoUIScale * 2)";
            y = "0.5 - ( 10 / 2) * (pixelH * pixelGridNoUIScale * 2)";
            w = "10 * (pixelW * pixelGridNoUIScale * 2)";
            h = "10 * (pixelH * pixelGridNoUIScale * 2)";
            show = 0;
        };
    };
    class ControlsBackground {
        class MouseArea: RscText {
            idc = 999;
            style = 16;
            x = "safezoneXAbs";
            y = "safezoneY";
            w = "safezoneWAbs";
            h = "safezoneH";
        };
    };
};
