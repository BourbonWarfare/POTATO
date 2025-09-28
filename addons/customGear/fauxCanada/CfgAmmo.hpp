class CfgAmmo {
    class gm_shell_105x617mm_HESH_T_dm512;
    class GVARMAIN(Sh_105x617mmR_m416_WPT): gm_shell_105x617mm_HESH_T_dm512 {
        caliber = 0.01;
        hit = 24;
        explosive = 0.05;
        indirectHit = 2;
        indirectHitRange = 1;
        submunitionAmmo = QGVARMAIN(SmokeShellTank_105x617mmR);
        submunitionInitialOffset[] = {0,0,-1};
        submunitionInitSpeed = 0.1;
        submunitionParentSpeedCoef = 0;
    };
    class SmokeShellArty;
    class GVARMAIN(SmokeShellTank): SmokeShellArty {
        class EventHandlers {
            class ADDON {
                init = QUOTE(_this call FUNC(canonSmoke));
            };
        };
        effectsSmoke = QEGVAR(filledSmoke,bigSmoke_GM);
        timeToLive = 30;
    };
    class GVARMAIN(SmokeShellTank_105x617mmR): GVARMAIN(SmokeShellTank) {
        class EventHandlers {
            class ADDON {
                init = QUOTE(_this call FUNC(canonSmoke));
            };
        };
        effectsSmoke = QEGVAR(filledSmoke,bigSmoke_GM);
        timeToLive = 20;
    };
};
