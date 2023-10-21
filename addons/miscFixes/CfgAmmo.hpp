class CfgAmmo {
    
    // Fix smoke bounce (downside is gl smokes lose some sound effects)
    class SmokeShell;
    class G_40mm_Smoke: SmokeShell {
        simulation = "shotSmoke";
        deflectionSlowDown = 0.2;
    };
};
