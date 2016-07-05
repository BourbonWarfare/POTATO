#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(defaultLanguages) = [
  ["en", "English"],
  ["ru", "Russian"],
  ["ar", "Arabic"],
  ["de", "German"],
  ["fr", "French"]
];

GVAR(initialized) = false;

// catch events fired pre post-init
GVAR(runInitNow) = false;
if ((getNumber (missionConfigFile >> "CfgLoadouts" >> "usePotato")) == 1) then {
    GVAR(gearEHID) = [QEGVAR(assignGear,gearAssigned), {GVAR(runInitNow) = true;}] call CBA_fnc_addEventHandler;
};

ADDON = true;
