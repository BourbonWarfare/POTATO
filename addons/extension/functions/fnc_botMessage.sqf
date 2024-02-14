/*
 * Author: BadWolf
 * Function used to send a message to the discord bots
 *
 * Arguments:
 * 0: message type - string
 * 1: target channel - string
 * 2: message - string
 * 3: title - string (optional)
 *
 * Examples:
 * ["message", "staff", "A message"] call potato_extension_fnc_botMessage;
 * ["embed", "arma", "Embed Body", "Embed Title"] call potato_extension_fnc_botMessage;
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_type", "_channel", "_message", ["_title",""]];

if (_type == "message") then {
    _title = "";
};

if (_type == "embed" && isNil "_title") then {
    _title = "Potato Server";
};

private _return = "potato_extension" callExtension ["message:bot_message", [_type, _channel, _message, _title]];

TRACE_1("Return",_return);
