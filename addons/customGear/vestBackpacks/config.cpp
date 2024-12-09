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
    // Adds copies of the BAF Osprey Mk4 belt and webbing, Russian Smersh LBE (Olive/Coyote), certain ALICE LBE, M23 chest rigs, 6Sh92 chest rigs, and the Raven vest as backpacks
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
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\data\UI\icon_V_O_RUS_RPS_Smersh_AK_ModernOlive_ca.paa";
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
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\data\UI\icon_V_O_RUS_RPS_Smersh_VOG_ModernOlive_ca.paa";
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
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\data\UI\icon_V_O_RUS_RPS_Smersh_VOG_SPP_Coyote_ca.paa";
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
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\data\UI\icon_V_O_RUS_RPS_Smersh_PKP_Coyote_ca.paa";
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
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\data\UI\icon_V_O_RUS_RPS_Smersh_PKP_Light_Coyote_ca.paa";
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
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\data\UI\icon_V_O_RUS_RPS_Smersh_PKP_SPP_Coyote_ca.paa";
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
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\data\UI\icon_V_O_RUS_RPS_Smersh_SVD_Coyote_ca.paa";
        hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4"};
        hiddenSelectionsTextures[] = {"CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\RPS_c_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\RPS_Straps_c_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\Suharka_MED_VOG_c_CO.paa","CUP\Creatures\People\Military\CUP_Creatures_People_Military_RussiaModern\Vest\RPS_Smersh\Data\SVD_c_CO.paa"};
        maximumLoad = 160;
        mass = 21;
    };
    class potato_alice: Bag_Base {
        scope = 2;
        displayName = "ALICE Gear (Rifleman)";
        picture = "\cwr3\humans\cwr3_soldiers_usa\ui\cwr3_v_alice_rifleman_ca.paa";
        model = "\cwr3\humans\cwr3_soldiers_usa\vests\cwr3_alice_rifleman.p3d";
        hiddenSelections[] = {"hs_vest1"};
        hiddenSelectionsTextures[] = {"\cwr3\humans\cwr3_soldiers_usa\vests\data\ssgear_alice_co.paa"};
        maximumLoad = 160;
        mass = 25;
    };
    class potato_alice_mg: Bag_Base {
        scope = 2;
        displayName = "ALICE Gear (Machinegunner)";
        picture = "\cwr3\humans\cwr3_soldiers_usa\ui\cwr3_v_alice_mg_ca.paa";
        model = "\cwr3\humans\cwr3_soldiers_usa\vests\cwr3_alice_mg.p3d";
        hiddenSelections[] = {"hs_vest1"};
        hiddenSelectionsTextures[] = {"\cwr3\humans\cwr3_soldiers_usa\vests\data\ssgear_alice_co.paa"};
        maximumLoad = 190;
        mass = 30;
    };
    class potato_alice_gl: Bag_Base {
        scope = 2;
        displayName = "ALICE Gear (Grenadier)";
        picture = "\cwr3\humans\cwr3_soldiers_usa\ui\cwr3_v_alice_grenadier_ca.paa";
        model = "\cwr3\humans\cwr3_soldiers_usa\vests\cwr3_alice_grenadier.p3d";
        hiddenSelections[] = {"hs_vest1","hs_vest2"};
        hiddenSelectionsTextures[] = {"\cwr3\humans\cwr3_soldiers_usa\vests\data\ssgear_alice_co.paa","\cwr3\humans\cwr3_soldiers_usa\vests\data\gear_nadevest_co.paa"};
        maximumLoad = 180;
        mass = 27;
    };
    class potato_alice_officer: Bag_Base {
        scope = 2;
        displayName = "ALICE Gear (Officer)";
        picture = "\cwr3\humans\cwr3_soldiers_usa\ui\cwr3_v_alice_officer_ca.paa";
        model = "\cwr3\humans\cwr3_soldiers_usa\vests\cwr3_alice_officer.p3d";
        hiddenSelections[] = {"hs_vest1"};
        hiddenSelectionsTextures[] = {"\cwr3\humans\cwr3_soldiers_usa\vests\data\ssgear_alice_co.paa"};
        maximumLoad = 160;
        mass = 25;
    };
    class potato_TK_Vest_1: Bag_Base {
        scope = 2;
        displayName = "M23 Pioneer (Takistani)";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Taki\data\ui\icon_v_tk_combat_vest_ca";
        model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Taki\CUP_TK_Vest1.p3d";
        hiddenSelections[] = {"camo1","camo2"};
        hiddenSelectionsTextures[] = {"\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Taki\data\tak_soldier_equip_co.paa"};
        maximumLoad = 190;
        mass = 25;
    };
    class potato_TK_Vest_2: Bag_Base {
        scope = 2;
        displayName = "M23 Pioneer (Takistani - No Buttpack)";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Taki\data\ui\icon_v_tk_combat_vest_ca";
        model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Taki\CUP_TK_Vest2.p3d";
        hiddenSelections[] = {"camo1","camo2"};
        hiddenSelectionsTextures[] = {"\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Taki\data\tak_soldier_equip_co.paa"};
        maximumLoad = 170;
        mass = 23;
    };
    class potato_SLA_M23_1_OD: Bag_Base {
        scope = 2;
        displayName = "M23 Pioneer (Green)";
        picture = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Taki\data\ui\icon_v_tk_combat_vest_ca";
        model = "\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Taki\CUP_TK_Vest1.p3d";
        hiddenSelections[] = {"camo1","camo2"};
        hiddenSelectionsTextures[] = {"\CUP\Creatures\People\Military\CUP_Creatures_People_Military_sla\data\m23_green_co.paa"};
        maximumLoad = 170;
        mass = 23;
    };
    class potato_6sh92: Bag_Base {
        scope = 2;
        displayName = "6Sh92 (Flora)";
        picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6sh92_ca.paa";
        model = "\rhsafrf\addons\rhs_infantry\gear\vests\rhs_6sh92";
        hiddenSelections[] = {"Camo1","Camo2"};
        hiddenSelectionsTextures[] = {"\rhsafrf\addons\rhs_infantry\data\6b23_co.paa","\rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_co.paa"};
        maximumLoad = 150;
        mass = 16;
    };
    class potato_6sh92_headset: Bag_Base {
        scope = 2;
        displayName = "6Sh92 (Flora - Headset)";
        picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6sh92_headset_ca.paa";
        model = "\rhsafrf\addons\rhs_infantry\gear\vests\rhs_6sh92_headset";
        hiddenSelections[] = {"Camo1","Camo2"};
        hiddenSelectionsTextures[] = {"\rhsafrf\addons\rhs_infantry\data\6b23_co.paa","\rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_co.paa"};
        maximumLoad = 150;
        mass = 16;
    };
    class potato_6sh92_radio: Bag_Base {
        scope = 2;
        displayName = "6Sh92 (Flora - Radio)";
        picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6sh92_radio_ca.paa";
        model = "\rhsafrf\addons\rhs_infantry\gear\vests\rhs_6sh92_radio";
        hiddenSelections[] = {"Camo1","Camo2"};
        hiddenSelectionsTextures[] = {"\rhsafrf\addons\rhs_infantry\data\6b23_co.paa","\rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_co.paa"};
        maximumLoad = 150;
        mass = 16;
    };
    class potato_6sh92_vog: Bag_Base {
        scope = 2;
        displayName = "6Sh92 (Flora - VOG)";
        picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6sh92_vog_ca.paa";
        model = "\rhsafrf\addons\rhs_infantry\gear\vests\rhs_6sh92_vog";
        hiddenSelections[] = {"Camo1","Camo2"};
        hiddenSelectionsTextures[] = {"\rhsafrf\addons\rhs_infantry\data\6b23_co.paa","\rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_co.paa"};
        maximumLoad = 170;
        mass = 18;
    };
    class potato_6sh92_vog_headset: Bag_Base {
        scope = 2;
        displayName = "6Sh92 (Flora - VOG/Headset)";
        picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6sh92_vog_headset_ca.paa";
        model = "\rhsafrf\addons\rhs_infantry\gear\vests\rhs_6sh92_vog_headset";
        hiddenSelections[] = {"Camo1","Camo2"};
        hiddenSelectionsTextures[] = {"\rhsafrf\addons\rhs_infantry\data\6b23_co.paa","\rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_co.paa"};
        maximumLoad = 170;
        mass = 18;
    };
    class potato_V_TacVestIR_blk: Bag_Base {
        scope = 2;
        displayName = "Raven Vest";
        picture = "\A3\characters_f\Data\UI\icon_V_TacVestIR_blk_CA.paa";
        model = "\A3\Characters_F_Beta\INDEP\equip_ir_vest01";
        hiddenSelections[] = {"camo1","camo2"};
        hiddenSelectionsTextures[] = {"\z\acp\addons\Solid_CoyoteBrown_core_lite\data\clothing_Solid_CoyoteBrown_CO.paa","\z\acp\addons\Solid_CoyoteBrown_core_lite\data\tech_Solid_CoyoteBrown_CO.paa"};
        maximumLoad = 180;
        mass = 22;
    };
};