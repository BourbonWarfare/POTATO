#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core"};
        author = "Potato";
        authors[] = {"AACO"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CfgCloudlets {
    class SmokeShellWhiteSmall;
    class GVAR(SmokeShellWhiteFilled): SmokeShellWhiteSmall {
        animationSpeedCoef=0.75; //default 1
        colorCoef[] = {"colorR", "colorG", "colorB", 3}; //default 1.8
        sizeCoef = 2; //default 1
        interval = 0.13; //default 0.2
        lifeTime = 22; //default 14
        moveVelocity[] = {0,0.1,0}; //default {0,0.3,0}
        weight = 6.4; //default 1.26
        volume = 5; //default 1
        destroyOnWaterSurface = 1;
        destroyOnWaterSurfaceOffset = 0.05; //default -0.3
        destroyAfterCrossing = "true";
        onSurface = "true";
        keepOnSurface = "true";
    };
};

class GVAR(bigSmoke) {
    class SmokeShellWhite {
        simulation = "particles";
        type = QGVAR(SmokeShellWhiteFilled);
        position[] = {0,0,0};
        intensity = 5;
        interval = 0.333;
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
};
