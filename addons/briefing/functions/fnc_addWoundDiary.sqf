/*
 * Author: AACO
 * Function used to add wound notes to a player's diary
 *
 * Arguments:
 * 0: Unit to add to the notes to <OBJECT>
 * 1: The wound class array <ARRAY>
 *
 * Examples:
 * [player, "true" configClasses (configfile >> "ACE_Medical_Advanced" >> "Injuries" >> "wounds")] call potato_briefing_fnc_addWoundDiary;
 *
 * Public: Yes
 */

#include "script_component.hpp"

params ["_newPlayer", "_wounds"];
TRACE_1("params",_this);

private _woundInfo = [];
private _woundsDiaryBuilder = [];
private _minPain = 9999;
private _maxPain = -9999;
private _minBleedRate = 9999;
private _maxBleedRate = -9999;

{
    private _wound = [];
    private _woundCfg = _x;

    _wound pushBack getText (_woundCfg >> "name");

    private _pain = getNumber (_woundCfg >> "pain");
    if (_pain < _minPain) then { _minPain = _pain; };
    if (_pain > _maxPain) then { _maxPain = _pain ; };
    _wound pushBack _pain;

    {
        private _bleedRate = getNumber (_woundCfg >> _x >> "bleedingRate");
        if (_bleedRate < _minPain) then { _minBleedRate = _bleedRate; };
        if (_bleedRate > _maxPain) then { _maxBleedRate = _bleedRate; };
        _wound pushBack _bleedRate;
    } forEach ["Minor", "Medium", "Large"];

    _woundInfo pushBack _wound;
} forEach _wounds;

private _rangePain = _maxPain - _minPain;
private _rangeBleedRate = _maxBleedRate - _minBleedRate;

_woundsDiaryBuilder pushBack "Injuries:";
{
    _x params ["_name", "_pain", "_minorBleedRate", "_mediumBleedRate", "_largeBleedRate"];

    _woundsDiaryBuilder pushBack format ["  • %1", _name];

    // calculate pain
    _woundsDiaryBuilder pushBack format ["      Pain: %1", [_pain, _minPain, _rangePain] call FUNC(displayDanger)];

    // calculate large bleed rate
    _woundsDiaryBuilder pushBack format ["      Large %1, bleed rate: %2", _name, [_largeBleedRate, _minBleedRate, _rangeBleedRate] call FUNC(displayDanger)];

    // calculate medium bleed rate
    _woundsDiaryBuilder pushBack format ["      Medium %1, bleed rate: %2", _name, [_mediumBleedRate, _minBleedRate, _rangeBleedRate] call FUNC(displayDanger)];

    // calculate minor bleed rate
    _woundsDiaryBuilder pushBack format ["      Minor %1, bleed rate: %2", _name, [_minorBleedRate, _minBleedRate, _rangeBleedRate] call FUNC(displayDanger)];
} forEach _woundInfo;

_newPlayer createDiaryRecord ["medical", ["Injuries", _woundsDiaryBuilder joinString "<br/>"]];
