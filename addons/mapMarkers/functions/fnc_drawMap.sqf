/*
 * Hook for rendering icons on map
 *
 * Arguments:
 * 0: Map Control <CONTROL>
 *
 * Return Value:
 * None
 */
#include "script_component.hpp"

params ["_mapControl"];

private _mapSize = ((ctrlPosition _mapControl) select 3) / (getResolution select 4);
private _sizeFactor = (_mapSize + 1) / 2;
private _mapScale = ctrlMapScale _mapControl;

{
    _x params [
        ["_icon", "\A3\ui_f\data\map\markers\nato\b_unknown.paa", [""]],
        ["_color", [1, 1, 1, 1], [[]]],
        ["_size", [24, 24], [[]]],
        ["_textLeft", "", [""]],
        ["_textRight", "", [""]]
    ];
    _size params ["_width", "_height"];
    _width = _width * _sizeFactor;
    _height = _height * _sizeFactor;
    private _textSize = if ((_mapScale * _mapSize) > 0.1) then {0} else {0.05 * _sizeFactor};

    _mapControl drawIcon [_icon, _color, _position, _width, _height, 0, if (_textLeft != "") then {_textLeft} else {_textRight}, 1, _textSize, "TahomaB", if (_textLeft != "") then {"left"} else {"right"}];
    if (_textLeft != "" && _textRight != "") then {
        _mapControl drawIcon ["#(argb,8,8,3)color(0,0,0,0)", _color, _position, _width, _height, 0, _textRight, 1, _textSize, "TahomaB", "right"];
    };
} count GVAR(drawCache);
