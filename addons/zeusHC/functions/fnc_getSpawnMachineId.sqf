#include "script_component.hpp"
TRACE_1("Params",_this);

private _allHCs = (entities "HeadlessClient_F") select {isPlayer _x};
TRACE_1("",_allHCs);

private _returnClientId = SERVER_CLIENT_ID;

if (_allHCs isEqualTo []) exitWith { _returnClientId };

//Find the HC with least units on it
private _hcIDs = [];
private _hcCounts = [];

{
  _hcIDs pushBack (owner _x);
  _hcCounts pushBack 0;
  nil
} count _allHCs;

{
  private _index = _hcIDs find (groupOwner _x);
  if (_index > -1) then {
    _hcCounts set [_index, ((_hcCounts select _index) + (count units _x))];
  };
  nil
} count allGroups;

(_hcCounts call CBA_fnc_findMin) params ["", "_bestHcIndex"];
_returnClientId = _hcIDs select _bestHcIndex;

_returnClientId
