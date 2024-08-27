[
    QGVAR(enable),
    "CHECKBOX",
    ["Enable Body Cleanup", "Enable/Disable whether or not AI bodies will be automatically cleaned up upon their deaths"],
    ["POTATO - Body Cleanup", "Body Cleanup"],
    false, // default value
    true, // isGlobal
    {[QGVAR(enable), _this] call ACEFUNC(common,cbaSettings_settingChanged)}
] call CBA_settings_fnc_init;
[
    QGVAR(hideInsteadOfDelete),
    "CHECKBOX",
    ["Hide bodies", "Whether or not we will hide and disable simulation on dead bodies instead of deleting them outright"],
    ["POTATO - Body Cleanup", "Body Cleanup"],
    false, // default value
    true, // isGlobal
    {[QGVAR(hideInsteadOfDelete), _this] call ACEFUNC(common,cbaSettings_settingChanged)}
] call CBA_settings_fnc_init;
