[
    QGVAR(showNotifcations),
    "CHECKBOX",
    ["Show POTATO system chat notifications", "False should disable most notifcations, can use to make clean recordings."],
    ["POTATO - User", "Admin Chat"],
    true
] call cba_settings_fnc_init;
[
    QGVAR(showTechNotifcations),
    "CHECKBOX",
    ["Show #tech info", "Show more techincal/debug info in chat"],
    ["POTATO - User", "Admin Chat"],
    false
] call cba_settings_fnc_init;
[
    QGVAR(hideSystemPlayerConnecting),
    "CHECKBOX",
    ["Hide system player connection messages", "Hides ""Player is losing connection"" type messages"],
    ["POTATO - User", "Admin Chat"],
    false
] call cba_settings_fnc_init;
[
    QGVAR(showPlayerStats),
    "LIST",
    ["Show player stats at end of mission", "Show some bonus stats like distance walked and medical actions [Setting change takes effect next mission]"],
    ["POTATO - User", "Admin Chat"],
    [[0, 1, 2], ["Disabled", "Enabled (Show At Bottom)", "Enabled (Show At Top)"], 0], // opt-in to give in a few sessions to test
    true, // isGlobal
    { call FUNC(init_stats); } // on change
] call cba_settings_fnc_init;
