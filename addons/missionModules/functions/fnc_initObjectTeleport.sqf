#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function handles the transfer for the ACE "become group leader"
 * action statement override.
 *
 * Arguments:
 * 0: The module being initialized
 *
 * Examples:
 * Should be called by module init
 *
 * Public: No
 */
params ["_logic", "", "_activated"];
if (!_activated || !hasInterface) exitWith {
    TRACE_3("leaving TP Object early",_logic,_activated,hasInterface);
};

if (isNull _logic) exitWith {
    WARNING_1("Attempted to initialize object teleport module at %1",diag_time);
};

private _syncedObjects = synchronizedObjects _logic;
if (_syncedObjects isEqualTo []) exitWith {
    if (CBA_missionTime < 30) then {
        ERROR_MSG_1("No objects synced with object TP [%1]",_logic);
    };
};
_syncedObjects = _syncedObjects#0;

private _safeStart = _logic getVariable [QUOTE(safeStart), true];
private _holdLength = _logic getVariable [QUOTE(holdLength), 2];
private _posName = _logic getVariable [QUOTE(posName), 3];

//IGNORE_PRIVATE_WARNING["_caller", "_arguments"];
private _actionID = [
    _syncedObjects,
    format ["Teleport to %1", _posName],
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_connect_ca.paa",
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_connect_ca.paa",
    "_this distance _target < 5", "_caller distance _target < 5",
    {}, {}, {_caller setVehiclePosition [_arguments#0, [], 15, "NONE"]},{},
    [getPosATL _logic], _holdLength, 1000, false, false
] call BIS_fnc_holdActionAdd;

TRACE_5("Adding object TP actions",_logic,_safeStart,_holdLength,_posName,_actionID);
if (_safeStart) then { // We will need to manually clean these up
    private _actionArr = _syncedObjects getVariable [QGVAR(tpActions), []];
    _actionArr pushBack _actionID;
    _syncedObjects setVariable [QGVAR(tpActions), _actionArr];
    GVAR(tpActionCleanup) pushBackUnique _syncedObjects;
};
