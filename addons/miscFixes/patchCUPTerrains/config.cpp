#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchCUPTerrains

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "potato_core",
            "CUP_Buildings_Config", "CUP_CAStructures_Mil", "CUP_CAStructures_E_HouseL"
        };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CfgVehicles {
    /// Base classes
    class House;
    class House_EP1;
    class House_F;

    /// Building armor increases
    class Land_Budova4_in;
    class Land_Garaz_s_tankem;
    class Land_Cihlovej_Dum_in;
    class Land_Dum_olezlina_closed;
    class Land_Dum_mesto_in_bare;
    class Land_Ind_Shed_01_EP1;
    class Land_Dum_olez_istan1_closed;
    class Land_A_BuildingWIP: House {
        armor = 2000; // original 500
    };
    class Land_A_BuildingWIP_EP1: House_EP1 {
        armor = 2000; // original 500
    };
    class Land_A_Pub_01: House {
        armor = 1400; // original 600
    };
    class Land_Mil_Barracks_L: House {
        armor = 800; // original 400
    };
    class Land_Mil_Barracks_i: House {
        armor = 600; // original 400
    };
    class Land_Mil_Barracks: House {
        armor = 600; // original 400
    };
    class Land_HouseB_Tenement: House {
        armor = 288; // original 180
    };
    class Land_a_stationhouse: House {
        armor = 1000; // original 320
    };
    class Land_A_Stationhouse_ep1: House_EP1 {
        armor = 1000; // original 350
    };
    class Land_WIP_F: House_F {
        armor = 2000; // original 500
    };
    class Land_Letistni_hala: House {
        armor = 400; // original 200
    };
    class Land_Garaz_bez_tanku: Land_Garaz_s_tankem {
        armor = 600; // original 300
    };
    class Land_Budova4: Land_Budova4_in {
        armor = 750; // original 150
    };
    class Land_Budova3: House {
        armor = 600; // original 300
    };
    class Land_Budova2: House {
        armor = 700; // original 150
    };
    class Land_Budova1: House {
        armor = 700; // original 500
    };
    class Land_Garaz: House {
        armor = 225; // original 75
    };
    class Land_Dum_olez_istan1: Land_Dum_olez_istan1_closed {
        armor = 600; // original 150
    };
    class Land_Stanice: House {
        armor = 800; // original 500
    };
    class Land_Cihlovej_Dum_mini: Land_Cihlovej_Dum_in {
        armor = 1000; // original 500
    };
    class Land_Dum_olezlina: Land_Dum_olezlina_closed {
        armor = 750; // original 150
    };
    class Land_Dum_m2: House {
        armor = 750; // original 500
    };
    class Land_Dum_mesto: House {
        armor = 750;
    };
    class Land_Dum_mesto2: House {
        armor = 750;
    };
    class Land_Dum_mesto3: House {
        armor = 600; // original 150
    };
    class Land_Budova5: House {
        armor = 750; // original 500
    };
    class Land_Repair_center: House {
        armor = 750; // original 500
    };
    class Land_Dumruina_mini: House {
        armor = 800; // original 500
    };
    class Land_Sara_zluty_statek_in: House {
        armor = 300; // original 150
    };
    class Land_Sara_domek_zluty: House {
        armor = 600; // original 300
    };
    class Land_Kasarna: House {
        armor = 500; // original 200
    };
    class Land_Dum_mesto_in: Land_Dum_mesto_in_bare {
        armor = 600; // original 300
    };
    class Land_Barrack2: House {
        armor = 300; // original 100
    };
    class Land_Ind_Shed_02_EP1: Land_Ind_Shed_01_EP1 {
        armor = 250; // original 110
    };
    class Land_Mil_Repair_center_EP1: House_EP1 {
        armor = 750; // original 250
    };
    class Land_Mil_Barracks_EP1: House_EP1 {
        armor = 500; // original 250
    };
    class Land_Mil_Barracks_i_EP1: House_EP1 {
        armor = 800; // original 400
    };
    class Land_Mil_Barracks_L_EP1: House_EP1 {
        armor = 800; // original 400
    };
    class Land_Mil_Guardhouse_EP1: House_EP1 {
        armor = 600; // original 250
    };
    class Land_House_L_9_EP1: House_EP1 {
        armor = 750; // original 250
    };
    class Land_ZalChata: House {
        armor = 800; // original 500
    };
    class Land_Mil_Guardhouse: House {
        armor = 800; // original 400
    };
    class Land_Bouda3: House {
        armor = 600; // original 200
    };
    class Land_Dum_olez_istan2_maly: House {
        armor = 600; // original 150
    };
    class Land_Dum_istan2: House {
        armor = 800; // original 700
    };
};
