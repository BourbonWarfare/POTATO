class CfgAmmo {
    class FlareCore;
    class FlareBase: FlareCore {};

    class Flare_82mm_AMOS_White: FlareCore {
        intensity = 2500000; // vanilla: 10000
    };
    
    // BIS base gl-flare
    class F_40mm_White: FlareBase {
        intensity = 1250000; // vanilla: 10000
        timeToLive = 40; // vanilla: 25
        coefGravity = 0.25; // vanilla: undefined (would be 1)
        // Makes the ammo fall the ground slower
    };

    // CUP
    class CUP_Sub_F_40mm_StarCluster_White: F_40mm_White {
        intensity = 1250000; // rhs: 100000
        timeToLive = 40; // rhs: 60
    };
    class CUP_Sub_F_40mm_StarCluster_Red: F_40mm_White {
        intensity = 1250000; // rhs: 100000
        timeToLive = 40; // rhs: 60
    };
    class CUP_Sub_F_40mm_StarCluster_Green: F_40mm_White {
        intensity = 1250000; // rhs: 100000
        timeToLive = 40; // rhs: 60
    };

    // Leave colored flares for signaling, matching RHS values
    class F_40mm_Green: F_40mm_White {
        brightness = 25;
        timeToLive = 60;
        intensity = 100000;
        coefGravity = 1;
    };
    class F_40mm_Red: F_40mm_White {
        brightness = 25;
        timeToLive = 60;
        intensity = 100000;
        coefGravity = 1;
    };
    class F_40mm_Yellow: F_40mm_White {
        brightness = 25;
        timeToLive = 60;
        intensity = 100000;
        coefGravity = 1;
    };
    class F_40mm_Cir: F_40mm_White {
        brightness = 25;
        timeToLive = 60;
        intensity = 100000;
        coefGravity = 1;
    };
};
