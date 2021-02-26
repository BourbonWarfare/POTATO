//pragma SKIP_COMPILE
[
    QGVAR(showTimer),
    "CHECKBOX",
    ["Show SafeStart Timer", "False disables the on screen timer, can use to make clean recordings."],
    "POTATO UI",
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
    "POTATO Admin",
    false,
    1
] call cba_settings_fnc_init;
