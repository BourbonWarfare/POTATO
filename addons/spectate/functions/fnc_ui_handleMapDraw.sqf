/*
 * Author: AACO
 * Function used to handle map draw
 * Should only be called from events
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [] call potato_spectate_fnc_ui_handleMapDraw;
 *
 * Public: No
 */

#include "script_component.hpp"
#define MAP_MIN_ENTITY_DISTANCE 30.0
#define ICON_CAMERA "a3\Ui_f\data\GUI\Rsc\RscDisplayEGSpectator\cameraTexture_ca.paa"

TRACE_1("Params",_this);

BEGIN_COUNTER(drawMap);

// Track nearest unit
private _loc = MAP_DISPLAY ctrlMapScreenToWorld getMousePosition;
private _nearestEntity = objNull;
private _minDist = 999999;

// Draw unit icons
private _handledVehicles = [];
{
    private _dist = _x distance2D _loc;

    if (_dist < _minDist && { alive _x } && { _dist < MAP_MIN_ENTITY_DISTANCE } && { simulationEnabled _x } && { !(isObjectHidden _x) }) then {
        _minDist = _dist;
        _nearestEntity = _x;
    };

    private _vehicle = vehicle _x;
    if (!(_vehicle in _handledVehicles) && { alive _vehicle } && { simulationEnabled _vehicle } && { !isObjectHidden _vehicle }) then {
        _handledVehicles pushBack _vehicle;

        private _vehicleTexture = [_vehicle] call FUNC(getVehicleIcon);

        private _sideColor = _vehicle getVariable QGVAR(sideColor);
        if (isNil "_sideColor") then {
            _sideColor = [side group _vehicle] call BIS_fnc_sideColor;
            _vehicle setVariable [QGVAR(sideColor), _sideColor];
        };

        private _text = "";

        if (GVAR(mapHighlighted) == _vehicle || {GVAR(mapHighlighted) in _vehicle}) then {
            private _name = [GVAR(mapHighlighted), nil, NAME_MAX_CHARACTERS] call BIS_fnc_getName;
            _sideColor = [0.8, 0.8, 0.5, 1];
            _text = if (isPlayer GVAR(mapHighlighted)) then { _name } else { format ["%1: %2", "AI", _name]; };
        };

        if (_vehicle getVariable ["ACE_isUnconscious", false]) then {
            _vehicleTexture = ICON_REVIVE;
            _sideColor = [0.5, 0, 0, 1];
        };

        if (time <= _vehicle getVariable [QGVAR(highlightTime), 0]) then {
            _sideColor = [1, 1, 1, 1];
        };

        MAP_DISPLAY drawIcon [_vehicleTexture, _sideColor, getPosASLVisual _vehicle, 24.0, 24.0, getDirVisual _vehicle, _text, 1, 0.04, "TahomaB", "right"];
    };
    nil
} count allUnits; // count used here for speed, ensure nil is above this line

// set highlighted unit
private _text = if (isNull _nearestEntity) then {
    ""
} else {
    format ["%1 [%2 m]", [_nearestEntity] call FUNC(getName), round (_nearestEntity distance GVAR(cam))]
};

GVAR(mapHighlighted) = _nearestEntity;
MAP_FOOTER ctrlSetText _text;

// Draw camera icon
private _cameraPos = getPosASLVisual GVAR(cam);
private _cameraDir = getDirVisual GVAR(cam);
MAP_DISPLAY drawIcon [ICON_CAMERA, [0.5, 1.0, 0.5, 1.0], _cameraPos, 32.0, 48.0, _cameraDir, "", 1, 0.05, "TahomaB", "right"];
MAP_DISPLAY drawArrow [_cameraPos, (_cameraPos getPos [300, _cameraDir]), [0.5, 1.0, 0.5, 1.0]];

END_COUNTER(drawMap);
