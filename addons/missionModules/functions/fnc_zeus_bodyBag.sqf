/*
 * Author: Dani
 * Body bags the unit it places on
 *
 * Public: No
 */

#include "script_component.hpp"

params ["_logic"];

if (!local _logic) exitWith {};
private _unit = _logic getVariable ["bis_fnc_curatorAttachObject_object",objnull];
TRACE_2("",_logic,_unit);

if ([nil, _unit] call ACEFUNC(medical_treatment,canPlaceInBodyBag)) then {
    [ACE_PLAYER, _unit] call ACEFUNC(medical_treatment,placeInBodyBag);
} else {
    [objNull, "Place on unit"] call BIS_fnc_showCuratorFeedbackMessage;
};

deleteVehicle _logic;
