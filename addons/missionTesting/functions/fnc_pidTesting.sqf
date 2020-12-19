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
    } forEach [[QUOTE(Standing),QUOTE(UP)],[QUOTE(Crouch),QUOTE(MIDDLE)],[QUOTE(Prone),QUOTE(DOWN)]];
    _ctrl lbSetCurSel PID_DEFAULT_STANCE;
    _ctrl ctrlAddEventHandler [QUOTE(LBSelChanged),{_this call FUNC(updateStancePID);}];
    _ctrl ctrlCommit 0;
} forEach [PID_STANCE_1_IDC,PID_STANCE_2_IDC,PID_STANCE_3_IDC];

{
    private _ctrl = _display displayCtrl _x;
    _ctrl sliderSetRange [0, 1];
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
_pidDummy_1 setUnitPos "UP";
//Create a second unit.
private _pidDummy_2 = _classDummy2 createVehicle _pos;
TRACE_1("_pidDummy_2",_pidDummy_2);
GVAR(DummyUnits) pushBack _pidDummy_2;
_pidDummy_2 enableSimulation false;
_pidDummy_2 setUnitPos "UP";
//Create a third unit.
private _pidDummy_3 = _classDummy3 createVehicle _pos;
TRACE_1("_pidDummy_3",_pidDummy_3);
GVAR(DummyUnits) pushBack _pidDummy_3;
_pidDummy_3 enableSimulation false;
_pidDummy_3 setUnitPos "UP";

[] call FUNC(updatePositionPID);

private _dir = getDir ACE_PLAYER;
private _dirD1 = _dir - 180;

{
_x setDir _dirD1;
} forEach [_pidDummy_1,_pidDummy_2,_pidDummy_3];



//(QGVAR(LoadoutPID) call BIS_fnc_rscLayer) cutRsc [QGVAR(LoadoutPID), "PLAIN", 0, false];



/*

=======================================================================================================

_class = "B_officer_F";
_pos = getPos player;
//Create a unit.
vic0 = createVehicle [_class,_pos];
vic0 enableSimulation false;
//Create a second unit.
vic1 = createVehicle [_class,_pos];
vic1 enableSimulation false;
//Create a second unit.
vic2 = createVehicle [_class,_pos];
vic2 enableSimulation false;


onEachFrame{
private _disBetween = 2; // Distance between the two units.
private _unit = player;
private _posUnit = getPos _unit;
private _beg = eyePos _unit; // Eye position of the player.
private _end = (_beg vectorAdd (getCameraViewDirection _unit vectorMultiply 1000)); // Draw a line 1000 units long from the camera of the player.
private _dir = getDir _unit;
private _ins = terrainIntersectAtASL [_beg, _end]; // Get the position on the terrain where the line from the players camera intersects with the terrain.
vic0 setPosASLW _ins; // Set the position of vic0 as the intersect point.

// This section uses vector math to set the direction of the vic0 unit to mirror that of the player.
private _v_unit = vectorDir _unit;
private _v_vicUnit = vectorDir vic0;
private _v_diff = _v_vicUnit vectorDiff _v_unit;
vic0 setVectorDir _v_diff;

// Find some way to move the second unit to be a set distance (_disBetween) way from vic0, on a line perpendicular to the line of the player view.

private _newEnd = vic0 modelToWorldWorld [_disBetween,0,0];
vic1 setPosASLW _newEnd;
private _v_unit = vectorDir _unit;
private _v_vicUnit = vectorDir vic1;
private _v_diff = _v_vicUnit vectorDiff _v_unit;
vic1 setVectorDir _v_diff;

private _newEnd = vic0 modelToWorldWorld [-(_disBetween),0,0];
vic2 setPosASLW _newEnd;
private _v_unit = vectorDir _unit;
private _v_vicUnit = vectorDir vic2;
private _v_diff = _v_vicUnit vectorDiff _v_unit;
vic2 setVectorDir _v_diff;
_disStr = str (round (_unit distance vic0));

drawIcon3D ["", [1,0,0,0.50], ASLToAGL _ins, 1, 1, 45, _disStr, 1, 0.1, "TahomaB"];

}

*/
