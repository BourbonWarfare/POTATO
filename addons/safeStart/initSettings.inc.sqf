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
    "LIST",
    ["Show SafeStart Timer", "Whether to show the safe start timer and additional safe start equipment information."],
    ["POTATO - User", "Safe Start"],
    [[0, 1, 2], ["Timer and Info Off", "Display Timer", "(DEV) Display Timer and Info"], 1],
    0, {
    if (missionNamespace getVariable [QGVAR(startTime_PV), -1] != -1) then {
        if (_this > 0) then {
            private _title = uiNamespace getVariable [QGVAR(timerRscTitle), displayNull];
            if (isNull _title) exitWith {
                [QGVAR(timerRscTitle)] call CFUNC(createRscTitle);
                _title = uiNamespace getVariable [QGVAR(timerRscTitle), displayNull];
            };
            private _ctrlGroup = _title displayCtrl IDC_SAFESTARTINFO_BASEGRP;
            if (_this == 2) then {
                (_ctrlGroup controlsGroupCtrl IDC_SAFESTARTEQUIP_BACKGROUND) ctrlShow true;
                (_ctrlGroup controlsGroupCtrl IDC_SAFESTARTINFO_DISP) ctrlShow true;
                [_ctrlGroup controlsGroupCtrl IDC_SAFESTARTINFO_DISP] call FUNC(fillSafeStartEquip);
            } else {
                (_ctrlGroup controlsGroupCtrl IDC_SAFESTARTEQUIP_BACKGROUND) ctrlShow false;
                (_ctrlGroup controlsGroupCtrl IDC_SAFESTARTINFO_DISP) ctrlShow false;
            };
        } else {
            QGVAR(timerRscTitle) cutFadeOut 0;
        };
    };
}] call cba_settings_fnc_init;

[
    QGVAR(enabled),
    "CHECKBOX",
    ["Enable safe start at mission start", "Enables safe start at the start of the mission."],
    ["POTATO - Mission Maker", "Safe Start"],
    false,
    1
] call cba_settings_fnc_init;
