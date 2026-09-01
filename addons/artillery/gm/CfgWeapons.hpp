class gm_SemiAuto;
class CfgWeapons {
    class gm_mortar_base;
    class gm_120mm_m120_base: gm_mortar_base {
        class range_01_single: gm_SemiAuto {};
        class range_02_single: range_01_single {
            textureType = "burst";
        };
        class range_03_single: range_01_single {
            textureType = "fullAuto";
        };
    };
    class gm_120mm_2b11_base: gm_mortar_base {
        class range_01_single: gm_SemiAuto {};
        class range_02_single: range_01_single {
            textureType = "burst";
        };
        class range_03_single: range_01_single {
            textureType = "fullAuto";
        };
    };
};
