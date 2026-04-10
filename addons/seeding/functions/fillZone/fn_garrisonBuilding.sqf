#include "..\..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This function spawns a group of units and occupies the building. The number
* of units is provided as an argument.
*
* Arguments:
* _building - The building to occupy (OBJECT).
* _forceSize - Number of units to spawn (SCALAR, default 4).
* _chanceToMove - Chance a unit will be static when garrisoned (SCALAR| [0, 1], default 0.1)
* _sideGarrison - Side of the buildings garrison (SIDE, default east).
* _allowMovementOnShot - When shot near, allow a unit to move (BOOL, true).
* _group - The group units are spawned into. Should not be passed, used for recursion (GROUP).
*
* Return:
* none
*
* Example:
* [_building, 4, 0.6] spawn bw_fnc_garrisonBuilding;
*//***************************************************************************/
params [
    ["_building", objNull, [objNull]],
    ["_forceSize", 4, [4]],
    ["_chanceToMove", 0.1, [0.1]],
    ["_sideGarrison", east, [east]],
    ["_allowMovementOnShot", true, [true]],
    ["_group", grpNull, [grpNull]]
];

if (isNull _building || _forceSize <= 0) exitWith {};

if (isNull _group) then {
    _group = createGroup [_sideGarrison, true];
    private _type = typeOf _building;
    if (_type in ["land_gm_euro_barracks_01", "land_gm_euro_barracks_02","Land_Tenement_01","Land_A_Hospital"]) then {
        _forceSize = 2.25 * _forceSize;
    };
    if (_type in ["land_gm_euro_pub_02","gm_bunker_command_01_plain"]) then {
        _forceSize = 1.5 * _forceSize;
    };
    _forceSize = round _forceSize;
};
if !(local _group) exitWith {
    [_this] remoteExecCall [QFUNC(garrisonBuilding), _group];
};

private _type = switch (_forceSize mod 6) do {
    case 2: {selectRandom ["_rifleman", "_rifleman", "_lat", "_ar"]};
    case 3: {selectRandom ["_ar", "_ar", "_ar",  "_ar", "_mmgg"]};
    case 4: {selectRandom ["_ftl", "_ftl", "_sl"]};
    case 5: {selectRandom ["_sm", "_rifleman_02"]};
    default {selectRandom ["_rifleman", "_rifleman_03", "_rifleman_04"]};
};
private _sideType = switch (_sideGarrison) do {
    case east: {"e"};
    case west: {"w"};
    case resistance: {"i"};
    default {"e"};
};
private _unit = _group createUnit ["potato_" + _sideType + _type, BW_UNIT_SPAWN_POS, [], 0, "NONE"];
_forceSize = _forceSize - 1;
if (_allowMovementOnShot && random 1 < 0.15) then {
    _unit addEventHandler ["FiredNear", {
        params ["_unit", "_firer"];
        if (side _firer != side player || {_firer distance2D _unit > 8 + random 10}) exitWith {};
        _unit enableAI "PATH";
        _unit removeEventHandler [_thisEvent, _thisEventHandler];
    }];
};

if (_forceSize == 4) then {
    _group selectLeader _unit;
};

if (_forceSize <= 0) then {
    _group selectLeader _unit;
    [{
        _this call FUNC(occupyBuilding)
    }, [_group, _building, 100 * (1 -_chanceToMove), "UPPER"], 0.1] call CBA_fnc_waitAndExecute;
} else {
    [{_this call FUNC(garrisonBuilding)},
        [_building, _forceSize, _chanceToMove, _sideGarrison, _allowMovementOnShot, _group],
        PGVAR(zeusHC,delayBetweenUnitCreation) * (1 + random 0.5)] call CBA_fnc_waitAndExecute;
};
