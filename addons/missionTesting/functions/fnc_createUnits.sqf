#include "..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This function is used as part of the armor testing system.
* This function creates units to be shot. It starts by confirming there's
* enough space in the running unit list to not overload testing. If the
* testplan isn't empty, it queues up another call in 100ms, otherwise it
* sets the flag that it's done creating units. If there are not too many
* groups or units, it will units until either the single creation run has
* 100 units place OR there are no more tests that must be run
* The units are created with each recieving their own group, parts of the AI
* are immediately disabled, while others have to wait a frame to avoid issues
* with the zeus AI menu clearing the params. Each unit has it's own sequence
* of recursively called "shoot" function chain. Once either condition is
* reached, there is a short check to see if there was a failure to create a
* unit, which throws an error and ends the test. The function normally ends
* by recursively calling itself spaced by 500ms
*
* Arguments:
* _maxUnits - The maximum number of units to exists at once (NUMBER).
* _testPoints - The range/hitpoint combos to shoot (ARRAY).
* _posASL - The center position (ASL) for the units to be created
*            (ARRAY, default getPosASL ace_player).
*
* Return:
* none
*
* Example:
* [150, [[100, SHOTPOS_CHEST],[200, SHOTPOS_CHEST]]] call potato_missionTesting_fnc_createUnits;
*//***************************************************************************/
params ["_maxUnits", "_testPoints", ["_posASL", getPosASL ace_player]];

if (count GVAR(activeTestUnits) > _maxUnits - count _testPoints) exitWith {
    if (GVAR(testPlan) isNotEqualTo []) then {
        [{call FUNC(createUnits)}, _this, 0.1] call CBA_fnc_waitAndExecute;
    } else {
        GVAR(creatingUnits) = false;
    };
};

if (count allGroups > 200) exitWith {
    [{call FUNC(createUnits)}, _this, 0.5] call CBA_fnc_waitAndExecute;
};
private _maxPer = 100;
while {count GVAR(activeTestUnits) < _maxUnits - count _testPoints &&
      count GVAR(testPlan) > 0 &&
      _maxPer > 0} do {
    ((GVAR(testPlan) deleteAt [-1])#0) params [
        "_identifier", "_unitClass", "_v0", "_ammo", "_testNotes", "_side"
    ];
    private _posAGL = [];
    private _itr = 100;
    while {_posAGL isEqualTo [] && _itr > 0} do {
        _posAGL = _posASL findEmptyPosition [5, 100];
        _posAGL = _posAGL isFlatEmpty [5];
        _itr = _itr - 1;
    };
    if (_posAGL isEqualTo []) exitWith {};
    _posAGL = ASLToAGL _posAGL;
    for "_i" from 1 to 5 do {
        private _grp = createGroup [_side, true];
        private _unit = _grp createUnit [_unitClass, _posAGL, [], 0, "NONE"];
        _posAGL = _posAGL vectorAdd [0, 1, 0];
        GVAR(activeTestUnits) pushBack getObjectID _unit;
        _unit setVariable [QGVAR(testParams), [_identifier, _testNotes]];
        _unit disableAI "TARGET";
        _unit disableAI "AUTOTARGET";
        [{ // set skill module fucks this up, we wait for it to finish
            params ["_unit"];
            _unit disableAI "PATH";
            _unit setUnitPos "UP";
            _unit setBehaviour "COMBAT";
        }, _unit, 0.1] call CBA_fnc_waitAndExecute;
        [{
            params ["_unit", "_bulletParams"];
            _unit setDir 180;
            _unit disableAI "ALL";
           [{call FUNC(shootUnit)}, _bulletParams] call CBA_fnc_execNextFrame;
        }, [_unit, [_unit, _ammo, _v0, _testNotes#1]], 2] call CBA_fnc_waitAndExecute;
        _maxPer = _maxPer - 1;
    };
};

if (count GVAR(activeTestUnits) < _maxUnits - count _testPoints &&
    count GVAR(testPlan) > 0 &&
    _maxPer > 0) exitWith {
    GVAR(testPlan) = [];
    GVAR(creatingUnits) = false;
    GVAR(damageTestingResults) = createHashMap;
    systemChat "ERROR: Space too small, exiting testing early";
};

if (GVAR(testPlan) isNotEqualTo []) then {
    [{call FUNC(createUnits)}, _this, 0.5] call CBA_fnc_waitAndExecute;
} else {
    GVAR(creatingUnits) = false;
};
