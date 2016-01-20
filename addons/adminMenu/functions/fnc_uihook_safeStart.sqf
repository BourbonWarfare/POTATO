#include "script_component.hpp"

params ["_newSetting"];

if (_newSetting) then {
    [] remoteExecCall [QEFUNC(safeStart,makeSafe), 2];

    _debugMsg = format ["PABST_ADMIN: %1 is turning on SafeStart", (profileName)];
    ["potato_adminMsg", [_debugMsg]] call ACEFUNC(common,globalEvent);
} else {
    missionNamespace setVariable [QEGVAR(safeStart,startTime_PV), -1, true];

    _debugMsg = format ["PABST_ADMIN: %1 is turning off SafeStart", (profileName)];
    ["potato_adminMsg", [_debugMsg]] call ACEFUNC(common,globalEvent);
};
