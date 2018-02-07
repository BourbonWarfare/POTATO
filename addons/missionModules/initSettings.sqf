[
    QGVAR(aiSkill_set),
    "CHECKBOX",
    ["Master Enable", "Enable/disable setting AI skills/behaviors on unit creation."],
    "POTATO AI",
    false,
    1
] call cba_settings_fnc_init;

[
    QGVAR(aiSkill_aimingAccuracy_min),
    "SLIDER",
    ["Aiming Accuracy Floor", "Minimum aiming accuracy for a spawned unit."],
    "POTATO AI",
    [0, 1, 0.55, 2],
    1
] call cba_settings_fnc_init;

[
    QGVAR(aiSkill_aimingAccuracy_max),
    "SLIDER",
    ["Aiming Accuracy Ceiling", "Maximum aiming accuracy for a spawned unit."],
    "POTATO AI",
    [0, 1, 0.85, 2],
    1
] call cba_settings_fnc_init;

[
    QGVAR(aiSkill_aimingShake_min),
    "SLIDER",
    ["Aiming Shake Floor", "Minimum aiming shake for a spawned unit."],
    "POTATO AI",
    [0, 1, 0.5, 2],
    1
] call cba_settings_fnc_init;

[
    QGVAR(aiSkill_aimingShake_max),
    "SLIDER",
    ["Aiming Shake Ceiling", "Maximum aiming shake for a spawned unit."],
    "POTATO AI",
    [0, 1, 0.75, 2],
    1
] call cba_settings_fnc_init;

[
    QGVAR(aiSkill_aimingSpeed_min),
    "SLIDER",
    ["Aiming Speed Floor", "Minimum aiming speed for a spawned unit."],
    "POTATO AI",
    [0, 1, 0.55, 2],
    1
] call cba_settings_fnc_init;

[
    QGVAR(aiSkill_aimingSpeed_max),
    "SLIDER",
    ["Aiming Speed Ceiling", "Maximum aiming speed for a spawned unit."],
    "POTATO AI",
    [0, 1, 0.75, 2],
    1
] call cba_settings_fnc_init;

[
    QGVAR(aiSkill_commanding_min),
    "SLIDER",
    ["Commanding Floor", "Minimum commanding for a spawned unit."],
    "POTATO AI",
    [0, 1, 0.75, 2],
    1
] call cba_settings_fnc_init;

[
    QGVAR(aiSkill_commanding_max),
    "SLIDER",
    ["Commanding Ceiling", "Maximum commanding for a spawned unit."],
    "POTATO AI",
    [0, 1, 0.95, 2],
    1
] call cba_settings_fnc_init;

[
    QGVAR(aiSkill_courage_min),
    "SLIDER",
    ["Courage Floor", "Minimum courage for a spawned unit."],
    "POTATO AI",
    [0, 1, 0.9, 2],
    1
] call cba_settings_fnc_init;

[
    QGVAR(aiSkill_courage_max),
    "SLIDER",
    ["Courage Ceiling", "Maximum courage for a spawned unit."],
    "POTATO AI",
    [0, 1, 1, 2],
    1
] call cba_settings_fnc_init;

[
    QGVAR(aiSkill_general_min),
    "SLIDER",
    ["General Floor", "Minimum 'general' for a spawned unit."],
    "POTATO AI",
    [0, 1, 1, 2],
    1
] call cba_settings_fnc_init;

[
    QGVAR(aiSkill_general_max),
    "SLIDER",
    ["General Ceiling", "Maximum 'general' for a spawned unit."],
    "POTATO AI",
    [0, 1, 1, 2],
    1
] call cba_settings_fnc_init;

[
    QGVAR(aiSkill_reloadSpeed_min),
    "SLIDER",
    ["Reload Speed Floor", "Minimum reload speed for a spawned unit."],
    "POTATO AI",
    [0, 1, 0.75, 2],
    1
] call cba_settings_fnc_init;

[
    QGVAR(aiSkill_reloadSpeed_max),
    "SLIDER",
    ["Reload Speed Ceiling", "Maximum reload speed for a spawned unit."],
    "POTATO AI",
    [0, 1, 0.95, 2],
    1
] call cba_settings_fnc_init;

[
    QGVAR(aiSkill_spotDistance_min),
    "SLIDER",
    ["Spot Distance Floor", "Minimum spot distance for a spawned unit."],
    "POTATO AI",
    [0, 1, 0.75, 2],
    1
] call cba_settings_fnc_init;

[
    QGVAR(aiSkill_spotDistance_max),
    "SLIDER",
    ["Spot Distance Ceiling", "Maximum spot distance for a spawned unit."],
    "POTATO AI",
    [0, 1, 0.95, 2],
    1
] call cba_settings_fnc_init;

[
    QGVAR(aiSkill_spotTime_min),
    "SLIDER",
    ["Spot Time Floor", "Minimum spot time for a spawned unit."],
    "POTATO AI",
    [0, 1, 0.75, 2],
    1
] call cba_settings_fnc_init;

[
    QGVAR(aiSkill_spotTime_max),
    "SLIDER",
    ["Spot Time Ceiling", "Maximum spot time for a spawned unit."],
    "POTATO AI",
    [0, 1, 0.95, 2],
    1
] call cba_settings_fnc_init;

[
    QGVAR(aiSkill_AUTOCOMBAT),
    "CHECKBOX",
    ["Autocombat", "Enable/disable AI automatically changing to combat mode."],
    "POTATO AI",
    true,
    1
] call cba_settings_fnc_init;

[
    QGVAR(aiSkill_COVER),
    "CHECKBOX",
    ["Cover", "Enable/disable AI moving into cover when in combat."],
    "POTATO AI",
    true,
    1
] call cba_settings_fnc_init;

[
    QGVAR(aiSkill_PATH),
    "CHECKBOX",
    ["Path", "Enable/disable AI from moving, but not engaging/looking."],
    "POTATO AI",
    true,
    1
] call cba_settings_fnc_init;

[
    QGVAR(aiSkill_SUPPRESSION),
    "CHECKBOX",
    ["Suppression", "Enable/disable AI from being suppressed."],
    "POTATO AI",
    true,
    1
] call cba_settings_fnc_init;
