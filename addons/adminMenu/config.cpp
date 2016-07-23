#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core"};
        author = "Potato";
        authors[] = {"PabstMirror"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "Interrupt_adminMenu.hpp"

class GVAR(supplies) {
    class ACE_Box_Misc {};
    class ACE_medicalSupplyCrate {};
    class ACE_medicalSupplyCrate_advanced {};
    
    class EGVAR(miscFixes,smawBox) {};
    class EGVAR(vz99,box) {};

    class Box_NATO_Ammo_F {};
    class Box_East_Ammo_F {};
    class Box_IND_Ammo_F {};
    class Box_NATO_AmmoOrd_F {};
    class HLC_AK_ammobox {};
    class HLC_M14_ammobox {};

    class C_Offroad_01_F {};
    class I_MRAP_03_hmg_F {};
    class O_APC_Wheeled_02_rcws_F {};
    class B_MBT_01_TUSK_F {};
    class rhs_t80u {};

    class B_Heli_Transport_01_F {};
    class O_Heli_Light_02_unarmed_F {};
    class I_Heli_Transport_02_F {};
    class B_Heli_Attack_01_F {};
};
