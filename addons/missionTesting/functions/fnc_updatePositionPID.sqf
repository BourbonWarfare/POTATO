/*
 * Author: BadWolf, Pabo
 * Function is called once when the Breifings dialog is opened.
 *
 * Arguments:
 *
 * Examples:
 * [] call potato_missionTesting_fnc_runWeaponsTest;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params [""];

private _disBetween = 2;

private _pidDummy_1 = GVAR(DummyUnits) select 0;
private _pidDummy_2 = GVAR(DummyUnits) select 1;
private _pidDummy_3 = GVAR(DummyUnits) select 2;

_newPosD1 = ACE_PLAYER modelToWorldWorld [0,5,0];
_pidDummy_1 setPosASLW _newPosD1;
_newPosD2 = _pidDummy_1 modelToWorldWorld [_disBetween,0,0];
_newPosD3 = _pidDummy_1 modelToWorldWorld [-(_disBetween),0,0];
_pidDummy_2 setPosASLW _newPosD2;
_pidDummy_3 setPosASLW _newPosD3;
