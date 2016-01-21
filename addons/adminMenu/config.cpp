#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core"};
        author[] = {"PabstMirror"};
        authorUrl = "https://github.com/PabstMirror";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "pabst_adminMenu.hpp"

class ACE_Settings {
    class GVAR(showNotifcations) {
        category = QUOTE(PREFIX);
        displayName = "Potato: Show SystemChat Notifcations";
        description = "False should disable most Notifcations, can use to make clean recordings.";
        typeName = "BOOL";
        value = 1;
        isClientSettable = 1;
    };
};

class GVAR(supplies) {
    class ACE_Box_Misc {};
    class ACE_medicalSupplyCrate {};
    class ACE_medicalSupplyCrate_advanced {};

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
