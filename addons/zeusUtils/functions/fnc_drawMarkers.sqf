#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function is called each frame from a Draw3D EH.
 * It draws all markers in the relevant marker arrays.
 * This function MUST be called through the Draw3D
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
//IGNORE_PRIVATE_WARNING["_localCuratorModule"];
TRACE_1("diag marker Handle:",diag_frameNo);

// It takes twice as long to access all these global variables as it does
// to make a private copy and use that
private _maxDisplayDistance = GVAR(markerDisplayDistance);
private _markerScale = GVAR(markerDisplayScale) / 12; // Marker of size 24 => 2
private _showMarkerText = GVAR(showMarkerText);
{
    _y params ["_drawObject", "_text", "_icon", "_color", "_size", "_posATL"];
    if (isNull _drawObject) then {continue};

    private _baseDrawPos = (getPosASLVisual _drawObject) vectorAdd [0, 0, 7.5];
    private _distance = _baseDrawPos distance _localCuratorModule;
    if (_maxDisplayDistance < _distance) then {continue};

    private _sizeModifier = _markerScale * _size * exp (-_distance / 300);
    private _colorAlpha = +_color;
    _colorAlpha set [3, 0.55];
    if (_showMarkerText) then {
        drawIcon3D [
            _icon,
            _colorAlpha,
            _baseDrawPos,
            _sizeModifier,
            _sizeModifier,
            0,
            _text,
            2,
            0.05 * _sizeModifier,
            "RobotoCondensedBold",
            "right",
            false,
            0.002 * _sizeModifier,
            -0.0265 * _sizeModifier
        ];
    } else {
        drawIcon3D [
            _icon,
            _colorAlpha,
            _baseDrawPos,
            _sizeModifier,
            _sizeModifier,
            0,
            "",
            2,
            0.04 * _sizeModifier
        ];
    };
} forEach EGVAR(markers,markerHash);
