
private _category = ["POTATO - User", "Go By (DUI Nametags)"];

[
    QGVAR(goBy),
    "EDITBOX",
    ["Go By", "How do you want to be called\nFully Optional, Please be respectful."],
    _category,
    "",
    false,
    {
        call FUNC(syncPlayer);
    }
] call CBA_fnc_addSetting;

[
    QGVAR(show),
    "LIST",
    ["Show", "When to show other's info on their DUI-Nametags."],
    _category,
    [[0, 1, 2], ["Disabled", "During Safe-Start", "Always"], 1],
    false
] call CBA_fnc_addSetting;

[
    QGVAR(color),
    "COLOR",
    ["Color"],
    _category,
    [1, 0.3, 0, 1],
    false,
    {
        GVAR(colorHex) = [(_this select 0) * 255,(_this select 1) * 255,(_this select 2) * 255] call diwako_dui_main_fnc_toHex;
    }
] call CBA_fnc_addSetting;
