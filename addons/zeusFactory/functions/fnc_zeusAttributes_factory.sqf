#include "script_component.hpp"

#define SIDES_ARRAY [west, east, independent]

if (isNil QGVAR(carArray)) then { // init vehicle arrays if they don't exist
    GVAR(carArray) = [];
    [GVAR(carArray), "cars"] call FUNC(addVehiclesToArray);
    GVAR(apcArray) = [];

    [GVAR(apcArray), "apcs"] call FUNC(addVehiclesToArray);

    GVAR(helicopterArray) = [];
    [GVAR(helicopterArray), "helicopters"] call FUNC(addVehiclesToArray);
    TRACE_3("",count GVAR(carArray),count GVAR(apcArray),count GVAR(helicopterArray));
};

if (isNil QGVAR(lastSide)) then {GVAR(lastSide) = east};
if (isNil QGVAR(lastCar)) then {GVAR(lastCar) = (CARS_ARRAY select 0)};
if (isNil QGVAR(lastAPC)) then {GVAR(lastAPC) = (APC_ARRAY select 0)};
if (isNil QGVAR(lastHeli)) then {GVAR(lastHeli) = (HELI_ARRAY select 0)};

disableSerialization;

params ["_control"];
private _logicObject = missionNamespace getVariable ["BIS_fnc_initCuratorAttributes_target", objnull];
TRACE_2("zeusAttributes_factory",_control,_logicObject);

private _display = ctrlparent _control;
private _ctrlButtonOK = _display displayctrl 1; //IDC_OK
_control ctrlRemoveAllEventHandlers "setFocus";


// Init: Side List (If already set, do not allow changing)
private _set = _logicObject getVariable [QGVAR(set), false];
private _selectedIndexSide = SIDES_ARRAY find (_logicObject getVariable [QGVAR(side), GVAR(lastSide)]);
(_display displayCtrl 23071) lbSetCurSel _selectedIndexSide;
if (_set) then {(_display displayCtrl 23071) ctrlEnable false};

// Init: Vehicle Lists
{
    _x params ["_idc", "_vehicleArray", "_currentValue"];
    private _setIndex = 0;
    lbClear (_display displayCtrl _idc);
    {
        private _displayName = getText (configFile >> "CfgVehicles" >> _x >> "displayName");
        private _icon = getText (configFile >> "CfgVehicles" >> _x >> "icon");
        ([_x] call FUNC(getSeatInfo)) params ["_gunnerTurrets", "_cargo"];
        if (_cargo < 2) then { TRACE_2("skip",_x,_cargo); continue; }; // skip vics that can't carry anything

        private _toolTip = format ["%1\nCrew %2 Carries %3",_x,1+count _gunnerTurrets,_cargo];
        private _index = (_display displayCtrl _idc) lbAdd format ["[%1] %2",_cargo, _displayName];
        (_display displayCtrl _idc) lbSetPicture [_index, _icon];
        (_display displayCtrl _idc) lbSetValue [_index, _forEachIndex];
        (_display displayCtrl _idc) lbSetTooltip [_index, _toolTip];
        if (_currentValue == _x) then {_setIndex = _index};
    } forEach _vehicleArray;
    (_display displayCtrl _idc) lbSetCurSel _setIndex;
} forEach [
    [23072, GVAR(carArray), (_logicObject getVariable [QGVAR(carType), GVAR(lastCar)])],
    [23073, GVAR(apcArray), (_logicObject getVariable [QGVAR(apcType), GVAR(lastAPC)])],
    [23074, GVAR(helicopterArray), (_logicObject getVariable [QGVAR(heliType), GVAR(lastHeli)])]
];


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

    private _set = _logicObject getVariable [QGVAR(set), false];

    TRACE_1("",_set);
    if (!_set) then { // Only update side if not already set
        private _selectedIndexSide = (lbCurSel (_display displayCtrl 23071)) max 0;
        private _selectedSide = SIDES_ARRAY select _selectedIndexSide;
        GVAR(lastSide) = _selectedSide;
        _logicObject setVariable [QGVAR(side), _selectedSide, true];
        _logicObject setVariable [QGVAR(set), true, true];
    };

    private _carType = GVAR(carArray) param [(_display displayCtrl 23072) lbValue ((lbCurSel (_display displayCtrl 23072)) max 0), "err"];
    _logicObject setVariable [QGVAR(carType), _carType, true];
    GVAR(lastCar) = _carType;
    private _apcType = GVAR(apcArray) param [(_display displayCtrl 23073) lbValue ((lbCurSel (_display displayCtrl 23073)) max 0), "err"];
    _logicObject setVariable [QGVAR(apcType), _apcType, true];
    GVAR(lastAPC) = _apcType;
    private _heliType = GVAR(helicopterArray) param [(_display displayCtrl 23074) lbValue ((lbCurSel (_display displayCtrl 23074)) max 0), "err"];
    _logicObject setVariable [QGVAR(heliType), _heliType, true];
    GVAR(lastHeli) = _heliType;

    TRACE_3("setting vehicles",_carType,_apcType,_heliType);
};

_display displayaddeventhandler ["unload", _fnc_onUnload];
_ctrlButtonOK ctrladdeventhandler ["buttonclick", _fnc_onConfirm];
