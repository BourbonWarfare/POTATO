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

GVAR(DummyUnits) = [];

private _display = DISPLAY_TESTMENU createDisplay QGVAR(LoadoutPID);

waituntil {!isnull (finddisplay 9997)};

private _handledClasses = [];
private _factions = [];
private _masterArray = [[west,[]],[east,[]],[independent,[]],[civilian,[]]];

{
    private _unit = _x;
    private _classname = typeOf _unit;

    if (!(_classname in _handledClasses)) then {
        _handledClasses pushBack _classname;
        switch (side _x) do {
            case (west): {
                ((_masterArray select 0) select 1) pushBack _classname;
                };
            case (east): {
                ((_masterArray select 1) select 1) pushBack _classname;
                };
            case (resistance): {
                ((_masterArray select 2) select 1) pushBack _classname;
                };
            default {
                ((_masterArray select 3) select 1) pushBack _classname;
            };
        };
    };
} forEach allUnits;


{
    private _classArray = _x select 1;
    private _side = _x select 0;
    if (count _classArray > 0) then {
        _factions pushBack _x;
    };
} forEach _masterArray;

GVAR(factionClassList) = _factions;

{
    private _ctrl = _display displayCtrl _x;
    {
        private _side = _x select 0;
        _ctrl lbAdd str _side;
    } forEach _factions;
    _ctrl lbSetCurSel PID_DEFAULT_FACTION;
    _ctrl ctrlAddEventHandler [QUOTE(LBSelChanged),{_this call FUNC(updateClassListPID);}];
    _ctrl ctrlCommit 0;
    private _classCtrl = _display displayCtrl (_x + 3);
        private _classes = _factions select PID_DEFAULT_FACTION select 1;
        {
            private _displayName = getText (configfile >> "CfgVehicles" >> _x >> "displayName");
            _classCtrl lbAdd _displayName;
            _classCtrl lbSetData [_forEachIndex,_x];
        } forEach _classes;
    _classCtrl lbSetCurSel PID_DEFAULT_CLASS;
    _classCtrl ctrlAddEventHandler [QUOTE(LBSelChanged),{_this call FUNC(updateClassPID);}];
    _classCtrl ctrlCommit 0;
} forEach [PID_SIDE_1_IDC,PID_SIDE_2_IDC,PID_SIDE_3_IDC];

{
    private _ctrl = _display displayCtrl _x;
    {
        private _text = _x select 0;
        private _data = _x select 1;
        _ctrl lbAdd _text;
        _ctrl lbSetData [_forEachIndex,_data];
    } forEach PID_STANCES;
    _ctrl lbSetCurSel PID_DEFAULT_STANCE_INDEX;
    _ctrl ctrlAddEventHandler [QUOTE(LBSelChanged),{_this call FUNC(updateStancePID);}];
    _ctrl ctrlCommit 0;
} forEach [PID_STANCE_1_IDC,PID_STANCE_2_IDC,PID_STANCE_3_IDC];

{
    private _ctrl = _display displayCtrl _x;
    _ctrl sliderSetRange [-180, 180];
    _ctrl sliderSetPosition PID_DEFAULT_DIR;
    _ctrl ctrlAddEventHandler [QUOTE(SliderPosChanged),{_this call FUNC(updateDirPID);}];
} forEach [PID_DIR_SLIDER_1_IDC,PID_DIR_SLIDER_2_IDC,PID_DIR_SLIDER_3_IDC];

private _pos = getPos ACE_PLAYER;

private _classDummy1 = lbData [PID_CLASS_1_IDC,PID_DEFAULT_CLASS];
private _classDummy2 = lbData [PID_CLASS_2_IDC,PID_DEFAULT_CLASS];
private _classDummy3 = lbData [PID_CLASS_3_IDC,PID_DEFAULT_CLASS];

//Create a unit.
private _pidDummy_1 = _classDummy1 createVehicle _pos;
TRACE_1("_pidDummy_1",_pidDummy_1);
GVAR(DummyUnits) pushBack _pidDummy_1;
_pidDummy_1 enableSimulation false;
_pidDummy_1 switchMove PID_DEFAULT_STANCE;
//Create a second unit.
private _pidDummy_2 = _classDummy2 createVehicle _pos;
TRACE_1("_pidDummy_2",_pidDummy_2);
GVAR(DummyUnits) pushBack _pidDummy_2;
_pidDummy_2 enableSimulation false;
_pidDummy_2 switchMove PID_DEFAULT_STANCE;
//Create a third unit.
private _pidDummy_3 = _classDummy3 createVehicle _pos;
TRACE_1("_pidDummy_3",_pidDummy_3);
GVAR(DummyUnits) pushBack _pidDummy_3;
_pidDummy_3 enableSimulation false;
_pidDummy_3 switchMove PID_DEFAULT_STANCE;
// Create an empty position
private _pidEmpty = "HeliHEmpty" createVehicle _pos;
TRACE_1("_pidEmpty",_pidEmpty);
GVAR(DummyUnits) pushBack _pidEmpty;

private _dir = getDir ACE_PLAYER;
private _dirD1 = _dir - 180;

{
_x setDir _dirD1;
} forEach [_pidDummy_1,_pidDummy_2,_pidDummy_3,_pidEmpty];

[5] call FUNC(updatePositionPID);

_display displayAddEventHandler [QUOTE(UnLoad), QUOTE(if((_this select 1)!= 3) then{{deleteVehicle _x} forEach GVAR(DummyUnits);};)];
