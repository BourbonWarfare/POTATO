/*
 * Author: AACO
 * Function used to update the recruit information
 * Should only be called from an event handler
 *
 * Examples:
 * [] call potato_recruits_fnc_updateRecruitInfo;
 *
 * Public: No
 */

#include "script_component.hpp"

#define START_FADE_DISTANCE 150
#define END_FADE_DISTANCE 200
#define FADE_DIFF 50
#define TAG_COLOR 0.15,0.451,0.94
#define TAG_ALPHA 0.85
#define TAG_WIDTH 1
#define TAG_HEIGHT 1

TRACE_1("Params",_this);

if !(isNull MESSAGE_DISPLAY) then {

    // get all units in the player's group, check for changes in inPlayer for JIPs
    private _units = [];
    {
        if !(isNull _x) then {
            _units pushBack [_x, alive _x, isPlayer _x];
        };
        nil
    } count units (group player); // count used for speed, ensure `nil` is above this line

    TRACE_2("Groups", GVAR(oldSquad), _units);
    if !(GVAR(oldSquad) isEqualTo _units) then {
        GVAR(oldSquad) = _units;
        private _recruits = [];
        private _recruitCount = {
            _x params ["_unit", "_isAlive", "_isPlayer"];
            // _isPlayer left out for testing, make sure you don't leave it out for release
            if (_isAlive && {[_unit] call FUNC(isNotMember)}) then {
                _recruits pushBack (name _unit);
                true
            } else {
                false
            }
        } count _units;

        TRACE_2("Recruits",_recruits,_recruitCount);
        if (_recruitCount > 0) then {
            MESSAGE_CONTROL ctrlSetStructuredText parseText format [
                "<t size='0.75'>You have %1 in your group:<br/>%2<br/>Say hello and make sure you vote on their %3</t>",
                ["a recruit", "some recruits"] select (_recruitCount > 1),
                _recruits joinString "<br/>",
                ["thread", "threads"] select (_recruitCount > 1)
            ];
            MESSAGE_CONTROL ctrlSetPosition [
                0.88 * safezoneW + safezoneX,
                0.15 * safezoneH + safezoneY,
                0.105 * safezoneW,
                (2 + _recruitCount) * 0.017 * safezoneH
            ];
            MESSAGE_CONTROL ctrlCommit 0.25;
        } else {
            MESSAGE_CONTROL ctrlSetStructuredText parseText "";
            MESSAGE_CONTROL ctrlSetPosition [
                0.88 * safezoneW + safezoneX,
                0.15 * safezoneH + safezoneY,
                0.105 * safezoneW,
                0
            ];
            MESSAGE_CONTROL ctrlCommit 0.25;
        };
    };
};

if (GVAR(showTags)) then {
    private _playerPos = getPosVisual player;
    {
        if (side _x == playerSide) then {
            {
                //  && {isPlayer _x} left out for testing, add it back when tested
                if (!isNull _x && {alive _x} && {[_x] call FUNC(isNotMember)}) then {
                    private _unitPos = getPosVisual _x;
                    private _unitDistance = _playerPos distance _unitPos;
                    if (_unitDistance < END_FADE_DISTANCE) then {
                        drawIcon3D [
                            texture,
                            [
                                TAG_COLOR,
                                ((FADE_DIFF - ((_unitDistance max START_FADE_DISTANCE) - START_FADE_DISTANCE)) / FADE_DIFF) * TAG_ALPHA
                            ],
                            _unitPos,
                            TAG_WIDTH,
                            TAG_HEIGHT,
                            0, // no angle
                            format ["Hi, my name is:<br/>%1", name _x],
                            2, // outline
                            0.5, // text size
                            "RobotoCondensed",
                            "center"
                        ];
                    };
                };
                nil
            } count (units (group player)); // count used for speed, ensure `nil` is above this line
        };
    } count allGroups; // count used for speed, ensure `nil` is above this line
};
