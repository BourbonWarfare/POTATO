#include "..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This function is used as part of the armor testing system.
* This function takes two factions, a position to create the test around,
* test points and a maximum number of units. It starts by confirming there
* are test points and the two factions are real and retrieves the faction test
* sets. A test plan is created so that the first factions armor is tested
* against all of the second factions guns and visa versa. Then AI uncon is
* enabled  and event handlers are setup to track ace medical uncon, fatalInjury
* and death events and vanilla killed events. Finally if the create unit
* system is not running, it starts the recursive call sequence.
*
* Arguments:
* _faction0 - The first of the two factions to be tested (default "potato_w")
* _faction1 - The second of the two factions to be tested (default "potato_e")
* _startPosASL - The starting position units should be created around in
                ASL format (ARRAY, default [])
* _testPoints - An array of array elements in pair form. Each pair is
    0: Distance in meters the target should be simulated at
    1: The place on the unit that should be shot at
    (default [])
* _maxUnits - The maximum number of units to create for the
                test (NUMBER, default 100)
*
* Return:
* None
*
* Example:
* ["poatato_w", "poatato_e", getPosASL player] call potato_missionTesting_fnc_testFactionPair;
*//***************************************************************************/
params [
    ["_faction0", "poatato_w"],
    ["_faction1", "potato_e"],
    ["_startPosASL", [], [[]]],
    ["_testPoints", [
        [100, SHOTPOS_FACE],
        [100, SHOTPOS_HEAD],
        [100, SHOTPOS_CHEST],
        [200, SHOTPOS_CHEST],
        [300, SHOTPOS_CHEST]
    ], []],
    ["_maxUnits", 100, [0]]
];

if (_testPoints isEqualTo []) exitWith {
    WARNING_2("Testing [%1] vs [%2], no test points provided",_faction0,_faction1);
};

private _fact0Classes = _faction0 call FUNC(getFactionParams);
if (_fact0Classes isEqualTo []) exitWith {
    WARNING_1("Faction [%1] either not real faction or not in CfgLoadouts",_faction0);
};
private _fact1Classes = _faction1 call FUNC(getFactionParams);
if (_fact1Classes isEqualTo []) exitWith {
   WARNING_1("Faction [%1] either not real faction or not in CfgLoadouts",_faction1);
};

// What if we created a plan for tests
_fact0Classes params ["_fact0Units", "_fact0Weapons", "_fact0Side"];
_fact1Classes params ["_fact1Units", "_fact1Weapons", "_fact1Side"];
if (isNil QGVAR(testPlan)) then {
    GVAR(testPlan) = [];
};
{
    _x params ["_identifier", "_ammo", "_friction", "_v0"];
    private _speeds = [
        _friction,
        _v0,
        _testPoints apply {_x#0}
    ] call FUNC(getProjectileVelocity);
    _identifier = _faction1 + "|" + _identifier;
    {
        private _unitClass = _x;
        {
            GVAR(testPlan) pushBack [
                _identifier,
                _unitClass,
                _x,
                _ammo,
                _testPoints#_forEachIndex,
                _fact1Side
            ];
        } forEach _speeds;
    } forEach _fact1Units;
} forEach _fact0Weapons;
{
    _x params ["_identifier", "_ammo", "_friction", "_v0"];
    private _speeds = [
        _friction,
        _v0,
        _testPoints apply {_x#0}
    ] call FUNC(getProjectileVelocity);
    _identifier = _faction0 + "|" + _identifier;
    {
        private _unitClass = _x;
        {
            GVAR(testPlan) pushBack [
                _identifier,
                _unitClass,
                _x,
                _ammo,
                _testPoints#_forEachIndex,
                _fact0Side
            ];
        } forEach _speeds;
    } forEach _fact0Units;
} forEach _fact1Weapons;

if (GVAR(testPlan) isEqualTo []) exitWith {
    WARNING_2("Failed to make test plan using [%1] & [%2]",_faction0,_faction1);
};

// Setup settings
["ace_medical_statemachine_AIUnconsciousness", true, 2, "server"] call CBA_settings_fnc_set;

if (isNil QGVAR(fatalInjuryEH) || {GVAR(fatalInjuryEH) < 0}) then {
    GVAR(fatalInjuryEH) = ["ace_medical_FatalInjury", {
        params [["_unit", objNull]];
        _unit setVariable [QGVAR(ended), true];
        _unit setVariable [QGVAR(fatalHit), true];
    }] call CBA_fnc_addEventHandler;
};
if (isNil QGVAR(unconEH) || {GVAR(unconEH) < 0}) then {
    GVAR(unconEH) = ["ace_unconscious", {
        params ["_unit", "_state"];
        if (_unit getVariable [QGVAR(ended), false]) exitWith {};
        _unit setVariable [QGVAR(ended), true];
        _unit setVariable [QGVAR(uncon), _state];
        [{call FUNC(endUnitTesting)}, _unit, 0.1] call CBA_fnc_waitAndExecute;

    }] call CBA_fnc_addEventHandler;
};

if (isNil QGVAR(killedEH) || {GVAR(killedEH) < 0}) then {
    GVAR(killedEH) = addMissionEventHandler ["EntityKilled", {
        params ["_unit"];
        _unit setVariable [QGVAR(ended), true];
        [{call FUNC(endUnitTesting)}, _unit, 0.1] call CBA_fnc_waitAndExecute;
}];
};

if (isNil QGVAR(damageTestingResults)) then {
    GVAR(damageTestingResults) = createHashMap;
};
if (isNil QGVAR(activeTestUnits)) then {
    GVAR(activeTestUnits) = [];
};

// Start testing as needed
if (isNil QGVAR(creatingUnits) || {!GVAR(creatingUnits)}) then {
    GVAR(creatingUnits) = true;
    if (_startPosASL isEqualTo []) then {
        _startPosASL = nil;
    };
    [_maxUnits, _testPoints, _startPosASL] call FUNC(createUnits);
};
