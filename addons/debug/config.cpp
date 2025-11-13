#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core"};
        skipWhenMissingDependencies = 1;
        author = "Potato";
        authors[] = {"Lambda.Tiger"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#ifdef ENABLE_DEBUG_SYSTEMS
#include "CfgEventHandlers.hpp"
#endif
class CfgAmmo {
    class RocketBase;
    class CUP_R_PG7VL_AT: RocketBase {
        airLock = 1;
    };
    class CUP_R_PG7VM_AT: RocketBase {
        airLock = 1;
    };
    class CUP_R_PG7V_AT: RocketBase {
        airLock = 1;
    };
};
class CfgMagazines {
    class CA_LauncherMagazine;
    class CUP_PG7V_M: CA_LauncherMagazine {
        maxLeadSpeed = 100;
    };
    class CUP_PG7VM_M: CA_LauncherMagazine {
        maxLeadSpeed = 100;
    };
    class CUP_PG7VL_M: CA_LauncherMagazine {
        maxLeadSpeed = 100;
    };
};
