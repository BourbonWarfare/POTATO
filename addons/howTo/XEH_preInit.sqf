#include "script_component.hpp"

private _category = ["POTATO - User", "How To"];

[
    QGVAR(showForGroupMembers),
    "CHECKBOX",
    ["Show For Group Members", "Show how to hints for equipment other people in your group are using"],
    _category,
    false,
    0
] call CBA_fnc_addSetting;
