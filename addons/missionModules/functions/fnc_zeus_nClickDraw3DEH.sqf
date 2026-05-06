#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function is run by a module on init. It takes the configured
 * side and configs to create resupply entries for them in the
 * players diary. This function can be called on the module later as the
 * module should not be automatically deleted.
 *
 * Arguments:
 * None
 *
 * Examples:
 * Should be called by EH callback
 *
 * Public: No
 */
private _lastPos = [0,0,0];
private _camPos = positionCameraToWorld [0,0,0];
private _intersect = lineIntersectsSurfaces [AGLToASL _camPos, AGLToASL screenToWorld getMousePosition, ace_player];
if (_intersect isEqualTo []) then {
    _intersect = screenToWorld getMousePosition;
} else {
    _intersect = ASLToAGL (_intersect#0#0);
};
{
    drawIcon3D [
        "\z\diwako_dui\addons\indicators\ui\indicators\diamond.paa",
        [0.8, 0.2, 0, 1],
        _x,
        1,
        1,
        0,
        GVAR(nClick_posText)#_forEachIndex,
        2,
        0.05 * 1,
        "RobotoCondensed",
        "right",
        FALSE,
        0.002 * 1,
        -0.0265 * 1
    ];
    if (_lastPos isNotEqualTo [0,0,0]) then {
        drawLine3D [_lastPos, _x, [0.8, 0, 0, 1], 5];
    };
    _lastPos = _x;
} forEach (GVAR(nClickPos) + [_intersect]);
