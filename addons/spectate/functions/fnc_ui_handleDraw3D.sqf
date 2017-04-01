/*
 * Author: AACO
 * Function used to draw the 3D icons/do per-frame calculations
 * Should only be called from events
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [] call potato_spectate_fnc_ui_handleDraw3D;
 *
 * Public: No
 */

#include "script_component.hpp"
#define HEIGHT_OFFSET 1.0
#define GRENADE_ICON "A3\Ui_f\data\IGUI\Cfg\HoldActions\holdAction_connect_ca.paa"
#define ICON_BACKGROUND_UNIT "a3\Ui_f\data\GUI\Rsc\RscDisplayEGSpectator\UnitName_ca.paa"

TRACE_1("Params",_this);

BEGIN_COUNTER(draw3D);

BEGIN_COUNTER(updateCursor)
private _cursorObject = objNull;

private _intersections = [getMousePosition select 0, getMousePosition select 1, GVAR(camTarget), vehicle GVAR(camTarget)] call BIS_fnc_getIntersectionsUnderCursor;

if (count _intersections > 0) then {
    _cursorObject = (_intersections select 0) select 3;
};

if !(_cursorObject isKindOf "Man") then {
    if (count crew _cursorObject > 0) then {
        _cursorObject = (crew _cursorObject) select 0;
    } else {
        _cursorObject = objNull;
    };
};

GVAR(cursorObject) = _cursorObject;
END_COUNTER(updateCursor)

BEGIN_COUNTER(camTick);
// Calculate delta time
private _currentTime = diag_tickTime;
GVAR(camDeltaTime) = _currentTime - GVAR(camLastTickTime);
GVAR(camLastTickTime) = _currentTime;

// Follow camera update
if (GVAR(currentCamIndex) == THIRD_PERSON || {GVAR(currentCamIndex) == FIRST_PERSON}) then {
    private _focus = if (isNull GVAR(camTarget)) then {
        private _testFocus = allUnits select 0;
        if (isNil "_testFocus") then {
            objNull
        } else {
            _testFocus
        }
    } else {
        GVAR(camTarget)
    };

    if (!isNull _focus && {_focus != GVAR(camTarget)}) then {
        [_focus] call FUNC(setFocus);
    };

    if (!isNull _focus && {GVAR(currentCamIndex) == THIRD_PERSON}) then {
        [_focus] call FUNC(prepareTarget);
    };
};

// Focus get in / out of vehicle state
if (isNull GVAR(camTarget)) then {
    GVAR(targetInVehicle) = false;
} else {
    if (GVAR(hasTarget)) then {
        if (!GVAR(targetInVehicle) && { vehicle GVAR(camTarget) != GVAR(camTarget) }) then {
            [GVAR(camTarget)] call FUNC(setTarget);
            GVAR(targetInVehicle) = true;
        };

        if (GVAR(targetInVehicle) && { vehicle GVAR(camTarget) == GVAR(camTarget) }) then {
            [GVAR(camTarget)] call FUNC(setTarget);
            GVAR(targetInVehicle) = false;
        };
    };
};

// Camera lights
if (count GVAR(camLights) > 1) then {
    (GVAR(camLights) select 1) setPosASL (AGLToASL (screenToWorld getMousePosition));
};
END_COUNTER(camTick);

if !(GVAR(mapOpen)) then {
    if (GVAR(tagsVisible)) then {
        BEGIN_COUNTER(drawTags);
        // Groups and Units
        {
            _x params ["_unit", "_type", "_icon"];
            private _position = _unit modelToWorldVisual (_unit selectionPosition "Head");
            _position set [2, (_position select 2) + HEIGHT_OFFSET];

            if (_type == 2 && { _unit distance GVAR(cam) < DISTANCE_NAMES } && {GVAR(camTarget) == _unit || GVAR(cursorObject) == _unit}) then {
                drawIcon3D [
                    ICON_BACKGROUND_UNIT,
                    [0,0,0,if (GVAR(camTarget) == _unit) then { 0.8 } else { 0.4 }],
                    _position,
                    5.0,
                    3.5,
                    0.0,
                    "",
                    0,
                    0.035,
                    "PuristaMedium",
                    "center"
                ];
            };

            // Apply modifiers
            if (_type == 1 && { time <= _unit getVariable [QGVAR(highlightTime), 0] }) then {
                _icon set [1, [1,1,1, ((_icon select 1) select 3)]];
            };
            _icon set [2, _position];

            // Draw icon
            drawIcon3D _icon;

            nil
        } count GVAR(thingsToDraw); // count used here for speed, ensure nil above this line
        END_COUNTER(drawTags);
    };

    if (GVAR(drawProjectiles)) then {
        BEGIN_COUNTER(drawTracers);
        // Draw projectiles and grenades paths
        if (GVAR(drawProjectiles)) then {
            private _projectilesNew = [];
            private _grenadesNew = [];

            // Draw projectiles if there are any
            {
                _x params [
                    ["_projectile", objNull, [objNull]],
                    ["_segments", [], [[]]]
                ];

                if !(isNull _projectile) then {
                    private _newestIndex = _segments pushBack [
                        getPosVisual _projectile,
                        (vectorMagnitude velocity _projectile) call {
                            if (_this < 250) exitWith { [0,0,1,1] };
                            if (_this < 250) exitWith { [0,1,0,1] };
                            [1,0,0,1]
                        }
                    ];

                    if (_newestIndex > MAX_TRACKED_PROJECTILE_SEGMENTS) then {
                        _segments deleteAt 0;
                        _newestIndex = _newestIndex - 1;
                    };

                    private _oldLoc = [];
                    {
                        _x params ["_locNew", "_colorNew"];
                        if !(_oldLoc isEqualTo []) then {
                            drawLine3D [_oldLoc, _locNew, _colorNew];
                        };
                        _oldLoc = _locNew;

                        nil
                    } count _segments; // count used here for speed, ensure nil above this line

                    _projectilesNew pushBack [_projectile, _segments];
                };

                nil
            } count GVAR(projectiles); // count used here for speed, ensure nil above this line
            GVAR(projectiles) = _projectilesNew;

            {
                if !(isNull _x) then {
                    private _grenadeVelocityMagnitude = vectorMagnitude velocity _x;

                    // Draw grenade
                    drawIcon3D [GRENADE_ICON, [1,0,0,1], getPosVisual _x, 0.6, 0.6, if (_grenadeVelocityMagnitude > 0) then { time * 100 * _grenadeVelocityMagnitude } else { 0 }, "", 0, 0.05, "TahomaB"];

                    // Store grenade for next frame
                    _grenadesNew pushBack _x;
                };

                nil
            }  count GVAR(grenades); // count used here for speed, ensure nil above this line
            GVAR(grenades) = _grenadesNew;
        };
        END_COUNTER(drawTracers);
    };
};

END_COUNTER(draw3D);
