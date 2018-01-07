#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

if (hasInterface) then {
    [
        QGVAR(showMessage),
        "CHECKBOX",
        ["Show Recuit Message", "Show the recruit message dialog."],
        "POTATO UI",
        true,
        0,
        {
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
            if (missionNamespace getVariable [QEGVAR(safeStart,startTime_PV), -1] != -1) exitWith {
                [_this] call FUNC(toggleRecruitTags);
            };
        }
    ] call cba_settings_fnc_init;


    // Register events
    ["potato_safeStartOn", {
        [GVAR(showMessage)] call FUNC(toggleRecruitInfo);
        [GVAR(showTags)] call FUNC(toggleRecruitTags);
    }] call CBA_fnc_addEventHandler;

    ["potato_safeStartOff", {
        [false] call FUNC(toggleRecruitInfo);
        [false] call FUNC(toggleRecruitTags);
    }] call CBA_fnc_addEventHandler;
};

ADDON = true;
