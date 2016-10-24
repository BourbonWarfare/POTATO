#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {
            "potato_usmc_rifleman","potato_usmc_rifleman_02","potato_usmc_rifleman_03","potato_usmc_rifleman_04","potato_usmc_sf_rifleman",
            "potato_usmc_sniper","potato_usmc_aar","potato_usmc_sf_aar","potato_usmc_mmgag","potato_usmc_hmgag","potato_usmc_matag",
            "potato_usmc_hatag","potato_usmc_msamag","potato_usmc_mtrag","potato_usmc_mtrg","potato_usmc_ar","potato_usmc_sf_ar",
            "potato_usmc_mmgg","potato_usmc_hmgg","potato_usmc_lat","potato_usmc_sf_lat","potato_usmc_matg","potato_usmc_hatg","potato_usmc_msamg",
            "potato_usmc_coy","potato_usmc_xo","potato_usmc_fac","potato_usmc_plt","potato_usmc_sgt","potato_usmc_sl","potato_usmc_sf_sl",
            "potato_usmc_mmgl","potato_usmc_hmgl","potato_usmc_matl","potato_usmc_hatl","potato_usmc_msaml","potato_usmc_mtrl","potato_usmc_stl",
            "potato_usmc_ftl","potato_usmc_sf_ftl","potato_usmc_vicl","potato_usmc_cm","potato_usmc_plm","potato_usmc_sm","potato_usmc_sf_sm",
            "potato_usmc_eodl","potato_usmc_eod","potato_usmc_vicc","potato_usmc_vicd","potato_usmc_pilot","potato_usmc_cc"
        };
        weapons[] = {"potato_fakeNVG"};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core", "mbg_celle2", "ace_ui", "rhs_c_weapons", "Taliban_fighters"};
        author = "Potato";
        authors[] = {"PabstMirror"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgFactionClasses.hpp"
#include "CfgVehicles.hpp"

//Fix CELLE font error:
class CfgLocationTypes {
    class MBG_celle2_icon_A7 {
        font = "PuristaMedium";
    };
};

//Undo ACE's changes to system messages text brightness
class RscChatListDefault {
    colorMessageProtocol[] = {0.65,0.65,0.65,1};
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

    class Uniform_Base;
    class U_Afghan06: Uniform_Base {
        author = "EricJ";
        scope = 2;
        displayName = "Afghan Clothes 6";
        picture = "\A3\characters_f\data\ui\icon_U_Citizen_ca.paa";
        model = "\Taliban_Fighters\Uniforms\Afghan_06NH.p3d";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"Taliban_Fighters\data\tak_civil06_1_co.paa"};
        class ItemInfo: UniformItem {
            uniformModel = "-";
            uniformClass = "TBan_Fighter6NH";
            armor = 0;
            passThrough = 1;
            containerClass = "Supply30";
            mass = 30;
        };
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
};

#include "CfgEden.hpp"
#include "CfgEventHandlers.hpp"
