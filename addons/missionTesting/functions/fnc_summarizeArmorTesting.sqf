#include "..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This function is used as part of the armor testing system. It takes the
* test results array and creates a human readable formatted list of tests.
* If the output type is set to none, it will add BB-Code formatting for use
* with forums posts (remove this when forums die).
*
* Arguments:
* _output - The output mode to use, either rpt, clipboard,
            or none (NUMBER, default OUTPUT_NONE)
*
* Return:
* A formatted string joined by endl
*
* Example:
* [1] call potato_missionTesting_fnc_summarizeTesting;
*//***************************************************************************/
params [["_output", OUTPUT_NONE, [OUTPUT_NONE]]];

if (isNil QGVAR(damageTestingResults) || {GVAR(damageTestingResults) isEqualTo createHashMap}) exitWith {
    ""
};

private _damageResultHash = GVAR(damageTestingResults);
private _keys = keys _damageResultHash;
private _keys = _keys apply {[_x] + (_x splitString "|")};
private _factions = _keys apply {_x#1};
_factions = _factions arrayIntersect _factions;

private _finalString = [];
private _cfgWeapons = configFile >> "CfgWeapons";
private _outputToMenu = OUTPUT_NONE == _output;
{
	private _faction = _x;
	if (_finalString isNotEqualTo []) then {
		_finalString pushBack "";
	};
	_finalString pushBack format ["Shooting At: %1", _faction];
	private _testsets = _keys select {_x#1 == _faction};
	{
		_x params ["_key", "", "_weaponClassname", "", "_unitClass"];
        private _weaponName = getText (_cfgWeapons >> _weaponClassname >> "displayName");
        if (_outputToMenu) then {
            _finalString pushBack format ["- %1 => %2", _weaponName, _unitClass];
        } else {
            _finalString pushBack format ["%1 => %2", _weaponName, _unitClass];
        };
		{
			_x params ["_range", "_hitPoint"];
			private _hitArr = [];
			{
				_x params ["_hits", "_uncon", "_fatalHit"];
				_hitArr pushBack (switch (true) do {
                    case (_uncon): {format ["%1 to uncon", _hits];};
                    case (_fatalHit): {format ["%1 to kill", _hits];};
                    default {format ["%1 still standing", _hits];};
                });
			} forEach _y;
			_hitpoint = switch (_hitPoint) do {
				case SHOTPOS_HEAD: {"Head"};
				case SHOTPOS_FACE: {"Face"};
				default {"Chest"};
			};
			private _hitArrUnique = _hitArr arrayIntersect _hitArr;
			_hitArrUnique = _hitArrUnique apply {private _str = _x; [_x, {_str == _x} count _hitArr]};
			_hitArrUnique = _hitArrUnique apply {format ["%1 (x%2)", _x#0, _x#1]};
			_finalString pushBack format ["%4%1 @ %2m | %3",
				_hitPoint,
				_range,
				_hitArrUnique joinString ", ",
                ["  ", " - "] select _outputToMenu
			];
		} forEach (_damageResultHash get _key);
	} forEach _testsets;
} forEach _factions;

switch (_output) do {
    case OUTPUT_CLIPBOARD: {
        {
            "ace" callExtension ["clipboard:append", [_x + endl]];
        } forEach _finalString;
        "ace" callExtension ["clipboard:complete", []];
    };
    case OUTPUT_RPT: {
        {
            diag_log text _x;
        } forEach _finalString
    };
    default {};
};
_finalString joinString endl
