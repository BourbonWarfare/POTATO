/*
 * Author: AACO
 * Function used to draw markers
 *
 * Arguments:
 * 0: Map control <CONTROL>
 *
 * Examples:
 * [(findDisplay 12) displayCtrl 52] call potato_markers_fnc_drawMarkers; // draw markers on map
 * [(findDisplay 133) displayCtrl 101] call potato_markers_fnc_drawMarkers; // draw markers on GPS
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

BEGIN_COUNTER(drawMarkers);

params ["_mapControl"];

if ((player != player) || {!alive player}) exitWith {};

//Map's height / Screen height:
private _mapSize = ((ctrlPosition _mapControl) select 3) / (getResolution select 4);
private _sizeFactor = (_mapSize + 1) / 2;

if (GVAR(groupAndUnitEnabled)) then {

    private _recalc = diag_tickTime > GVAR(nextUpdate);

    {
        TRACE_1("icon data", _x);
        _x params ["_text", "_texture", "_color", "_size", "_position"];

        if (_recalc) then {
            private _drawObject = (GVAR(drawHash) select 0) select _forEachIndex;
            if !(isNull _drawObject) then {
                if (_drawObject isEqualType grpNull) then {
                    if (isNull (leader _drawObject)) exitWith {};
                    _position = position (leader _drawObject);
                } else {
                    _position = position _drawObject;
                };
                _x set [4, _position];
            };
        };

        _mapControl drawIcon [_texture,
                             _color,
                             _position,
                             _size * _sizeFactor,
                             _size * _sizeFactor,
                             0,
                             "",
                             0,
                             (([0.0375,0] select (((ctrlMapScale _mapControl) * _mapSize) > 0.1)) * _sizeFactor),
                             'PuristaSemiBold',
                             "right"];
         _mapControl drawIcon [ INVISIBLE_TEXTURE ,
                              [0,0,0,1],
                              _position,
                              _size * _sizeFactor,
                              _size * _sizeFactor,
                              0,
                              _text,
                              0,
                              (([0.0375,0] select (((ctrlMapScale _mapControl) * _mapSize) > 0.1)) * _sizeFactor),
                              'PuristaSemiBold',
                              "right"];

    } forEach (GVAR(drawHash) select 1);

    if (_recalc) then { GVAR(nextUpdate) = diag_tickTime + GVAR(groupAndUnitUpdateDelay) };
};

if (GVAR(intraFireteamEnabled) && {(ctrlMapScale _mapControl) < 0.5}) then {
    {
        if !(isNull _x) then {
            private _color = switch (assignedTeam _x) do {
                case "RED": { RED_ARRAY };
                case "YELLOW": { YELLOW_ARRAY };
                case "GREEN": { GREEN_ARRAY };
                case "BLUE": { BLUE_ARRAY };
                default { WHITE_ARRAY };
            };
            if (isNil "_color") exitWith {};
            private _textsize = if((ctrlMapScale _mapControl) < 0.005) then {0.02} else {0};
            private _unitPosition = position _x;
            private _unitName = if (alive _x) then { name _x } else { "" };
            private _size = -(3200/13)*(ctrlMapScale _mapControl) + (386/13);
            if (_size < 10) then {_size = 10};
            if (_size > 26) then {_size = 26};
            _mapControl drawIcon [(_x call STHud_Icon),[0,0,0,1],_unitPosition,_size,_size,direction _x,_unitName,1,_textSize,'PuristaLight',"left"];
            _mapControl drawIcon [(_x call STHud_Icon),_color,_unitPosition,_size - 4,_size - 4,direction _x,"",1,_textSize,'PuristaLight',"left"];
        };

        nil
    } count (units (group player));
};

END_COUNTER(drawMarkers);
