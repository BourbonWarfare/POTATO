#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

[
    QGVAR(showNotifcations),
    "CHECKBOX",
    ["Show POTATO system chat notifications", "False should disable most notifcations, can use to make clean recordings."],
    "POTATO UI",
    true
] call cba_settings_fnc_init;

ADDON = true;
