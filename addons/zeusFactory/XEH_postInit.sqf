#include "script_component.hpp"

[QGVAR(zeusFeedback), {
    params ["_msg"];
    TRACE_1("zeusFeedback",_msg);
    if (isNull curatorCamera) exitWith {};
    [objNull, _msg] call BIS_fnc_showCuratorFeedbackMessage;
}] call CBA_fnc_addEventHandler;

[QGVAR(updateFactory), { // Update factory and queue names for zeus
    params ["_factory"];
    TRACE_1("updateFactory eh",_factory);
    private _dispatchQueue = _factory getVariable [QGVAR(dispatchQueue), []];
    {
        private _displayName = getText (configOf _x >> "displayName");
        _x setName format ["%1: Queued #%2", _displayName, (_forEachIndex + 1)];
    } forEach _dispatchQueue;
    private _factorySide = _factory getVariable QGVAR(side);
    private _factoryID = _factory getVariable QGVAR(factoryID);
    _factory setName format ["Factory #%1 [%2]", _factoryID, _factorySide];
}] call CBA_fnc_addEventHandler;

[QGVAR(newFactory), {
    params ["_factory"];
    INFO_1("starting factory loop for logic [%1]",_factory);
    _factory setVariable [QGVAR(active), true, true];
    private _side = _factory getVariable [QGVAR(side), sideUnknown];
    if (_side == sideUnknown) exitWith {ERROR("No side on factory logic");};
    [LINKFUNC(factoryLoop), 0.5, [_factory, _side, [], [], []]] call CBA_fnc_addPerFrameHandler;
}] call CBA_fnc_addEventHandler;
