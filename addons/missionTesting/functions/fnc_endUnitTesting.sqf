#include "..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
*
*
* Arguments:
* _unit - The unit that has died or gone unconcious.
*
* Return:
* none
*
* Example:
* [player] call potato_missionTesting_fnc_endUnitTesting;
*//***************************************************************************/
params [["_unit", objNull]];

private _testSet = _unit getVariable [QGVAR(testParams), []];
if (_testSet isEqualTo []) exitWith {
    ERROR_2("Testing ended on invalid unit [%1] (%2)",_unit,typeOf _unit);
};
// Remove the unit from active units
private _uid = getObjectID _unit;
private _idx = GVAR(activeTestUnits) find _uid;
if (_idx < 0) then {
    ERROR_2("Testing ended on unit not in active list [%1] (%2)",_unit,typeOf _unit);
};
GVAR(activeTestUnits) deleteAt _idx;

private _fatalHit = _unit getVariable [QGVAR(fatalHit), false];
private _hits = _unit getVariable [QGVAR(hits), -1];
private _uncon = _unit getVariable [QGVAR(uncon), false];

private _testInfo = GVAR(damageTestingResults) getOrDefault [
    (_testSet#0) + "|" + typeOf _unit,
    createHashMap,
    true
];
private _subtestInfo = _testInfo getOrDefault [
    _testSet#1,
    [],
    true
];
_subtestInfo pushBack [_hits, _uncon, _fatalHit];
// clean up
private _grp = group _unit;
deleteVehicle _unit;
deleteGroup _grp;
// If we're done, make sure everything is cleaned up
if (GVAR(activeTestUnits) isEqualTo [] && !GVAR(creatingUnits)) then {
    ["ace_medical_statemachine_AIUnconsciousness", false, 2, "server"] call CBA_settings_fnc_set;
    ["ace_medical_FatalInjury", GVAR(fatalInjuryEH)] call CBA_fnc_removeEventHandler;
    ["ace_unconscious", GVAR(unconEH)] call CBA_fnc_removeEventHandler;
    removeMissionEventHandler ["EntityKilled", GVAR(killedEH)];
    GVAR(fatalInjuryEH) = -1;
    GVAR(unconEH) = -1;
    GVAR(woundRecvEH) = -1;
    GVAR(killedEH) = -1;
    publicVariable QGVAR(damageTestingResults);
};
