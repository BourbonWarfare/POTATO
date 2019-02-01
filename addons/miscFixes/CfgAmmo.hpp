class CfgAmmo {
    
    // Fix smoke bounce (downside is gl smokes lose some sound effects)
    class SmokeShell;
    class G_40mm_Smoke: SmokeShell {
		simulation = "shotSmoke";
		deflectionSlowDown = 0.2;
    };
    
    
    class B_65x39_Case;
    class B_65x39_Case_red: B_65x39_Case {
        model = "\A3\Weapons_f\Data\bullettracer\tracer_red";
    };
};
