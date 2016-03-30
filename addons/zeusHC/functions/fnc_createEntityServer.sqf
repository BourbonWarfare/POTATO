#include "script_component.hpp"

params [];
TRACE_1("params",_this);

private _allHCs = (entities "HeadlessClient_F") select {isPlayer _x};
TRACE_1("",_allHCs);

if (_allHCs isEqualTo []) exitWith {
    [QGVAR(createEntity), _this] call ace_common_fnc_serverEvent;
};

//Find the HC with least units on it

private _hcIDs = [];
private _hcCounts = [];

{
    _hcIDs pushBack (owner _x);
    _hcCounts pushBack 0;
} forEach _allHCs;

{
    private _index = _hcIDs find (groupOwner _x);
    if (_index >= 0) then {
        _hcCounts set [_index, ((_hcCounts select _index) + (count units _x))]; 
    };
} forEach allGroups;

(_hcCounts call CBA_fnc_findMin) params ["", "_bestHcIndex"];
private _targetMachine = _allHCs select _bestHcIndex;

TRACE_3("",_hcIDs,_hcCounts,_targetMachine);

[QGVAR(createEntity), _targetMachine, _this] call ace_common_fnc_targetEvent;
