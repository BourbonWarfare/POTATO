#include "script_component.hpp"

disableSerialization;

params ["_control"];

private _logicObject = missionNamespace getVariable ["BIS_fnc_initCuratorAttributes_target", objnull];
TRACE_2("zeusAttributes_place",_control,_logicObject);

private _display = ctrlparent _control;
private _ctrlButtonOK = _display displayctrl 1; //IDC_OK
_control ctrlRemoveAllEventHandlers "SetFocus";

if (isNil QGVAR(lastTransport)) then {GVAR(lastTransport) = 0};
if (isNil QGVAR(lastOrders)) then {GVAR(lastOrders) = 0};
if (isNil QGVAR(lastRadius)) then {GVAR(lastRadius) = 100};
if (isNil QGVAR(attackTarget)) then {GVAR(attackTarget) = true};
if (isNil QGVAR(useLAMBS)) then {GVAR(useLAMBS) = true};

// Init: Transport List
lbClear (_display displayCtrl 23071);
for "_i" from 0 to 6 do {
    private _name = switch (_i) do {
    case TRANSPORT_FOOT: {"On Foot"};
    case TRANSPORT_CAR_RTB: {"Car [RTB]"};
    case TRANSPORT_CAR_FOLLOW: {"Car [FOLLOW]"};
    case TRANSPORT_APC_RTB: {"APC [RTB]"};
    case TRANSPORT_APC_FOLLOW: {"APC [FOLLOW]"};
    case TRANSPORT_HELI: {"Heli Drop"};
    case TRANSPORT_PARADROP: {"Para Drop"};
        default {"ERR"};
    };
    (_display displayCtrl 23071) lbAdd _name;
};
private _transportType = _logicObject getVariable [QGVAR(transport), GVAR(lastTransport)];
(_display displayCtrl 23071) lbSetCurSel _transportType;

// Init: Orders List
lbClear (_display displayCtrl 23072);
for "_i" from 0 to 4 do {
    private _name = switch (_i) do {
    case ORDERS_MOVE: {"Basic Move"};
    case ORDERS_GARRISION: {"Garrision"};
    case ORDERS_PATROL: {"Patrol"};
    case ORDERS_SEARCH: {"Search"};
    case ORDERS_ATTACK: {"Attack Mark"};
        default {"ERR"};
    };
    (_display displayCtrl 23072) lbAdd _name;
};
private _ordersType = _logicObject getVariable [QGVAR(orders), GVAR(lastOrders)];
(_display displayCtrl 23072) lbSetCurSel _ordersType;

private _radius = _logicObject getVariable [QGVAR(radius), GVAR(lastRadius)];
(_control controlsgroupctrl 23074) sliderSetRange [10, 2000];
[_control controlsgroupctrl 23074, _control controlsgroupctrl 23075, "m", _radius] call bis_fnc_initSliderValue;
[_control controlsgroupctrl 23074, _control controlsgroupctrl 23075, "m"] call bis_fnc_initSliderValue;

(_control controlsgroupctrl 23076) cbSetChecked GVAR(attackTarget);
(_control controlsgroupctrl 23077) cbSetChecked GVAR(useLAMBS);

private _fnc_onUnload = {
    params [["_display", displayNull, [displayNull]], ["_exitCode", -1]];
    TRACE_1("_fnc_onUnload params",_display);

    private _logicObject = missionnamespace getVariable ["BIS_fnc_initCuratorAttributes_target", objnull];
    if (isNull _logicObject) exitWith {TRACE_1("null",_logicObject);};

    private _set = _logicObject getVariable [QGVAR(set), false];
    TRACE_2("",_exitCode,_set);
    if ((_exitCode != 1) && {!_set}) then {
        TRACE_2("deleting",_logicObject,_exitCode);
        deleteVehicle _logicObject;
    };
};

private _fnc_onConfirm = {
    params [["_ctrlButtonOK", controlNull, [controlNull]]];
    TRACE_1("_fnc_onConfirm params",_this);
    private _display = ctrlparent _ctrlButtonOK;
    if (isNull _display) exitWith {};

    private _logicObject = missionnamespace getvariable ["BIS_fnc_initCuratorAttributes_target", objnull];
    if (isNull _logicObject) exitWith {ERROR_1("Logic [%1] is null on confirm",_logicObject);};


    private _transportType = (lbCurSel (_display displayCtrl 23071)) max 0;
    GVAR(lastTransport) = _transportType;
    _logicObject setVariable [QGVAR(transportType), _transportType, true];

    private _ordersType = (lbCurSel (_display displayCtrl 23072)) max 0;
    GVAR(lastOrders) = _ordersType;
    _logicObject setVariable [QGVAR(ordersType), _ordersType, true];

    private _radius = sliderposition (_display displayCtrl 23074);
    GVAR(lastRadius) = _radius;
    _logicObject setVariable [QGVAR(radius), _radius, true];

    private _attackTarget = cbChecked (_display displayCtrl 23076);
    GVAR(attackTarget) = _attackTarget;
    _logicObject setVariable [QGVAR(attackTarget), _attackTarget, true];

    private _useLAMBS = cbChecked (_display displayCtrl 23077);
    GVAR(useLAMBS) = _useLAMBS;
    _logicObject setVariable [QGVAR(useLAMBS), _useLAMBS, true];

    _logicObject setVariable [QGVAR(set), true, true];
    TRACE_3("set",_transportType,_ordersType,_radius);
};

_display displayaddeventhandler ["unload", _fnc_onUnload];
_ctrlButtonOK ctrladdeventhandler ["buttonclick", _fnc_onConfirm];
