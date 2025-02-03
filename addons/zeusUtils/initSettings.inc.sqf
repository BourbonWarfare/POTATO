//***************** Player FPS Display *********************/
/// User settings
[
    QGVAR(clientFPSEnable), "CHECKBOX",
    ["Report client FPS to Zeus", "Report your FPS to the Zanes for performance management."],
    ["POTATO - User", "Zeus Player FPS Display"],
    true,
    2,
    {
        if (GVAR(clientFPSEnable)) then {
            [] call FUNC(initLocalFPSEH);
        };
    },
    false
] call CBA_fnc_addSetting;

[
    QGVAR(clientFPSUpdateRate), "TIME",
    ["Client FPS Report Period", "How long should elapse between your client reporting your FPS to Zeus."],
    ["POTATO - User", "Zeus Player FPS Display"],
    [3, 90, 5],
    2,
    {},
    false
] call CBA_fnc_addSetting;

// Zeus Settings
[
    QGVAR(missionFPSEnable), "CHECKBOX",
    ["Enable Zeus FPS counter", "Enable Zeus display of players FPS counters. Takes some network overhead."],
    ["POTATO - Mission Maker", "Zeus Utilities"],
    false,
    1,
    {},
    false
] call CBA_fnc_addSetting;

[
    QGVAR(skipFPSAboveThreshold), "CHECKBOX",
    ["Skip FPS above threshold", "Skip displaying player FPS is above threshold."],
    ["POTATO - Zeus", "Zeus Player FPS Display"],
    true,
    2,
    {},
    false
] call CBA_fnc_addSetting;

[
    QGVAR(fpsThreshold), "SLIDER",
    ["FPS warning threshold", "Highlight a players FPS's when it's below this threshold."],
    ["POTATO - Zeus", "Zeus Player FPS Display"],
    [1, 60, 20, 0, false],
    2,
    {},
    false
] call CBA_fnc_addSetting;

[
    QGVAR(playerFPSDisplayDistance), "SLIDER",
    ["Maximum FPS display distance", "The maximum distance a player's FPS will be displayed"],
    ["POTATO - Zeus", "Zeus Player FPS Display"],
    [100, 1000, 200, 0, false],
    2,
    {},
    false
] call CBA_fnc_addSetting;

[
    QGVAR(fpsWarningColor), "COLOR",
    ["Critical FPS color", "The color to set an FPS counter that falls below the thereshold."],
    ["POTATO - Zeus", "Zeus Player FPS Display"],
    [0.8, 0, 0, 0.8],
    2,
    {},
    false
] call CBA_fnc_addSetting;
