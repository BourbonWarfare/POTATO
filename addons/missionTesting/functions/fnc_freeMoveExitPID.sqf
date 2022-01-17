/*
 * Author: BadWolf
 *
 *
 * Arguments:
 *
 * Examples:
 * [] spawn potato_missionTesting_fnc_runWeaponsTest;
 *
 * Public: No
 */

#include "\a3\ui_f\hpp\definedikcodes.inc"
#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_ctrl","_button","_BtnShift","_BtnCtrl","_BtnAlt"];

private _buttonDisabled = false; // true: block the original comand, false: Execute the normal command of that button
private _blockInput = { _ButtonDisabled = true; };


if (_button isEqualTo DIK_T) then {

	if (_BtnCtrl) then
	{
        systemChat "CTRL+T pressed Deleting RscTitle and Opening old dialogs";
        [] call FUNC(displayMenu);
        [] call FUNC(pidTesting);
        [] call FUNC(returnValuesPID);
	};
};
