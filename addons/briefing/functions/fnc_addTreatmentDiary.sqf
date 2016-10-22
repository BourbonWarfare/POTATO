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
#define DEBUG_MODE_FULL
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
    private _treatmentClassName = configName (_treatmentCfg);

    if (_treatmentClassName != "Bandage") then { // ignore the basic bandage

        private _treatment = [];
        private _woundList = [];
        
        _treatment pushBack (_treatmentClassName);
        {

            private _woundClassName = configName _x;
            private _wound = [];
            private _woundName = getText (_x >> "name");
            _wound pushBack _woundName;

            private _index = (_woundEffectiveness select 0) find _woundName;
            if (_index < 0) then {
                (_woundEffectiveness select 0) pushBack _woundName;
                _index = ((_woundEffectiveness select 1) pushBack [9999, -9999]);
            };

            {
                private _subWound = format ["%1%2", _woundClassName, _x];

                private _effectiveness = if (isNumber (_treatmentCfg >> _subWound >> "effectiveness")) then {
                     getNumber (_treatmentCfg >> _subWound >> "effectiveness")
                } else {
                    WARNING_2("No config for wound type [%1] config base [%2]", _woundClassName, _subWound);
                    getNumber (_treatmentCfg >> "effectiveness")
                };

                TRACE_2("", _subWound, _effectiveness);

                if (_effectiveness < (((_woundEffectiveness select 1) select _index) select 0)) then {
                    ((_woundEffectiveness select 1) select _index) set [0, _effectiveness];
                };

                if (_effectiveness > (((_woundEffectiveness select 1) select _index) select 1)) then {
                    ((_woundEffectiveness select 1) select _index) set [1, _effectiveness];
                };

                _wound pushBack _effectiveness;
            } forEach ["Minor","Medium","Large"];

            _woundList pushBack _wound;
            TRACE_1("", _wound);
        } forEach _wounds;

        _treatment pushBack _woundList;
        _treatmentInfo pushBack _treatment;
        TRACE_2("", _treatment, _woundList);
    };
} forEach ("true" configClasses (configfile >> "ACE_Medical_Advanced" >> "Treatment" >> "Bandaging"));

TRACE_1("", _treatmentInfo);
TRACE_1("", _woundEffectiveness);

_treatmentsDiaryBuilder pushBack "Bandages and their effect on injuries:";
{
    TRACE_1("treatment", _x);
    _x params ["_treatmentName", "_woundList"];
    _treatmentsDiaryBuilder pushBack format ["  • %1", _treatmentName];

    {
        TRACE_1("wound info", _x);
        _x params ["_woundName", "_minorEffectiveness", "_mediumEffectiveness", "_largeEffectiveness"];

        private _index = (_woundEffectiveness select 0) find _woundName;
        if (_index > -1) then {
            (_woundEffectiveness select 1) select _index
        } else {
            [0, 10]
        } params ["_minEffectiveness", "_maxEffectiveness"];

        private _rangeEffectiveness = _maxEffectiveness - _minEffectiveness;

        _treatmentsDiaryBuilder pushBack format [
            "      %1 - Minor: %2",
            _woundName,
            [_minorEffectiveness, _minEffectiveness, _rangeEffectiveness, true] call FUNC(displayDanger)
        ];

        _treatmentsDiaryBuilder pushBack format [
            "      %1 - Medium: %2",
            _woundName,
            [_mediumEffectiveness, _minEffectiveness, _rangeEffectiveness, true] call FUNC(displayDanger)
        ];

        _treatmentsDiaryBuilder pushBack format [
            "      %1 - Large: %2",
            _woundName,
            [_largeEffectiveness, _minEffectiveness, _rangeEffectiveness, true] call FUNC(displayDanger)
        ];

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
