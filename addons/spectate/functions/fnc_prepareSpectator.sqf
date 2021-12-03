#include "script_component.hpp"
/*
 * Author: AACO
 * Function used to prepare the spectator unit on all computer
 *
 * Arguments:
 * 0: unit to prepare <OBJECT>
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [player] call potato_spectate_fnc_prepareSpectator;
 *
 * Public: No
 */

params [
    ["_unit", objNull, [objNull]],
    ["_oldUnit", objNull, [objNull]]
];
TRACE_2("prepareSpectator",_unit,_oldUnit);

if !(isNull _unit) then {
    _unit enableSimulation false;
    _unit allowDamage false;
    _unit setVariable [QACEGVAR(medical,allowDamage), false];
    _unit setVariable [QGVAR(timeOfDeath), CBA_missionTime];

    if (isServer) then {
        _unit hideObjectGlobal true;
    };

    if !(isNull _oldUnit) then {
        _unit setVariable [QGVAR(oldUnit), _oldUnit];

        private _side = [[configOf _oldUnit >> "side", 7] call CFUNC(getNumber)] call CFUNC(toSide);
        private _sideColor = if (_side != sideLogic) then { 
            [_side] call BIS_fnc_sideColor
        } else {
            [0.7,0.6,0,1]
        };
        _unit setVariable [QGVAR(oldSideColor), _sideColor];
        _unit setVariable [QACEGVAR(killtracker,output), _oldUnit getVariable [QACEGVAR(killtracker,output), "None"]];
    };
};
