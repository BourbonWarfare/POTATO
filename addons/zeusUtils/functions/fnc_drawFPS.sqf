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
//IGNORE_PRIVATE_WARNING["_thisEvent", "_thisEventHandler","_localCuratorModule"];
TRACE_1("diag FPS Handle:",diag_frameNo);
if !(GVAR(missionFPSEnable)) exitWith {
    [ZEUSUTILS_DEH_FPS] call FUNC(removeDraw3DEH);
};

// It takes twice as long to access all these global variables as it does
// to make a private copy and use that
private _colorSelectArray = [[1, 1, 1, GVAR(fpsWarningColor)#3], GVAR(fpsWarningColor)];
private _skipAbove = GVAR(skipFPSAboveThreshold);
private _fpsThreshold = GVAR(fpsThreshold);
private _maxDisplayDistance = GVAR(playerFPSDisplayDistance);
{
    _y params ["_unit", "_fps"];
    private _distance = _unit distance _localCuratorModule;
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
        ASLToAGL getPosASLVisual _unit,
        1,
        2,
        0,
        _fps,
        2,
        0.03
    ];
} forEach GVAR(playerFPSCache);