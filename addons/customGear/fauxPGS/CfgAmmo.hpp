class CfgAmmo {
    class G_40mm_HE;
    class GVAR(he): G_40mm_HE {
        // cartridge = "FxCartridge_abgrenade"; // from CUP_Weapons_XM29
        hit = 65;
        indirectHit = 6;
        indirectHitRange = 5;
    };
    class G_40mm_HEDP;
    class GVAR(hedp): G_40mm_HEDP {
        // cartridge = "FxCartridge_abgrenade";
        hit = 90;
        indirectHit = 4;
        indirectHitRange = 3;
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
