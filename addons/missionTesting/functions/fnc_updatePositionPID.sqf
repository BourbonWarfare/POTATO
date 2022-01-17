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

params ["_dist"];

private _disBetween = 2;
private _pidDummy_1 = GVAR(DummyUnits) select 0;
private _pidDummy_2 = GVAR(DummyUnits) select 1;
private _pidDummy_3 = GVAR(DummyUnits) select 2;
private _pidEmpty = GVAR(DummyUnits) select 3;

if(!isNil "_dist") then {
_newPosEmpty = ACE_PLAYER modelToWorldWorld [0,_dist,0];
_pidEmpty setPosASLW _newPosEmpty;
};

_newPosD1 = _pidEmpty modelToWorldWorld [0,0,0];
_newPosD2 = _pidEmpty modelToWorldWorld [_disBetween,0,0];
_newPosD3 = _pidEmpty modelToWorldWorld [-(_disBetween),0,0];
_pidDummy_1 setPosWorld _newPosD1;
_pidDummy_2 setPosWorld _newPosD2;
_pidDummy_3 setPosWorld _newPosD3;
