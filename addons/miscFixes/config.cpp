#include "script_component.hpp"

#ifndef POTATO_LEAN_CONFIGS

class CfgPatches {
    class ADDON {
        units[] = {
            QUSMC(rifleman),QUSMC(rifleman_02),QUSMC(rifleman_03),QUSMC(rifleman_04),QUSMC(sf_rifleman),
            QUSMC(sniper),QUSMC(aar),QUSMC(sf_aar),QUSMC(mmgag),QUSMC(hmgag),QUSMC(matag),
            QUSMC(hatag),QUSMC(msamag),QUSMC(mtrag),QUSMC(mtrg),QUSMC(ar),QUSMC(sf_ar),
            QUSMC(mmgg),QUSMC(hmgg),QUSMC(lat),QUSMC(sf_lat),QUSMC(matg),QUSMC(hatg),QUSMC(msamg),
            QUSMC(coy),QUSMC(xo),QUSMC(fac),QUSMC(plt),QUSMC(sgt),QUSMC(sl),QUSMC(sf_sl),
            QUSMC(mmgl),QUSMC(hmgl),QUSMC(matl),QUSMC(hatl),QUSMC(msaml),QUSMC(mtrl),QUSMC(stl),
            QUSMC(ftl),QUSMC(sf_ftl),QUSMC(vicl),QUSMC(cm),QUSMC(plm),QUSMC(sm),QUSMC(sf_sm),
            QUSMC(eodl),QUSMC(eod),QUSMC(vicc),QUSMC(vicd),QUSMC(pilot),QUSMC(cc),
            QMSV(rifleman),QMSV(rifleman_02),QMSV(rifleman_03),QMSV(rifleman_04),QMSV(sf_rifleman),
            QMSV(marksman),QMSV(sf_marksman),QMSV(aar),QMSV(sf_aar),QMSV(ag),QMSV(mmgag),QMSV(hmgag),
            QMSV(matag),QMSV(hatag),QMSV(msamag),QMSV(mtrag),QMSV(mtrg),QMSV(ar),QMSV(sf_ar),QMSV(mmgg),
            QMSV(hmgg),QMSV(g),QMSV(sf_g),QMSV(matg),QMSV(hatg),QMSV(msamg),QMSV(coy),QMSV(acoy),QMSV(pol),
            QMSV(fac),QMSV(plt),QMSV(aplt),QMSV(sl),QMSV(sf_sl),QMSV(sf_ftl),QMSV(mmgl),QMSV(hmgl),
            QMSV(matl),QMSV(hatl),QMSV(msaml),QMSV(mtrl),QMSV(stl),QMSV(sr),QMSV(vicl),QMSV(engl),QMSV(cm),
            QMSV(plm),QMSV(sm),QMSV(sf_sm),QMSV(eng),QMSV(demo),QMSV(vicc),QMSV(vicd),QMSV(pilot),QMSV(cc),
            QAIR(rifleman),QAIR(rifleman_02),QAIR(rifleman_03),QAIR(rifleman_04),QAIR(sf_rifleman),
            QAIR(sniper),QAIR(aar),QAIR(sf_aar),QAIR(mmgag),QAIR(hmgag),QAIR(matag),
            QAIR(hatag),QAIR(msamag),QAIR(mtrag),QAIR(mtrg),QAIR(ar),QAIR(sf_ar),
            QAIR(mmgg),QAIR(hmgg),QAIR(lat),QAIR(sf_lat),QAIR(matg),QAIR(hatg),QAIR(msamg),
            QAIR(coy),QAIR(xo),QAIR(fac),QAIR(plt),QAIR(sgt),QAIR(sl),QAIR(sf_sl),
            QAIR(mmgl),QAIR(hmgl),QAIR(matl),QAIR(hatl),QAIR(msaml),QAIR(mtrl),QAIR(stl),
            QAIR(ftl),QAIR(sf_ftl),QAIR(vicl),QAIR(cm),QAIR(plm),QAIR(sm),QAIR(sf_sm),
            QAIR(engl),QAIR(eng),QAIR(demo),QAIR(vicc),QAIR(vicd),QAIR(pilot),QAIR(cc)
        };
        weapons[] = {
            "potato_fakeNVG", "potato_arifle_RPK", // below are shimmed weapons, remove eventually
            "hlc_rifle_rpk", "hlc_rifle_rpk74n",
            "hlc_rifle_aks74u", "hlc_rifle_ak74_dirty",
            "hlc_rifle_aks74_GL", "hlc_rifle_aks74"
        };
        magazines[] = {
            "potato_75Rnd_762x39mm_tracer", // below are shimmed mags, remove eventually
            "hlc_75Rnd_762x39_m_rpk", "hlc_60Rnd_545x39_t_rpk",
            "hlc_VOG25_AK", "hlc_GRD_White", "hlc_GRD_Red"
        };
        requiredVersion = REQUIRED_VERSION;
<<<<<<< HEAD
        requiredAddons[] = {"potato_core", "mbg_celle2", "ace_ui", "rhs_c_weapons"};
=======
        requiredAddons[] = {
            "potato_core", "mbg_celle2", "ace_ui", "ace_ai", "BWA3_Common",
            "rhs_c_weapons", "rhsusf_c_weapons", "CUP_Weapons_AK"
        };
>>>>>>> 41d3ae471fa68c936cf90e057aa94ee5ef0b918c
        author = "Potato";
        authors[] = {"PabstMirror", "AACO"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

// Fix CELLE font error:
class CfgLocationTypes {
    class MBG_celle2_icon_A7 {
        font = "PuristaMedium";
    };
};

// Undo ACE's changes to system messages text brightness
class RscChatListDefault {
    colorMessageProtocol[] = {0.65,0.65,0.65,1};
};

<<<<<<< HEAD
class CfgVehicles {
    class LandVehicle;
    class StaticWeapon: LandVehicle {
        insideSoundCoef = 0; //ACRE uses this for vehicle sound attenuation (makes it easy to hear mortar gunners)
    };

    class Box_NATO_Support_F;
    class GVAR(smawBox): Box_NATO_Support_F {
        scope = 1;
        displayName = "SMAW Weapon Box";
        transportMaxWeapons = 9001;
        transportMaxMagazines = 9001;
        transportMaxItems = 9001;
        maximumload = 1000;

        class TransportWeapons {
            MACRO_ADDWEAPON(rhs_weap_smaw,1);
        };
        class TransportMagazines {
            MACRO_ADDMAGAZINE(rhs_mag_smaw_HEAA,2);
            MACRO_ADDMAGAZINE(rhs_mag_smaw_HEDP,2);
            MACRO_ADDMAGAZINE(rhs_mag_smaw_SR,4);
        };
        class TransportItems {};
        class TransportBackpacks {};
    };
    
    class GVAR(acreBox): Box_NATO_Support_F {
        scope = 1;
        displayName = "ACRE Radio Box";
        transportMaxWeapons = 9001;
        transportMaxMagazines = 9001;
        transportMaxItems = 9001;
        maximumload = 1000;

        class TransportWeapons {};
        class TransportMagazines {};
        class TransportItems {
            MACRO_ADDITEM(ACRE_PRC343,20);
            MACRO_ADDITEM(ACRE_PRC148,10);
            MACRO_ADDITEM(ACRE_PRC117F,10);       
        };
        class TransportBackpacks {};
    };
};


class CfgWeapons {
    class NVGoggles;
    class potato_fakeNVG: NVGoggles {
        author = "pabst";
        modelOptics = QUOTE(PATHTOF(models\plotNVGs));
        model = "\A3\weapons_f\empty";
        displayName = "Fake NVGs (AI Only)";
        descriptionShort = "[Plot Googles] Do not attempt to use as a player, only to allow AI to have better vision";
        class ItemInfo {
            type = 616;
            hmdType = 0;
            uniformModel = "\A3\weapons_f\empty";
            modelOff = "\A3\weapons_f\empty";
            mass = 20;
        };
    };

    // create lighter SMAWs for playability
    class Launcher;
    class Launcher_Base_F: Launcher {
        class WeaponSlotsInfo;
    };
    class rhs_weap_smaw : Launcher_Base_F {
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 70;
        };
    };

    // Manually list all mags for HLC/RHS compat
    class rhs_weap_ak74m;
    class rhs_weap_akm : rhs_weap_ak74m {
        magazines[] = {"rhs_30Rnd_762x39mm", "rhs_30Rnd_762x39mm_tracer", "rhs_30Rnd_762x39mm_89", "rhs_30Rnd_762x39mm_U""hlc_30Rnd_762x39_b_ak", "hlc_30Rnd_762x39_t_ak", "hlc_45Rnd_762x39_m_rpk", "HLC_45rnd_762x39_T_RPK", "hlc_30rnd_762x39_s_ak"};
    };

    // shim the bugged uniform
    class InventoryItem_Base_F;
    class UniformItem: InventoryItem_Base_F {
        type = 801;
    };

};

class CfgMagazines {
    class CA_LauncherMagazine;
    class rhs_mag_smaw_HEAA: CA_LauncherMagazine {
        mass = 80;
    };
    class rhs_mag_smaw_HEDP: CA_LauncherMagazine {
        mass = 65;
    };
=======
// fix popup error when editing units
class CfgUnitInsignia {
    delete BWA3_insignia_name_Ghost;
    delete BWA3_insignia_name_Kickapoo;
    delete BWA3_insignia_name_Tonic;
>>>>>>> 41d3ae471fa68c936cf90e057aa94ee5ef0b918c
};

#include "CfgAISkill.hpp"
#include "CfgAmmo.hpp"
#include "CfgEden.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgFactionClasses.hpp"
#include "CfgMagazines.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"

#endif
