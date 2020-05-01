#include "script_component.hpp"

params ["_group", "_prioity", "_message", "_showFor", "_icon", "_iconColor"];
TRACE_6("groupReport",_group,_prioity,_message,_showFor,_icon,_iconColor);

// Show chat message:
if (_message != "") then {
    private _lastChatMsg = _group getVariable [QGVAR(lastChatMsg), -999];
    if (CBA_missionTime > (_lastChatMsg + 30)) then {
        systemChat format ["%1: %2", groupID _group, _message];
        _group setVariable [QGVAR(lastChatMsg), CBA_missionTime];
    };
};

// Update Icon:
if (_showFor > 0) then {
    private _keepUntil = CBA_missionTime + _showFor;
    private _needToAdd = true;
    {
        _x params ["_xGroup", "_xKeepUntil", "_xPrioity", "_xIcon", "_xIconColor"];
        if (_group == _xGroup) exitWith {
            if (_prioity >= _xPrioity) then {
                TRACE_1("Removing old report with lower/equal prioity",_x);
                GVAR(friendlyReports) deleteAt _forEachIndex;
            } else {
                _needToAdd = false;
            };
        };
    } forEach GVAR(friendlyReports);
    if (_needToAdd) then {
        TRACE_5("Adding new report",_group,_keepUntil,_prioity,_icon,_iconColor);
        GVAR(friendlyReports) pushBack [_group, _keepUntil, _prioity, _icon, _iconColor];
    };
};
