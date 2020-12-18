/*
 * Author: Alablm
 * Triggers the Naloxone drug removal action
 *
 * Arguments:
 * 0: Patient <OBJECT>
 * 1: Medication <STRING> (optional)
 *
 * Return Value:
 * None
 *
 * Examples:
 * [player, "Naloxone"] call potato_miscMedical_fnc_Naloxone;
 *
 */

#include "script_component.hpp"
params ["_unit","_medicationClassName"];
TRACE_2("Naloxone",_unit,_medicationClassName);

_startMeds = _unit getVariable "ace_medical_medications";
{
    _medication = _x select 0;
    if (_medicationClassName == "Naloxone") then {
        if (_medication == "Morphine" or {_medication == _medicationClassName}) then {
            _startMeds set [_forEachIndex, ["FakeDrug", 5, 1, 0, 0, 0]];
        };
    } else {
      if (_medication == _medicationClassName) then {
          _startMeds set [_forEachIndex, ["FakeDrug", 5, 1, 0, 0, 0]];
      };
    };
} forEach _startMeds;
_unit setVariable ["ace_medical_medications", _startMeds];
