[
    QGVAR(groupAndUnitEnabled), "CHECKBOX",
    ["groupAndUnit"],
    ["POTATO - Mission Maker", "Markers"],
    false, // default value
    true, // isGlobal
    {},
    true // Needs mission restart
] call CBA_fnc_addSetting;

[
    QGVAR(intraFireteamEnabled), "CHECKBOX",
    ["intraFireteam"],
    ["POTATO - Mission Maker", "Markers"],
    false, // default value
    true, // isGlobal
    {},
    true // Needs mission restart
] call CBA_fnc_addSetting;

[
    QGVAR(intraFireteam_playerOnly), "CHECKBOX",
    ["intraFireteam - player only"],
    ["POTATO - Mission Maker", "Markers"],
    false, // default value
    true, // isGlobal
    {},
    true // Needs mission restart
] call CBA_fnc_addSetting;

[
    QGVAR(groupAndUnitUpdateDelay), "SLIDER",
    ["Update Delay"],
    ["POTATO - Mission Maker", "Markers"],
    [0,60,3,1], // [min, max, default value, trailing decimals (-1 for whole numbers only)]
    true, // isGlobal
    {},
    true // Needs mission restart
] call CBA_fnc_addSetting;
