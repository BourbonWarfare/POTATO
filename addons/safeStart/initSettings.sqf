[
    QGVAR(syncFortify),
    "CHECKBOX",
    ["Required for Fortify", "Only allow using fortify tool when safe start is enabled"],
    ["POTATO - Mission Maker", "Safe Start"],
    true, // default
    1 // global
] call cba_settings_fnc_init;

[
    QGVAR(showTimer),
    "CHECKBOX",
    ["Show SafeStart Timer", "False disables the on screen timer, can use to make clean recordings."],
    ["POTATO - User", "Safe Start"],
    true,
    0,
    {
        if (missionNamespace getVariable [QGVAR(startTime_PV), -1] != -1) then {
            if (_this) then {
                [QGVAR(timerRscTitle)] call CFUNC(createRscTitle);
            } else {
                QGVAR(timerRscTitle) cutFadeOut 0;
            };
        };
    }
] call cba_settings_fnc_init;

[
    QGVAR(enabled),
    "CHECKBOX",
    ["Enable safe start at mission start", "Enables safe start at the start of the mission."],
    ["POTATO - Mission Maker", "Safe Start"],
    false,
    1
] call cba_settings_fnc_init;
