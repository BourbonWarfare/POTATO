class CUP_B_A10_CAS_USA;
class CUP_B_A10_DYN_USA: CUP_B_A10_CAS_USA {
    class MFD {
        class AirplaneHUD {
            enableParallax = 1;
            class Pos10Vector {
                type = "vector";
                pos0[] = {0.51,0.305};
                pos10[] = {1.31,1.185};
            };
            topLeft = "HUD LH";
            topRight = "HUD PH";
            bottomLeft = "HUD LD";
            borderLeft = 0;
            borderRight = 0;
            borderTop = 0;
            borderBottom = 0;
            color[] = {0,1,0,0.1};
            types[] = {-2};
            class Bones {
                class PlaneW {
                    type = "fixed";
                    pos[] = {0.51,0.375};
                };
                class WeaponAim {
                    source = "weapon";
                    type = "vector";
                    pos0[] = {0.51,0.305};
                    pos10[] = {1.31,1.185};
                };
                class Target {
                    source = "target";
                    type = "vector";
                    pos0[] = {0.51,0.305};
                    pos10[] = {1.31,1.185};
                };
                class Velocity {
                    type = "vector";
                    source = "velocity";
                    pos0[] = {0.5,0.305};
                    pos10[] = {1.3,1.185};
                };
                class ILS_H {
                    type = "ils";
                    pos0[] = {0.5,0.305};
                    pos3[] = {0.74,0.305};
                };
                class ILS_W {
                    pos3[] = {0.5,0.569};
                    type = "ils";
                    pos0[] = {0.5,0.305};
                };
                class Level0 {
                    pos0[] = {0.5,0.375};
                    pos10[] = {1.3,1.255};
                    type = "horizon";
                    angle = 0;
                };
                class LevelP5 {
                    angle = 5;
                    pos0[] = {0.5,0.375};
                    pos10[] = {1.3,1.255};
                    type = "horizon";
                };
                class LevelM5 {
                    angle = -5;
                    pos0[] = {0.5,0.375};
                    pos10[] = {1.3,1.255};
                    type = "horizon";
                };
                class LevelP10 {
                    angle = 10;
                    pos0[] = {0.5,0.375};
                    pos10[] = {1.3,1.255};
                    type = "horizon";
                };
                class LevelM10 {
                    angle = -10;
                    pos0[] = {0.5,0.375};
                    pos10[] = {1.3,1.255};
                    type = "horizon";
                };
                class LevelP15 {
                    angle = 15;
                    pos0[] = {0.5,0.375};
                    pos10[] = {1.3,1.255};
                    type = "horizon";
                };
                class LevelM15 {
                    angle = -15;
                    pos0[] = {0.5,0.375};
                    pos10[] = {1.3,1.255};
                    type = "horizon";
                };
                class LevelP20 {
                    angle = 20;
                    pos0[] = {0.5,0.375};
                    pos10[] = {1.3,1.255};
                    type = "horizon";
                };
                class LevelM20 {
                    angle = -20;
                    pos0[] = {0.5,0.375};
                    pos10[] = {1.3,1.255};
                    type = "horizon";
                };
                class LevelP25 {
                    angle = 25;
                    pos0[] = {0.5,0.375};
                    pos10[] = {1.3,1.255};
                    type = "horizon";
                };
                class LevelM25 {
                    angle = -25;
                    pos0[] = {0.5,0.375};
                    pos10[] = {1.3,1.255};
                    type = "horizon";
                };
                class LevelP30 {
                    angle = 30;
                    pos0[] = {0.5,0.375};
                    pos10[] = {1.3,1.255};
                    type = "horizon";
                };
                class LevelM30 {
                    angle = -30;
                    pos0[] = {0.5,0.375};
                    pos10[] = {1.3,1.255};
                    type = "horizon";
                };
                class LevelP35 {
                    angle = 35;
                    pos0[] = {0.5,0.375};
                    pos10[] = {1.3,1.255};
                    type = "horizon";
                };
                class LevelM35 {
                    angle = -35;
                    pos0[] = {0.5,0.375};
                    pos10[] = {1.3,1.255};
                    type = "horizon";
                };
                class LevelP40 {
                    angle = 40;
                    pos0[] = {0.5,0.375};
                    pos10[] = {1.3,1.255};
                    type = "horizon";
                };
                class LevelM40 {
                    angle = -40;
                    pos0[] = {0.5,0.375};
                    pos10[] = {1.3,1.255};
                    type = "horizon";
                };
                class LevelP45 {
                    angle = 45;
                    pos0[] = {0.5,0.375};
                    pos10[] = {1.3,1.255};
                    type = "horizon";
                };
                class LevelM45 {
                    angle = -45;
                    pos0[] = {0.5,0.375};
                    pos10[] = {1.3,1.255};
                    type = "horizon";
                };
                class LevelP50 {
                    angle = 50;
                    pos0[] = {0.5,0.375};
                    pos10[] = {1.3,1.255};
                    type = "horizon";
                };
                class LevelM50 {
                    angle = -50;
                    pos0[] = {0.5,0.375};
                    pos10[] = {1.3,1.255};
                    type = "horizon";
                };
                class ImpactPoint {
                    type = "vector";
                    source = "ImpactPoint";
                    pos0[] = {0.5,0.34};
                    pos10[] = {1.3,1.255};
                };
                class NormalizeBombCircle {
                    type = "normalizedorsmaller";
                    limit = 0.08;
                    aspectRatio = 1.25;
                };
                class MissileFlightTimeRot1 {
                    type = "rotational";
                    source = "MissileFlightTime";
                    sourceScale = 1;
                    center[] = {0,0};
                    min = 0;
                    max = 0.5;
                    minAngle = 0;
                    maxAngle = 18;
                    aspectRatio = 1.25;
                };
                class MissileFlightTimeRot2 {
                    maxAngle = 36;
                    max = 1;
                    type = "rotational";
                    source = "MissileFlightTime";
                    sourceScale = 1;
                    center[] = {0,0};
                    min = 0;
                    minAngle = 0;
                    aspectRatio = 1.25;
                };
                class MissileFlightTimeRot3 {
                    maxAngle = 54;
                    max = 1.5;
                    type = "rotational";
                    source = "MissileFlightTime";
                    sourceScale = 1;
                    center[] = {0,0};
                    min = 0;
                    minAngle = 0;
                    aspectRatio = 1.25;
                };
                class MissileFlightTimeRot4 {
                    maxAngle = 72;
                    max = 2;
                    type = "rotational";
                    source = "MissileFlightTime";
                    sourceScale = 1;
                    center[] = {0,0};
                    min = 0;
                    minAngle = 0;
                    aspectRatio = 1.25;
                };
                class MissileFlightTimeRot5 {
                    maxAngle = 90;
                    max = 2.5;
                    type = "rotational";
                    source = "MissileFlightTime";
                    sourceScale = 1;
                    center[] = {0,0};
                    min = 0;
                    minAngle = 0;
                    aspectRatio = 1.25;
                };
                class MissileFlightTimeRot6 {
                    maxAngle = 108;
                    max = 3;
                    type = "rotational";
                    source = "MissileFlightTime";
                    sourceScale = 1;
                    center[] = {0,0};
                    min = 0;
                    minAngle = 0;
                    aspectRatio = 1.25;
                };
                class MissileFlightTimeRot7 {
                    maxAngle = 126;
                    max = 3.5;
                    type = "rotational";
                    source = "MissileFlightTime";
                    sourceScale = 1;
                    center[] = {0,0};
                    min = 0;
                    minAngle = 0;
                    aspectRatio = 1.25;
                };
                class MissileFlightTimeRot8 {
                    maxAngle = 144;
                    max = 4;
                    type = "rotational";
                    source = "MissileFlightTime";
                    sourceScale = 1;
                    center[] = {0,0};
                    min = 0;
                    minAngle = 0;
                    aspectRatio = 1.25;
                };
                class MissileFlightTimeRot9 {
                    maxAngle = 162;
                    max = 4.5;
                    type = "rotational";
                    source = "MissileFlightTime";
                    sourceScale = 1;
                    center[] = {0,0};
                    min = 0;
                    minAngle = 0;
                    aspectRatio = 1.25;
                };
                class MissileFlightTimeRot10 {
                    maxAngle = 180;
                    max = 5;
                    type = "rotational";
                    source = "MissileFlightTime";
                    sourceScale = 1;
                    center[] = {0,0};
                    min = 0;
                    minAngle = 0;
                    aspectRatio = 1.25;
                };
                class MissileFlightTimeRot11 {
                    maxAngle = 198;
                    max = 5.5;
                    type = "rotational";
                    source = "MissileFlightTime";
                    sourceScale = 1;
                    center[] = {0,0};
                    min = 0;
                    minAngle = 0;
                    aspectRatio = 1.25;
                };
                class MissileFlightTimeRot12 {
                    maxAngle = 216;
                    max = 6;
                    type = "rotational";
                    source = "MissileFlightTime";
                    sourceScale = 1;
                    center[] = {0,0};
                    min = 0;
                    minAngle = 0;
                    aspectRatio = 1.25;
                };
                class MissileFlightTimeRot13 {
                    maxAngle = 234;
                    max = 6.5;
                    type = "rotational";
                    source = "MissileFlightTime";
                    sourceScale = 1;
                    center[] = {0,0};
                    min = 0;
                    minAngle = 0;
                    aspectRatio = 1.25;
                };
                class MissileFlightTimeRot14 {
                    maxAngle = 252;
                    max = 7;
                    type = "rotational";
                    source = "MissileFlightTime";
                    sourceScale = 1;
                    center[] = {0,0};
                    min = 0;
                    minAngle = 0;
                    aspectRatio = 1.25;
                };
                class MissileFlightTimeRot15 {
                    maxAngle = 270;
                    max = 7.5;
                    type = "rotational";
                    source = "MissileFlightTime";
                    sourceScale = 1;
                    center[] = {0,0};
                    min = 0;
                    minAngle = 0;
                    aspectRatio = 1.25;
                };
                class MissileFlightTimeRot16 {
                    maxAngle = 288;
                    max = 8;
                    type = "rotational";
                    source = "MissileFlightTime";
                    sourceScale = 1;
                    center[] = {0,0};
                    min = 0;
                    minAngle = 0;
                    aspectRatio = 1.25;
                };
                class MissileFlightTimeRot17 {
                    maxAngle = 306;
                    max = 8.5;
                    type = "rotational";
                    source = "MissileFlightTime";
                    sourceScale = 1;
                    center[] = {0,0};
                    min = 0;
                    minAngle = 0;
                    aspectRatio = 1.25;
                };
                class MissileFlightTimeRot18 {
                    maxAngle = 324;
                    max = 9;
                    type = "rotational";
                    source = "MissileFlightTime";
                    sourceScale = 1;
                    center[] = {0,0};
                    min = 0;
                    minAngle = 0;
                    aspectRatio = 1.25;
                };
                class MissileFlightTimeRot19 {
                    maxAngle = 342;
                    max = 9.5;
                    type = "rotational";
                    source = "MissileFlightTime";
                    sourceScale = 1;
                    center[] = {0,0};
                    min = 0;
                    minAngle = 0;
                    aspectRatio = 1.25;
                };
                class MissileFlightTimeRot20 {
                    maxAngle = 360;
                    max = 10;
                    type = "rotational";
                    source = "MissileFlightTime";
                    sourceScale = 1;
                    center[] = {0,0};
                    min = 0;
                    minAngle = 0;
                    aspectRatio = 1.25;
                };
                class Limit0109 {
                    limits[] = {
                        0.1,
                        0.1,
                        0.9,
                        0.9
                    };
                    type = "limit";
                };
            };
            class Draw {
                alpha = 0.4;
                color[] = {0,0.3,0.05};
                condition = "on";
                class PlaneW {
                    clipTL[] = {0,1};
                    clipBR[] = {1,0};
                    type = "line";
                    points[] = {{"PlaneW",{-0.08,0},1},{"PlaneW",{-0.03,0},1},{"PlaneW",{-0.015,0.033},1},{"PlaneW",{0,0},1},{"PlaneW",{0.015,0.033},1},{"PlaneW",{0.03,0},1},{"PlaneW",{0.08,0},1}};
                };
                class PlaneHeading {
                    clipTL[] = {0,1};
                    clipBR[] = {1,0};
                    type = "line";
                    points[] = {{"Velocity",{0,-0.022},1},{"Velocity",{0.014,-0.0154},1},{"Velocity",{0.02,0},1},{"Velocity",{0.014,0.0154},1},{"Velocity",{0,0.022},1},{"Velocity",{-0.014,0.0154},1},{"Velocity",{-0.02,0},1},{"Velocity",{-0.014,-0.0154},1},{"Velocity",{0,-0.022},1},{},{"Velocity",{0.04,0},1},{"Velocity",{0.02,0},1},{},{"Velocity",{-0.04,0},1},{"Velocity",{-0.02,0},1},{},{"Velocity",{0,-0.044},1},{"Velocity",{0,-0.022},1},{}};
                };
                class Static {
                    clipTL[] = {0,0.1};
                    clipBR[] = {1,0};
                    type = "line";
                    points[] = {{{0.21,0.52},1},{{0.19,0.5},1},{{0.21,0.48},1},{},{{0.18,0.2},1},{{0.18,0.85},1},{},{{0.79,0.52},1},{{0.81,0.5},1},{{0.79,0.48},1},{},{{0.82,0.2},1},{{0.82,0.85},1},{},{{0.52,0.09},1},{{0.5,0.07},1},{{0.48,0.09},1},{},{{0.2,0.065},1},{{0.8,0.065},1},{}};
                };
                class Horizont {
                    clipTL[] = {0,0};
                    clipBR[] = {1,1};
                    class Dimmed {
                        class Level0 {
                            type = "line";
                            points[] = {{"Level0",{-0.2,0},1},{"Level0",{-0.05,0},1},{},{"Level0",{0.05,0},1},{"Level0",{0.2,0},1}};
                        };
                        class VALM_1_0 {
                            type = "text";
                            source = "static";
                            text = 0;
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = {"Level0",{-0.23,-0.025},1};
                            right[] = {"Level0",{-0.13,-0.025},1};
                            down[] = {"Level0",{-0.23,0.025},1};
                        };
                        class VALM_2_0 {
                            align = "right";
                            pos[] = {"Level0",{0.22,-0.025},1};
                            right[] = {"Level0",{0.32,-0.025},1};
                            down[] = {"Level0",{0.22,0.025},1};
                            type = "text";
                            source = "static";
                            text = 0;
                            scale = 1;
                            sourceScale = 1;
                        };
                        class LevelM5 {
                            type = "line";
                            points[] = {{"LevelM5",{-0.2,-0.03},1},{"LevelM5",{-0.2,0},1},{"LevelM5",{-0.15,0},1},{},{"LevelM5",{-0.1,0},1},{"LevelM5",{-0.05,0},1},{},{"LevelM5",{0.05,0},1},{"LevelM5",{0.1,0},1},{},{"LevelM5",{0.15,0},1},{"LevelM5",{0.2,0},1},{"LevelM5",{0.2,-0.03},1}};
                        };
                        class VALM_1_5 {
                            type = "text";
                            source = "static";
                            text = -5;
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = {"LevelM5",{-0.23,-0.085},1};
                            right[] = {"LevelM5",{-0.13,-0.085},1};
                            down[] = {"LevelM5",{-0.23,-0.035},1};
                        };
                        class VALM_2_5 {
                            align = "right";
                            pos[] = {"LevelM5",{0.22,-0.085},1};
                            right[] = {"LevelM5",{0.32,-0.085},1};
                            down[] = {"LevelM5",{0.22,-0.035},1};
                            type = "text";
                            source = "static";
                            text = -5;
                            scale = 1;
                            sourceScale = 1;
                        };
                        class LevelP5 {
                            type = "line";
                            points[] = {{"LevelP5",{-0.2,0.03},1},{"LevelP5",{-0.2,0},1},{"LevelP5",{-0.05,0},1},{},{"LevelP5",{0.05,0},1},{"LevelP5",{0.2,0},1},{"LevelP5",{0.2,0.03},1}};
                        };
                        class VALP_1_5 {
                            type = "text";
                            source = "static";
                            text = "5";
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = {"LevelP5",{-0.23,0.035},1};
                            right[] = {"LevelP5",{-0.13,0.035},1};
                            down[] = {"LevelP5",{-0.23,0.085},1};
                        };
                        class VALP_2_5 {
                            align = "right";
                            pos[] = {"LevelP5",{0.22,0.035},1};
                            right[] = {"LevelP5",{0.32,0.035},1};
                            down[] = {"LevelP5",{0.22,0.085},1};
                            type = "text";
                            source = "static";
                            text = "5";
                            scale = 1;
                            sourceScale = 1;
                        };
                        class LevelM10 {
                            type = "line";
                            points[] = {{"LevelM10",{-0.2,-0.03},1},{"LevelM10",{-0.2,0},1},{"LevelM10",{-0.15,0},1},{},{"LevelM10",{-0.1,0},1},{"LevelM10",{-0.05,0},1},{},{"LevelM10",{0.05,0},1},{"LevelM10",{0.1,0},1},{},{"LevelM10",{0.15,0},1},{"LevelM10",{0.2,0},1},{"LevelM10",{0.2,-0.03},1}};
                        };
                        class VALM_1_10 {
                            type = "text";
                            source = "static";
                            text = -10;
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = {"LevelM10",{-0.23,-0.085},1};
                            right[] = {"LevelM10",{-0.13,-0.085},1};
                            down[] = {"LevelM10",{-0.23,-0.035},1};
                        };
                        class VALM_2_10 {
                            align = "right";
                            pos[] = {"LevelM10",{0.22,-0.085},1};
                            right[] = {"LevelM10",{0.32,-0.085},1};
                            down[] = {"LevelM10",{0.22,-0.035},1};
                            type = "text";
                            source = "static";
                            text = -10;
                            scale = 1;
                            sourceScale = 1;
                        };
                        class LevelP10 {
                            type = "line";
                            points[] = {{"LevelP10",{-0.2,0.03},1},{"LevelP10",{-0.2,0},1},{"LevelP10",{-0.05,0},1},{},{"LevelP10",{0.05,0},1},{"LevelP10",{0.2,0},1},{"LevelP10",{0.2,0.03},1}};
                        };
                        class VALP_1_10 {
                            type = "text";
                            source = "static";
                            text = "10";
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = {"LevelP10",{-0.23,0.035},1};
                            right[] = {"LevelP10",{-0.13,0.035},1};
                            down[] = {"LevelP10",{-0.23,0.085},1};
                        };
                        class VALP_2_10 {
                            align = "right";
                            pos[] = {"LevelP10",{0.22,0.035},1};
                            right[] = {"LevelP10",{0.32,0.035},1};
                            down[] = {"LevelP10",{0.22,0.085},1};
                            type = "text";
                            source = "static";
                            text = "10";
                            scale = 1;
                            sourceScale = 1;
                        };
                        class LevelM15 {
                            type = "line";
                            points[] = {{"LevelM15",{-0.2,-0.03},1},{"LevelM15",{-0.2,0},1},{"LevelM15",{-0.15,0},1},{},{"LevelM15",{-0.1,0},1},{"LevelM15",{-0.05,0},1},{},{"LevelM15",{0.05,0},1},{"LevelM15",{0.1,0},1},{},{"LevelM15",{0.15,0},1},{"LevelM15",{0.2,0},1},{"LevelM15",{0.2,-0.03},1}};
                        };
                        class VALM_1_15 {
                            type = "text";
                            source = "static";
                            text = -15;
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = {"LevelM15",{-0.23,-0.085},1};
                            right[] = {"LevelM15",{-0.13,-0.085},1};
                            down[] = {"LevelM15",{-0.23,-0.035},1};
                        };
                        class VALM_2_15 {
                            align = "right";
                            pos[] = {"LevelM15",{0.22,-0.085},1};
                            right[] = {"LevelM15",{0.32,-0.085},1};
                            down[] = {"LevelM15",{0.22,-0.035},1};
                            type = "text";
                            source = "static";
                            text = -15;
                            scale = 1;
                            sourceScale = 1;
                        };
                        class LevelP15 {
                            type = "line";
                            points[] = {{"LevelP15",{-0.2,0.03},1},{"LevelP15",{-0.2,0},1},{"LevelP15",{-0.05,0},1},{},{"LevelP15",{0.05,0},1},{"LevelP15",{0.2,0},1},{"LevelP15",{0.2,0.03},1}};
                        };
                        class VALP_1_15 {
                            type = "text";
                            source = "static";
                            text = "15";
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = {"LevelP15",{-0.23,0.035},1};
                            right[] = {"LevelP15",{-0.13,0.035},1};
                            down[] = {"LevelP15",{-0.23,0.085},1};
                        };
                        class VALP_2_15 {
                            align = "right";
                            pos[] = {"LevelP15",{0.22,0.035},1};
                            right[] = {"LevelP15",{0.32,0.035},1};
                            down[] = {"LevelP15",{0.22,0.085},1};
                            type = "text";
                            source = "static";
                            text = "15";
                            scale = 1;
                            sourceScale = 1;
                        };
                        class LevelM20 {
                            type = "line";
                            points[] = {{"LevelM20",{-0.2,-0.03},1},{"LevelM20",{-0.2,0},1},{"LevelM20",{-0.15,0},1},{},{"LevelM20",{-0.1,0},1},{"LevelM20",{-0.05,0},1},{},{"LevelM20",{0.05,0},1},{"LevelM20",{0.1,0},1},{},{"LevelM20",{0.15,0},1},{"LevelM20",{0.2,0},1},{"LevelM20",{0.2,-0.03},1}};
                        };
                        class VALM_1_20 {
                            type = "text";
                            source = "static";
                            text = -20;
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = {"LevelM20",{-0.23,-0.085},1};
                            right[] = {"LevelM20",{-0.13,-0.085},1};
                            down[] = {"LevelM20",{-0.23,-0.035},1};
                        };
                        class VALM_2_20 {
                            align = "right";
                            pos[] = {"LevelM20",{0.22,-0.085},1};
                            right[] = {"LevelM20",{0.32,-0.085},1};
                            down[] = {"LevelM20",{0.22,-0.035},1};
                            type = "text";
                            source = "static";
                            text = -20;
                            scale = 1;
                            sourceScale = 1;
                        };
                        class LevelP20 {
                            type = "line";
                            points[] = {{"LevelP20",{-0.2,0.03},1},{"LevelP20",{-0.2,0},1},{"LevelP20",{-0.05,0},1},{},{"LevelP20",{0.05,0},1},{"LevelP20",{0.2,0},1},{"LevelP20",{0.2,0.03},1}};
                        };
                        class VALP_1_20 {
                            type = "text";
                            source = "static";
                            text = "20";
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = {"LevelP20",{-0.23,0.035},1};
                            right[] = {"LevelP20",{-0.13,0.035},1};
                            down[] = {"LevelP20",{-0.23,0.085},1};
                        };
                        class VALP_2_20 {
                            align = "right";
                            pos[] = {"LevelP20",{0.22,0.035},1};
                            right[] = {"LevelP20",{0.32,0.035},1};
                            down[] = {"LevelP20",{0.22,0.085},1};
                            type = "text";
                            source = "static";
                            text = "20";
                            scale = 1;
                            sourceScale = 1;
                        };
                        class LevelM25 {
                            type = "line";
                            points[] = {{"LevelM25",{-0.2,-0.03},1},{"LevelM25",{-0.2,0},1},{"LevelM25",{-0.15,0},1},{},{"LevelM25",{-0.1,0},1},{"LevelM25",{-0.05,0},1},{},{"LevelM25",{0.05,0},1},{"LevelM25",{0.1,0},1},{},{"LevelM25",{0.15,0},1},{"LevelM25",{0.2,0},1},{"LevelM25",{0.2,-0.03},1}};
                        };
                        class VALM_1_25 {
                            type = "text";
                            source = "static";
                            text = -25;
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = {"LevelM25",{-0.23,-0.085},1};
                            right[] = {"LevelM25",{-0.13,-0.085},1};
                            down[] = {"LevelM25",{-0.23,-0.035},1};
                        };
                        class VALM_2_25 {
                            align = "right";
                            pos[] = {"LevelM25",{0.22,-0.085},1};
                            right[] = {"LevelM25",{0.32,-0.085},1};
                            down[] = {"LevelM25",{0.22,-0.035},1};
                            type = "text";
                            source = "static";
                            text = -25;
                            scale = 1;
                            sourceScale = 1;
                        };
                        class LevelP25 {
                            type = "line";
                            points[] = {{"LevelP25",{-0.2,0.03},1},{"LevelP25",{-0.2,0},1},{"LevelP25",{-0.05,0},1},{},{"LevelP25",{0.05,0},1},{"LevelP25",{0.2,0},1},{"LevelP25",{0.2,0.03},1}};
                        };
                        class VALP_1_25 {
                            type = "text";
                            source = "static";
                            text = "25";
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = {"LevelP25",{-0.23,0.035},1};
                            right[] = {"LevelP25",{-0.13,0.035},1};
                            down[] = {"LevelP25",{-0.23,0.085},1};
                        };
                        class VALP_2_25 {
                            align = "right";
                            pos[] = {"LevelP25",{0.22,0.035},1};
                            right[] = {"LevelP25",{0.32,0.035},1};
                            down[] = {"LevelP25",{0.22,0.085},1};
                            type = "text";
                            source = "static";
                            text = "25";
                            scale = 1;
                            sourceScale = 1;
                        };
                        class LevelM30 {
                            type = "line";
                            points[] = {{"LevelM30",{-0.2,-0.03},1},{"LevelM30",{-0.2,0},1},{"LevelM30",{-0.15,0},1},{},{"LevelM30",{-0.1,0},1},{"LevelM30",{-0.05,0},1},{},{"LevelM30",{0.05,0},1},{"LevelM30",{0.1,0},1},{},{"LevelM30",{0.15,0},1},{"LevelM30",{0.2,0},1},{"LevelM30",{0.2,-0.03},1}};
                        };
                        class VALM_1_30 {
                            type = "text";
                            source = "static";
                            text = -30;
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = {"LevelM30",{-0.23,-0.085},1};
                            right[] = {"LevelM30",{-0.13,-0.085},1};
                            down[] = {"LevelM30",{-0.23,-0.035},1};
                        };
                        class VALM_2_30 {
                            align = "right";
                            pos[] = {"LevelM30",{0.22,-0.085},1};
                            right[] = {"LevelM30",{0.32,-0.085},1};
                            down[] = {"LevelM30",{0.22,-0.035},1};
                            type = "text";
                            source = "static";
                            text = -30;
                            scale = 1;
                            sourceScale = 1;
                        };
                        class LevelP30 {
                            type = "line";
                            points[] = {{"LevelP30",{-0.2,0.03},1},{"LevelP30",{-0.2,0},1},{"LevelP30",{-0.05,0},1},{},{"LevelP30",{0.05,0},1},{"LevelP30",{0.2,0},1},{"LevelP30",{0.2,0.03},1}};
                        };
                        class VALP_1_30 {
                            type = "text";
                            source = "static";
                            text = "30";
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = {"LevelP30",{-0.23,0.035},1};
                            right[] = {"LevelP30",{-0.13,0.035},1};
                            down[] = {"LevelP30",{-0.23,0.085},1};
                        };
                        class VALP_2_30 {
                            align = "right";
                            pos[] = {"LevelP30",{0.22,0.035},1};
                            right[] = {"LevelP30",{0.32,0.035},1};
                            down[] = {"LevelP30",{0.22,0.085},1};
                            type = "text";
                            source = "static";
                            text = "30";
                            scale = 1;
                            sourceScale = 1;
                        };
                        class LevelM35 {
                            type = "line";
                            points[] = {{"LevelM35",{-0.2,-0.03},1},{"LevelM35",{-0.2,0},1},{"LevelM35",{-0.15,0},1},{},{"LevelM35",{-0.1,0},1},{"LevelM35",{-0.05,0},1},{},{"LevelM35",{0.05,0},1},{"LevelM35",{0.1,0},1},{},{"LevelM35",{0.15,0},1},{"LevelM35",{0.2,0},1},{"LevelM35",{0.2,-0.03},1}};
                        };
                        class VALM_1_35 {
                            type = "text";
                            source = "static";
                            text = -35;
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = {"LevelM35",{-0.23,-0.085},1};
                            right[] = {"LevelM35",{-0.13,-0.085},1};
                            down[] = {"LevelM35",{-0.23,-0.035},1};
                        };
                        class VALM_2_35 {
                            align = "right";
                            pos[] = {"LevelM35",{0.22,-0.085},1};
                            right[] = {"LevelM35",{0.32,-0.085},1};
                            down[] = {"LevelM35",{0.22,-0.035},1};
                            type = "text";
                            source = "static";
                            text = -35;
                            scale = 1;
                            sourceScale = 1;
                        };
                        class LevelP35 {
                            type = "line";
                            points[] = {{"LevelP35",{-0.2,0.03},1},{"LevelP35",{-0.2,0},1},{"LevelP35",{-0.05,0},1},{},{"LevelP35",{0.05,0},1},{"LevelP35",{0.2,0},1},{"LevelP35",{0.2,0.03},1}};
                        };
                        class VALP_1_35 {
                            type = "text";
                            source = "static";
                            text = "35";
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = {"LevelP35",{-0.23,0.035},1};
                            right[] = {"LevelP35",{-0.13,0.035},1};
                            down[] = {"LevelP35",{-0.23,0.085},1};
                        };
                        class VALP_2_35 {
                            align = "right";
                            pos[] = {"LevelP35",{0.22,0.035},1};
                            right[] = {"LevelP35",{0.32,0.035},1};
                            down[] = {"LevelP35",{0.22,0.085},1};
                            type = "text";
                            source = "static";
                            text = "35";
                            scale = 1;
                            sourceScale = 1;
                        };
                        class LevelM40 {
                            type = "line";
                            points[] = {{"LevelM40",{-0.2,-0.03},1},{"LevelM40",{-0.2,0},1},{"LevelM40",{-0.15,0},1},{},{"LevelM40",{-0.1,0},1},{"LevelM40",{-0.05,0},1},{},{"LevelM40",{0.05,0},1},{"LevelM40",{0.1,0},1},{},{"LevelM40",{0.15,0},1},{"LevelM40",{0.2,0},1},{"LevelM40",{0.2,-0.03},1}};
                        };
                        class VALM_1_40 {
                            type = "text";
                            source = "static";
                            text = -40;
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = {"LevelM40",{-0.23,-0.085},1};
                            right[] = {"LevelM40",{-0.13,-0.085},1};
                            down[] = {"LevelM40",{-0.23,-0.035},1};
                        };
                        class VALM_2_40 {
                            align = "right";
                            pos[] = {"LevelM40",{0.22,-0.085},1};
                            right[] = {"LevelM40",{0.32,-0.085},1};
                            down[] = {"LevelM40",{0.22,-0.035},1};
                            type = "text";
                            source = "static";
                            text = -40;
                            scale = 1;
                            sourceScale = 1;
                        };
                        class LevelP40 {
                            type = "line";
                            points[] = {{"LevelP40",{-0.2,0.03},1},{"LevelP40",{-0.2,0},1},{"LevelP40",{-0.05,0},1},{},{"LevelP40",{0.05,0},1},{"LevelP40",{0.2,0},1},{"LevelP40",{0.2,0.03},1}};
                        };
                        class VALP_1_40 {
                            type = "text";
                            source = "static";
                            text = "40";
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = {"LevelP40",{-0.23,0.035},1};
                            right[] = {"LevelP40",{-0.13,0.035},1};
                            down[] = {"LevelP40",{-0.23,0.085},1};
                        };
                        class VALP_2_40 {
                            align = "right";
                            pos[] = {"LevelP40",{0.22,0.035},1};
                            right[] = {"LevelP40",{0.32,0.035},1};
                            down[] = {"LevelP40",{0.22,0.085},1};
                            type = "text";
                            source = "static";
                            text = "40";
                            scale = 1;
                            sourceScale = 1;
                        };
                        class LevelM45 {
                            type = "line";
                            points[] = {{"LevelM45",{-0.2,-0.03},1},{"LevelM45",{-0.2,0},1},{"LevelM45",{-0.15,0},1},{},{"LevelM45",{-0.1,0},1},{"LevelM45",{-0.05,0},1},{},{"LevelM45",{0.05,0},1},{"LevelM45",{0.1,0},1},{},{"LevelM45",{0.15,0},1},{"LevelM45",{0.2,0},1},{"LevelM45",{0.2,-0.03},1}};
                        };
                        class VALM_1_45 {
                            type = "text";
                            source = "static";
                            text = -45;
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = {"LevelM45",{-0.23,-0.085},1};
                            right[] = {"LevelM45",{-0.13,-0.085},1};
                            down[] = {"LevelM45",{-0.23,-0.035},1};
                        };
                        class VALM_2_45 {
                            align = "right";
                            pos[] = {"LevelM45",{0.22,-0.085},1};
                            right[] = {"LevelM45",{0.32,-0.085},1};
                            down[] = {"LevelM45",{0.22,-0.035},1};
                            type = "text";
                            source = "static";
                            text = -45;
                            scale = 1;
                            sourceScale = 1;
                        };
                        class LevelP45 {
                            type = "line";
                            points[] = {{"LevelP45",{-0.2,0.03},1},{"LevelP45",{-0.2,0},1},{"LevelP45",{-0.05,0},1},{},{"LevelP45",{0.05,0},1},{"LevelP45",{0.2,0},1},{"LevelP45",{0.2,0.03},1}};
                        };
                        class VALP_1_45 {
                            type = "text";
                            source = "static";
                            text = "45";
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = {"LevelP45",{-0.23,0.035},1};
                            right[] = {"LevelP45",{-0.13,0.035},1};
                            down[] = {"LevelP45",{-0.23,0.085},1};
                        };
                        class VALP_2_45 {
                            align = "right";
                            pos[] = {"LevelP45",{0.22,0.035},1};
                            right[] = {"LevelP45",{0.32,0.035},1};
                            down[] = {"LevelP45",{0.22,0.085},1};
                            type = "text";
                            source = "static";
                            text = "45";
                            scale = 1;
                            sourceScale = 1;
                        };
                        class LevelM50 {
                            type = "line";
                            points[] = {{"LevelM50",{-0.2,-0.03},1},{"LevelM50",{-0.2,0},1},{"LevelM50",{-0.15,0},1},{},{"LevelM50",{-0.1,0},1},{"LevelM50",{-0.05,0},1},{},{"LevelM50",{0.05,0},1},{"LevelM50",{0.1,0},1},{},{"LevelM50",{0.15,0},1},{"LevelM50",{0.2,0},1},{"LevelM50",{0.2,-0.03},1}};
                        };
                        class VALM_1_50 {
                            type = "text";
                            source = "static";
                            text = -50;
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = {"LevelM50",{-0.23,-0.085},1};
                            right[] = {"LevelM50",{-0.13,-0.085},1};
                            down[] = {"LevelM50",{-0.23,-0.035},1};
                        };
                        class VALM_2_50 {
                            align = "right";
                            pos[] = {"LevelM50",{0.22,-0.085},1};
                            right[] = {"LevelM50",{0.32,-0.085},1};
                            down[] = {"LevelM50",{0.22,-0.035},1};
                            type = "text";
                            source = "static";
                            text = -50;
                            scale = 1;
                            sourceScale = 1;
                        };
                        class LevelP50 {
                            type = "line";
                            points[] = {{"LevelP50",{-0.2,0.03},1},{"LevelP50",{-0.2,0},1},{"LevelP50",{-0.05,0},1},{},{"LevelP50",{0.05,0},1},{"LevelP50",{0.2,0},1},{"LevelP50",{0.2,0.03},1}};
                        };
                        class VALP_1_50 {
                            type = "text";
                            source = "static";
                            text = "50";
                            align = "left";
                            scale = 1;
                            sourceScale = 1;
                            pos[] = {"LevelP50",{-0.23,0.035},1};
                            right[] = {"LevelP50",{-0.13,0.035},1};
                            down[] = {"LevelP50",{-0.23,0.085},1};
                        };
                        class VALP_2_50 {
                            align = "right";
                            pos[] = {"LevelP50",{0.22,0.035},1};
                            right[] = {"LevelP50",{0.32,0.035},1};
                            down[] = {"LevelP50",{0.22,0.085},1};
                            type = "text";
                            source = "static";
                            text = "50";
                            scale = 1;
                            sourceScale = 1;
                        };
                    };
                };
                class RadarTargets {
                    type = "radar";
                    pos0[] = {0.51,0.305};
                    pos10[] = {1.31,1.185};
                    points[] = {{{-0.05,-0.055},1},{{0.05,-0.055},1},{{0.05,0.055},1},{{-0.05,0.055},1},{{-0.05,-0.055},1}};
                };
                class MGun {
                    type = "group";
                    condition = "mgun";
                    class Circle {
                        type = "line";
                        points[] = {{"ImpactPoint",1,{0.01,0},1},{"ImpactPoint",1,{-0.01,0},1},{},{"ImpactPoint",1,{0,0.011},1},{"ImpactPoint",1,{0,-0.011},1},{},{"ImpactPoint",1,{0,-0.077},1},{"ImpactPoint",1,{0.049,-0.0539},1},{"ImpactPoint",1,{0.07,0},1},{"ImpactPoint",1,{0.049,0.0539},1},{"ImpactPoint",1,{0,0.077},1},{"ImpactPoint",1,{-0.049,0.0539},1},{"ImpactPoint",1,{-0.07,0},1},{"ImpactPoint",1,{-0.049,-0.0539},1},{"ImpactPoint",1,{0,-0.077},1},{},{"ImpactPoint",1,{0,-0.154},1},{"ImpactPoint",1,{0.07,-0.13398},1},{"ImpactPoint",1,{0.1218,-0.077},1},{"ImpactPoint",1,{0.14,0},1},{"ImpactPoint",1,{0.1218,0.077},1},{"ImpactPoint",1,{0.07,0.13398},1},{"ImpactPoint",1,{0,0.154},1},{"ImpactPoint",1,{-0.07,0.13398},1},{"ImpactPoint",1,{-0.1218,0.077},1},{"ImpactPoint",1,{-0.14,0},1},{"ImpactPoint",1,{-0.1218,-0.077},1},{"ImpactPoint",1,{-0.07,-0.13398},1},{"ImpactPoint",1,{0,-0.154},1},{},{"ImpactPoint",1,{0,-0.154},1},{"ImpactPoint",1,{0,-0.176},1},{},{"ImpactPoint",1,{-0.07,-0.133368},1},{"ImpactPoint",1,{-0.08,-0.15242},1},{},{"ImpactPoint",1,{-0.121244,-0.077},1},{"ImpactPoint",1,{-0.138564,-0.088},1},{},{"ImpactPoint",1,{-0.14,6.73155e-009},1},{"ImpactPoint",1,{-0.16,7.6932e-009},1},{},{"ImpactPoint",1,{-0.121244,0.077},1},{"ImpactPoint",1,{-0.138564,0.088},1},{},{"ImpactPoint",1,{-0.07,0.133368},1},{"ImpactPoint",1,{-0.08,0.15242},1},{},{"ImpactPoint",1,{1.22392e-008,0.154},1},{"ImpactPoint",1,{1.39876e-008,0.176},1},{},{"ImpactPoint",1,{0.07,0.133368},1},{"ImpactPoint",1,{0.08,0.15242},1},{},{"ImpactPoint",1,{0.121244,0.077},1},{"ImpactPoint",1,{0.138564,0.088},1},{},{"ImpactPoint",1,{0.14,-1.83643e-009},1},{"ImpactPoint",1,{0.16,-2.09878e-009},1},{},{"ImpactPoint",1,{0.121244,-0.077},1},{"ImpactPoint",1,{0.138564,-0.088},1},{},{"ImpactPoint",1,{0.07,-0.133368},1},{"ImpactPoint",1,{0.08,-0.15242},1},{}};
                    };
                };
                class Bomb {
                    type = "group";
                    condition = "bomb";
                    class BombCrosshair {
                        width = 4;
                        type = "line";
                        points[] = {{"ImpactPoint",{0,0.1125},1},{"ImpactPoint",{0,0.1},1},{},{"ImpactPoint",{-0.09,0},1},{"ImpactPoint",{-0.08,0},1},{},{"ImpactPoint",{0.09,0},1},{"ImpactPoint",{0.08,0},1},{},{"ImpactPoint",{0,-0.0025},1},{"ImpactPoint",{0,0.0025},1},{},{"ImpactPoint",{-0.002,0},1},{"ImpactPoint",{0.002,0},1},{},{"ImpactPoint",{0,-0.1},1},{"ImpactPoint",{0.013888,-0.09848},1},{"ImpactPoint",{0.02736,-0.09397},1},{"ImpactPoint",{0.04,-0.0866},1},{"ImpactPoint",{0.051424,-0.0766},1},{"ImpactPoint",{0.06128,-0.06428},1},{"ImpactPoint",{0.06928,-0.05},1},{"ImpactPoint",{0.075176,-0.0342},1},{"ImpactPoint",{0.078784,-0.01736},1},{"ImpactPoint",{0.08,0},1},{"ImpactPoint",{0.078784,0.01736},1},{"ImpactPoint",{0.075176,0.0342},1},{"ImpactPoint",{0.06928,0.05},1},{"ImpactPoint",{0.06128,0.06428},1},{"ImpactPoint",{0.051424,0.0766},1},{"ImpactPoint",{0.04,0.0866},1},{"ImpactPoint",{0.02736,0.09397},1},{"ImpactPoint",{0.013888,0.09848},1},{"ImpactPoint",{0,0.1},1},{"ImpactPoint",{-0.013888,0.09848},1},{"ImpactPoint",{-0.02736,0.09397},1},{"ImpactPoint",{-0.04,0.0866},1},{"ImpactPoint",{-0.051424,0.0766},1},{"ImpactPoint",{-0.06128,0.06428},1},{"ImpactPoint",{-0.06928,0.05},1},{"ImpactPoint",{-0.075176,0.0342},1},{"ImpactPoint",{-0.078784,0.01736},1},{"ImpactPoint",{-0.08,0},1},{"ImpactPoint",{-0.078784,-0.01736},1},{"ImpactPoint",{-0.075176,-0.0342},1},{"ImpactPoint",{-0.06928,-0.05},1},{"ImpactPoint",{-0.06128,-0.06428},1},{"ImpactPoint",{-0.051424,-0.0766},1},{"ImpactPoint",{-0.04,-0.0866},1},{"ImpactPoint",{-0.02736,-0.09397},1},{"ImpactPoint",{-0.013888,-0.09848},1},{"ImpactPoint",{0,-0.1},1},{},{},{"ImpactPoint",-1,"Velocity",1,"NormalizeBombCircle",1,"ImpactPoint",1,{0,0},1},{"Velocity",1,"Limit0109",1,{0,0},1}};
                    };
                    class Circle {
                        type = "line";
                        width = 6;
                        points[] = {{"ImpactPoint",{0,-0.08},1},{"ImpactPoint",{0,-0.1},1},{"MissileFlightTimeRot1",{0,0.08},1,"ImpactPoint",1},{"MissileFlightTimeRot2",{0,0.08},1,"ImpactPoint",1},{"MissileFlightTimeRot3",{0,0.08},1,"ImpactPoint",1},{"MissileFlightTimeRot4",{0,0.08},1,"ImpactPoint",1},{"MissileFlightTimeRot5",{0,0.08},1,"ImpactPoint",1},{"MissileFlightTimeRot6",{0,0.08},1,"ImpactPoint",1},{"MissileFlightTimeRot7",{0,0.08},1,"ImpactPoint",1},{"MissileFlightTimeRot8",{0,0.08},1,"ImpactPoint",1},{"MissileFlightTimeRot9",{0,0.08},1,"ImpactPoint",1},{"MissileFlightTimeRot10",{0,0.08},1,"ImpactPoint",1},{"MissileFlightTimeRot11",{0,0.08},1,"ImpactPoint",1},{"MissileFlightTimeRot12",{0,0.08},1,"ImpactPoint",1},{"MissileFlightTimeRot13",{0,0.08},1,"ImpactPoint",1},{"MissileFlightTimeRot14",{0,0.08},1,"ImpactPoint",1},{"MissileFlightTimeRot15",{0,0.08},1,"ImpactPoint",1},{"MissileFlightTimeRot16",{0,0.08},1,"ImpactPoint",1},{"MissileFlightTimeRot17",{0,0.08},1,"ImpactPoint",1},{"MissileFlightTimeRot18",{0,0.08},1,"ImpactPoint",1},{"MissileFlightTimeRot19",{0,0.08},1,"ImpactPoint",1},{"MissileFlightTimeRot20",{0,0.08},1,"ImpactPoint",1},{"MissileFlightTimeRot20",{0,0.064},1,"ImpactPoint",1}};
                    };
                    class Distance {
                        type = "text";
                        source = "ImpactDistance";
                        sourceScale = 0.001;
                        sourcePrecision = 1;
                        max = 15;
                        align = "center";
                        scale = 1;
                        pos[] = {"ImpactPoint",{-0.002,0.11},1};
                        right[] = {"ImpactPoint",{0.045,0.11},1};
                        down[] = {"ImpactPoint",{-0.002,0.15},1};
                    };
                };
                class AAMissile {
                    condition = "AAmissile";
                    class Circle {
                        type = "line";
                        points[] = {{"WeaponAim",{0,-0.275},1},{"WeaponAim",{0.125,-0.23925},1},{"WeaponAim",{0.2175,-0.1375},1},{"WeaponAim",{0.25,0},1},{"WeaponAim",{0.2175,0.1375},1},{"WeaponAim",{0.125,0.23925},1},{"WeaponAim",{0,0.275},1},{"WeaponAim",{-0.125,0.23925},1},{"WeaponAim",{-0.2175,0.1375},1},{"WeaponAim",{-0.25,0},1},{"WeaponAim",{-0.2175,-0.1375},1},{"WeaponAim",{-0.125,-0.23925},1},{"WeaponAim",{0,-0.275},1},{},{"Target",{0,-0.077},1},{"Target",{0.07,0},1},{"Target",{0,0.077},1},{"Target",{-0.07,0},1},{"Target",{0,-0.077},1}};
                    };
                };
                class ATMissile {
                    condition = "ATmissile";
                    class Circle {
                        type = "line";
                        points[] = {{"WeaponAim",{0,-0.198},1},{"WeaponAim",{0.09,-0.17226},1},{"WeaponAim",{0.1566,-0.099},1},{"WeaponAim",{0.18,0},1},{"WeaponAim",{0.1566,0.099},1},{"WeaponAim",{0.09,0.17226},1},{"WeaponAim",{0,0.198},1},{"WeaponAim",{-0.09,0.17226},1},{"WeaponAim",{-0.1566,0.099},1},{"WeaponAim",{-0.18,0},1},{"WeaponAim",{-0.1566,-0.099},1},{"WeaponAim",{-0.09,-0.17226},1},{"WeaponAim",{0,-0.198},1},{},{"Target",{0,-0.077},1},{"Target",{0.07,0},1},{"Target",{0,0.077},1},{"Target",{-0.07,0},1},{"Target",{0,-0.077},1}};
                    };
                };
                class Rockets {
                    condition = "Rocket";
                    class Circle {
                        type = "line";
                        points[] = {{"ImpactPoint",{0.01,0},1},{"ImpactPoint",{-0.01,0},1},{},{"ImpactPoint",{0,0.011},1},{"ImpactPoint",{0,-0.011},1},{},{"ImpactPoint",{0,-0.132},1},{"ImpactPoint",{0.06,-0.11484},1},{"ImpactPoint",{0.1044,-0.066},1},{"ImpactPoint",{0.12,0},1},{"ImpactPoint",{0.1044,0.066},1},{"ImpactPoint",{0.06,0.11484},1},{"ImpactPoint",{0,0.132},1},{"ImpactPoint",{-0.06,0.11484},1},{"ImpactPoint",{-0.1044,0.066},1},{"ImpactPoint",{-0.12,0},1},{"ImpactPoint",{-0.1044,-0.066},1},{"ImpactPoint",{-0.06,-0.11484},1},{"ImpactPoint",{0,-0.132},1},{}};
                    };
                };
                class AltScale {
                    type = "scale";
                    scale = 1;
                    source = "altitudeASL";
                    sourceScale = 1;
                    align = "right";
                    pos[] = {0.86,0.82};
                    right[] = {0.94,0.82};
                    down[] = {0.86,0.87};
                    lineXleft = 0.825;
                    lineYright = 0.835;
                    lineXleftMajor = 0.825;
                    lineYrightMajor = 0.845;
                    bottom = 0.2;
                    top = 0.85;
                    center = 0.5;
                    step = 20;
                    StepSize = 0.0325;
                    horizontal = 0;
                    min = "none";
                    max = "none";
                    numberEach = 5;
                    majorLineEach = 5;
                };
                class SpeedScale {
                    type = "scale";
                    scale = 1;
                    source = "speed";
                    sourceScale = 3.6;
                    align = "right";
                    pos[] = {0.06,0.17};
                    right[] = {0.14,0.17};
                    down[] = {0.06,0.22};
                    lineXleft = 0.175;
                    lineYright = 0.165;
                    lineXleftMajor = 0.175;
                    lineYrightMajor = 0.155;
                    bottom = 0.85;
                    center = 0.5;
                    top = 0.2;
                    step = 20;
                    StepSize = 0.0325;
                    horizontal = 0;
                    min = "none";
                    max = "none";
                    numberEach = 5;
                    majorLineEach = 5;
                };
                class Gear {
                    condition = "ils";
                    class text {
                        type = "text";
                        source = "static";
                        text = "GEAR";
                        align = "right";
                        scale = 0.5;
                        sourceScale = 1;
                        pos[] = {{0.84,0.88},1};
                        right[] = {{0.9,0.88},1};
                        down[] = {{0.84,0.92},1};
                    };
                };
                class Flaps {
                    condition = "flaps";
                    class text {
                        type = "text";
                        source = "static";
                        text = "FLAPS";
                        align = "right";
                        scale = 0.5;
                        sourceScale = 1;
                        pos[] = {{0.84,0.93},1};
                        right[] = {{0.9,0.93},1};
                        down[] = {{0.84,0.97},1};
                    };
                };
                class weapons {
                    type = "text";
                    source = "weapon";
                    align = "right";
                    scale = 0.5;
                    sourceScale = 1;
                    pos[] = {{0.1,0.88},1};
                    right[] = {{0.16,0.88},1};
                    down[] = {{0.1,0.92},1};
                };
                class ammo {
                    type = "text";
                    source = "ammo";
                    align = "right";
                    scale = 0.5;
                    sourceScale = 1;
                    pos[] = {{0.1,0.93},1};
                    right[] = {{0.16,0.93},1};
                    down[] = {{0.1,0.97},1};
                };
                class VspeedNumber {
                    type = "text";
                    align = "right";
                    scale = 1;
                    source = "vspeed";
                    sourceScale = 1;
                    pos[] = {{0.86,0.12},1};
                    right[] = {{0.94,0.12},1};
                    down[] = {{0.86,0.17},1};
                };
                class HeadingScale {
                    type = "scale";
                    scale = 1;
                    source = "Heading";
                    sourceScale = 1;
                    align = "center";
                    pos[] = {0.2,0};
                    right[] = {0.28,0};
                    down[] = {0.2,0.05};
                    lineXleft = 0.06;
                    lineYright = 0.05;
                    lineXleftMajor = 0.06;
                    lineYrightMajor = 0.04;
                    bottom = 0.8;
                    center = 0.5;
                    top = 0.2;
                    step = 2;
                    StepSize = 0.03;
                    horizontal = 1;
                    min = "none";
                    max = "none";
                    numberEach = 5;
                    majorLineEach = 5;
                };
                class ILS {
                    condition = "ils";
                    class Glideslope {
                        clipTL[] = {0,0};
                        clipBR[] = {1,1};
                        class ILS {
                            type = "line";
                            points[] = {{"ILS_W",{-0.24,0},1},{"ILS_W",{0.24,0},1},{},{"ILS_W",{0,0.0264},1},{"ILS_W",{0,-0.0264},1},{},{"ILS_W",{0.12,0.0264},1},{"ILS_W",{0.12,-0.0264},1},{},{"ILS_W",{0.24,0.0264},1},{"ILS_W",{0.24,-0.0264},1},{},{"ILS_W",{-0.12,0.0264},1},{"ILS_W",{-0.12,-0.0264},1},{},{"ILS_W",{-0.24,0.0264},1},{"ILS_W",{-0.24,-0.0264},1},{},{"ILS_H",{0,-0.264},1},{"ILS_H",{0,0.264},1},{},{"ILS_H",{0.024,0},1},{"ILS_H",{-0.024,0},1},{},{"ILS_H",{0.024,0.132},1},{"ILS_H",{-0.024,0.132},1},{},{"ILS_H",{0.024,0.264},1},{"ILS_H",{-0.024,0.264},1},{},{"ILS_H",{0.024,-0.132},1},{"ILS_H",{-0.024,-0.132},1},{},{"ILS_H",{0.024,-0.264},1},{"ILS_H",{-0.024,-0.264},1}};
                        };
                    };
                };
            };
        };
    };
};
