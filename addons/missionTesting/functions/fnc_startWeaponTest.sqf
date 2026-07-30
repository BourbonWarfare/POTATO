#include "..\script_component.hpp"
#define INFORM_TESTER(msg) systemChat msg;\
hint msg;\
INFO(msg)
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This function is used as part of the armor testing system.
* This function spawns a group of units and occupies the building. The number
* of units is provided as an argument.
*
* Arguments:
* _faction0 - The first faction to test against (STRING, default "potato_w").
* _faction1 - The second faction to test against (STRING, default "potato_e").
*
* Return:
* none
*
* Example:
* ["potato_e", "potato_w"] call potato_missionTesting_fnc_starWeaponTest;
*//***************************************************************************/
params [
    ["_faction0", "potato_w", [""]],
    ["_faction1", "potato_e", [""]]
];

if (EGVAR(spectate,running)) exitWith {
    INFORM_TESTER("Cannot run testing menu damage test from spectate");
};
if (EGVAR(safeStart,safeStartEnabled)) exitWith {
    INFORM_TESTER("Cannot run testing menu damage test with safe start enabled");
};
private _exit = false;
for "_i" from 1 to 5 do {
    private _posAGL = (getPosASL ace_player) findEmptyPosition [5, 100];
    _posAGL = _posAGL isFlatEmpty [5];
    if (_posAGL isEqualTo [] || {surfaceIsWater _posAGL}) exitWith {
        WARNING("Cannot run damage in current location, please move to an open flat area");
        _exit = true;
    };
};
if (_exit) exitWith {
    INFORM_TESTER("ERR: Cannot run damage in current location, please move to an open flat area");
};
// Pretty good chance a round hits you
ace_player allowDamage false;
[_faction0, _faction1, getPosASL ace_player] remoteExecCall [QFUNC(testFactionPair), 2];
[{_this allowDamage true}, ace_player, 10] call CBA_fnc_waitAndExecute;

if (isNil QGVAR(testingVarUpdateEH)) then {
    GVAR(testingVarUpdateEH) = true;
    QGVAR(damageTestingResults) addPublicVariableEventHandler {
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
