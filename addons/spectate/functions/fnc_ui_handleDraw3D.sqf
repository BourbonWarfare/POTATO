/*
 * Author: AACO
 * Function used to draw the 3D icons
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
#define HEIGHT_OFFSET 1.5
#define ICON_BACKGROUND_UNIT "a3\Ui_f\data\GUI\Rsc\RscDisplayEGSpectator\UnitName_ca.paa"

TRACE_1("Params",_this);

BEGIN_COUNTER(draw3D);

BEGIN_COUNTER(updateCursor);
private _cursorObject = objNull;

private _intersections = [getMousePosition select 0, getMousePosition select 1, GVAR(camTarget), vehicle GVAR(camTarget)] call BIS_fnc_getIntersectionsUnderCursor;

if (count _intersections > 0) then {
    _cursorObject = (_intersections select 0) select 3;
};

if !(_cursorObject isKindOf "Man") then {
    if (count crew _cursorObject < 1) then {
        _cursorObject = objNull;
    };
};

GVAR(cursorObject) = _cursorObject;
END_COUNTER(updateCursor);

if !(GVAR(mapOpen) || GVAR(fullMapOpen)) then {
    switch (GVAR(tagsVisible)) do {
        case TAGS_VISIBLE_MODE_NAMES: {
            BEGIN_COUNTER(drawTags);
            // Groups and Units
            {
                _x params ["_unit", "_type", "_icon"];
                private _position = _unit modelToWorldVisual (_unit selectionPosition "Head");
                _position set [2, (_position select 2) + HEIGHT_OFFSET];

                if (_type == 2 && { _unit distance GVAR(cam) < DISTANCE_NAMES } && {_unit in GVAR(camTarget) || _unit in GVAR(cursorObject)}) then {
                    drawIcon3D [
                        ICON_BACKGROUND_UNIT,
                        [0, 0, 0, [0.4, 0.8] select (_unit in GVAR(camTarget))],
                        _position,
                        5.0,
                        4,
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
        case TAGS_VISIBLE_MODE_MARKS: {
            BEGIN_COUNTER(drawTags);
            // Markers
            private _recalc = diag_tickTime > EGVAR(markers,nextUpdate);
            if (_recalc) then {
                EGVAR(markers,nextUpdate) = diag_tickTime + EGVAR(markers,groupAndUnitUpdateDelay);
            };
            private _cameraPosASL = getPosASL GVAR(cam);
            private _markerScale = EGVAR(zeusUtils,markerDisplayScale) / 12; // Marker of size 24 => 2
            {
                _y params ["_drawObject", "_text", "_icon", "_color", "_size", "_posATL"];
                private _baseDrawPosASL = if (isNull _drawObject) then {
                    ATLToASL _posATL
                } else {
                    getPosASLVisual _drawObject
                };
                if (!isNull _drawObject && _recalc) then {
                    _y set [5, ASLToATL _baseDrawPosASL];
                };
                private _distance = _baseDrawPosASL distance _cameraPosASL;
                if (_maxDisplayDistance < 3000) then {continue};

                private _sizeModifier = _markerScale * _size * exp (-_distance / 300);
                private _colorAlpha = +_color;
                _colorAlpha set [3, 0.55];
                drawIcon3D [
                    _icon,
                    _colorAlpha,
                    ASLToAGL _baseDrawPosASL vectorAdd [0, 0, 15],
                    _sizeModifier,
                    _sizeModifier,
                    0,
                    _text,
                    2,
                    0.05 * _sizeModifier,
                    "RobotoCondensedBold",
                    "right",
                    false,
                    0.002 * _sizeModifier,
                    -0.0265 * _sizeModifier
                ];
            } forEach EGVAR(markers,markerHash);
            END_COUNTER(drawTags);
        };
        default {};
    };

    // Draw projectiles and grenades paths
    if (GVAR(drawProjectiles)) then {
        BEGIN_COUNTER(drawTracers);

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
                        if (_this < 500) exitWith { [0,1,0,1] };
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
                    if (_oldLoc isNotEqualTo []) then {
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
            TRACE_1("grenade",_x);
            _x params ["_projectile", "_icon", "_color"];
            if !(isNull _projectile) then {
                // Draw grenade
                drawIcon3D [_icon, _color, (getPosVisual _projectile) vectorAdd [0,0,0.25], 0.4, 0.4, 0, "", 0, 0.05, "TahomaB"];

                // Store grenade for next frame
                _grenadesNew pushBack _x;
            };

            nil
        }  count GVAR(grenades); // count used here for speed, ensure nil above this line
        GVAR(grenades) = _grenadesNew;
        END_COUNTER(drawTracers);
    };
};

END_COUNTER(draw3D);
