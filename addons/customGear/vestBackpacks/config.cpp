#include "\z\potato\addons\customGear\script_component.hpp"
#undef COMPONENT
#define COMPONENT customGear_vestBackpacks

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "CUP_Weapons_LoadOrder", "CUP_Creatures_People_LoadOrder" };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CfgVehicles {
    // Adds copies of the BAF Osprey Mk4 belt and webbing, and the Russian Smersh (Olive/Coyote) as backpacks
    class Bag_Base;
    class potato_Osprey_Mk4_Belt: Bag_Base { 
        author = "AChesheireCat";
        scope = 2;
        displayName = "Osprey Mk4 Battle Belt";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\CUP_vests\webbing\data\UI\osprey_mk4_belt_ca.paa";
        model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\CUP_vests\webbing\osprey_mk4_belt.p3d";
        hiddenSelections[] = {"camo1","camo2"};
        hiddenSelectionsTextures[] = {"CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\CUP_vests\osprey_mk4\data\equip_co.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\CUP_vests\osprey_mk4\data\gear_co.paa"};
        maximumLoad = 160;
        mass = 25;
    };
    class potato_Osprey_Mk4_Webbing: Bag_Base {
        author = "AChesheireCat";
        scope = 2;
        displayName = "Osprey Mk4 Webbing";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\CUP_vests\webbing\data\UI\osprey_mk4_webbing_ca.paa";
        model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\CUP_vests\webbing\osprey_mk4_webbing.p3d";
        hiddenSelections[] = {"camo","camo1","camo2"};
        hiddenSelectionsTextures[] = {"CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\CUP_vests\webbing\data\US_PASGT_vest_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\CUP_vests\osprey_mk4\data\equip_co.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_BAF\CUP_vests\osprey_mk4\data\gear_co.paa"};
        maximumLoad = 160;
        mass = 25;
    };
    class potato_RPS_Smersh_AK_ModernOlive: Bag_Base {
        author = "AChesheireCat";
        scope = 2;
        displayName = "RPS Smersh (Olive/AK)";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\data\UI\icon_V_O_RUS_RPS_Smersh_AK_Coyote_ca.paa";
        model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\CUP_rps_smersh_ak.p3d";
        hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4"};
        hiddenSelectionsTextures[] = {"CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\RPS_m_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\RPS_Straps_m_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\Suharka_MED_VOG_m_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\AK_m_CO.paa"};
        maximumLoad = 160;
        mass = 25;
    };
    class potato_RPS_Smersh_VOG_ModernOlive: Bag_Base {
        author = "AChesheireCat";
        scope = 2;
        displayName = "RPS Smersh (Olive/VOG)";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\data\UI\icon_V_O_RUS_RPS_Smersh_VOG_Coyote_ca.paa";
        model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\CUP_rps_smersh_vog.p3d";
        hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4"};
        hiddenSelectionsTextures[] = {"CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\RPS_m_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\RPS_Straps_m_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\Suharka_MED_VOG_m_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\AK_m_CO.paa"};
        maximumLoad = 160;
        mass = 27;
    };
    class potato_RPS_Smersh_VOG_SPP_ModernOlive: Bag_Base {
        author = "AChesheireCat";
        scope = 2;
        displayName = "RPS Smersh (Olive/SPP/VOG)";
        model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\CUP_rps_smersh_vog_spp.p3d";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\data\UI\icon_V_O_RUS_RPS_Smersh_VOG_SPP_ModernOlive_ca.paa";
        hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4"};
        hiddenSelectionsTextures[] = {"CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\RPS_m_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\RPS_Straps_m_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\Suharka_MED_VOG_m_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\AK_m_CO.paa"};
        maximumLoad = 190;
        mass = 30;
    };
    class potato_RPS_Smersh_PKP_ModernOlive: Bag_Base {
        author = "AChesheireCat";
        scope = 2;
        displayName = "RPS Smersh (Olive/PKP)";
        model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\CUP_rps_smersh_pkp.p3d";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\data\UI\icon_V_O_RUS_RPS_Smersh_PKP_ModernOlive_ca.paa";
        hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4"};
        hiddenSelectionsTextures[] = {"CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\RPS_m_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\RPS_Straps_m_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\Suharka_MED_VOG_m_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\PKP_m_CO.paa"};
        maximumLoad = 160;
        mass = 27;
    };
    class potato_RPS_Smersh_PKP_Light_ModernOlive: Bag_Base {
        author = "AChesheireCat";
        scope = 2;
        displayName = "RPS Smersh (Olive/PKP Light)";
        model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\CUP_rps_smersh_pkp_light.p3d";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\data\UI\icon_V_O_RUS_RPS_Smersh_PKP_Light_ModernOlive_ca.paa";
        hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4"};
        hiddenSelectionsTextures[] = {"CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\RPS_m_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\RPS_Straps_m_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\Suharka_MED_VOG_m_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\PKP_m_CO.paa"};
        maximumLoad = 160;
        mass = 25;
    };
    class potato_RPS_Smersh_PKP_SPP_ModernOlive: Bag_Base {
        author = "AChesheireCat";
        scope = 2;
        displayName = "RPS Smersh (Olive/SPP/PKP)";
        model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\CUP_rps_smersh_pkp_spp.p3d";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\data\UI\icon_V_O_RUS_RPS_Smersh_PKP_SPP_ModernOlive_ca.paa";
        hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4"};
        hiddenSelectionsTextures[] = {"CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\RPS_m_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\RPS_Straps_m_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\Suharka_MED_VOG_m_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\PKP_m_CO.paa"};
        maximumLoad = 190;
        mass = 30;
    };
    class potato_RPS_Smersh_SVD_ModernOlive: Bag_Base {
        author = "AChesheireCat";
        scope = 2;
        displayName = "RPS Smersh (Olive/SVD)";
        model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\CUP_rps_smersh_svd.p3d";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\data\UI\icon_V_O_RUS_RPS_Smersh_SVD_ModernOlive_ca.paa";
        hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4"};
        hiddenSelectionsTextures[] = {"CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\RPS_m_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\RPS_Straps_m_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\Suharka_MED_VOG_m_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\SVD_m_CO.paa"};
        maximumLoad = 160;
        mass = 21;
    };
    class potato_RPS_Smersh_AK_Coyote: Bag_Base {
        author = "AChesheireCat";
        scope = 2;
        displayName = "RPS Smersh (Coyote/AK)";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\data\UI\icon_V_O_RUS_RPS_Smersh_AK_Coyote_ca.paa";
        model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\CUP_rps_smersh_ak.p3d";
        hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4"};
        hiddenSelectionsTextures[] = {"CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\RPS_c_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\RPS_Straps_c_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\Suharka_MED_VOG_c_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\AK_c_CO.paa"};
        maximumLoad = 160;
        mass = 25;
    };
    class potato_RPS_Smersh_VOG_Coyote: Bag_Base {
        author = "AChesheireCat";
        scope = 2;
        displayName = "RPS Smersh (Coyote/VOG)";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\data\UI\icon_V_O_RUS_RPS_Smersh_VOG_Coyote_ca.paa";
        model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\CUP_rps_smersh_vog.p3d";
        hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4"};
        hiddenSelectionsTextures[] = {"CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\RPS_c_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\RPS_Straps_c_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\Suharka_MED_VOG_c_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\AK_c_CO.paa"};
        maximumLoad = 160;
        mass = 27;
    };
    class potato_RPS_Smersh_VOG_SPP_Coyote: Bag_Base {
        author = "AChesheireCat";
        scope = 2;
        displayName = "RPS Smersh (Coyote/SPP/VOG)";
        model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\CUP_rps_smersh_vog_spp.p3d";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\data\UI\icon_V_O_RUS_RPS_Smersh_VOG_SPP_ModernOlive_ca.paa";
        hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4"};
        hiddenSelectionsTextures[] = {"CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\RPS_c_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\RPS_Straps_c_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\Suharka_MED_VOG_c_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\AK_c_CO.paa"};
        maximumLoad = 190;
        mass = 30;
    };
    class potato_RPS_Smersh_PKP_Coyote: Bag_Base {
        author = "AChesheireCat";
        scope = 2;
        displayName = "RPS Smersh (Coyote/PKP)";
        model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\CUP_rps_smersh_pkp.p3d";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\data\UI\icon_V_O_RUS_RPS_Smersh_PKP_ModernOlive_ca.paa";
        hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4"};
        hiddenSelectionsTextures[] = {"CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\RPS_c_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\RPS_Straps_c_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\Suharka_MED_VOG_c_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\PKP_c_CO.paa"};
        maximumLoad = 160;
        mass = 27;
    };
    class potato_RPS_Smersh_PKP_Light_Coyote: Bag_Base {
        author = "AChesheireCat";
        scope = 2;
        displayName = "RPS Smersh (Coyote/PKP Light)";
        model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\CUP_rps_smersh_pkp_light.p3d";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\data\UI\icon_V_O_RUS_RPS_Smersh_PKP_Light_ModernOlive_ca.paa";
        hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4"};
        hiddenSelectionsTextures[] = {"CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\RPS_c_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\RPS_Straps_c_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\Suharka_MED_VOG_c_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\PKP_c_CO.paa"};
        maximumLoad = 160;
        mass = 25;
    };
    class potato_RPS_Smersh_PKP_SPP_Coyote: Bag_Base {
        author = "AChesheireCat";
        scope = 2;
        displayName = "RPS Smersh (Coyote/SPP/PKP)";
        model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\CUP_rps_smersh_pkp_spp.p3d";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\data\UI\icon_V_O_RUS_RPS_Smersh_PKP_SPP_ModernOlive_ca.paa";
        hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4"};
        hiddenSelectionsTextures[] = {"CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\RPS_c_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\RPS_Straps_c_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\Suharka_MED_VOG_c_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\PKP_c_CO.paa"};
        maximumLoad = 190;
        mass = 30;
    };
    class potato_RPS_Smersh_SVD_Coyote: Bag_Base {
        author = "AChesheireCat";
        scope = 2;
        displayName = "RPS Smersh (Coyote/SVD)";
        model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\CUP_rps_smersh_svd.p3d";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\data\UI\icon_V_O_RUS_RPS_Smersh_SVD_ModernOlive_ca.paa";
        hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4"};
        hiddenSelectionsTextures[] = {"CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\RPS_c_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\RPS_Straps_c_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\Suharka_MED_VOG_c_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\SVD_c_CO.paa"};
        maximumLoad = 160;
        mass = 21;
    };
};