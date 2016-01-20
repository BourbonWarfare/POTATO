#include "script_component.hpp"

if ((!isServer) && hasInterface) exitWith {};

GVAR(dataIndex) = -1;
GVAR(fsmNo) = -1;

if (isServer) then {
    GVAR(dataIndex) = 0;
    [] execFSM "z\potato\addons\serverMonitor\pabst_fsmCPS.fsm";
    diag_log text format ["[POTATO] Server Monitor FSM Installed [Index %1]", GVAR(dataIndex)];
    
    //Send all HC an event with their index:
    [{
        if (time < 1) exitWith {}; //wait for HCs to connect before triggering events
        {
            ["hcSetIndex", [_x], [_forEachIndex]] call ace_common_fnc_targetEvent;
        } forEach (entities "HeadlessClient_F");
    }, 0, []] call CBA_fnc_addPerFrameHandler;

} else {
    if (!hasInterface) then {
        ["hcSetIndex", {
            params ["_index"];
            GVAR(dataIndex) = _index;
            [] execFSM "z\potato\addons\serverMonitor\pabst_fsmCPS.fsm";
            diag_log text format ["[POTATO] Server Monitor FSM Installed [Index %1]", GVAR(dataIndex)];
        }] call ace_common_fnc_addEventHandler;
    };
};

[{
    if (GVAR(dataIndex) < 0) exitWith {diag_log text format ["[POTATO] Waiting on index"];};
    params ["_args"];
    _args params ["_lastTime", "_lastFrame", "_lastFSM"];
    _delta = diag_tickTime - _lastTime;
    _fps = (diag_frameno - _lastFrame) / _delta;
    _cps = (GVAR(fsmNo) - _lastFSM) / _delta;
    _args set [0, diag_tickTime];
    _args set [1, diag_frameno];
    _args set [2, GVAR(fsmNo)];

    _localUnits = {local _x} count allUnits;
    TRACE_3("tick",_localUnits,_fps,_cps);

    missionNameSpace setVariable [(format [QGVAR(%1), GVAR(dataIndex)]), [_localUnits, _fps, _cps], true];

}, 10, [0, 0, 0]] call CBA_fnc_addPerFrameHandler;
