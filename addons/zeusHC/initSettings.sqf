[
    QGVAR(maxAICount),
    "SLIDER",
    ["Maximum AI Count", "Maximum active AI allowed at one time."],
    ["POTATO - Mission Maker", "ZeusHC Spawning"],
    [1, 200, 90, 0],
    1
] call cba_settings_fnc_init;

[
    QGVAR(maxGroupCountPerSide),
    "SLIDER",
    ["Maximum Groups Per Side", "Maximum active groups allowed (per side)."],
    ["POTATO - Mission Maker", "ZeusHC Spawning"],
    [1, 280, 280, 0],
    1
] call cba_settings_fnc_init;

[
    QGVAR(delayBetweenUnitCreation),
    "SLIDER",
    ["Delay Between AI Creation", "Delay between creating AI units from potato tools."],
    ["POTATO - Mission Maker", "ZeusHC Spawning"],
    [0, 10, 0.4, 1],
    1
] call cba_settings_fnc_init;

[
    QGVAR(delayBetweenGroupCreation),
    "SLIDER",
    ["Delay Between AI Group Creation", "Delay between creating AI groups from potato tools."],
    ["POTATO - Mission Maker", "ZeusHC Spawning"],
    [0, 10, 1, 1],
    1
] call cba_settings_fnc_init;
