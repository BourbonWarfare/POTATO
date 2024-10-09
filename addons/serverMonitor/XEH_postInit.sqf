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
            ["potato_hcSetIndex", [_forEachIndex + 1], [_x]] call CBA_fnc_targetEvent;
        } forEach (entities "HeadlessClient_F");
        [_this select 1] call CBA_fnc_removePerFrameHandler;
    }, 0, []] call CBA_fnc_addPerFrameHandler;

} else {
    if (!hasInterface) then {
        ["potato_hcSetIndex", {
            params ["_index"];
            GVAR(dataIndex) = _index;
            [] execFSM "z\potato\addons\serverMonitor\pabst_fsmCPS.fsm";
            diag_log text format ["[POTATO] Server Monitor FSM Installed [Index %1]", GVAR(dataIndex)];
        }] call CBA_fnc_addEventHandler;
    };
};

[{
    if (GVAR(dataIndex) < 0) exitWith {diag_log text format ["[POTATO] Waiting on index"];};
    params ["_args"];
    _args params ["_lastTime", "_lastFrame", "_lastFSM"];
    private _delta = diag_tickTime - _lastTime;
    private _fps = (diag_frameNo - _lastFrame) / _delta;
    private _cps = (GVAR(fsmNo) - _lastFSM) / _delta;
    _args set [0, diag_tickTime];
    _args set [1, diag_frameNo];
    _args set [2, GVAR(fsmNo)];

    private _localUnits = {local _x} count allUnits;
    TRACE_3("tick",_localUnits,_fps,_cps);

    missionNamespace setVariable [(format [QGVAR(%1), GVAR(dataIndex)]), [_localUnits, _fps, _cps], true];

}, 10, [0, 0, 0]] call CBA_fnc_addPerFrameHandler;
