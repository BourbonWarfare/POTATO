#include "script_component.hpp"

params ["_winningSide"];
TRACE_1("params",_this);

if (isServer) then {
    private _missionType = getMissionConfigValue[QEGVAR(missionTesting, missionType), "other"];
    [_winningSide, "Mission ended", _missionType] call ocap_fnc_exportData;
    ["potato_adminMsg", [_debugMsg, profileName, "#ALL"]] call CBA_fnc_globalEvent;
    private _debugMsg = format ["Saving OCAP recording with side %1 and mission type %2", _winningSide, _missionType];
};

if ((!hasInterface) || {EGVAR(core,playerStartingSide) == _winningSide}) then {
    ["", true, 1] call BIS_fnc_endMission;
} else {
    ["", false, 1] call BIS_fnc_endMission;
};
