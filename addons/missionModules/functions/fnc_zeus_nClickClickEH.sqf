#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function is run by a module on init. It takes the configured
 * side and configs to create resupply entries for them in the
 * players diary. This function can be called on the module later as the
 * module should not be automatically deleted.
 *
 * Arguments:
 * 0: The module being initialized
 * 2: Whether the module is active
 *
 * Examples:
 * Should be called by module init
 *
 * Public: No
 */
//IGNORE_PRIVATE_WARNING["_thisEvent", "_thisEventHandler"];
TRACE_1("click EH",_this);
params ["_disp", "_button", "_xPos", "_yPos", "_shift"];
if (isNull curatorCamera) exitWith {
    _disp displayRemoveEventHandler [_thisEvent, _thisEventHandler];
    removeMissionEventHandler ["Draw3D", GVAR(nClickDraw3D)];
    GVAR(nClickDraw3D) = -1;
};
if (_button != 0) exitWith {};
private _intersect = lineIntersectsSurfaces [AGLToASL positionCameraToWorld [0,0,0], AGLToASL screenToWorld [_xPos, _yPos], ace_player];
if (_intersect isEqualTo [] || _shift) then {
    _intersect = screenToWorld [_xPos, _yPos];
} else {
    _intersect = ASLToAGL (_intersect#0#0);
};
GVAR(nClickPos) pushBack _intersect;

if (count GVAR(nClick_posText) <= count GVAR(nClickPos)) then {
    _disp displayRemoveEventHandler [_thisEvent, _thisEventHandler];
    removeMissionEventHandler ["Draw3D", GVAR(nClickDraw3D)];
    GVAR(nClickDraw3D) = -1;
    [GVAR(nClickPos)] call compile GVAR(nClickFunc);
};
