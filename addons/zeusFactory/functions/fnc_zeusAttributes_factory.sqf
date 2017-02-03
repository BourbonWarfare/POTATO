#include "script_component.hpp"

#define SIDES_ARRAY [west, east, independent]
#define CARS_ARRAY ["CUP_B_HMMWV_Transport_USA", "C_Offroad_01_F", "badTest", "B_MRAP_01_F", "O_T_MRAP_02_ghex_F", "B_T_LSV_01_unarmed_F", "CUP_C_SUV_TK", "CUP_B_UAZ_Unarmed_CDF", "CUP_O_Ural_Open_RU"]

#define APC_ARRAY ["B_APC_Wheeled_01_cannon_F", "O_APC_Wheeled_02_rcws_F", "rhsusf_m113_usarmy", "M1126_ICV_M2_DG1_NOSLATWOOD", "rhsgref_ins_g_uaz_dshkm_chdkz", "CUP_I_BTR40_MG_TKG", "rhs_bmd1", "rhs_bmp1_vdv", "rhs_btr60_msv", "rhsgref_BRDM2_msv"]

#define HELI_ARRAY ["CUP_B_UH1Y_UNA_USMC", "CUP_B_UH60M_Unarmed_US", "B_Heli_Light_01_F", "B_Heli_Transport_01_F", "I_Heli_Transport_02_F", "B_Heli_Transport_03_F", "O_Heli_Transport_04_F", "I_Heli_light_03_unarmed_F", "rhs_ka60_c", "CUP_C_Mi17_Civilian_RU", "CUP_C_Mi17_VIV_RU"]


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
        if (isClass (configFile >> "CfgVehicles" >> _x)) then {
            private _displayName = getText (configFile >> "CfgVehicles" >> _x >> "displayName");
            private _icon = getText (configFile >> "CfgVehicles" >> _x >> "icon");
            private _index = (_display displayCtrl _idc) lbAdd format ["[%1] %2", [_x, true] call BIS_fnc_crewCount, _displayName];
            (_display displayCtrl _idc) lbSetPicture [_index, _icon];
            (_display displayCtrl _idc) lbSetValue [_index, _forEachIndex];
            (_display displayCtrl _idc) lbSetTooltip [_index, _x];
            if (_currentValue == _x) then {_setIndex = _index};
        } else {
            WARNING_1("Vehicle Classname [%1] does not exist in modset",_x);
        };
    } forEach _vehicleArray;
    (_display displayCtrl _idc) lbSetCurSel _setIndex;
} forEach [
[23072, CARS_ARRAY, (_logicObject getVariable [QGVAR(carType), GVAR(lastCar)])],
[23073, APC_ARRAY, (_logicObject getVariable [QGVAR(apcType), GVAR(lastAPC)])],
[23074, HELI_ARRAY, (_logicObject getVariable [QGVAR(heliType), GVAR(lastHeli)])]
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
    if (isNull _logicObject) exitWith {ERROR_1("Logic [%1] is null on confirm", _logicObject);};

    private _set = _logicObject getVariable [QGVAR(set), false];

    TRACE_1("",_set);
    if (!_set) then { // Only update side if not already set
        private _selectedIndexSide = (lbCurSel (_display displayCtrl 23071)) max 0;
        private _selectedSide = SIDES_ARRAY select _selectedIndexSide;
        GVAR(lastSide) = _selectedSide;
        _logicObject setVariable [QGVAR(side), _selectedSide, true];
        _logicObject setVariable [QGVAR(set), true, true];
    };

    private _carType = CARS_ARRAY param [(_display displayCtrl 23072) lbValue ((lbCurSel (_display displayCtrl 23072)) max 0), "err"];
    _logicObject setVariable [QGVAR(carType), _carType, true];
    GVAR(lastCar) = _carType;
    private _apcType = APC_ARRAY param [(_display displayCtrl 23073) lbValue ((lbCurSel (_display displayCtrl 23073)) max 0), "err"];
    _logicObject setVariable [QGVAR(apcType), _apcType, true];
    GVAR(lastAPC) = _apcType;
    private _heliType = HELI_ARRAY param [(_display displayCtrl 23074) lbValue ((lbCurSel (_display displayCtrl 23074)) max 0), "err"];
    _logicObject setVariable [QGVAR(heliType), _heliType, true];
    GVAR(lastHeli) = _heliType;

    TRACE_3("setting vehicles",_carType,_apcType,_heliType);
};

_display displayaddeventhandler ["unload", _fnc_onUnload];
_ctrlButtonOK ctrladdeventhandler ["buttonclick", _fnc_onConfirm];
