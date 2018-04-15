[
    QGVAR(deadCleanupEnabled),
    "CHECKBOX",
    ["Enable dead body cleanup", "Enables clean up of dead bodies and blown up vehicles."],
    "POTATO Admin",
    false,
    1
] call cba_settings_fnc_init;

[
    QGVAR(deletionDelay),
    "SLIDER",
    ["Time between deleting units", "Time in seconds between object removals (0 is each frame)"],
    "POTATO Admin",
    [0, 5, 0, 2],
    1
] call cba_settings_fnc_init;

[
    QGVAR(minTime),
    "SLIDER",
    ["Min time for cleanup", "Minium time the dead have to be... dead for garbage collection."],
    "POTATO Admin",
    [0, 300, 180, 0],
    1
] call cba_settings_fnc_init;

[
    QGVAR(maxTime),
    "SLIDER",
    ["Max time for cleanup", "Max time the dead have to be... dead before forced garbage collection."],
    "POTATO Admin",
    [300, 1200, 900, 0],
    1
] call cba_settings_fnc_init;

[
    QGVAR(disableRaycasting),
    "CHECKBOX",
    ["Disable raycasting for cleanup", "Disables visual checks for garbage collected objects."],
    "POTATO Admin",
    false,
    1,
    {
        TRACE_1("Params", _this);
        DFUNC(canCollect) = if (_this) then {
            { _this call FUNC(canCollectDist); }
        } else {
            { _this call FUNC(canCollectDistAndCast); }
        };
    }
] call cba_settings_fnc_init;

[
    QGVAR(minDistance),
    "SLIDER",
    ["Min distance for cleanup", "Minium distance the dead have to be away from players for garbage collection."],
    "POTATO Admin",
    [10, 500, 150, 0],
    1,
    { GVAR(minDistanceSqr) = _this^2; }
] call cba_settings_fnc_init;

[
    QGVAR(maxDistance),
    "SLIDER",
    ["Max distance for ray cast", "Maxiumum distance the dead have to skip raycasted."],
    "POTATO Admin",
    [500, 5000, 1500, 0],
    1,
    { GVAR(maxDistanceSqr) = _this^2; }
] call cba_settings_fnc_init;
