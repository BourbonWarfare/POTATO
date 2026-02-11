#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function takes a module, uses it's position to clear units in acrtive
 * fire misisons and release them. This helps cancel missions that are not
 * desired or broken.
 *
 * Arguments:
 * _logic - The logic that is calling the function. OBJECT
 *
 * Example:
 * Called via module function
 *
 * Public: No
 */
params ["_logic"];

if (isNil QGVAR(artilleryGunArray) || {GVAR(artilleryGunArray) isEqualTo []}) exitWith {};

private _nearObjects = _logic nearEntities [["StaticWeapon", "Car_F", "Tank_F"], 50];
private _artilleryToClear = _nearObjects select {
    local _x &&
    {0 < getNumber ((configOf _x) >> "artilleryScanner") &&
    {_x in GVAR(artilleryGunArray)}} &&
    {(_x getVariable [QGVAR(artyMission), ["", ARTILLERY_MISSION_STATUS_FREE]])#1 == ARTILLERY_MISSION_STATUS_FIRING}
};
TRACE_1("gunsToClear",_artilleryToClear);
{
    private _missionParams = _x getVariable [QGVAR(artyMission), [""]];
    _missionParams params [
        "_missionID", "", "_holdTime", ["_missionType", ARTILLERY_MISSIONTYPE_POINT]
    ];
    if (_missionID != "" &&
        _missionType in ARTILLERY_REPORT_ON_COMPLETION) then {
        [QGVAR(missionComplete), [_missionID, true]] call CBA_fnc_serverEvent;
        _missionParams set [3, ARTILLERY_MISSIONTYPE_UNDEF];
        _missionParams set [2, 420 + _missionParams#2];
    };
    _x setVariable [QGVAR(artyMission), nil];
} forEach _artilleryToClear;

if (local _logic) then {
    [{deleteVehicle _this}, _logic, 1] call CBA_fnc_waitAndExecute;
};
