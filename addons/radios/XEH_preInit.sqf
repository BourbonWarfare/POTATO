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

ADDON = true;
