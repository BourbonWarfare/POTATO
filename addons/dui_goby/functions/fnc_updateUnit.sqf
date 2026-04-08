#include "..\script_component.hpp"
/*
 * Author: PabstMirror
 * Update external unit's nametag info variable when they change their goBy variable or when safe start toggles
 *
 * Arguments:
 * 0: unit to update or true to update all units <OBJECT><BOOL>
 */
params [["_unit", objNull, [true, objNull]]];

if (_unit isEqualTo true) exitWith {
    TRACE_1("updating all units",(GVAR(show)));
    {
        _x call FUNC(updateUnit);
    } forEach allUnits;
};

if ((isNull _unit) || {GVAR(show) == 0} || {GVAR(show) == 1 && {!EGVAR(safeStart,safeStartEnabled)}}) exitWith {
    TRACE_2("disabled-cleanup",GVAR(show),_unit);
    _unit setVariable ["diwako_dui_nametags_customInfo", nil];
};

private _goby = _unit getVariable [QGVAR(goBy), ""];
TRACE_2("updateUnit",_unit,_goby);
if (_goby == "") exitWith {
    _unit setVariable ["diwako_dui_nametags_customInfo", nil];
};

_unit setVariable ["diwako_dui_nametags_customInfo", _goby];
