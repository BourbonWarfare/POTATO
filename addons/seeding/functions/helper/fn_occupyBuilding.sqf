#include "..\..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This fucntion places a group of infantry in a designated building distributing
* them among positions evenly. In additon, it will force a given percentage to
* be static and enforce a stance if given
*
* Arguments:
* _grp - group to be placed into the bunker
* _building - building to be occupied
* _staticOdds - chance that any unit is to be static 0-100,
                                use -1 for no unit stationary, default 100%
* _stance - enforced stance, default AUTO
*
* Return:
* none
*
* Example:
* [_grg, _building, 80, "UP"] spawn bw_fnc_occupyBuilding;
*//***************************************************************************/
params [
    ["_grp", grpNull, [grpNull]],
    ["_building", objNull, [objNull]],
    ["_staticOdds", 100, [123]],
    ["_stance", "AUTO", [""]]
];

// checks if we have a group and a building
if (isNull _grp || isNull _building) exitWith {};
if (!local _grp) then {
    _this remoteExecCall [QFUNC(occupyBuild), _grp];
};

// default stance works
if (_stance == "UPPER") then {
    _stance = selectRandom ["UP", "UP", "UP", "MIDDLE"];
} else {
    if !((toUpper _stance) in ["UP", "DOWN", "MIDDLE"]) then {
        _stance = "AUTO";
    };
};


// find max number of idxs
private _buildingPoses = _building buildingPos -1;
_buildingPoses = _buildingPoses select {_x isNotEqualTo [0, 0, 0]};
// if there aren't positions don't try anything else
if (_buildingPoses isEqualTo []) exitWith {};
private _nIdx = count _buildingPoses;
//*** Shuffle or sort the building positions
[_buildingPoses, true] call cba_fnc_shuffle;
private _maxReactionTime =  time + 7200;
// Move units into the building and try to make them stay still for a while
{
    // get the position and place them there
    _x setPosATL (_buildingPoses#(_forEachIndex mod _nIdx));
    // try to stay still or never move again
    if (_staticOdds > random 100) then 	{
        _x disableAI "PATH";
        _x setVariable ["lambs_danger_disableAI", true];
    } else {
        doStop _x;
    };
    // Disable LAMBS explosion dodging
    _x setVariable ["lambs_eventhandlers_explosionReactionTime", _maxReactionTime];
    // set stance
    _x setUnitPos _stance;
} forEach units _grp;
_grp setVariable ["lambs_danger_disableGroupAI", true];;
