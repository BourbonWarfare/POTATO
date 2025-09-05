[
    "potato_disableForestry", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type
    ["Disable Forestry", "Checking this box will turn OFF forestry, removing the option for players to chop down trees."], // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    "POTATO - Forestry", // Pretty name of the category where the setting can be found. Can be stringtable entry.
    true, // data for this setting: [min, max, default, number of shown trailing decimals]
    true // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
] call CBA_fnc_addSetting;

[
    "potato_requireEntrenchingTool", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type
    ["Require Entrenching Tool", "Unchecking this box will allow players to chop down trees without needing an ACE Entrenching Tool."], // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    "POTATO - Forestry", // Pretty name of the category where the setting can be found. Can be stringtable entry.
    true, // data for this setting: [min, max, default, number of shown trailing decimals]
    true // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
] call CBA_fnc_addSetting;

[
    "potato_chopTime", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "TIME", // setting type
    ["Chopping Time Duration", "Time, in seconds, required to chop down a tree."], // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    "POTATO - Forestry", // Pretty name of the category where the setting can be found. Can be stringtable entry.
    [1, 60, 8], // data for this setting: [min, max, default, number of shown trailing decimals]
    true // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
] call CBA_fnc_addSetting;
