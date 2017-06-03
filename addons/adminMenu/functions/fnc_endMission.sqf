#include "script_component.hpp"

params ["_winningSide"];
TRACE_1("params",_this);

if ((!hasInterface) || {EGVAR(core,playerStartingSide) == _winningSide}) then {
    if (isDedicated) then {
        ["potato_endMission"] call CBA_fnc_localEvent;
        EGVAR(core,serverReadyToEnd) = true; // TODO: remove when ready
        [
            { missionNamespace getVariable [QEGVAR(core,serverReadyToEnd), false] || diag_tickTime >= _this },
            { ["", true, 1] call BIS_fnc_endMission; },
            diag_tickTime + 15
        ] call CBA_fnc_waitUntilAndExecute;
    } else {
        ["", true, 1] call BIS_fnc_endMission;
    };
} else {
    ["", false, 1] call BIS_fnc_endMission;
};
