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

private _localCuratorModule = curatorCamera;
// It takes twice as long to access all these global variables as it does
// to make a private copy and use that
private _colorSelectArray = [[1, 1, 1, GVAR(fpsWarningColor)#3], GVAR(fpsWarningColor)];
private _skipAbove = GVAR(skipFPSAboveThreshold);
private _fpsThreshold = GVAR(fpsThreshold);
private _maxDisplayDistance = GVAR(playerFPSDisplayDistance);
{
    private _fps = _x getVariable [QGVAR(playerFPS), -1];
    private _distance = _x distance _localCuratorModule;
    if (_fps < -1 ||
        (_skipAbove && _fps > _fpsThreshold ) ||
        {_distance > _maxDisplayDistance}) then {
        continue;
    };
    private _color = _colorSelectArray select (_fps <= _fpsThreshold);
    _fps = (_fps toFixed 1) + " FPS";
    drawIcon3D [
        "",
        _color,
        ASLToAGL getPosASLVisual _x,
        1,
        2,
        0,
        _fps,
        2,
        0.03
    ];
} forEach allUnits; //(call CBA_fnc_players);