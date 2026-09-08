#include "..\script_component.hpp"
/*
 * Server event handler for minefield markers
 *
 * Arguments:
 * 0: Unit <OBJECT>
 * 1: Position AGL (but z always 0 for now) <ARRAY>
 *
 * Returns:
 * None
 *
 * Examples:
 * [player, getpos player] call potato_missionModules_fnc_minefield_steppedInIt
 */
 

params ["_unit", "_minePos"];
INFO_1("minefield_steppedInIt %1",name _unit);

if (-1 != (GVAR(minefield_previousExplosions) findIf { _minePos inArea _x })) exitWith {
    INFO("- skipping: close to previous");
};

GVAR(minefield_previousExplosions) pushBack [_minePos, 15, 15];
private _mine = createVehicle ["ACE_APERSMine_ToePopper_Ammo", _minePos, [], 0, "NONE"];
triggerAmmo _mine;
