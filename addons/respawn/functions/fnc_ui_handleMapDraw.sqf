/*
 * Author: AACO
 * Function used to handle map draw
 * Should only be called by UI events
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [] call potato_respawn_fnc_ui_handleMapDraw;
 *
 * Public: No
 */

#include "script_component.hpp"
#define MAP_MIN_RP_DISTANCE 75.0
#define ICON_REVIVE "a3\Ui_f\data\GUI\Rsc\RscDisplayEGSpectator\ReviveIcon_ca.paa"

TRACE_1("Params",_this);

BEGIN_COUNTER(drawMap);

// Draw unit icons
private _handledVehicles = [];
{
    private _vehicle = vehicle _x;
    if (!(_vehicle in _handledVehicles) && { alive _vehicle } && { simulationEnabled _vehicle } && { !isObjectHidden _vehicle }) then {
        _handledVehicles pushBack _vehicle;

        private _vehicleTexture = [_vehicle] call EFUNC(spectate,getVehicleIcon);

        private _sideColor = _vehicle getVariable QEGVAR(spectate,sideColor);
        if (isNil "_sideColor") then {
            _sideColor = [side group _vehicle] call BIS_fnc_sideColor;
            _vehicle setVariable [QEGVAR(spectate,sideColor), _sideColor];
        };

        if (_vehicle getVariable ["ACE_isUnconscious", false]) then {
            _vehicleTexture = ICON_REVIVE;
            _sideColor = [0.5, 0, 0, 1];
        };

        if (time <= _vehicle getVariable [QEGVAR(spectate,highlightTime), 0]) then {
            _sideColor = [1, 1, 1, 1];
        };

        ADMIN_MAP drawIcon [_vehicleTexture, _sideColor, getPosASLVisual _vehicle, 24.0, 24.0, getDirVisual _vehicle, "", 1, 0.04, "TahomaB", "right"];
    };
    nil
} count allUnits; // count used here for speed, ensure nil is above this line

// Track nearest RP
private _loc = ADMIN_MAP ctrlMapScreenToWorld getMousePosition;
private _nearestRP = objNull;
private _minDist = 999999;

// draw RPs
{
    private _dist = _x distance2D _loc;

    if (_dist < _minDist && { _dist < MAP_MIN_RP_DISTANCE }) then {
        _minDist = _dist;
        _nearestRP = _x;
    };

    private _color = [0.7, 0.26, 0.96, 1]; // royal purple
    private _text = "";

    if (GVAR(mapHighlighted) == _x) then {
        _color = [0.8, 0.8, 0.5, 1];
        _text = _x getVariable [QGVAR(rpName), "Respawn Point"];
    };

    ADMIN_MAP drawIcon [QPATHTOF(data\respawn_point), _color, getPosASLVisual _x, 32.0, 32.0, getDirVisual _x, _text, 1, 0.06, "TahomaB", "right"];

    nil
} count (entities QGVAR(placeRespawnPoint)); // count used here for speed, ensure nil is above this line

GVAR(mapHighlighted) = _nearestRP;

END_COUNTER(drawMap);
