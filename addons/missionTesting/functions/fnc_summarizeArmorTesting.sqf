#include "..\script_component.hpp"
#define OUTPUT_NONE 0
#define OUTPUT_CLIPBOARD 1
#define OUTPUT_RPT 2
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
*
*
* Arguments:
*
*
* Return:
* A formatted ARRAY
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
		_finalString pushBack format ["%1 => %2", _weaponName, _unitClass];
        if (_outputToMenu) then {
            _finalString pushBack "[list]";
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
                ["  ", "[*] "] select _outputToMenu
			];
		} forEach (_damageResultHash get _key);
        if (_outputToMenu) then {
            _finalString pushBack "[/list]";
        };
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
