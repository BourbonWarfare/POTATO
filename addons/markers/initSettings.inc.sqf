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
    QGVAR(intraFireteam_occlude), "CHECKBOX",
    ["intraFireteam - Occlude Marks"],
    ["POTATO - Mission Maker", "Markers"],
    false, // default value
    true, // isGlobal
    {
        if (!isNil QGVAR(intraAlphaPFEH) && {GVAR(intraAlphaPFEH) >= 0}) then {
            [GVAR(intraAlphaPFEH)] call CBA_fnc_removePerFrameHandler;
            GVAR(intraAlphaPFEH) = nil;
        };
    },
    false
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
