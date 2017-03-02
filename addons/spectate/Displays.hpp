#define XFACTOR (((safeZoneW / safeZoneH) min 1.2) / 40)
#define XOFFSET (safeZoneX + (safeZoneW - ((safeZoneW / safeZoneH) min 1.2)) / 2)
#define YFACTOR ((((safeZoneW / safeZoneH) min 1.2) / 1.2) / 25)
#define YOFFSET (safeZoneY + (safeZoneH - (((safeZoneW / safeZoneH) min 1.2) / 1.2)) / 2)

class RscText;
class RscTree;
class RscButton;
class RscPicture;
class RscMapControl;
class RscControlsGroup;
class RscStructuredText;
class RscPictureKeepAspect;
class RscControlsGroupNoScrollbars;

class GVAR(overlay) {
    idd = OVERLAY_IDD;

    enableSimulation = 1;
    movingEnable = 0;
    closeOnMissionEnd = 1;

    onKeyDown = QUOTE(_this call FUNC(ui_handleKeyDown));
    onMouseMoving = QUOTE(_this call FUNC(ui_handleMouseMoving));
    onChildDestroyed = QUOTE(_this call FUNC(ui_checkToClose));

    class ControlsBackground {
        class MouseHandler: RscText {
            idc = MOUSE_IDC;

            onMouseZChanged = QUOTE(_this call FUNC(ui_handleMouseZ));
            onMouseButtonUp = QUOTE(_this call FUNC(ui_handleMouseUp));
            onMouseButtonDown = QUOTE(_this call FUNC(ui_handleMouseDown));
            onMouseButtonDblClick = QUOTE(_this call FUNC(ui_handleMouseDoubleClick));

            x = "safeZoneXAbs";
            y = "safeZoneY";
            w = "safeZoneWAbs";
            h = "safeZoneH";

            text = "";
            colorBackground[] = {1,1,1,0};
            style = 16;
        };
    };

    class Controls {
        class GameTimeText: RscText {
            idc = TIMER_IDC;

            x = QUOTE(16 * XFACTOR + XOFFSET);
            y = QUOTE(0 * YFACTOR + safeZoneY);
            w = QUOTE(8 * XFACTOR);
            h = QUOTE(1.5 * YFACTOR);

            style = 2;
            text = "00:00:00";
            colorBackground[] = {0,0,0,0.75};
            sizeEx = QUOTE(1.0 * YFACTOR);
        };
        class List: RscTree {
            idc = LIST_IDC;

            onMouseExit = QUOTE([false] call FUNC(ui_showList));
            onMouseEnter = QUOTE([true] call FUNC(ui_showList));
            onTreeSelChanged = QUOTE(_this call FUNC(ui_handleListClick));

            x = "safeZoneX";
            y = "safeZoneY";
            w = QUOTE(13.5 * XFACTOR);
            h = "safeZoneH";

            multiselectEnabled = 0;
            colorBorder[] = {0,0,0,0};
            colorBackground[] = {0,0,0,0.75};
            expandOnDoubleclick = 1;
            fade = 0.8;
            shadow = 1;
            colorLines[] = {0,0,0,0};

            class ScrollBar {
                width = 0;
                height = 0;
                scrollSpeed = 0.1;
                color[] = {1,1,1,0};
            };
        };
        class CameraTypesGroup: RscControlsGroupNoScrollbars {
            idc = CAM_GROUP_IDC;

            x = QUOTE(15.5 * XFACTOR + XOFFSET);
            y = QUOTE(safeZoneY + safeZoneH - 2.38 * YFACTOR);
            w = QUOTE(8.6 * XFACTOR);
            h = 2.6;

            class controls {
                class CameraTypesBackground: RscText {
                    idc = CAM_BG_IDC;

                    x = QUOTE(0.6 * XFACTOR);
                    y = QUOTE(0.4 * YFACTOR);
                    w = QUOTE(7.5 * XFACTOR);
                    h = QUOTE(2 * YFACTOR);

                    colorBackground[] = {0,0,0,0.75};
                };
                class Free: RscButton {
                    idc = CAM_FREE_IDC;

                    onButtonClick = QUOTE([FREE_CAMERA] call FUNC(ui_changeCamera));

                    x = QUOTE(1.3 * XFACTOR);
                    y = QUOTE(0.8 * YFACTOR);
                    w = QUOTE(1.63 * XFACTOR);
                    h = QUOTE(1.37 * YFACTOR);

                    text = CAM_ICON_FREE_SELECTED;
                    tooltip = "$STR_A3_Spectator_free_camera_tooltip";

                    style = 48;
                    colorBackground[] = {0,0,0,0};
                    colorBackgroundDisabled[] = {0,0,0,0};
                    colorBackgroundActive[] = {0,0,0,0};
                    colorFocused[] = {0,0,0,0};
                };
                class Third: RscButton {
                    idc = CAM_THIRD_IDC;

                    onButtonClick = QUOTE([THIRD_PERSON] call FUNC(ui_changeCamera));

                    x = QUOTE(3.6 * XFACTOR);
                    y = QUOTE(0.8 * YFACTOR);
                    w = QUOTE(1.63 * XFACTOR);
                    h = QUOTE(1.37 * YFACTOR);

                    text = CAM_ICON_THIRD;
                    tooltip = "$STR_A3_Spectator_3pp_camera_tooltip";

                    style = 48;
                    colorBackground[] = {0,0,0,0};
                    colorBackgroundDisabled[] = {0,0,0,0};
                    colorBackgroundActive[] = {0,0,0,0};
                    colorFocused[] = {0,0,0,0};
                };
                class First: RscButton {
                    idc = CAM_FIRST_IDC;

                    onButtonClick = QUOTE([FIRST_PERSON] call FUNC(ui_changeCamera));

                    x = QUOTE(5.8 * XFACTOR);
                    y = QUOTE(0.8 * YFACTOR);
                    w = QUOTE(1.63 * XFACTOR);
                    h = QUOTE(1.37 * YFACTOR);

                    text = CAM_ICON_FIRST;
                    tooltip = "$STR_A3_Spectator_1pp_camera_tooltip";

                    style = 48;
                    colorBackground[] = {0,0,0,0};
                    colorBackgroundDisabled[] = {0,0,0,0};
                    colorBackgroundActive[] = {0,0,0,0};
                    colorFocused[] = {0,0,0,0};
                };
            };
        };
        class MapGroup: RscControlsGroupNoScrollbars {
            idc = MAP_GROUP_IDC;

            x = QUOTE(-0.8 * XFACTOR + XOFFSET);
            y = QUOTE(-0.8 * YFACTOR + YOFFSET);
            w = QUOTE(41.5962 * XFACTOR);
            h = QUOTE(26.7 * YFACTOR);

            class controls {
                class Map: RscMapControl {
                    idc = MAP_IDC;

                    onDraw = QUOTE(_this call FUNC(ui_handleMapDraw));
                    onMouseButtonClick = QUOTE(_this call FUNC(ui_handleMapClick));

                    x = QUOTE(-3.36 * XFACTOR);
                    y = QUOTE(1.3 * YFACTOR);
                    w = QUOTE(40.0 * XFACTOR);
                    h = QUOTE(22.4 * YFACTOR);

                    maxSatelliteAlpha = 0.75;
                    colorBackground[] = {1,1,1,1};
                };
                class MapHeader: RscText {
                    idc = MAP_HEADER_IDC;

                    x = QUOTE(0.8 * XFACTOR);
                    y = QUOTE(0.8 * YFACTOR);
                    w = QUOTE(40 * XFACTOR);
                    h = QUOTE(1.3 * YFACTOR);

                    colorBackground[] = {0,0,0,0.75};
                };
                class MapFooter: RscText {
                    idc = MAP_FOOTER_IDC;

                    x = QUOTE(0.8 * XFACTOR);
                    y = QUOTE(24.5 * YFACTOR);
                    w = QUOTE(40 * XFACTOR);
                    h = QUOTE(1.3 * YFACTOR);

                    text = "";

                    style = 2;
                    colorBackground[] = {0,0,0,0.75};
                    sizeEx = QUOTE(1.0 * YFACTOR);
                };
                class MapTitle: RscText {
                    idc = MAP_TITLE_IDC;

                    x = QUOTE(1.1 * XFACTOR);
                    y = QUOTE(0.9 * YFACTOR);
                    w = QUOTE(36.5 * XFACTOR);
                    h = QUOTE(1.1 * YFACTOR);

                    text = "";

                    colorText[] = {1,1,1,1};
                    sizeEx = QUOTE(1.0 * YFACTOR);
                };
                class SpectatorsCount: RscText {
                    idc = MAP_SPEC_COUNT_IDC;

                    x = QUOTE(39.1 * XFACTOR);
                    y = QUOTE(0.9 * YFACTOR);
                    w = QUOTE(1.6 * XFACTOR);
                    h = QUOTE(1.1 * YFACTOR);

                    text = "";

                    colorText[] = {1,1,1,1};
                    sizeEx = QUOTE(1.0 * YFACTOR);
                };
                class SpectatorsIcon: RscPictureKeepAspect {
                    idc = MAP_SPEC_ICON_IDC;

                    x = QUOTE(37.9 * XFACTOR);
                    y = QUOTE(1.1 * YFACTOR);
                    w = QUOTE(0.9 * XFACTOR);
                    h = QUOTE(0.8 * YFACTOR);

                    text = CAM_ICON_FIRST;
                };
            };
        };
        class FocusInfo: RscControlsGroupNoScrollbars {
            idc = FOCUS_GROUP_IDC;

            x = QUOTE(12.1 * XFACTOR + XOFFSET);
            y = QUOTE(24 * YFACTOR + YOFFSET);
            w = QUOTE(16 * XFACTOR);
            h = QUOTE(5.5 * YFACTOR);

            class controls {
                class UpperBackground: RscText {
                    idc = FOCUS_UP_BG_IDC;

                    x = QUOTE(3.5 * XFACTOR);
                    y = QUOTE(0 * YFACTOR);
                    w = QUOTE(12.4 * XFACTOR);
                    h = QUOTE(1.4 * YFACTOR);

                    colorBackground[] = {0,0,0,0.75};
                };
                class LowerBackground: RscText {
                    idc = FOCUS_DOWN_BG_IDC;

                    x = QUOTE(3.5 * XFACTOR);
                    y = QUOTE(1.5 * YFACTOR);
                    w = QUOTE(12.4 * XFACTOR);
                    h = QUOTE(4 * YFACTOR);

                    colorBackground[] = {0,0,0,0.75};
                };
                class VehicleType: RscPicture {
                    idc = FOCUS_VEHICLE_IDC;

                    x = QUOTE(13.5 * XFACTOR);
                    y = QUOTE(0.3 * YFACTOR);
                    w = QUOTE(2.1 * XFACTOR);
                    h = QUOTE(1 * YFACTOR);

                    text = "\A3\ui_f\data\map\vehicleicons\iconMan_ca.paa";
                };
                class UnitType: RscPictureKeepAspect {
                    idc = FOCUS_UNIT_IDC;

                    x = QUOTE(14.6 * XFACTOR);
                    y = QUOTE(0.3 * YFACTOR);
                    w = QUOTE(1 * XFACTOR);
                    h = QUOTE(1 * YFACTOR);

                    text = "\A3\ui_f\data\map\vehicleicons\iconMan_ca.paa";
                };
                class Name: RscText {
                    idc = FOCUS_NAME_IDC;

                    x = QUOTE(3.6 * XFACTOR);
                    y = QUOTE(0 * YFACTOR);
                    w = QUOTE(9.9 * XFACTOR);
                    h = QUOTE(1.4 * YFACTOR);

                    text = "";

                    shadow = 0;
                    sizeEx = QUOTE(1 * YFACTOR);
                };
                class KillCG: RscControlsGroup {
                    idc = FOCUS_KILL_CG_IDC;

                    x = QUOTE(3.5 * XFACTOR);
                    y = QUOTE(1.5 * YFACTOR);
                    w = QUOTE(12.4 * XFACTOR);
                    h = QUOTE(4 * YFACTOR);

                    class controls {
                        class Kill: RscStructuredText {
                            idc = FOCUS_KILL_IDC;

                            x = QUOTE(0 * XFACTOR);
                            y = QUOTE(0 * YFACTOR);
                            w = QUOTE(12 * XFACTOR);
                            h = QUOTE(10 * YFACTOR);

                            shadow = 0;
                        };
                    };
                };
            };
        };
        class RespawnButton: RscButton {
            idc = RESPAWN_IDC;

            onButtonClick = QUOTE([] spawn EFUNC(respawn,openClientRespawn));

            x = safezoneX + safezoneW - 0.2;
            y = safezoneY + safezoneH - 0.08;
            w = 0.2;
            h = 0.08;

            text = "Open Respawn";
            colorBackground[] = {0,0,0,0.5};
            sizeEx = QUOTE(1.0 * YFACTOR);
        };
        class HelpText: RscStructuredText {
            idc = HELP_IDC;

            x = 0.25;
            y = 0.25;
            w = 0.5;
            h = 0.5;

            text = QUOTE(HELP_TEXT);
            colorBackground[] = {0,0,0,0.5};
        };
    };
};
