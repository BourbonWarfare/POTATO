params [
    ["_vestArr", [], [[]]],
    ["_unit", objNull, [objNull]]
];
if (!alive _unit) exitWith {
    hint "Test unit died!?";
};
if (_vestArr isEqualTo []) exitWith {
    hint parseText format ["Finished testing<br/>%1 errors<br/>Check rpt for details", lmd_tst_errors];
    diag_log formatText ["Ending vest armor testing with %1 errors", lmd_tst_errors];
    deleteVehicle _unit;
};
private _currentVest = _vestArr#0;
_vestArr deleteAt 0;
hintSilent parseText format ["Testing<br/>%1", _currentVest];
// Remove vest and add new one
removeVest _unit;
_unit addVest _currentVest;
// Position unit
_unit setDir 180;
/**** Bullet info ***//*
B_556x45_Ball
hit = 9;
typicalSpeed = 920;
/*********************/
private _bullet = createVehicle ["B_556x45_Ball", getPosATL _unit vectorAdd [0, -1, 1.4], [], 0, "CAN_COLLIDE"];
_bullet setvectorDirAndUp [[0, 1, 0], [0, 0, 1]];
_bullet setVelocity [0, 920, 0];

// Wait a moment and fire the next round
[{call lmd_tst_fnc_vestTestRecurse}, [_vestArr, _unit], diag_deltaTime*4] call CBA_fnc_waitAndExecute;
