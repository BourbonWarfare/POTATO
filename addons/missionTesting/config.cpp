#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {QGVAR(missionTesting)};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core"};
        author = "Potato";
        authors[] = {"BadWolf"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class GVAR(displayMissionTesting) {
    idd = 9999;
    movingEnable = 1;
    enableSimulation = 1;
    enableDisplay = 1;
};
class GVAR(displayBreifings) {
    idd = 9998;
    movingEnable = 1;
    enableSimulation = 1;
    enableDisplay = 1;
};


#include "CfgEventHandlers.hpp"
#include "CfgEden.hpp"
#include "CfgVehicles.hpp"

// Not used yet, but may in the future
class CfgCommands{
	allowedHTMLLoadURIs[] = {
		"*.coalitiongroup.net/*" // strings support wildcards '*' and '?'
	};
};