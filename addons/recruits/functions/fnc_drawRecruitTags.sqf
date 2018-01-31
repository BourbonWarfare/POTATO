/*
 * Author: AACO
 * Function used to draw the recruit information
 * Should only be called from an event handler
 *
 * Examples:
 * [] call potato_recruits_fnc_drawRecruitTags;
 *
 * Public: No
 */

#include "script_component.hpp"

#define START_FADE_DISTANCE 50
#define END_FADE_DISTANCE 100
#define FADE_DIFF 50
#define TAG_COLOR 0.15,0.451,0.94
#define TAG_ALPHA 0.85

TRACE_1("Params",_this);

BEGIN_COUNTER(GVAR(tags));
if (GVAR(showTags)) then {
    private _playerPos = getPosVisual player;
    {
        if (side _x == playerSide) then {
            {
                if (!isNull _x && {alive _x} && {isPlayer _x} && {[_x] call FUNC(isNotMember)}) then {
                    private _unitPos = getPosVisual _x;
                    private _unitDistance = _playerPos distance _unitPos;
                    if (_unitDistance < END_FADE_DISTANCE || {_unitDistance == 0}) then {
                        drawIcon3D [
                            QPATHTOF(data\recruit.paa),
                            [
                                TAG_COLOR,
                                ((FADE_DIFF - ((_unitDistance max START_FADE_DISTANCE) - START_FADE_DISTANCE)) / FADE_DIFF) * TAG_ALPHA
                            ],
                            _x modelToWorldVisual ((_x selectionPosition "pilot") vectorAdd [0,0,_unitDistance * 0.026 + 0.3]),
                            1,
                            1,
                            0, // no angle
                            name _x,
                            2, // outline
                            0.025, // text size
                            "RobotoCondensed"
                        ];
                    };
                };
                nil
            } count (units _x); // count used for speed, ensure `nil` is above this line
        };
        nil
    } count allGroups; // count used for speed, ensure `nil` is above this line
};
END_COUNTER(GVAR(tags));
