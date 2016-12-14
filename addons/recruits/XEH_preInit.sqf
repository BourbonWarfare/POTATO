#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

if !(hasInterface) exitWith {};

// Register events
["potato_safeStartOn", {
    [GVAR(showMessage) || GVAR(showTag)] call FUNC(toggleRecruitInfo);
}] call CBA_fnc_addEventHandler;

["potato_safeStartOff", {
    [false] call FUNC(toggleRecruitInfo);
}] call CBA_fnc_addEventHandler;

["ace_settingChanged", {
    params ["_name", "_value"];

    if (_name == QGVAR(showMessage) && missionNamespace getVariable [QEGVAR(safeStart,startTime_PV), -1] != -1) exitWith {
        if (_value) then {
            [QGVAR(message)] call CFUNC(createDisplay);
        } else {
            QGVAR(message) cutFadeOut 1;
        };
        [_value || GVAR(showTag)] call FUNC(toggleRecruitInfo);
    };
    if (_name == QGVAR(showTag) && missionNamespace getVariable [QEGVAR(safeStart,startTime_PV), -1] != -1) exitWith {
        [GVAR(showMessage) || _value] call FUNC(toggleRecruitInfo);
    };
}] call CBA_fnc_addEventHandler;

ADDON = true;
