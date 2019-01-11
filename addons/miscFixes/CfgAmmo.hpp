class CfgAmmo {
    
    // Testing smoke bounce
    class G_40mm_SmokePurple;
    class GVAR(G_40mm_SmokePurple): G_40mm_SmokePurple {
		simulation = "shotSmoke";
		deflectionSlowDown = 0;
    };
    class GVAR(G_40mm_SmokeBlue): G_40mm_SmokePurple {
        submunitionAmmo = "SmokeShellBlue";
        simulation = "shotDeploy";
    };
    
    
    class B_65x39_Case;
    class B_65x39_Case_red: B_65x39_Case {
        model = "\A3\Weapons_f\Data\bullettracer\tracer_red";
    };
};
