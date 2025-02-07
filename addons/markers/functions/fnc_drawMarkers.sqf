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

#include "..\script_component.hpp"
//TRACE_1("Params",_this);

BEGIN_COUNTER(drawMarkers);

params ["_mapControl"];

if ((player != player) || {!alive player} || {side player == sideLogic}) exitWith {};

//Map's height / Screen height:
private _mapSize = ((ctrlPosition _mapControl) select 3) / (getResolution select 4);
private _sizeFactor = (_mapSize + 1) / 2;

if (GVAR(groupAndUnitEnabled)) then {
    private _recalc = diag_tickTime > GVAR(nextUpdate);
    if (_recalc) then {
        GVAR(nextUpdate) = diag_tickTime + GVAR(groupAndUnitUpdateDelay);
    };

    if (diag_tickTime > GVAR(nextUpdateDrawHash) && _recalc) then {
        TRACE_1("Updating side draw hash",diag_tickTime);
        GVAR(nextUpdateDrawHash) = diag_tickTime + MARKER_DRAW_HASH_REFRESH_TIME;
        private _newDrawHash = createHashMap;
        private _sideArray = [] call FUNC(getSideArray);
        {
            private _side = _y#6;
            if (_side in _sideArray) then {
                _newDrawHash set [_x, _y];
            };
        } forEach GVAR(markerHash);
        GVAR(drawHash) = _newDrawHash;
    };

    {
#ifdef DEBUG_MODE_DRAW_EH
        TRACE_2("icon data",_x,_y);
#endif
        _y params ["_drawObject", "_text", "_icon", "_color", "_size", "_posATL"];

        if (_recalc) then {
            if !(isNull _drawObject) then {
                if (_drawObject isEqualType grpNull) then {
                    if (isNull (leader _drawObject)) exitWith {};
                    _posATL = getPosATL (leader _drawObject);
                } else {
                    _posATL = getPosATL _drawObject;
                };
                _y set [5, _posATL];
                TRACE_2("Updating position",_drawObject,_posATL);
            } else {
                TRACE_1("Updating position, skip",_drawObject);
            };
        };

        _mapControl drawIcon [
            _icon,
            _color,
            _posATL,
            _size * _sizeFactor,
            _size * _sizeFactor,
            0,
            _text,
            1,
            (([0.05,0] select (((ctrlMapScale _mapControl) * _mapSize) > 0.1)) * _sizeFactor),
            'TahomaB',
            "right"
        ];

    } forEach GVAR(drawHash);
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
