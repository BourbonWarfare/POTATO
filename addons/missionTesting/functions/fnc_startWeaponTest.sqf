#include "..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This function spawns a group of units and occupies the building. The number
* of units is provided as an argument.
*
* Arguments:
* _faction0 - The first faction to test against (STRING, default "potato_w").
* _faction1 - The second faction to test against (STRING, default "potato_e").
*
* Return:
* none
*
* Example:
* ["potato_e", "potato_w"] call potato_missionTesting_fnc_starWeaponTest;
*//***************************************************************************/
params [
    ["_faction0", "potato_w", [""]],
    ["_faction1", "potato_e", [""]]
];

if (EGVAR(spectate,running)) exitWith {
    INFO("Cannot run testing menu damage test from spectate");
};
private _exit = false;
for "_i" from 1 to 5 do {
    private _posAGL = (getPosASL ace_player) findEmptyPosition [5, 100];
    _posAGL = _posAGL isFlatEmpty [5];
    if (_posAGL isEqualTo [] || {surfaceIsWater _posAGL}) exitWith {
        WARNING("Cannot run damage in current location, please move to an open flat area");
        _exit = true;
    };
};
if (_exit) exitWith {
    systemChat "ERR: Cannot run damage in current location, please move to an open flat area";
};
// Pretty good chance a round hits you
ace_player allowDamage false;
[_faction0, _faction1, getPosASL ace_player] remoteExecCall [QFUNC(testFactionPair), 2];
[{_this allowDamage true}, ace_player, 10] call CBA_fnc_waitAndExecute;
