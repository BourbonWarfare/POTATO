[
    QGVAR(highlighColorOption), "COLOR",
    ["ORBAT highlight color", "The color the player is highlighted with in the ORBAT."],
    ["POTATO - User", "ORBAT"],
    [1, 1, 1], // default value
    2, // local only
    {},
    false // No mission restart needed
] call CBA_fnc_addSetting;

[
    QGVAR(useCompactOrbat), "CHECKBOX",
    ["Compact ORBAT", "Draw a compact ORBAT with one group per line."],
    ["POTATO - User", "ORBAT"],
    false, // default value
    2, // local only
    {},
    false // No mission restart needed
] call CBA_fnc_addSetting;

[
    QGVAR(sortOrbat), "CHECKBOX",
    ["Attempt Compact ORBAT Sort", "ONLY WORKS ON COMPACT ORBAT. Attempt to sort and group orbat by platoon and other assets (i.e., air, weapons, etc.)"],
    ["POTATO - User", "ORBAT"],
    false, // default value
    2, // local only
    {},
    false // No mission restart needed
] call CBA_fnc_addSetting;
