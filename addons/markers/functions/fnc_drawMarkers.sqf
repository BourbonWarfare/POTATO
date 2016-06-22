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

params ["_mapControl"];

if ((player != player) || {!alive player}) exitWith {};

//Map's height / Screen height:
private _mapSize = ((ctrlPosition _mapControl) select 3) / (getResolution select 4);
private _sizeFactor = (_mapSize + 1) / 2;

if (GVAR(groupAndUnitEnabled) && {diag_tickTime > GVAR(nextUpdate)}) then {

    private _recalc = diag_tickTime > GVAR(nextUpdate);

    {
        _x params ["_text", "_texture", "_color", "_size", "_position"];

        if (_recalc) then {
            private _drawObject = (GVAR(drawHash) select 0) select _forEachIndex;
            if !(isNull _drawObject) then {
                _position = if (_drawObject isEqualType grpNull) then {
                    position (leader _drawObject);
                } else {
                    position _drawObject;
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
                             _text,
                             1,
                             (([0.05,0] select (((ctrlMapScale _mapControl) * _mapSize) > 0.1)) * _sizeFactor),
                             'TahomaB',
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

            private _unitPosition = position _x;
            private _unitName = if (alive _x) then { name _x } else { "" };

            _mapControl drawIcon [UNIT_MARKER_ICON,
                                  _color,
                                  _unitPosition,
                                  UNIT_MARKER_SIZE * _sizeFactor,
                                  UNIT_MARKER_SIZE * _sizeFactor,
                                  direction _x,
                                  _unitName,
                                  1,
                                  (([0,0.02] select (((ctrlMapScale _mapControl) * _mapSize) < 0.005)) * _sizeFactor),
                                  'TahomaB',
                                  "left"];
        };

        nil
    } count (units (group player));
};
