//pragma SKIP_COMPILE
[
    QGVAR(showNotifcations),
    "CHECKBOX",
    ["Show POTATO system chat notifications", "False should disable most notifcations, can use to make clean recordings."],
    ["POTATO - User", "Admin Chat"],
    true
] call cba_settings_fnc_init;
