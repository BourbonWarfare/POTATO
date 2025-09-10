#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchHLC

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "hlcweapons_G36", "hlcweapons_core" };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CfgWeapons {
    // add zeroing to iron sighted G36es
    class hlc_G36_base;
    class hlc_rifle_G36V : hlc_G36_base {
        discreteDistance[] = {100, 200, 300, 400, 500};
        discreteDistanceInitIndex = 1;
    };
};

class CfgMagazineWells {
    class CBA_556x45_SCAR_EGLM {
        NIA_mags[] = {"hlc_30rnd_556x45_EPR","hlc_30rnd_556x45_SOST","hlc_30rnd_556x45_SPR","hlc_30rnd_556x45_S","hlc_30rnd_556x45_M","hlc_30rnd_556x45_t","hlc_30rnd_556x45_MDim","hlc_30rnd_556x45_TDim","hlc_30rnd_556x45_EPR_PMAG","hlc_30rnd_556x45_SOST_PMAG","hlc_30rnd_556x45_SPR_PMAG","hlc_30rnd_556x45_S_PMAG","hlc_30rnd_556x45_M_PMAG","hlc_30rnd_556x45_t_PMAG","hlc_30rnd_556x45_MDim_PMAG","hlc_30rnd_556x45_TDim_PMAG","hlc_30rnd_556x45_EPR_STANAGHD","hlc_30rnd_556x45_SOST_STANAGHD","hlc_30rnd_556x45_SPR_STANAGHD","hlc_30rnd_556x45_S_STANAGHD","hlc_30rnd_556x45_M_STANAGHD","hlc_30rnd_556x45_t_STANAGHD","hlc_30rnd_556x45_MDim_STANAGHD","hlc_30rnd_556x45_TDim_STANAGHD","hlc_30rnd_556x45_EPR_L5","hlc_30rnd_556x45_SOST_L5","hlc_30rnd_556x45_SPR_L5","hlc_30rnd_556x45_S_L5","hlc_30rnd_556x45_M_L5","hlc_30rnd_556x45_t_L5","hlc_30rnd_556x45_MDim_L5","hlc_30rnd_556x45_TDim_L5","hlc_30rnd_556x45_EPR_EMAG","hlc_30rnd_556x45_SOST_EMAG","hlc_30rnd_556x45_SPR_EMAG","hlc_30rnd_556x45_S_EMAG","hlc_30rnd_556x45_M_EMAG","hlc_30rnd_556x45_t_EMAG","hlc_30rnd_556x45_MDim_EMAG","hlc_30rnd_556x45_TDim_EMAG"};
    };
};

class CfgMagazines {
    // fixes tracer every 3 mags to actually have te3
    class 30Rnd_556x45_Stanag;
    class hlc_30Rnd_545x39_B_AK: 30Rnd_556x45_Stanag {};
    class hlc_30Rnd_545x39_T_ak: hlc_30Rnd_545x39_B_AK {};
    class hlc_30Rnd_545x39_EP_ak : hlc_30Rnd_545x39_B_AK {
        lastroundstracer = 3; // was 0
        tracersevery = 3; // was 0
    };
    class hlc_30Rnd_545x39_EP_ak_Plum : hlc_30Rnd_545x39_B_AK {
        lastroundstracer = 3; // was 0
        tracersevery = 3; // was 0
    };
    class hlc_30Rnd_545x39_EP_ak_Black : hlc_30Rnd_545x39_B_AK {
        lastroundstracer = 3; // was 0
        tracersevery = 3; // was 0
    };
    class hlc_45Rnd_545x39_EP_rpk : hlc_30Rnd_545x39_T_ak {
        tracersevery = 3; // was 0
    };
    class hlc_45Rnd_545x39_EP_rpkm : hlc_30Rnd_545x39_T_ak {
        tracersevery = 3; // was 0
    };
    class hlc_60Rnd_545x39_EP_rpk : hlc_30Rnd_545x39_T_ak {
        tracersevery = 3; // was 0
    };
};
