#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function initializes the GVAR(fpsAvgCalc) array and adds the per
 * frame event handler to calculate and report FPS to the server. If the player
 * has turned off the system or it's already runnig
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Examples:
 * [] call potato_zeusUtils_fnc_initLocalFPSEH;
 *
 * Public: No
 */
TRACE_3("init local FPS EH",hasInterface,GVAR(fpsAvgCalcEH),GVAR(clientEnable));
if (!hasInterface || GVAR(fpsAvgCalcEH) >= 0 || !GVAR(clientEnable)) exitWith {};

GVAR(fpsAvgCalc) = [diag_fps, [1, 1, 1, 1, 1] vectorMultiply (diag_fps / 5)];
GVAR(fpsAvgCalcEH) = [{
    params ["_startTime", "_handle"];
    if !(GVAR(clientEnable)) exitWith {
        GVAR(fpsAvgCalcEH) = -1;
        [_handle] call CBA_fnc_removePerFrameHandler;
    };
    private _nextFPS = diag_fps / 5;
    private _timeSinceInit floor CBA_missionTime - _startTime;
    private _idx = _timeSinceInit mod 5;
    GVAR(fpsAvgCalc) set [0, GVAR(fpsAvgCalc)#0 + _nextFPS - GVAR(fpsAvgCalc)#1#_idx];
    GVAR(fpsAvgCalc)#1 set [_idx, diag_fps / 5];
    if (_timeSinceInit  mod GVAR(clientUpdateRate) == 0) then {
        [player, GVAR(fpsAvgCalc)#0] remoteExecCall [QFUNC(updateServerFPSList), 2];
    };
}, 1, floor CBA_missionTime] call CBA_fnc_addPerFrameHandler;
