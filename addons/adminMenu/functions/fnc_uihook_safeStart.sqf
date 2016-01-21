#include "script_component.hpp"

params ["_newSetting"];
TRACE_1("params",_this);

if (_newSetting) then {
    [] remoteExecCall [QEFUNC(safeStart,makeSafe), 2];

    _debugMsg = format ["Turning on SafeStart"];
    ["potato_adminMsg", [_debugMsg, profileName]] call ACEFUNC(common,globalEvent);
} else {
    missionNamespace setVariable [QEGVAR(safeStart,startTime_PV), -1, true];

    _debugMsg = format ["Turning off SafeStart"];
    ["potato_adminMsg", [_debugMsg, profileName]] call ACEFUNC(common,globalEvent);
};
