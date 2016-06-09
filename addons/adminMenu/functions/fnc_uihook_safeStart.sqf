#include "script_component.hpp"

params ["_newSetting"];
TRACE_1("params",_this);

if (_newSetting) then {
    [] remoteExecCall [QEFUNC(safeStart,makeSafe), 2];

    private _debugMsg = format ["Turning on SafeStart"];
    ["potato_adminMsg", [_debugMsg, profileName]] call CBA_fnc_globalEvent;
} else {
    missionNamespace setVariable [QEGVAR(safeStart,startTime_PV), -1, true];

    private _debugMsg = format ["Turning off SafeStart"];
    ["potato_adminMsg", [_debugMsg, profileName]] call CBA_fnc_globalEvent;
};
