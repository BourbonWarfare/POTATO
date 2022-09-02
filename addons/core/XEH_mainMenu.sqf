#include "script_component.hpp"

if (hasInterface) then {
    INFO("disabling soggy menu");
    profileNamespace setVariable ["emm_mainmenu_enabled", false];
    profileNamespace setVariable ["emm_multiplayermenu_enabled", false];
    saveProfileNamespace;
};
