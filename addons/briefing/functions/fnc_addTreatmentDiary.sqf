/*
 * Author: AACO
 * Function used to add treatment notes to a player's diary
 *
 * Arguments:
 * 0: Unit to add to the notes to <OBJECT>
 * 1: If the unit is a medic or not <BOOL>
 * 2: The wound class array <ARRAY>
 *
 * Examples:
 * [player, true, "true" configClasses (configfile >> "ACE_Medical_Advanced" >> "Injuries" >> "wounds")] call potato_briefing_fnc_addTreatmentDiary;
 *
 * Public: Yes
 */

#include "script_component.hpp"

params ["_newPlayer", "_isMedic", "_wounds"];
TRACE_1("params",_this);

private _woundEffectiveness = [[],[]];
private _treatmentInfo = [];
private _treatmentsDiaryBuilder = [];
private _minEffectiveness = 9999;
private _maxEffectiveness = -9999;

{
    private _treatmentCfg = _x;
    private _treatment = [];
    private _woundList = [];

    _treatment pushBack (configName (_treatmentCfg));
    {
        private _wound = [];
        private _woundName = getText (_x >> "name");
        _wound pushBack _woundName;

        private _index = (_woundEffectiveness select 0) find _woundName;
        if (_index < 0) then {
            (_woundEffectiveness select 0) pushBack _woundName;
            _index = (_woundEffectiveness select 1) pushBack [9999, -9999];
        };

        {
            private _subWound = format ["%1%2", _woundName, _x];
            private _effectiveness = getNumber (_config >> _subWound >> "effectiveness");

            if (_effectiveness < (((_woundEffectiveness select 1) select _index) select 0)) then {
                ((_woundEffectiveness select 1) select _index) set [0, _effectiveness];
            };

            if (_effectiveness > (((_woundEffectiveness select 1) select _index) select 1)) then {
                ((_woundEffectiveness select 1) select _index) set [1, _effectiveness];
            };

            _wound pushBack _bleedRate;
        } forEach ["Minor","Medium","Large"];

        _woundList pushBack _wound;
    } forEach _wounds;

    _treatment pushBack _woundList;
    _treatmentInfo pushBack _treatment;
} forEach ("true" configClasses (configfile >> "ACE_Medical_Advanced" >> "Treatment" >> "Bandaging"));

_treatmentsDiaryBuilder pushBack "Bandages and their effect on injuries:";
{
    _x params ["_treatmentName", "_woundList"];
    _treatmentsDiaryBuilder pushBack format ["  • %1", _treatmentName];

    {
        _x params ["_woundInfo"];
        {
            _x params ["_woundName", "_minorEffectiveness", "_mediumEffectiveness", "_largeEffectiveness"];

            private _index = (_woundEffectiveness select 0) find _woundName;
            if (_index > -1) {
                (_woundEffectiveness select 1) select _index
            } else {
                [0, 10]
            } params ["_minEffectiveness", "_maxEffectiveness"];

            private _rangeEffectiveness = _maxEffectiveness - _minEffectiveness;

            _treatmentsDiaryBuilder pushBack format [
                "      %1 - Minor: %2",
                _woundName,
                [_minorEffectiveness, _minEffectiveness, _rangeEffectiveness, true] call FUNC(displayDanger);
            ];

            _treatmentsDiaryBuilder pushBack format [
                "      %1 - Medium: %2",
                _woundName,
                [_mediumEffectiveness, _minEffectiveness, _rangeEffectiveness, true] call FUNC(displayDanger);
            ];

            _treatmentsDiaryBuilder pushBack format [
                "      %1 - Large: %2",
                _woundName,
                [_largeEffectiveness, _minEffectiveness, _rangeEffectiveness, true] call FUNC(displayDanger);
            ];
        } forEach _woundInfo;

        _treatmentsDiaryBuilder pushBack "";
    } forEach _woundList;
} forEach _treatmentInfo;

if (_isMedic) then {
    _treatmentsDiaryBuilder pushBack "";
    _treatmentsDiaryBuilder pushBack "Drugs:";

    {
        _treatmentsDiaryBuilder pushBack format ["  • %1", configName (_x)];

        if (getNumber (_x >> "painReduce") > 0) then {
            _treatmentsDiaryBuilder pushBack "      Reduces pain";
        };

        private _hrNumber = ((getArray (_x >> "hrIncreaseNormal")) select 0);
        if !(isNil "_hrNumber") then {

            if (_hrNumber > 0) then {
                _treatmentsDiaryBuilder pushBack "      Increases heart rate";
            };
            if (_hrNumber < 0) then {
                _treatmentsDiaryBuilder pushBack "      Decreases heart rate";
            };
        };

        if (getNumber (_x >> "viscosityChange") > 0) then {
            _treatmentsDiaryBuilder pushBack "      Decreases blood pressure";
        };

        _treatmentsDiaryBuilder pushBack format ["      Time in system (seconds): %1", getNumber (_x >> "timeInSystem")];
    } forEach ("true" configClasses (configfile >> "ACE_Medical_Advanced" >> "Treatment" >> "Medication"));

    _treatmentsDiaryBuilder pushBack "";
    _treatmentsDiaryBuilder pushBack "Fluids:";
    _treatmentsDiaryBuilder pushBack "  • All fluids increase blood pressure";
};

_newPlayer createDiaryRecord ["medical", ["Treatments", _treatmentsDiaryBuilder joinString "<br/>"]];
