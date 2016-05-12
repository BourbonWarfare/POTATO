/*
 * Author: AACO
 * Debug helper function used to get the min/max/average of all the skills across the AI
 *
 * Public: Yes
 */

private _fnc_getSkillArray {
    params ["_skill", "_skillArray"];
    _skillArray params ["_min", "_max", "_total"];

    _min = _min min _skill;
    _max = _max max _skill;
    _total = _total + _skill;

    [_min, _max, _total]
}

private _fnc_logAndFormat {
    private _line = format _this;
    diag_log _line;
    _line
}

private _skills [
    "aimingAccuracy",
    "aimingShake",
    "aimingSpeed",
    "commanding",
    "courage",
    "endurance",
    "general",
    "reloadSpeed",
    "spotDistance",
    "spotTime"
];

private _skill = [1, 0, 0];

private _values = [];
{
    _values pushBack [1, 0, 0];
} count _skills;

private _aiCount = {
    private _unit = _x;

    _skill = [skill _unit, _skill] call _fnc_getSkillArray;
    {
        _newValue = [_unit skill _x, _values select _forEachIndex] call _fnc_getSkillArray;
        _values set [_forEachIndex, _newValue];
    } forEach _skills;

    true
} (allUnits - allPlayers);

private _message = [];

_message pushBack (["Total AI count: %1", _aiCount] call _fnc_logAndFormat);
_message pushBack (["Overall AI skill max: %1", (_skill select 1)] call _fnc_logAndFormat);
_message pushBack (["Overall AI skill average: %1", (_skill select 2) / _aiCount] call _fnc_logAndFormat);
_message pushBack (["Overall AI skill min: %1", (_skill select 0)] call _fnc_logAndFormat);

{
    (_values select _forEachIndex) params ["_min", "_max", "_total"];

    _message pushBack (["  Specific skill: %1", _x] call _fnc_logAndFormat);
    _message pushBack (["    max: %1", _max] call _fnc_logAndFormat);
    _message pushBack (["    average: %1", (_total / _aiCount] call _fnc_logAndFormat);
    _message pushBack (["    min: %1", _min] call _fnc_logAndFormat);
} forEach _skills;

hintSilent (_message joinString "\n");
copyToClipboard (_message joinString (toString [13,10]));
