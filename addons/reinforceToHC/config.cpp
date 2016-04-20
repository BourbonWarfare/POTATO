#include "script_component.hpp"

class CfgPatches {
    class potato_reinforceToHC {
    units[] = {"Ares_Module_Reinforcements_Spawn_Units"};
    requiredVersion = REQUIRED_VERSION;
    requiredAddons[] = {"potato_core","potato_zeusHC","Ares"};
    author[] = {"AACO"};
    authorUrl = "https://github.com/BourbonWarfare/POTATO";
    VERSION_CONFIG;
    };
};

class Extended_PreStart_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preStart));
    };
};

class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preInit));
    };
};

class Extended_PostInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_postInit));
    };
};

class CfgVehicles {
    class Ares_Reinforcements_Module_base;
    class Ares_Module_Reinforcements_Spawn_Units : Ares_Reinforcements_Module_base {
        displayName = "Spawn Units";
        function = QFUNC(reinforcementsCreateUnits);
        author = "Anton Struyk (Ares base) AACO (2HC)";
        scopeCurator = 2;
    };
};
