class CfgAmmo {
    class G_40mm_HE;
    class GVAR(he): G_40mm_HE {
        // 40->30mm conversion
    };
    class G_40mm_HEDP;
    class GVAR(hedp): G_40mm_HEDP {
        // 40->30mm conversion
    };
    class GVAR(airburst): GVAR(he) {
        class Eventhandlers {
            fired = QUOTE(call ace_xm157_fnc_airburst_ammoFired);
        };
    };
    class CUP_12Gauge_Pellets_Submunition_No00_Buck;
    class GVAR(00buckshot): CUP_12Gauge_Pellets_Submunition_No00_Buck {
        hit = 10;
        typicalSpeed = 365;
        submunitionAmmo = QGVAR(00buckshot_deploy);
        submunitionConeType[] = {"poissondisc", 18};
        submunitionConeAngle = 0.95;
    };
    class CUP_12Gauge_Pellets_Submunition_No00_Buck_Deploy;
    class GVAR(00buckshot_deploy): CUP_12Gauge_Pellets_Submunition_No00_Buck_Deploy {
        hit = 6;
        typicalSpeed = 365;
    };
};
