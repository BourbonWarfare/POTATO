class CfgWeapons {
    class gm_mp2a1_blk;
    class gm_mp2a1_gld: gm_mp2a1_blk {
        displayName = "MP2A1 9x19mm (Gold)";
        magazines[] = {
            "gm_32Rnd_9x19mm_b_DM51_mp2_blk",
            "gm_32Rnd_9x19mm_b_DM11_mp2_blk",
            "gm_32Rnd_9x19mm_ap_DM91_mp2_blk"
        };
        hiddenSelectionsTextures[] = {
            "\gm\gm_weapons\gm_machinepistols\gm_mp2\data\gld\gm_mp2a1_ext_01_gld_co.paa"
        };
    };

    class gm_autoCannon_base;
    class gm_145mm_kpvt_base: gm_autoCannon_base {
        class GunParticles {
            class Effect_01 {
                directionName = "MainTurret_Gun_pos";
                effectName = QGVARMAIN(MachineGunCloud);
                positionName = "MainTurret_Gun_dir";
            };
        };
    };
};
