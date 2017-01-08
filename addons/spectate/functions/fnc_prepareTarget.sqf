/*
 * Author: AACO
 * Function used to prepare the camera to the target
 *
 * Arguments:
 * 0: unit to prepare <OBJECT>
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [player] call potato_spectate_fnc_prepareTarget;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params [["_target", objNull, [objNull]]];

if !(isNull _target) then {
    private _zoom = if (GVAR(currentCamIndex) == THIRD_PERSON) then { GVAR(thirdPersonCamZoom) } else { 0.0 };
    if (GVAR(thirdPersonCamZoomTemp) != _zoom) then {
        GVAR(thirdPersonCamZoomTemp) = (GVAR(thirdPersonCamZoomTemp) * (1.0 - GVAR(camDeltaTime) * 10.0)) + (_zoom * GVAR(camDeltaTime) * 10.0);
    };

    private _vehicle = vehicle _target;
    private _isMan = _vehicle isKindOf "Man";
    private _boundingBox = [_vehicle] call FUNC(getBoundingBox);
    private _distance = (_boundingBox select 1) + GVAR(thirdPersonCamZoomTemp);

    if (_isMan) then {
        [
            (stance _vehicle) call {
                if (_this == "STAND") exitWith { 1.4 };
                if (_this == "CROUCH") exitWith { 0.8 };
                0.4
            },
            AGLToASL (_vehicle modelToWorldVisual (_vehicle selectionPosition "Spine3"))
        ]

    } else {
        private _height = (_boundingBox select 2) / 3.0;
        [
            _height,
            AGLToASL (_vehicle modelToWorldVisual [0, 0, _height])
        ]
    } params ["_height", "_center"];

    // Set dumy location and rotation
    GVAR(dummy) setPosASL _center;
    [GVAR(dummy), [GVAR(thirdPersonCamDirTemp) + GVAR(thirdPersonCamYaw), GVAR(thirdPersonCamPitch), 0.0]] call BIS_fnc_setObjectRotation;

    private _pos = AGLToASL (GVAR(dummy) modelToWorldVisual [0, -_distance, 0]);

    // Apply location and rotation to camera
    GVAR(cam) setPosASL _pos;
    GVAR(cam) setVectorDirAndUp [vectorDirVisual GVAR(dummy), vectorUpVisual GVAR(dummy)];
};
