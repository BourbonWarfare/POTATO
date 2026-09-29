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
