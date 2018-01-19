//potato_adminComs_fnc_mouseCatch

#include "script_component.hpp"
TRACE_1("params",_this);

disableSerialization;
params ["_display"];

private _chatList = _display displayCtrl 840431;
private _replyButton = _display displayCtrl 840432;

if (!([] call EFUNC(core,isAuthorized))) exitWith {
    _chatList ctrlShow false;
    _chatList ctrlEnable false;
    _replyButton ctrlShow false;
    _replyButton ctrlEnable false;
};

_chatList ctrlShow true;
_chatList ctrlEnable true;
_replyButton ctrlShow true;
_replyButton ctrlEnable true;

lbClear _chatList;

private _index = -1;
{
    _x params ["_time", "_msg", "_from", "_to"];
    TRACE_1("log:",_x);

    private _log = format [
        "%1:%2 [%3>%4] %5",
        [floor (_time / 60)] call CFUNC(zeroPadNumber),
        [floor (_time % 60)] call CFUNC(zeroPadNumber),
        _from,
        _to,
        _msg
    ];

    _index = _chatList lbAdd _log;
    _chatList lbSetTooltip [_index, _msg];
} forEach GVAR(logs);

if (_index != -1) then {
    _chatList lbSetCurSel _index;
};

_replyButton ctrlSetText "Reply: ";
