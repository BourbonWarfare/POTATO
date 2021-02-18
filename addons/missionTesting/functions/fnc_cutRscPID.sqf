/*
 * Author: BadWolf
 *
 *
 * Arguments:
 *
 * Examples:
 * [] call potato_missionTesting_fnc_runWeaponsTest;
 *
 * Public: No
 */

#include "\a3\ui_f\hpp\definedikcodes.inc"
#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_ctrl","_button","_BtnShift","_BtnCtrl","_BtnAlt"];

private _buttonDisabled = false; // true: block the original comand, false: Execute the normal command of that button
private _blockInput = { _ButtonDisabled = true; };

if (_button isEqualTo DIK_T) then // DIK_W = 17 = 0x11 = "W"
{
	// For now, button W is just registered, but won't block the original command for now (player can move forward).

	// If SHIFT is pressed, block "W" (walk forward) and show the systemchat message
	if (_BtnCtrl) then
	{
		systemChat "CTRL+T pressed";
        private _display = uiNamespace getVariable "RscTitleDisplayEmpty";
		call _blockInput; // call to disable the original command
	};
};

_buttonDisabled
