// CBA Settings

[
    QGVAR(enableCrewBailing),
    "CHECKBOX",
    ["Enable Crew-Bailing", "Enable/Disable the AI bailing out of mission-destroyed vehicles (When the vehicle cannot move and/or shoot)"],
    "POTATO AI Behaviours",
    true, // default value
    true, // isGlobal
    {[QGVAR(enableCrewBailing), _this] call EFUNC(common,cbaSettings_settingChanged)}
] call CBA_settings_fnc_init;

