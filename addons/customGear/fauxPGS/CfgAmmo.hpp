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
};
