#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core", "rhs_c_weapons"};
        author[] = {"AACO"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CfgCloudlets {
    class SmokeShellWhiteSmall;
    class GVAR(SmokeShellWhiteFilled): SmokeShellWhiteSmall {
        animationSpeedCoef=0.75; //default 1
        colorCoef[] = {"colorR", "colorG", "colorB", 3}; //default 1.8
        // particleFSNtieth = 16; //default 16
        // particleFSIndex = 12; //default 12
        // particleFSFrameCount = 8; //default 8
        sizeCoef = 2; //default 1
        interval = 0.125; //default 0.2
        lifeTime = 24; //default 14
        moveVelocity[] = {0,0.1,0}; //default {0,0.3,0}
        weight = 6.4; //default 1.26
        volume = 5; //default 1
        // rubbing = 0.05; //default 0.05
        // size[] = {0.2,6,10}; //default {0.2,6,10}
        // color[] = {
        // {0.7,0.7,0.7,0.24},
        // {0.7,0.7,0.7,0.26},
        // {0.7,0.7,0.7,0.25},
        // {0.7,0.7,0.7,0.22},
        // {0.7,0.7,0.7,0.18},
        // {0.7,0.7,0.7,0.1},
        // {0.7,0.7,0.7,0.01}
        // };
        // randomDirectionPeriod= 0.3; //default 0.3
        // randomDirectionIntensity = 0.15; //default 0.15
        // destroyOnWaterSurfaceOffset = -0.3; //default -0.3
        // MoveVelocityVar[] = {0.5,0.2,0.5}; //default {0.5,0.2,0.5}
        // sizeVar = 0.6; //default 0.6
        // colorVar[] = {0,0,0,0.05}; //default {0,0,0,0.05}
    };
};

class GVAR(bigSmoke) {
    class SmokeShellWhite {
        simulation = "particles";
        type = QGVAR(SmokeShellWhiteFilled);
        position[] = {0,0,0};
        intensity = 5;
        interval = .333;
    };
};

class CfgAmmo {
    class GrenadeHand;
    class SmokeShell: GrenadeHand {
        effectsSmoke = QGVAR(bigSmoke);
    };
    class SmokeShellArty: SmokeShell {
        effectsSmoke = QGVAR(bigSmoke);
    };
    class rhs_ammo_rdg2_white: SmokeShell {
        effectsSmoke = QGVAR(bigSmoke);
    };
    class rhs_ammo_rdg2_black: rhs_ammo_rdg2_white {
        effectsSmoke = QGVAR(bigSmoke);
    };
};
