#include "script_component.hpp"

/*
 * Author: Bailey
 * Draws debug information for every cell
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call potato_bodyCleanup_fnc_debugPFH;
 *
 * Public: No
 */
params ["_map"];
{
    _y params ["_sideLength", "_deadUnits", "_lastTimeObserved", "_isHidden", "_position"];
    _map drawIcon [
		"#(rgb,1,1,1)color(1,1,1,1)",
		[0,0,1,1],
		_position,
		0,
		0,
		0,
		format ["%1", 0 max floor (TIME_BEFORE_CLEANUP - (CBA_missionTime - _lastTimeObserved))],
        false,
        -1,
        "TahomaB",
        "center"
	];
    _map drawRectangle [
        _position,
        _sideLength / 2,
        _sideLength / 2,
        0,
        [1, 0, 0, 1],
        ""
    ];
} forEach GVAR(cells);

private _views = call FUNC(getPlayerViewCones);
{
    _x params ["_origin", "_viewDir", "_polar", "_fov"];
    _polar params ["", "_azimuth"];

    private _length = MAX_CLEANUP_DISTANCE / cos _fov;

    private _left = (_azimuth - _fov);
    private _right = (_azimuth + _fov);

    private _h2 = [sin _left, cos _left, 0] vectorMultiply _length;
    private _h3 = [sin _right, cos _right, 0] vectorMultiply _length;

    private _p1 = _origin;
    private _p2 = _origin vectorAdd _h2;
    private _p3 = _origin vectorAdd _h3;

    _map drawIcon [
		"#(rgb,1,1,1)color(1,1,1,1)",
		[0,1,1,1],
		_p1,
		15,
		15,
		0
	];

    _map drawTriangle [
        [_p1, _p2, _p3],
        [0, 1, 0, 1],
        ""
    ];
} forEach _views;
