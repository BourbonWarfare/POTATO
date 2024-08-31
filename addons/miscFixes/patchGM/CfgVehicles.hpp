class CfgVehicles {
    // Full body Alpenflage character
    class gm_xx_army_rifleman_01_akm_alp;
    class gm_xx_army_rifleman_01_akm_alp_full: gm_xx_army_rifleman_01_akm_alp {
        displayName = "Rifleman (Mountain)";
        hiddenSelectionsTextures[] = {
            "gm\gm_characters\gm_xx_characters\gm_xx_revolutionaries\data\gm_xx_uniform_fighter_01_alp_co",
            "gm\gm_characters\gm_xx_characters\gm_xx_revolutionaries\data\gm_xx_uniform_fighter_04_alp_co"
        };
        model = "\gm\gm_characters\gm_dk_characters\gm_dk_uniform_soldier_84";
        Items[] = {
            "gm_ge_army_gauzeBandage",
            "gm_ge_army_burnBandage"
        };
        linkedItems[] = {
            "ItemCompass",
            "gm_watch_kosei_80",
            "ItemRadio",
            "itemMap",
            "gm_ge_army_vest_80_rifleman",
            "gm_ge_headgear_m92_cover_oli"
        };
        magazines[] = {
            "gm_30Rnd_556x45mm_B_DM11_sg550_brn",
            "gm_30Rnd_556x45mm_B_DM11_sg550_brn",
            "gm_30Rnd_556x45mm_B_DM11_sg550_brn",
            "gm_30Rnd_556x45mm_B_DM11_sg550_brn",
            "HandGrenade",
            "HandGrenade"
        };
        weapons[] = {
            "Throw",
            "Put",
            "gm_sg550_blk"
        };
        RespawnItems[] = {
            "gm_ge_army_gauzeBandage",
            "gm_ge_army_burnBandage"
        };
        RespawnLinkedItems[] = {
            "ItemCompass",
            "gm_watch_kosei_80",
            "ItemRadio",
            "itemMap",
            "gm_ge_army_vest_80_rifleman",
            "gm_ge_headgear_m92_cover_oli"
        };
        RespawnMagazines[] = {
            "gm_30Rnd_556x45_B_DM11_sg550_brn",
            "gm_30Rnd_556x45_B_DM11_sg550_brn",
            "gm_30Rnd_556x45_B_DM11_sg550_brn",
            "gm_30Rnd_556x45_B_DM11_sg550_brn",
            "HandGrenade",
            "HandGrenade"
        };
        RespawnWeapons[] = {
            "Throw",
            "Put",
            "gm_sg550_blk"
        };
        scope = 1;
        scopeCurator = 0;
        uniformClass = "gm_xx_army_uniform_alp_full";
    };


    /// Add GM bridges
    class gm_structure_euro_80_base;
    class GVAR(land_basic_gm_structure_euro_bridge_base): gm_structure_euro_80_base {
        _generalMacro = "House_F";
        destrType = "destructBuilding";
        editorSubcategory = "gm_edsubcat_infrastructure_euro_80";
        simulation = "house";
        armor = 6000;
        class AttributeValues {
            objectIsSimple = 0;
        };
        class DestructionEffects {
            class DestroyPhase1 {
                intensity = 1;
                lifeTime = 0;
                interval = 1;
                position = "";
                simulation = "destroy";
                type = "DelayedDestruction";
            };
        };
    };

    // Single pier bridges
    class lmd_land_gm_euro_bridge_02_20_mainroad: GVAR(land_basic_gm_structure_euro_bridge_base) {
        displayName = "Two-Lane Bridge";
        model = "\gm\gm_structures\gm_roads_euro_80\gm_euro_bridge_02_20_mainroad.p3d";
        scope = 2;
        scopeCurator = 2;
        class Destruction {
            animations[] = {
                {"gm\gm_structures\gm_roads_euro_80\data\anims\bridge_02_destruct_01.rtm", 0.1, 1},
                {"gm\gm_structures\gm_roads_euro_80\data\anims\bridge_02_destruct_02.rtm", 0.1, 1},
                {"gm\gm_structures\gm_roads_euro_80\data\anims\bridge_02_destruct_03.rtm", 0.1, 1},
                {"gm\gm_structures\gm_roads_euro_80\data\anims\bridge_02_destruct_04.rtm", 0.1, 1}
            };
        };
        class HitPoints {
            class segment_01_hp {
                armor = 1;
                convexComponent = "segment_01";
                explosionShielding = 12;
                material = -1;
                minimalHit = 0.11;
                name = "segment_01_hp";
                passThrough = 1;
                radius = 0.6;
            };
            class segment_02_hp: segment_01_hp {
                convexComponent = "segment_02";
                name = "segment_02_hp";
            };
        };
        class AnimationSources {
            class segment_01_source {
                hitpoint = "segment_01_hp";
                raw = 1;
                source = "Hit";
            };
            class segment_02_source: segment_01_source {
                hitpoint = "segment_02_hp";
            };
        };
        class SimpleObject {
                animate [] = {};
                eden = 1;
                hide[] = {};
                init = "''";
                verticalOffset = 12.3;
                verticalOffsetWorld = 0;
        };
    };
    class lmd_land_gm_euro_bridge_02_20_mainroad_win: lmd_land_gm_euro_bridge_02_20_mainroad {
        displayName = "Two-Lane Bridge";
        editorCategory = "gm_edcat_structures_weferlingen_winter";
        model = "\gm\gm_structures\gm_structures_euro_80_winter\roads\gm_euro_bridge_02_20_mainroad_win.p3d";
    };
    class lmd_land_gm_euro_bridge_02_20_normalroad: lmd_land_gm_euro_bridge_02_20_mainroad {
        displayName = "One-Lane Bridge";
        model = "\gm\gm_structures\gm_roads_euro_80\gm_euro_bridge_02_20_normalroad.p3d";
    };
    class lmd_land_gm_euro_bridge_02_20_normalroad_win: lmd_land_gm_euro_bridge_02_20_normalroad {
        displayName = "One-Lane Bridge";
        editorCategory = "gm_edcat_structures_weferlingen_winter";
        model = "\gm\gm_structures\gm_structures_euro_80_winter\roads\gm_euro_bridge_02_20_normalroad_win.p3d";
    };
    class lmd_land_gm_euro_bridge_02_20_mainroad_half: lmd_land_gm_euro_bridge_02_20_mainroad {
        displayName = "Two-Lane Bridge (Single Collapse)";
        model = "\gm\gm_structures\gm_roads_euro_80\gm_euro_bridge_02_20_mainroad_half.p3d";
    };
    class lmd_land_gm_euro_bridge_02_20_mainroad_half_win: lmd_land_gm_euro_bridge_02_20_mainroad {
        displayName = "Two-Lane Bridge (Single Collapse)";
        editorCategory = "gm_edcat_structures_weferlingen_winter";
        model = "\gm\gm_structures\gm_structures_euro_80_winter\roads\gm_euro_bridge_02_20_mainroad_half_win.p3d";
    };
    class lmd_land_gm_euro_bridge_02_20_normalroad_half: lmd_land_gm_euro_bridge_02_20_mainroad {
        displayName = "One-Lane Bridge (Single Collapse)";
        model = "\gm\gm_structures\gm_roads_euro_80\gm_euro_bridge_02_20_normalroad_half.p3d";
    };
    class lmd_land_gm_euro_bridge_02_20_normalroad_half_win: lmd_land_gm_euro_bridge_02_20_normalroad {
        displayName = "One-Lane Bridge (Single Collapse)";
        editorCategory = "gm_edcat_structures_weferlingen_winter";
        model = "\gm\gm_structures\gm_structures_euro_80_winter\roads\gm_euro_bridge_02_20_normalroad_half_win.p3d";
    };

    // Arch bridges
    class lmd_land_gm_euro_bridge_01_25_badroad: GVAR(land_basic_gm_structure_euro_bridge_base) {
        displayName = "Arch Bridge";
        model = "\gm\gm_structures\gm_roads_euro_80\gm_euro_bridge_01_25_badroad.p3d";
        scope = 2;
        scopeCurator = 2;
        class Destruction {
            animations[] = {
                {"gm\gm_structures\gm_roads_euro_80\data\anims\bridge_01_destruct_01.rtm", 0.1, 1}
            };
        };
        class SimpleObject {
            animate [] = {};
            eden = 1;
            hide[] = {};
            init = "''";
            verticalOffset = 10.4;
            verticalOffsetWorld = 0;
        };
    };
    class lmd_land_gm_euro_bridge_01_25_badroad_win: lmd_land_gm_euro_bridge_01_25_badroad {
        displayName = "Arch Bridge";
        editorCategory = "gm_edcat_structures_weferlingen_winter";
        model = "\gm\gm_structures\gm_structures_euro_80_winter\roads\gm_euro_bridge_01_25_badroad_win.p3d";
    };
    class lmd_land_gm_euro_bridge_01_25_patrolPath: lmd_land_gm_euro_bridge_01_25_badroad {
        displayName = "Patrol Path Bridge";
        model = "\gm\gm_structures\gm_roads_euro_80\gm_euro_bridge_01_25_patrolpath.p3d";
    };
    class lmd_land_gm_euro_bridge_01_25_patrolPath_win: lmd_land_gm_euro_bridge_01_25_badroad_win {
        displayName = "Patrol Path Bridge";
        model = "\gm\gm_structures\gm_structures_euro_80_winter\roads\gm_euro_bridge_01_25_patrolpath_win.p3d";
    };
    class lmd_land_gm_euro_bridge_01_25_track: lmd_land_gm_euro_bridge_01_25_badroad {
        displayName = "Dirt Track Bridge";
        model = "\gm\gm_structures\gm_roads_euro_80\gm_euro_bridge_01_25_track.p3d";
    };
    class lmd_land_gm_euro_bridge_01_25_track_win: lmd_land_gm_euro_bridge_01_25_badroad_win {
        displayName = "Dirt Track Bridge";
        model = "\gm\gm_structures\gm_structures_euro_80_winter\roads\gm_euro_bridge_01_25_track_win.p3d";
    };

    // Highway bridges
    class lmd_land_gm_euro_bridge_03_50_highway: GVAR(land_basic_gm_structure_euro_bridge_base) {
        displayName = "Highway Bridge";
        model = "\gm\gm_structures\gm_roads_euro_80\gm_euro_bridge_03_50_highway.p3d";
        scope = 2;
        scopeCurator = 2;
        class Destruction {
            animations[] = {
                {"gm\gm_structures\gm_roads_euro_80\data\anims\bridge_03_destruct_01.rtm", 0.01, 1}
            };
        };
        class SimpleObject {
            animate [] = {};
            eden = 1;
            hide[] = {};
            init = "''";
            verticalOffset = 2.2;
            verticalOffsetWorld = 0;
        };
    };
    class lmd_land_gm_euro_bridge_03_50_highway_win: lmd_land_gm_euro_bridge_03_50_highway {
        displayName = "Highway Bridge";
        editorCategory = "gm_edcat_structures_weferlingen_winter";
        model = "\gm\gm_structures\gm_structures_euro_80_winter\roads\gm_euro_bridge_03_50_highway_win.p3d";
    };
    class lmd_land_gm_euro_bridge_03_50_highway_half: lmd_land_gm_euro_bridge_03_50_highway {
        displayName = "Highway Bridge (Single Collapse)";
        model = "\gm\gm_structures\gm_roads_euro_80\gm_euro_bridge_03_50_highway_half.p3d";

    };
    class lmd_land_gm_euro_bridge_03_50_highway_half_win: lmd_land_gm_euro_bridge_03_50_highway_win {
        displayName = "Highway Bridge (Single Collapse)";
        model = "\gm\gm_structures\gm_structures_euro_80_winter\roads\gm_euro_bridge_03_50_highway_half_win.p3d";
    };
};
