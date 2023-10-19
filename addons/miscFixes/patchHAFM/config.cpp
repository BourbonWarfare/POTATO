#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchHAFM

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "HAFM_Army_Units2","HAFM_Air_Configs","HAFM_ArmA2_Helis","HAFM_Kiowa_Config","HAFM_NH90_Config","HAFM_ArmA2","HAFM_Vehicles_Configs","HAFM_Naval" };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CfgVehicles {
    class I_C_Soldier_base_F;
    class Greek_Infantry_Army2: I_C_Soldier_base_F { XEH_ENABLED; }; // "" @HAFM
    class PlaneWreck;
    class A7Wreck: PlaneWreck { XEH_ENABLED; }; // "Wreck" @HAFM
    class M2000CWreck: PlaneWreck { XEH_ENABLED; }; // "Wreck" @HAFM
    class F16CWreck: PlaneWreck { XEH_ENABLED; }; // "Wreck" @HAFM
    class F4EWreck: PlaneWreck { XEH_ENABLED; }; // "Wreck" @HAFM
    class F16_B52reck: PlaneWreck { XEH_ENABLED; }; // "Wreck" @HAFM
    class HelicopterWreck;
    class HAFM_UH1HWreck: HelicopterWreck { XEH_ENABLED; }; // "Wreck" @HAFM
    class HAFM_AH64DWreck: HelicopterWreck { XEH_ENABLED; }; // "Wreck" @HAFM
    class hafm_kiowa_wreck: HelicopterWreck { XEH_ENABLED; }; // "Wreck" @HAFM
    class HAFM_NH90Wreck: HelicopterWreck { XEH_ENABLED; }; // "Wreck" @HAFM
    class C130HWreck: PlaneWreck { XEH_ENABLED; }; // "Wreck" @HAFM
    class CH_47FWreck: PlaneWreck { XEH_ENABLED; }; // "Wreck" @HAFM
    class Tank_F;
    class Leopard2A6HEL: Tank_F { XEH_ENABLED; }; // "Leopard 2A6HEL" @HAFM
    class Leopard2A4: Tank_F { XEH_ENABLED; }; // "Leopard 2A4" @HAFM
    class Leopard1A4: Tank_F { XEH_ENABLED; }; // "Leopard 1A4" @HAFM
    class M60A3: Tank_F { XEH_ENABLED; }; // "M60A3" @HAFM
    class Leonidas2: Tank_F { XEH_ENABLED; }; // "Leonidas-2 APC" @HAFM
    class M113: Tank_F { XEH_ENABLED; }; // "M113 APC" @HAFM
    class Leonidas3: Tank_F { XEH_ENABLED; }; // "Leonidas-300 APC" @HAFM
    class Boat_F;
    class HAFM_Naval_Container: Boat_F { XEH_ENABLED; }; // "Dry Deck Shelter" @HAFM
    class HAFM_Naval_214: Boat_F {};
    class HAFM_Naval_209: HAFM_Naval_214 { XEH_ENABLED; }; // "Type 209 class (209/1200)" @HAFM
    class Ship_F;
    class HAFM_Naval_MEKO: Ship_F { XEH_ENABLED; }; // "Hydra MEKO-200HN class FG" @HAFM
    class HAFM_Naval_Replenishment: Ship_F { XEH_ENABLED; }; // "Replenishment Ship" @HAFM
    class HAFM_Naval_GunBoat: Ship_F { XEH_ENABLED; }; // "HSY-56A Gunboat" @HAFM
    class HAFM_Naval_CB90: Ship_F { XEH_ENABLED; }; // "CB90 Attack boat" @HAFM
    class HAFM_Naval_Russen: Ship_F { XEH_ENABLED; }; // "Roussen-Class Missile Boat" @HAFM
};
