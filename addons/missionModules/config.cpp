#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {QGVAR(zeus_missionHint), QGVAR(zeus_globalSetSkill), QGVAR(sideMarker)};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core"};
        author[] = {"PabstMirror"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
#include "UI_RscAttributes.hpp"


class ACE_Settings {
    class GVAR(aiSkill_general) {
        category = QUOTE(PREFIX);
        displayName = "Global AI Set Skill: general,commanding,courage";
        typeName = "SCALAR";
        value = 0.5;
    };
    class GVAR(aiSkill_aimingAccuracy) {
        category = QUOTE(PREFIX);
        displayName = "Global AI Set Skill: aimingAccuracy";
        typeName = "SCALAR";
        value = 0.5;
    };
    class GVAR(aiSkill_weaponHandling) {
        category = QUOTE(PREFIX);
        displayName = "Global AI Set Skill: aimingShake,aimingSpeed,reloadSpeed";
        typeName = "SCALAR";
        value = 0.5;
    };
    class GVAR(aiSkill_spotting) {
        category = QUOTE(PREFIX);
        displayName = "Global AI Set Skill: spotDistance,spotTime";
        typeName = "SCALAR";
        value = 0.5;
    };
};

