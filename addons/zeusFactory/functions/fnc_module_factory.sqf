#include "script_component.hpp"

params ["_factory"];
TRACE_1("module_factory",_factory);

if (!isServer) exitWith {};

[{
    params ["_factory"];
    (isNull _factory) || {_factory getVariable [QGVAR(set), false]}
}, {
    params ["_factory"];
    if (isNull _factory) exitWith {TRACE_1("null",_factory);};

    private _side = _factory getVariable [QGVAR(side), sideUnknown];
    if (_side isEqualTo sideUnknown) exitWith {ERROR("badSide");};

    if (isNil QGVAR(factoryCount)) then {GVAR(factoryCount) = 1};
    
    _factory setVariable [QGVAR(factoryID), GVAR(factoryCount), true];
    GVAR(factoryCount) = GVAR(factoryCount) + 1;
    
    // Update factory name with side
    [QGVAR(updateFactory), [_factory], [_factory]] call CBA_fnc_targetEvent;

    
    private _allHCs = (entities "HeadlessClient_F") select {isPlayer _x};
    private _bestID = CBA_clientID;
    private _bestFactCount = 999;
    {
        private _hcID = owner _x;
        private _factCount = count ((entities QGVAR(factory)) select {(owner _x) == _hcID});
        if (_factCount < _bestFactCount) then {
            _bestID = _hcID;
            _bestFactCount = _factCount;
        };
    } forEach _allHCs;
    
    TRACE_2("sending event to best HC",_bestID,_bestFactCount);
    [QGVAR(newFactory), _factory, _bestID] call CBA_fnc_ownerEvent;

}, [_factory]] call CBA_fnc_waitUntilAndExecute;
