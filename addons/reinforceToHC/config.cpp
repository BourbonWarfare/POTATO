#include "script_component.hpp"

class CfgPatches {
  class potato_reinforceToHC {
    units[] = {QGVAR(Reinforcements_Spawn_Units),"Ares_Module_Reinforcements_Spawn_Units"};
    requiredVersion = 1.56;
    requiredAddons[] = {"potato_core","Ares"};
    author[] = {"AACO"};
    authorUrl = "https://github.com/BourbonWarfare/POTATO";
    version = "1.0.0.3";
    versionStr = "1.0.0.3";
    versionAr[] = {1,0,0,3};
  };
};

class Extended_PreInit_EventHandlers {
  class ADDON {
    init = QUOTE(call COMPILE_FILE(XEH_preInit));
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
