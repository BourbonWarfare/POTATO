class RscText;
class RscTree;
class RscButton;
class RscPicture;
class RscMapControl;
class RscControlsGroup;
class RscStructuredText;
class RscPictureKeepAspect;
class RscControlsGroupNoScrollbars;
class RscIGProgress;
class ACEGVAR(common,CompassControl);

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
        class List: RscTree {
            idc = LIST_IDC;

            onMouseExit = QUOTE([false] call FUNC(ui_showList));
            onMouseEnter = QUOTE([true] call FUNC(ui_showList));
            onTreeLButtonDown = QUOTE([true] call FUNC(ui_handleListClick));
            onTreeDblClick = QUOTE([false] call FUNC(ui_handleListClick));

            x = "safeZoneX";
            y = "safeZoneY";
            w = QUOTE(13.5 * XFACTOR);
            h = "safeZoneH";

            multiselectEnabled = 0;
            disableKeyboardSearch = 1;
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
        class Compass: ACEGVAR(common,CompassControl) {
            idc = COMPASS_IDC;

            y = "safeZoneY";
        };
        class MapGroup: RscControlsGroupNoScrollbars {
            idc = MAP_GROUP_IDC;

            x = 0;
            y = 0.1;
            w = 1;
            h = 0.8;

            class controls {
                class MapHeader: RscText {
                    idc = MAP_HEADER_IDC;

                    x = 0;
                    y = 0;
                    w = 1;
                    h = 0.05;

                    colorBackground[] = {0,0,0,0.75};
                };
                class MapFooter: RscText {
                    idc = MAP_FOOTER_IDC;

                    x = 0;
                    y = 0.75;
                    w = 1;
                    h = 0.05;

                    text = "";

                    style = 2;
                    colorBackground[] = {0,0,0,0.75};
                    sizeEx = QUOTE(1.0 * YFACTOR);
                };
                class GameTimeText: RscText {
                    idc = TIMER_IDC;

                    x = 0.01;
                    y = 0.76;
                    w = 0.29;
                    h = 0.03;

                    text = "00:00:00";
                    sizeEx = QUOTE(1.0 * YFACTOR);
                };
                class MapTitle: RscText {
                    idc = MAP_TITLE_IDC;

                    x = 0.01;
                    y = 0.01;
                    w = 0.69; // heh
                    h = 0.03;

                    text = "";

                    colorText[] = {1,1,1,1};
                    sizeEx = QUOTE(1.0 * YFACTOR);
                };
                class SpectatorsCount: RscText {
                    idc = MAP_SPEC_COUNT_IDC;

                    x = 0.965;
                    y = 0.01;
                    w = 0.03;
                    h = 0.03;

                    text = "";

                    colorText[] = {1,1,1,1};
                    sizeEx = QUOTE(1.0 * YFACTOR);
                };
                class SpectatorsIcon: RscPictureKeepAspect {
                    idc = MAP_SPEC_ICON_IDC;

                    x = 0.94;
                    y = 0.01;
                    w = 0.03;
                    h = 0.03;

                    text = CAM_ICON_FIRST;
                };
            };
        };
        class Map: RscMapControl {
            idc = MAP_IDC;

            onDraw = QUOTE(_this call FUNC(ui_handleMapDraw));
            onMouseButtonClick = QUOTE(_this call FUNC(ui_handleMapClick));

            x = 0;
            y = 0.15;
            w = 1;
            h = 0.7;

            maxSatelliteAlpha = 0.75;
            colorBackground[] = {1,1,1,1};
        };
        class FocusInfo: RscControlsGroupNoScrollbars {
            idc = FOCUS_GROUP_IDC;

            x = QUOTE(12.1 * XFACTOR + XOFFSET);
            y = QUOTE(24 * YFACTOR + YOFFSET);
            w = QUOTE(18 * XFACTOR);
            h = QUOTE(5.5 * YFACTOR);

            class controls {
                class UpperBackground: RscText {
                    idc = FOCUS_UP_BG_IDC;

                    x = QUOTE(5.5 * XFACTOR);
                    y = 0;
                    w = QUOTE(12.4 * XFACTOR);
                    h = QUOTE(1.4 * YFACTOR);

                    colorBackground[] = {0,0,0,0.75};
                };
                class LowerBackground: RscText {
                    idc = FOCUS_DOWN_BG_IDC;

                    x = QUOTE(5.5 * XFACTOR);
                    y = QUOTE(1.5 * YFACTOR);
                    w = QUOTE(12.4 * XFACTOR);
                    h = QUOTE(4 * YFACTOR);

                    colorBackground[] = {0,0,0,0.75};
                };
                class VehicleType: RscPicture {
                    idc = FOCUS_VEHICLE_IDC;

                    x = QUOTE(15.5 * XFACTOR);
                    y = QUOTE(0.3 * YFACTOR);
                    w = QUOTE(2.1 * XFACTOR);
                    h = QUOTE(1 * YFACTOR);

                    text = "\A3\ui_f\data\map\vehicleicons\iconMan_ca.paa";
                };
                class UnitType: RscPictureKeepAspect {
                    idc = FOCUS_UNIT_IDC;

                    x = QUOTE(16.6 * XFACTOR);
                    y = QUOTE(0.3 * YFACTOR);
                    w = QUOTE(1 * XFACTOR);
                    h = QUOTE(1 * YFACTOR);

                    text = "\A3\ui_f\data\map\vehicleicons\iconMan_ca.paa";
                };
                class Name: RscText {
                    idc = FOCUS_NAME_IDC;

                    x = QUOTE(5.6 * XFACTOR);
                    y = 0;
                    w = QUOTE(9.9 * XFACTOR);
                    h = QUOTE(1.4 * YFACTOR);

                    text = "";

                    shadow = 0;
                    sizeEx = QUOTE(1 * YFACTOR);
                };
                class KillCG: RscControlsGroup {
                    idc = FOCUS_KILL_CG_IDC;

                    x = QUOTE(5.5 * XFACTOR);
                    y = QUOTE(1.5 * YFACTOR);
                    w = QUOTE(12.4 * XFACTOR);
                    h = QUOTE(4 * YFACTOR);

                    class controls {
                        class Kill: RscStructuredText {
                            idc = FOCUS_KILL_IDC;

                            x = 0;
                            y = 0;
                            w = QUOTE(12 * XFACTOR);
                            h = QUOTE(10 * YFACTOR);

                            shadow = 0;
                        };
                    };
                };
                class MedicalCG: RscControlsGroupNoScrollbars {
                    idc = FOCUS_MEDICAL_GC_IDC;

                    x = 0;
                    y = 0;
                    w = QUOTE(5.5 * XFACTOR);
                    h = QUOTE(5.5 * YFACTOR);

                    class controls {
                        class BodyImgBackground: RscText {
                            idc = FOCUS_MEDICAL_BG_IDC;

                            x = QUOTE(0.25 * XFACTOR);
                            y = 0;
                            w = QUOTE(5 * XFACTOR);
                            h = QUOTE(5.5 * YFACTOR);

                            colorBackground[] = {0,0,0,0.75};
                        };
                        class BodyImgHead: RscPictureKeepAspect {
                            idc = FOCUS_MEDICAL_HEAD_IDC;

                            x = 0;
                            y = 0;
                            w = QUOTE(5.5 * XFACTOR);
                            h = QUOTE(5.5 * YFACTOR);
                            SizeEx = QUOTE(YFACTOR * 0.5);

                            colorBackground[] = {1,1,1,1};
                            colorPicture[] = {1,1,1,1};
                            colorText[] = {1,1,1,1};
                            text = QPATHTOF(data\body_head.paa);
                        };
                        class BodyImgTorso: BodyImgHead {
                            idc = FOCUS_MEDICAL_TORSO_IDC;
                            text = QPATHTOF(data\body_torso.paa);
                        };
                        class BodyImgLeftArm: BodyImgHead {
                            idc = FOCUS_MEDICAL_LEFT_ARM_IDC;
                            text = QPATHTOF(data\body_arm_left.paa);
                        };
                        class BodyImgRightArm: BodyImgHead {
                            idc = FOCUS_MEDICAL_RIGHT_ARM_IDC;
                            text = QPATHTOF(data\body_arm_right.paa);
                        };
                        class BodyImgLeftLeg: BodyImgHead {
                            idc = FOCUS_MEDICAL_LEFT_LEG_IDC;
                            text = QPATHTOF(data\body_leg_left.paa);
                        };
                        class BodyImgRightLeg: BodyImgHead {
                            idc = FOCUS_MEDICAL_RIGHT_LEG_IDC;
                            text = QPATHTOF(data\body_leg_right.paa);
                        };

                        class RatioBlood: RscIGProgress {
                            idc = FOCUS_MEDICAL_RATIO_BLOOD_IDC;
                            x = QUOTE(0.25 * XFACTOR);
                            y = 0;
                            w = QUOTE(0.2 * XFACTOR);
                            h = QUOTE(5.5 * YFACTOR);
                            colorBar[] = {0.65,0,0,1};
                        };
                        class RatioPain: RscIGProgress {
                            idc = FOCUS_MEDICAL_RATIO_PAIN_IDC;
                            x = QUOTE(0.5 * XFACTOR);
                            y = 0;
                            w = QUOTE(0.2 * XFACTOR);
                            h = QUOTE(5.5 * YFACTOR);
                            colorBar[] = {0.65,0.65,0,1};
                        };
                        class RatioPainSuppress: RscIGProgress {
                            idc = FOCUS_MEDICAL_RATIO_PAINSUPPRESS_IDC;
                            x = QUOTE(0.5 * XFACTOR);
                            y = 0;
                            w = QUOTE(0.2 * XFACTOR);
                            h = QUOTE(5.5 * YFACTOR);
                            colorBar[] = {0,0,1,0.4};
                        };
                        class InfoHeartIcon: RscPictureKeepAspect {
                            idc = -1;
                            x = QUOTE(4.0 * XFACTOR);
                            y = 0;
                            w = QUOTE(0.5 * XFACTOR);
                            h = QUOTE(0.5 * YFACTOR);
                            text = QPATHTOF(data\heart_ca.paa);
                        };
                        class InfoHeartRate: RscText {
                            idc = FOCUS_MEDICAL_INFO_HR_IDC;
                            x = QUOTE(4.25 * XFACTOR);
                            y = 0;
                            w = QUOTE(1.5 * XFACTOR);
                            h = QUOTE(0.5 * YFACTOR);
                            text = "";
                            shadow = 0;
                            sizeEx = QUOTE(0.5 * YFACTOR);
                        };
                        class InfoWatchesIcon: RscPictureKeepAspect {
                            idc = -1;
                            x = QUOTE(4.0 * XFACTOR);
                            y = QUOTE(5.1 * YFACTOR);
                            w = QUOTE(0.5 * XFACTOR);
                            h = QUOTE(0.4 * YFACTOR);
                            text = "\A3\Weapons_F\Data\UI\gear_item_watch_ca.paa";
                        };
                        class InfoWatchesText: RscText {
                            idc = FOCUS_MEDICAL_INFO_WATCHES_IDC;
                            x = QUOTE(4.25 * XFACTOR);
                            y = QUOTE(5.1 * YFACTOR);
                            w = QUOTE(1.5 * XFACTOR);
                            h = QUOTE(0.4 * YFACTOR);
                            text = "";
                            shadow = 0;
                            sizeEx = QUOTE(0.4 * YFACTOR);
                        };
                    };
                };
            };
        };
        class FullMap: Map {
            idc = FULL_MAP_IDC;

            x = "safeZoneXAbs";
            y = "safeZoneY";
            w = "safeZoneWAbs";
            h = "safeZoneH";
        };
        class BriefingGroup: RscControlsGroupNoScrollbars {
            idc = BRIEFING_GROUP_IDC;

            x = 0;
            y = 0;
            w = 1;
            h = 1;

            class controls {
                class BriefingBackground: RscText {
                    idc = BRIEFING_BG_IDC;

                    x = 0;
                    y = 0;
                    w = 1;
                    h = 1;

                    colorBackground[] = {0,0,0,0.75};
                };
                class BriefingGroup: RscControlsGroup {
                    idc = BRIEFINGS_GROUP_IDC;

                    x = 0;
                    y = 0;
                    w = 1;
                    h = 1;

                    class controls {};
                };
            };
        };
        class RespawnButton: RscButton {
            idc = RESPAWN_IDC;

            onButtonClick = QUOTE([] spawn EFUNC(respawn,openClientRespawn));

            x = QUOTE(safezoneX + safezoneW - 0.2);
            y = QUOTE(safezoneY + safezoneH - 0.08);
            w = 0.2;
            h = 0.08;

            text = "Open Respawn";
            colorBackground[] = {0,0,0,0.5};
            sizeEx = QUOTE(1.0 * YFACTOR);
        };
        class HelpText: RscStructuredText {
            idc = HELP_IDC;

            x = 0.25;
            y = 0.245;
            w = 0.5;
            h = 0.65;

            text = QUOTE(HELP_TEXT);
            colorBackground[] = {0,0,0,0.5};
        };
    };
};
