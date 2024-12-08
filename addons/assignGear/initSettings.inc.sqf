[
    QGVAR(showAllOptics), "CHECKBOX",
    ["Show all available optics", "Show all optic options, including the current selected optic."],
    ["POTATO - User", "Gear"],
    false, // default value
    2, // local only
    {},
    false // No mission restart needed
] call CBA_fnc_addSetting;
