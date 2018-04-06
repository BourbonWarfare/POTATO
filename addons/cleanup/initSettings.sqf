[
    QGVAR(deadCleanupEnabled),
    "CHECKBOX",
    ["Enable dead body cleanup", "Enables clean up of dead bodies and blown up vehicles."],
    "POTATO Admin",
    false,
    1
] call cba_settings_fnc_init;

[
    QGVAR(minTime),
    "SLIDER",
    ["Min time for cleanup", "Minium time the dead have to be... dead for garbage collection."],
    "POTATO Admin",
    [0, 300, 120, 10],
    1
] call cba_settings_fnc_init;

[
    QGVAR(maxTime),
    "SLIDER",
    ["Max time for cleanup", "Max time the dead have to be... dead before forced garbage collection."],
    "POTATO Admin",
    [300, 1200, 900, 10],
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
        DFUNC(canCollect) = if (_this) then {
            FUNC(canCollectDist)
        } else {
            FUNC(canCollectDistAndCast)
        };
    }
] call cba_settings_fnc_init;

[
    QGVAR(minDistance),
    "SLIDER",
    ["Min distance for cleanup", "Minium distance the dead have to be away from players for garbage collection."],
    "POTATO Admin",
    [10, 500, 150, 10],
    1,
    { GVAR(minDistanceSqr) = _this^2; }
] call cba_settings_fnc_init;

[
    QGVAR(maxDistance),
    "SLIDER",
    ["Max distance for ray cast", "Maxiumum distance the dead have to skip raycasted."],
    "POTATO Admin",
    [500, 5000, 1500, 100],
    1,
    { GVAR(maxDistanceSqr) = _this^2; }
] call cba_settings_fnc_init;
