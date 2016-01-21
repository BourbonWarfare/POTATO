#include "script_component.hpp"

TRACE_1("params",_this);

disableSerialization;

_chatList = (findDisplay 49) displayCtrl 840431;
_replyButton = (findDisplay 49) displayCtrl 840432;

if (!ctrlShown _chatList) exitWith {};

_index = lbCurSel _chatList;
if (_index < 0) exitWith {};
_lbText = _chatList lbText _index;

TRACE_2("",_index,_lbText);

if (_lbText == "") exitWith {};
if (_index >= (count GVAR(logs))) exitWith {};

_msgUser = (GVAR(logs) select _index) select 2;

TRACE_1("user", _msgUser);
_replyButton ctrlSetText format ["Reply: %1", _msgUser];
