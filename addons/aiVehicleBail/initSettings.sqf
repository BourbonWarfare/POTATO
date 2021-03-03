//pragma SKIP_COMPILE

[
    QGVAR(enableCrewBailing),
    "CHECKBOX",
    ["Enable Crew-Bailing", "Enable/Disable the AI bailing out of mission-destroyed vehicles (When the vehicle cannot move and/or shoot)"],
    ["POTATO - AI", "Vehicle Bail"],
    true, // default value
    true, // isGlobal
    {[QGVAR(enableCrewBailing), _this] call ACEFUNC(common,cbaSettings_settingChanged)}
] call CBA_settings_fnc_init;
[
    QGVAR(enableCookoff),
    "CHECKBOX",
    ["Enable Cook-off", "Enable/Disable Vehicles cooking off when they take appropiate amounts of damage"],
    ["POTATO - AI", "Vehicle Bail"],
    true, // default value
    true, // isGlobal
    {[QGVAR(enableCookoff), _this] call ACEFUNC(common,cbaSettings_settingChanged)}
] call CBA_settings_fnc_init;
[
    QGVAR(enableCookoffDetonations),
    "CHECKBOX",
    ["Enable Ammo Detonation", "Enable/Disable Whether or not vehicles will detonate their ammo when hit"],
    ["POTATO - AI", "Vehicle Bail"],
    true, // default value
    true, // isGlobal
    {[QGVAR(enableCookoffDetonations), _this] call ACEFUNC(common,cbaSettings_settingChanged)}
] call CBA_settings_fnc_init;
[
    QGVAR(enableCookoffMultihit),
    "CHECKBOX",
    ["Enable Multi-Hit Cookoff Check", "Enable/Disable whether or not multiple hits can be checked in the same frame"],
    ["POTATO - AI", "Vehicle Bail"],
    false, // default value
    true, // isGlobal
    {[QGVAR(enableCookoffMultihit), _this] call ACEFUNC(common,cbaSettings_settingChanged)}
] call CBA_settings_fnc_init;

