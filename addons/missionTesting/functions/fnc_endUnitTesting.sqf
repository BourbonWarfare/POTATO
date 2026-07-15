#include "..\script_component.hpp"
#define INFORM_TESTER(msg) systemChat msg;\
hint msg;\
INFO(msg)
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This function is part of the armor testing and handles when a unit dies
* or goes unconcious. It starts by attempting to remove the unit from
* the active tested units list and then adds test results to the
* damageTestingResults hashmap. This unit and group is then deleted. If the
* test is completed and the activeTestUntis array indicates there are no
* further tests, the function will removes eventhandlers and disable AI uncon
* In addition, the GVAR(damageTestingResults) variable is broadcast to all
* connected clients.
*
* Arguments:
* _unit - The unit that has died or gone unconcious (default objNull).
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
    if (is3DENPreview) then {
        private _testResults = [OUTPUT_NONE] call FUNC(summarizeArmorTesting);
        _testResults = _testResults regexReplace ["&", "?"];
        _testResults = ["<font size=28 face=""PuristaBold"">Damage Report</font>"] +
                        (_testResults splitString endl);
        {
            if ("Shooting At" in _x) then {
                _testResults set [_forEachIndex, "<br/><font size=18>" + _x + "</font>"];
            };
        } forEach _testResults;
        if !(player diarySubjectExists "POTATO") then {
            player createDiarySubject ["POTATO", "POTATO"];
        };
        // find the diary
        private _diaryEntries = player allDiaryRecords "POTATO";
        // find and replace existing orbat pages
        private _testMenuNotFound = true;
        {
            _x params ["_idx", "_title", "", "", "", "", "", "", "_record"];
            if (_title == "Damage Report") then {
                player setDiaryRecordText [["POTATO", _record], ["Damage Report", _testResults joinString "<br/>"]];
                _testMenuNotFound = false;
            };
        } forEach _diaryEntries;

        // if we didn't find and replace, add one
        if (_testMenuNotFound) then {
            player createDiaryRecord ["POTATO", ["Damage Report", _testResults joinString "<br/>"], taskNull, "NONE", false];
        };

        INFORM_TESTER("Test results put into diary entry (check map)");
    };
};
