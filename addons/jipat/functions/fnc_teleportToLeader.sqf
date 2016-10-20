/*
 * Author: Bismarck
 * Function used to teleport JIP unit to highest available leader
 *
 * Arguments:
 * 0: Unit to teleport <OBJECT>
 * 1: Side of unit to teleport <SIDE>
 *
 * Examples:
 * [player] call potato_jipat_fnc_teleportToLeader;
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params [["_unit", player, [objNull]], ["_side", west, [west]]];

_lead = [_side] call FUNC(getCurLeaderSide);

if (_lead isEqualTo objNull) then {
  hint "Sorry, there is no available leadership unit for auto-teleportation. Contact an administrator.";
  systemChat "Sorry, there is no available leadership unit for auto-teleportation. Contact an administrator.";
} else {

    if (vehicle _lead != _lead) then {
      //in car
      _unit allowDamage false;
      [{(_this select 0) allowDamage true;}, [_unit], 5] call CBA_fnc_waitAndExecute; //protect them in the case of fall damage or whatnot
      _unit moveInCargo (vehicle _lead);
      [
        {
            params ["_unit", "_side"];

            if !(_unit in (crew vehicle _lead)) then {
                //the cargo was full
                hint "Current mission leader is unavailable for teleport. Please wait, retrying in five seconds...";
                systemChat "Current mission leader is unavailable for teleport. Please wait, retrying in five seconds...";
                [] spawn {sleep 5; [] execVM "f\JIP\f_JIP_autoTeleport.sqf";}; //rerun script and try again
            } else {
                //they are there in the car
                hint ((name _unit) + ", you have joined the current commander (" + (name _lead) + ") inside the AO. Please ask them for assignment to a team.");
                systemChat ((name _unit) + ", you have joined the current commander (" + (name _lead) + ") inside the AO. Please ask them for assignment to a team.");
                [
                [
                    [_lead,_unit],
                    {
                    params ["_leader","_joiner"];
                    hint ((name _joiner) + " is a JIP (" + getText(configFile >> "CfgVehicles" >> (typeOf _joiner) >> "displayName") + ") and has been teleported into your vehicle. Assign them to a team, " + (name _leader) + "!");
                    systemChat ((name _joiner) + " is a JIP (" + getText(configFile >> "CfgVehicles" >> (typeOf _joiner) >> "displayName") + ") and has been teleported into your vehicle. Assign them to a team, " + (name _leader) + "!");
                    }
                ],
                "BIS_fnc_spawn",
                _lead
                ] call BIS_fnc_MP;
                [_unit] join (group _lead);
            };
        },
        [_unit, _lead],
        0.2
      ] call CBA_fnc_waitAndExecute;
      sleep 0.2;
      
    } else {
      //on foot
      _posPlant = _lead modelToWorld [0,-3,0]; //3 meters behind leader
      _posPlant set [2,0]; //ensure height atl = 0
      _unit allowDamage false; [] spawn {sleep 5; _unit allowDamage true}; //protect them in the case of fall damage or whatnot
      _unit setPosATL _posPlant;
      [_unit] join (group _lead);
      hint ((name _unit) + ", you have been teleported to the mission commander (" + (name _lead) + "), please ask them for assignment!");
      systemChat ((name _unit) + ", you have been teleported to the mission commander (" + (name _lead) + "), please ask them for assignment!");
      [
        [
          [_lead,_unit],
          {
            params ["_leader","_joiner"];
            hint ((name _joiner) + " is a JIP (" + getText(configFile >> "CfgVehicles" >> (typeOf _joiner) >> "displayName") + ") and has been teleported just behind your location. Assign them to a team, " + (name _leader) + "!");
            systemChat ((name _joiner) + " is a JIP (" + getText(configFile >> "CfgVehicles" >> (typeOf _joiner) >> "displayName") + ") and has been teleported just behind your location. Assign them to a team, " + (name _leader) + "!");
          }
        ],
        "BIS_fnc_spawn",
        _lead
      ] call BIS_fnc_MP;
    };
};