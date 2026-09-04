class Mode_SemiAuto;
class CfgWeapons {
    class CannonCore;
    class RocketPods;
    ADD_MAGAZINES_1_WEAPON(RocketPods,rockets_230mm_GAT,12Rnd_230mm_rockets);
    ADD_MAGAZINES_3_WEAPON(CannonCore,mortar_155mm_AMOS,32Rnd_155mm_Mo_shells,2Rnd_155mm_Mo_guided,4Rnd_155mm_Mo_guided);
    class mortar_82mm: CannonCore {
        magazines[] += {MAGAZINE_PAIRS(8Rnd_82mm_Mo_shells), MAGAZINE_PAIRS(8Rnd_82mm_Mo_guided)};
        class Single1: Mode_SemiAuto {};
        class Single2: Single1 {
            textureType = "burst";
        };
        class Single3: Single1 {
            textureType = "fullAuto";
        };
    };
};
