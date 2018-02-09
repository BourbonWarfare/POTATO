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

#include "script_component.hpp"
TRACE_1("Params",_this);

params [
    ["_unit", objNull, [objNull]],
    ["_oldUnit", objNull, [objNull]]
];

if !(isNull _unit) then {
    _unit enableSimulation false;
    _unit allowDamage false;
    _unit setVariable [QACEGVAR(medical,allowDamage), false];
    _unit setVariable [QGVAR(timeOfDeath), CBA_missionTime];

    if !(isNull _oldUnit) then {
        _unit setVariable [QGVAR(oldUnit), _oldUnit];
        _unit setVariable [QGVAR(oldSideColor), [[[configFile >> "CfgVehicles" >> (typeOf _oldUnit) >> "side", 7] call CFUNC(getNumber)] call CFUNC(toSide)] call BIS_fnc_sideColor]; // holy chained calls batman
        _unit setVariable [QEGVAR(miscFixes,eventsString), _oldUnit getVariable [QEGVAR(miscFixes,eventsString), "None"]];

        // hack to hopefully keep dead STHUD names longer
        private _stNameArray = _oldUnit getVariable ["sth_name", []];
        if !(_stNameArray isEqualTo []) then {
            _stNameArray set [0, false];
            _oldUnit setVariable ["sth_name", _stNameArray];
        };
    };
};
