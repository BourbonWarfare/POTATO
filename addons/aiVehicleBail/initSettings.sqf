// CBA Settings

[
    QGVAR(enableCrewBailing),
    "CHECKBOX",
    ["Enable Crew-Bailing", "Enable/Disable the AI bailing out of mission-destroyed vehicles (When the vehicle cannot move and/or shoot)"],
    "POTATO AI Behaviours",
    true, // default value
    true, // isGlobal
    {[QGVAR(enableCrewBailing), _this] call ACEFUNC(common,cbaSettings_settingChanged)}
] call CBA_settings_fnc_init;
[
    QGVAR(enableCookoff),
    "CHECKBOX",
    ["Enable Cook-off", "Enable/Disable Vehicles cooking off when they take appropiate amounts of damage"],
    "POTATO AI Behaviours",
    true, // default value
    true, // isGlobal
    {[QGVAR(enableCookoff), _this] call ACEFUNC(common,cbaSettings_settingChanged)}
] call CBA_settings_fnc_init;

