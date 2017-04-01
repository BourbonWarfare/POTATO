/*
 * Author: AACO
 * Function used update the things to 3D draw
 * Should only be called from events
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [] call potato_spectate_fnc_ui_updateThingsToDraw;
 *
 * Public: No
 */

#include "script_component.hpp"

#define ICON_UNIT "a3\Ui_f\data\GUI\Rsc\RscDisplayEGSpectator\UnitIcon_ca.paa"

TRACE_1("Params",_this);

private _thingsToDraw = [];

{
    private _distanceToCamera = GVAR(cam) distance _x;

    private _group = group _x;
    private _groupSide = side _group;
    private _groupName = groupId _group;
    private _groupLeader = leader _group;
    private _groupColor = [_groupSide] call BIS_fnc_sideColor;

    if (_distanceToCamera <= 3000.0 && { vehicle _x == _x || { _x == driver vehicle _x } }) then {
        // Calculate distance fade
        (_distanceToCamera call {
            if (_this <= 500) exitWith {
                [1.0, 4.0, -2.5, 0.04]
            };
            if (_this <= 1000) exitWith {
                [0.75, 3.5, -2.2, 0.035]
            };
            if (_this <= 1500) exitWith {
                [0.5, 3.0, -1.9, 0.03]
            };
            if (_this <= 2000) exitWith {
                [0.3, 2.5, -1.6, 0.025]
            };
            if (_this <= 2500) exitWith {
                [0.2, 2.0, -1.3, 0.02]
            };
            [0.15, 1.5, -1.0, 0.015]
        }) params ["_fadeByDistance", "_sizeByDistance", "_heightByDistance", "_fontSizeByDistance"];

        // Apply color fade
        _groupColor set [3, _fadeByDistance];

        // Show unit name only if camera is near enough
        if (_distanceToCamera < DISTANCE_NAMES) then {
            // Unit name
            _thingsToDraw pushBack [_x, 2, [
                "",
                [1,1,1,1],
                ZERO_POS,
                0.0,
                _heightByDistance,
                0.0,
                [_x] call FUNC(getName),
                2,
                _fontSizeByDistance,
                "PuristaMedium",
                "center"
            ]];
        } else {
            if (_x == _groupLeader) then {
                // Group name
                _thingsToDraw pushBack [_x, 0, [
                    "",
                    [1,1,1,_fadeByDistance],
                    ZERO_POS,
                    0.0,
                    _heightByDistance,
                    0.0,
                    _groupName,
                    2,
                    _fontSizeByDistance,
                    "PuristaMedium",
                    "center"
                ]];
            };
        };

        if (_x == _groupLeader) then {
            // Group icon
            _thingsToDraw pushBack [_x, 0, [
                [_group] call FUNC(getGroupIcon),
                _groupColor,
                ZERO_POS,
                _sizeByDistance,
                _sizeByDistance,
                0.0,
                "",
                0,
                0.035,
                "PuristaMedium",
                "center"
            ]];
        };

        // Draw unit icon
        _thingsToDraw pushBack [_x, 1, [
            if (_x getVariable ["ACE_isUnconscious", false]) then { ICON_REVIVE } else { ICON_UNIT },
            _groupColor,
            ZERO_POS,
            _sizeByDistance,
            _sizeByDistance,
            0.0,
            "",
            0.0,
            0.035,
            "PuristaMedium",
            "center"
        ]];
    };

    nil
} count allUnits; // count used here for speed, ensure nil above this line

GVAR(thingsToDraw) = _thingsToDraw;
