#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core", "mbg_celle2"};
        author[] = {"PabstMirror"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };

    //Dummy patches for old missions
    //DEPRECATE THESE by Feb2016
    class RDS_StaticWeapons_Core {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {};
    };
    class alive_sys_data {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {};
    };
    class alive_sys_profile {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {};
    };
    class alive_main {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {};
    };
    class alive_sys_weather {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {};
    };
    class alive_civ_placement {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {};
    };
    class alive_mil_opcom {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {};
    };
    class alive_mil_cqb {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {};
    };
};


//Fix CELLE font error:
class CfgLocationTypes {
    class MBG_celle2_icon_A7 {
        font = "PuristaMedium";
    };
};

class CfgVehicles {
    //Dummy veh for old missions
    //DEPRECATE THESE by Feb2016
    class I_static_AT_F;
    class RDS_Metis_CSAT: I_static_AT_F {
        displayName = "Old RDS STATIC (DELETE ME!!!!)";
    };
    class ModuleChemlight_F;
    class ALiVE_sys_data: ModuleChemlight_F {
        displayName = "Old Alive Module (DELETE ME!!!!)";
    };
    class ALiVE_sys_profile: ALiVE_sys_data{};
    class ALiVE_require: ALiVE_sys_data{};
    class ALiVE_civ_placement: ALiVE_sys_data{};
    class ALiVE_mil_OPCOM: ALiVE_sys_data{};
    class ALiVE_mil_cqb: ALiVE_sys_data{};
};
