#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

// defaults
GVAR(enabled) = false;
GVAR(radioInterference) = false;
GVAR(terrainInterference) = 0.5;
GVAR(addCommonChannelName) = "Negotiations";
GVAR(addCommonChannelNumber) = 8;
GVAR(addCommonChannelAllMR) = false;
GVAR(addCommonChannelAllLR) = false;

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

ADDON = true;
