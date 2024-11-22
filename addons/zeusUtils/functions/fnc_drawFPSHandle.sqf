#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function is called each frame from a Draw3D EH.
 * It adds an FPS count to each unit that reports it and will only show when
 * the Zeus interface is open. This function MUST be called through the Draw3D
 * event handler.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Examples:
 * call potato_zeusUtils_fnc_drawFPSHandle;
 *
 * Public: No
 */
//IGNORE_PRIVATE_WARNING["_thisEvent", "_thisEventHandler"];
diag_log formatText ["diag FPS Handle: %1", diag_frameNo];
if (isNull findDisplay 312 ||
    !GVAR(missionEnable)) exitWith {
    removeMissionEventHandler [_thisEvent, _thisEventHandler];
    GVAR(fpsDisplayEH) = -2;
};

private _players = allUnits;//call CBA_fnc_players;
private _localCuratorModule = curatorCamera;
// It takes twice as long to access all these global variables as it does
// to make a private copy and use that
private _colorSelectArray = [[1, 1, 1, GVAR(fpsWarningColor)#3], GVAR(fpsWarningColor)];
private _skipAbove = GVAR(skipFPSAboveThreshold);
private _fpsThreshold = GVAR(fpsThreshold);
private _maxDisplayDistance = GVAR(playerFPSDisplayDistance);
{
    private _fps = _x getVariable [QGVAR(playerFPS), -1];
    if (_fps < -1 ||
        (_skipAbove && _fps > _fpsThreshold ) ||
        {_x distance _localCuratorModule > _maxDisplayDistance}) then {
        continue;
    };
    private _color = _colorSelectArray select (_fps <= _fpsThreshold);
    _fps = (_fps toFixed 1) + " FPS";
    //  drawIcon3D ["\A3\ui_f\data\map\markers\handdrawn\dot_CA.paa", [0,0,0.8,0.8], ASLToAGL getPosASLVisual _x, 1, 1, 0];
    drawIcon3D [
        "",
        _color,
        [0, 0, 3] vectorAdd ASLToAGL getPosASLVisual _x,
        0,
        0,
        0,
        _fps,
        false,
        0.04
    ];
} forEach _players;