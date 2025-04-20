class CfgVehicles {
    class gm_wheeled_APC_base;

    /// BRDM-2s
    // Armed BRDM-2s
    class gm_brdm2_base: gm_wheeled_APC_base {
        ACEGVAR(vehicle_damage,hullDetonationProb) = 0;
        ACEGVAR(vehicle_damage,turretDetonationProb) = 0.2;
        ACEGVAR(vehicle_damage,engineDetonationProb) = 0.2;
        ACEGVAR(vehicle_damage,hullFireProb) = 0.5;
        ACEGVAR(vehicle_damage,turretFireProb) = 0.7;
        ACEGVAR(vehicle_damage,engineFireProb) = 0.7;
        ACEGVAR(vehicle_damage,detonationDuringFireProb) = 0.5;
        ACEGVAR(vehicle_damage,canHaveFireRing) = 0;
        ACEGVAR(cookoff,canHaveFireJet) = 0;
    };
    // Unarmed BRDM-2s
    class gm_brdm2um_base: gm_brdm2_base {
        ACEGVAR(vehicle_damage,hullDetonationProb) = 0;
        ACEGVAR(vehicle_damage,turretDetonationProb) = 0;
        ACEGVAR(vehicle_damage,engineDetonationProb) = 0.2;
        ACEGVAR(vehicle_damage,hullFireProb) = 0.5;
        ACEGVAR(vehicle_damage,turretFireProb) = 0;
        ACEGVAR(vehicle_damage,engineFireProb) = 0.7;
        ACEGVAR(vehicle_damage,detonationDuringFireProb) = 0.5;
        ACEGVAR(vehicle_damage,canHaveFireRing) = 0;
        ACEGVAR(cookoff,canHaveFireJet) = 0;
    };

    /// BTR-60s
    // Unarmed or external gun
    class gm_btr60_base: gm_wheeled_APC_base {
        ACEGVAR(vehicle_damage,hullDetonationProb) = 0;
        ACEGVAR(vehicle_damage,turretDetonationProb) = 0;
        ACEGVAR(vehicle_damage,engineDetonationProb) = 0.2;
        ACEGVAR(vehicle_damage,hullFireProb) = 0.2;
        ACEGVAR(vehicle_damage,turretFireProb) = 0;
        ACEGVAR(vehicle_damage,engineFireProb) = 0.7;
        ACEGVAR(vehicle_damage,detonationDuringFireProb) = 0.5;
        ACEGVAR(vehicle_damage,canHaveFireRing) = 0;
        ACEGVAR(cookoff,canHaveFireJet) = 0;
    };
    // KPVT Turret
    class gm_btr60pb_base: gm_btr60_base {
        ACEGVAR(vehicle_damage,hullDetonationProb) = 0;
        ACEGVAR(vehicle_damage,turretDetonationProb) = 0.2;
        ACEGVAR(vehicle_damage,engineDetonationProb) = 0.2;
        ACEGVAR(vehicle_damage,hullFireProb) = 0.2;
        ACEGVAR(vehicle_damage,turretFireProb) = 0.7;
        ACEGVAR(vehicle_damage,engineFireProb) = 0.7;
        ACEGVAR(vehicle_damage,detonationDuringFireProb) = 0.5;
        ACEGVAR(vehicle_damage,canHaveFireRing) = 0;
        ACEGVAR(cookoff,canHaveFireJet) = 0;
    };

    /// OT-64
    // Armed
    class gm_ot64_base: gm_wheeled_APC_base {
        ACEGVAR(vehicle_damage,hullDetonationProb) = 0;
        ACEGVAR(vehicle_damage,turretDetonationProb) = 0.2;
        ACEGVAR(vehicle_damage,engineDetonationProb) = 0.2;
        ACEGVAR(vehicle_damage,hullFireProb) = 0.2;
        ACEGVAR(vehicle_damage,turretFireProb) = 0.7;
        ACEGVAR(vehicle_damage,engineFireProb) = 0.7;
        ACEGVAR(vehicle_damage,detonationDuringFireProb) = 0.5;
        ACEGVAR(vehicle_damage,canHaveFireRing) = 0;
        ACEGVAR(cookoff,canHaveFireJet) = 0;
    };

    /// Fuchs
    class gm_fuchs_base: gm_wheeled_APC_base {
        ACEGVAR(vehicle_damage,hullDetonationProb) = 0;
        ACEGVAR(vehicle_damage,turretDetonationProb) = 0;
        ACEGVAR(vehicle_damage,engineDetonationProb) = 0.1;
        ACEGVAR(vehicle_damage,hullFireProb) = 0.2;
        ACEGVAR(vehicle_damage,turretFireProb) = 0.05;
        ACEGVAR(vehicle_damage,engineFireProb) = 0.5;
        ACEGVAR(vehicle_damage,detonationDuringFireProb) = 0.5;
        ACEGVAR(vehicle_damage,canHaveFireRing) = 0;
        ACEGVAR(cookoff,canHaveFireJet) = 0;

    };

    /// Luchs
    class gm_luchs_base: gm_wheeled_APC_base {
        ACEGVAR(vehicle_damage,hullDetonationProb) = 0;
        ACEGVAR(vehicle_damage,turretDetonationProb) = 0.2;
        ACEGVAR(vehicle_damage,engineDetonationProb) = 0.2;
        ACEGVAR(vehicle_damage,hullFireProb) = 0.2;
        ACEGVAR(vehicle_damage,turretFireProb) = 0.4;
        ACEGVAR(vehicle_damage,engineFireProb) = 0.5;
        ACEGVAR(vehicle_damage,detonationDuringFireProb) = 0.5;
        ACEGVAR(vehicle_damage,canHaveFireRing) = 0;
        ACEGVAR(cookoff,canHaveFireJet) = 1;
    };
};