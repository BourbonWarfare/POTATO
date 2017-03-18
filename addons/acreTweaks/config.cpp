#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core", "acre_sys_prc343"};
        author[] = {"PabstMirror"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"

class CfgAcreComponents {
    class ACRE_BaseRadio;
    class ACRE_PRC343_base: ACRE_BaseRadio {
        class Interfaces;
    };
    class ACRE_PRC343: ACRE_PRC343_base {
        // sinadRating = -100;
        // sensitivityMin = -100;
        // sensitivityMax = -50;
        class Interfaces: Interfaces {
            class CfgAcreDataInterface {
                getCurrentChannelData = QFUNC(tweak343_getCurrentChannelData);
            };
        };
    };
};
