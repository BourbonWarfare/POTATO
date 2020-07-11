/*
 * Author: BadWolf
 * Function called to populate the side arrays for each side. Will the default display the infromation for west.
 *
 * Arguments:
 * 0: side <INTERGER>
 *
 * Examples:
 * [0] call potato_missionTesting_fnc_weaponsReport;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_menu"];

GVAR(menus) = [
    ["Mission Report"]
    ,["Mission Testing"]
];

[_menu,"missionTesting",GVAR(menus)] call EFUNC(menu,mainMenu);

{
private _ctrl = MENU_DISPLAY displayCtrl (3000 + _menu);

}

_ctrl ctrlAddEventHandler ["SetFocus",{private _idc = _this select 0;private _index = (ctrlIDC _idc) - 3000 ;[_index] call EFUNC(,_activeFunction)}];
