#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

GVAR(availableLanguages) = [
    ["af", "Afrikaans"],
    ["am", "American"],
    ["ar", "Arabic"],
    ["bg", "Bulgarian"],
    ["cn", "Chinese"],
    ["de", "German"],
    ["en", "English"],
    ["es", "Spanish"],
    ["fa", "Persian"],
    ["fr", "French"],
    ["ga", "Irish"],
    ["gd", "Gaelic"],
    ["hg", "Hand Gestures and Grunts"],
    ["hi", "Hindi"],
    ["it", "Italian"],
    ["ja", "Japanese"],
    ["ku", "Kurdish"],
    ["la", "Latin"],
    ["mn", "Mongolian"],
    ["nv", "Navajo"],
    ["oc", "Occitan"],
    ["pl", "Polish"],
    ["ps", "Pushto"],
    ["pt", "Portuguese"],
    ["qu", "Quechua"],
    ["ru", "Russian"],
    ["so", "Somali"],
    ["sv", "Swedish"],
    ["sw", "Swahili"],
    ["tl", "Tagalog"],
    ["uk", "Ukrainian"],
    ["vi", "Vietnamese"],
    ["wa", "Walloon"],
    ["wo", "Wolof"],
    ["xh", "Xhosa"],
    ["yi", "Yiddish"],
    ["zu", "Zulu"]
];

GVAR(initialized) = false;

// catch events fired pre post-init
GVAR(runInitNow) = false;
if ((getNumber (missionConfigFile >> "CfgLoadouts" >> "usePotato")) == 1) then {
    GVAR(gearEHID) = [QEGVAR(assignGear,gearAssigned), {GVAR(runInitNow) = true;}] call CBA_fnc_addEventHandler;
};

ADDON = true;
