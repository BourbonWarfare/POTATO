#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_assignGear"};
        author = "Potato";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class ADDON {
    #include "\z\potato\addons\loadouts\loadouts\common.hpp"

    class potato_w {
        #include "\z\potato\addons\loadouts\loadouts\west_gear.hpp"
        #include "\z\potato\addons\loadouts\loadouts.hpp"
    };
    class potato_e {
        #include "\z\potato\addons\loadouts\loadouts\east_gear.hpp"
        #include "\z\potato\addons\loadouts\loadouts.hpp"
    };
    class potato_i { // Indy
        #include "\z\potato\addons\loadouts\loadouts\indy_gear.hpp"
        #include "\z\potato\addons\loadouts\loadouts.hpp"
    };
};
