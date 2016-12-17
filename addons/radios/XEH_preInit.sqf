#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

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

GVAR(initState) = 0;

if ((getText (configFile >> "CfgPatches" >> "acre_main" >> "versionStr")) == "2.3.0.926") then {
    [
        "ACRE_SPECTATOR_VOLUME",
        "SLIDER",
        "Spectator Volume [pre297]",
        "ACRE2",
        [0, 1, 1, 2],
        false,
        {}
    ] call CBA_Settings_fnc_init;
} else {
    ERROR_MSG("remove acre spectator cba_setting");
};

ADDON = true;
