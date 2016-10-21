#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {"potato_fakeNVG"};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core", "mbg_celle2", "ace_ui", "rhs_c_weapons"};
        author = "Potato";
        authors[] = {"PabstMirror"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};


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
};

#include "CfgEden.hpp"
#include "CfgEventHandlers.hpp"
