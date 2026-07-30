class CfgAmmo {

    // Fix smoke bounce (downside is gl smokes lose some sound effects)
    class SmokeShell;
    class G_40mm_Smoke: SmokeShell {
        simulation = "shotSmoke";
        deflectionSlowDown = 0.2;
    };
    // Tank shells engage air targets
    class ShellBase;
    class Sh_120mm_APFSDS: ShellBase {
        airLock = 1;
    };
    class Sh_120mm_HE: ShellBase {
        airLock = 1;
    };
};
