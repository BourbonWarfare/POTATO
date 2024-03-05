
#include "script_component.hpp"
TRACE_1("params",_this);

disableSerialization;

if (!([] call EFUNC(core,isAuthorized))) exitWith {};

private _textBox = (findDisplay 49) displayCtrl 840430;
private _chatList = (findDisplay 49) displayCtrl 840431;
private _replyButton = (findDisplay 49) displayCtrl 840432;

if (!ctrlShown _chatList) exitWith {};

private _text = ctrlText _textBox;
_textBox ctrlSetText ""; //Best line ever written, thanks mike!

private _index = lbCurSel _chatList;
if (_index < 0) exitWith {};
private _lbText = _chatList lbText _index;

TRACE_2("",_index,_lbText);

if (_lbText == "") exitWith {};
if (_index >= (count GVAR(logs))) exitWith {};

private _msgUser = (GVAR(logs) select _index) select 2;

TRACE_1("user",_msgUser);

["potato_adminMsg", [_text, profileName, _msgUser]] call CBA_fnc_globalEvent;
