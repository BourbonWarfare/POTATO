#include "\z\potato\addons\units\script_component.hpp"
#undef COMPONENT
#define COMPONENT zeusHC_noLambs
#define SIDE_NOLAMBS(unit,side) DOUBLES(TRIPLES(PREFIX,nolambs,side),unit)
#define UNITS_MODULES(SIDE) QGVAR(TRIPLES(SIDE,manpadTeam,noLambs)),\
QGVAR(TRIPLES(SIDE,matTeam,noLambs)),\
QGVAR(TRIPLES(SIDE,mmgTeam,noLambs)),\
QGVAR(TRIPLES(SIDE,patrol,noLambs)),\
QGVAR(TRIPLES(SIDE,fireteam,noLambs)),\
QGVAR(TRIPLES(SIDE,squad,noLambs))

class CfgPatches {
    class ADDON {
        units[] = {
            UNITS_MODULES(east),
            UNITS_MODULES(west),
            UNITS_MODULES(ind)
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
          "potato_core",
          "potato_zeusHC",
          "lambs_danger",
          "potato_units_noLambs"
        };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgFactionClasses.hpp"
#include "CfgVehicles.hpp"
