#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchCWRBAF

#define POTFIX(var1) DOUBLES(PREFIX,var1)
#define QPOTFIX(var1) QUOTE(POTFIX(var1))

#define MAG_2(mag) mag,mag
#define MAG_4(mag) MAG_2(mag),MAG_2(mag)
#define MAG_8(mag) MAG_4(mag),MAG_4(mag)
#define MAG_16(mag) MAG_8(mag),MAG_8(mag)
#define MAG_20(mag) MAG_16(mag),MAG_4(mag)

class CfgPatches {
    class ADDON {
        units[] = {
            QPOTFIX(cwr3_b_uk_fv107),
            QPOTFIX(cwr3_b_uk_fv107_unstab),
            QGVARMAIN(cwr3_b_uk_fv101_unstab),
            QGVARMAIN(cwr3_b_uk_fv432_gpmg_unstab),
            QGVARMAIN(cwr3_b_uk_fv432_peak_unstab),
            QGVARMAIN(cwr3_b_uk_fv510_unstab)
        };
        weapons[] = {
            QPOTFIX(CUP_Rarden_CTWS_veh)
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "potato_core",
            "cwr3_vehicle_fv101_uk",
            "cwr3_vehicle_fv510_uk",
            "cwr3_vehicle_fv432_uk",
            "cwr3_vehicle_fv620_uk",
            "cwr3_vehicle_lr_uk"
        };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CfgMagazines {
    class CUP_200Rnd_TE1_Red_Tracer_30mmGPR_M;
    class POTFIX(CUP_6Rnd_TE1_Red_Tracer_30mmGPR_M): CUP_200Rnd_TE1_Red_Tracer_30mmGPR_M {
        displayName = "6Rnd 40mm (GPR-T)";
        count = 6;
        displayNameShort = "30mm GPR-T";
    };

    class CUP_200Rnd_TE1_Red_Tracer_30mmAPFSDS_M;
    class POTFIX(CUP_6Rnd_TE1_Red_Tracer_30mmAPFSDS_M): CUP_200Rnd_TE1_Red_Tracer_30mmAPFSDS_M {
        displayName = "6Rnd 30mm (APFSDS-T)";
        displayNameShort = "30mm APFSDS-T";
        count = 6;
    };
};

class CfgWeapons {
    class autocannon_40mm_CTWS;
    class CUP_Rarden_CTWS_veh: autocannon_40mm_CTWS {
        class AP;
        class HE;
    };
    class POTFIX(CUP_Rarden_CTWS_veh): CUP_Rarden_CTWS_veh {
        magazineReloadTime = 20;
        autoReload = 1;
        class AP: AP {
            magazineReloadTime = 3;
            magazines[] = {QPOTFIX(CUP_6Rnd_TE1_Red_Tracer_30mmAPFSDS_M)};
        };
        class HE: HE {
            magazineReloadTime = 3;
            magazines[] = {QPOTFIX(CUP_6Rnd_TE1_Red_Tracer_30mmGPR_M)};
        };
    };
};

#include "CfgVehicles.hpp"
