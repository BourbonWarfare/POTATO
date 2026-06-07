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
// acos ~50 degrees
#define OCCLUSION_COS_ANGLE 0.7
// 1 - 0.6 * frame time (0.1)
#define OCCLUSION_FADE_ALPHA 0.94
// 1 + 3 * frame time (0.1)
#define OCCLUSION_DEFADE_ALPHA 1.3
#define MIN_VALUE_CONSIDERED 5e-2
//TRACE_1("Params",_this);

BEGIN_COUNTER(drawMarkers);

params ["_mapControl"];

if ((player != player) || {!alive player} || {side player == sideLogic}) exitWith {};

// Add alpha EH if needed
if (GVAR(intraFireteam_occlude) && {isNil QGVAR(intraAlphaPFEH)}) then {
    GVAR(intraAlphaPFEH) = [{
        private _time = time;
        private _posPlayerASL = eyePos player;
        private _dirVecPlayer = eyeDirection player;
        {
            if (_x == player) then {continue};
            private _unitPosition = getPosASLVisual _x;
            private _distance = _unitPosition distance2D _posPlayerASL;
            private _seen = _x getVariable [QGVAR(intraSeen), false];
            if (_x getVariable [QGVAR(nextAlpha), 0] < _time) then {
                _seen = _distance < 200 && {_distance < 100 ||
                {OCCLUSION_COS_ANGLE < _dirVecPlayer vectorDotProduct (_posPlayerASL vectorFromTo _unitPosition)}} &&
                {[] isEqualTo lineIntersectsObjs [_posPlayerASL, _x modelToWorldVisualWorld (_x selectionPosition  "pelvis"), _x, player, false, 20]};
                _x setVariable [QGVAR(nextAlpha), _time + 0.4 + random 0.4];
                _x setVariable [QGVAR(intraSeen), _seen];
            };
            private _alpha = _x getVariable [QGVAR(intraAlpha), 1];
            _alpha = if (!_seen) then {
                if (_alpha < MIN_VALUE_CONSIDERED) then {
                    0
                } else {
                    0 max (_alpha * OCCLUSION_FADE_ALPHA)
                };
            } else {
                if (_alpha < MIN_VALUE_CONSIDERED) then {
                    MIN_VALUE_CONSIDERED
                } else {;
                    1 min (_alpha * OCCLUSION_DEFADE_ALPHA)
                };
            };
            _x setVariable [QGVAR(intraAlpha), _alpha];
        } forEach units group player;
    }, 0.1] call CBA_fnc_addPerFrameHandler;
};

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
            if ((_y#6) in _sideArray) then {
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
    private _textScale = [0, 0.02 * _sizeFactor] select ((ctrlMapScale _mapControl) * _mapSize < 0.005);
    private _size = UNIT_MARKER_SIZE * _sizeFactor;
    {
        if (isNull _x) then {continue};
        private _alpha = _x getVariable [QGVAR(intraAlpha), 1];

        private _color = switch (assignedTeam _x) do {
            case "RED": { RED_ARRAY_A(_alpha) };
            case "YELLOW": { YELLOW_ARRAY_A(_alpha) };
            case "GREEN": { GREEN_ARRAY_A(_alpha) };
            case "BLUE": { BLUE_ARRAY_A(_alpha) };
            default { WHITE_ARRAY_A(_alpha) };
        };
        if (isNil "_color") then {continue};

        _mapControl drawIcon [
            UNIT_MARKER_ICON,
            _color,
             getPosASLVisual _x,
            _size,
            _size,
            direction _x,
            ["", name _x] select alive _x,
            1,
            _textScale ,
            'TahomaB',
            "left"
        ];
    } forEach units group player;
};

END_COUNTER(drawMarkers);
