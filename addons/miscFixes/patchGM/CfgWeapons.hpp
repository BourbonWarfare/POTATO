class CfgWeapons {
    class gm_dk_uniform_soldier_84_base;
    class gm_dk_army_uniform_soldier_84_m84: gm_dk_uniform_soldier_84_base {
        class ItemInfo;
    };
    class gm_xx_army_uniform_alp_full: gm_dk_army_uniform_soldier_84_m84 {
        displayName = "Fatigues (Mountain, Alpenflage)";
        hiddenSelectionsTextures[] = {
            "gm\gm_characters\gm_xx_characters\gm_xx_revolutionaries\data\gm_xx_uniform_fighter_01_alp_co",
            "gm\gm_characters\gm_xx_characters\gm_xx_revolutionaries\data\gm_xx_uniform_fighter_04_alp_co"
        };
        class ItemInfo: ItemInfo {
            uniformClass = "gm_xx_army_rifleman_01_akm_alp_full";
        };
        side = 2;
    };
};
