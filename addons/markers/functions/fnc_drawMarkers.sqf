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
//TRACE_1("Params",_this);

BEGIN_COUNTER(drawMarkers);

params ["_mapControl"];

if ((player != player) || {!alive player} || {side player == sideLogic}) exitWith {};

/*if (GVAR(autoclaimGroupMarker) &&
    player == leader player &&
    {groupID group player in GVAR(drawHash)}) then {
    private _hashKey = groupID group player;
    private _markerArray = GVAR(drawHash) get _hashKey;
    if (_markerArray#0 != player) then {
        [QGVAR(claimMarker), [_hashKey, player]] call CBA_fnc_globalEvent;
    };
};*/

//Map's height / Screen height:
private _mapSize = ((ctrlPosition _mapControl) select 3) / (getResolution select 4);
private _sizeFactor = (_mapSize + 1) / 2;

if (GVAR(groupAndUnitEnabled)) then {
    private _notAutoClaimMarker = !GVAR(autoclaimGroupMarker);
    private _recalc = diag_tickTime > GVAR(nextUpdate);

    {
        //TRACE_2("icon data",_X,_y);
        _y params ["_drawObject", "_text", "_texture", "_color", "_size", "_position"];

        if (_recalc) then {
            if !(isNull _drawObject) then {
                if (_drawObject isEqualType grpNull) then {
                    if (isNull (leader _drawObject)) exitWith {};
                    if (_notAutoClaimMarker) then {_y set [0, leader _drawObject];};
                    _position = position (leader _drawObject);
                } else {
                    _position = position _drawObject;
                };
                _y set [5, _position];
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

    } forEach GVAR(drawHash);

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

END_COUNTER(drawMarkers);
