#include "script_component.hpp"
/*
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call potato_adminComs_fnc_sendMessageToAdmin
 */
TRACE_1("params",_this);

disableSerialization;

private _textBox = (findDisplay 49) displayCtrl 840430;

private _text = ctrlText _textBox;
_textBox ctrlSetText ""; //Best line ever written, thanks mike!

if (_text == "") exitWith {systemChat "Input your msg";};

systemChat "Message Sent";

["potato_adminMsg", [_text, profileName]] call CBA_fnc_globalEvent;
