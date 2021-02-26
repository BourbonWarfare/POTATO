//pragma SKIP_COMPILE
[
    QGVAR(showMessage),
    "CHECKBOX",
    ["Show Recuit Message", "Show the recruit message dialog."],
    "POTATO UI",
    true,
    0,
    {
        if (!hasInterface) exitWith {};
        if (missionNamespace getVariable [QEGVAR(safeStart,startTime_PV), -1] != -1) exitWith {
            [_this] call FUNC(toggleRecruitInfo);
        };
    }
] call cba_settings_fnc_init;

[
    QGVAR(showTags),
    "CHECKBOX",
    ["Show Recuit Tags", "Show recruit tags above their heads."],
    "POTATO UI",
    true,
    0,
    {
        if (!hasInterface) exitWith {};
        if (missionNamespace getVariable [QEGVAR(safeStart,startTime_PV), -1] != -1) exitWith {
            [_this] call FUNC(toggleRecruitTags);
        };
    }
] call cba_settings_fnc_init;
