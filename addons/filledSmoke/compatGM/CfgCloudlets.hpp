class CfgCloudlets {
    class EGVAR(filledSmoke,SmokeShellWhiteFilled);
    class EGVAR(filledSmoke,SmokeShellWhiteFilled_GM): EGVAR(filledSmoke,SmokeShellWhiteFilled) {
        animationSpeedCoef = 0.75; //default 1
        colorCoef[] = {"colorR", "colorG", "colorB", 3}; //default 1.8
        sizeCoef = 2; //default 1
        interval = 0.13; //default 0.2
        lifeTime = 22; //default 14
        moveVelocity[] = {0,0.2,0}; //default {0,0.3,0}
        weight = 3.2; //default 1.26
        volume = 2.5; //default 1
        destroyAfterCrossing = 1;
        destroyOnWaterSurfaceOffset = 0.1;
    };
};

class EGVAR(filledSmoke,bigSmoke_GM) {
    class SmokeShellWhite {
        simulation = "particles";
        type = QEGVAR(filledSmoke,SmokeShellWhiteFilled);
        position[] = {0,0,0};
        intensity = 5;
        interval = 0.333;
    };
};
