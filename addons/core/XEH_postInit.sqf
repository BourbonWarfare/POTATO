#include "script_component.hpp"

["potato_adminMsg", {
    params ["_msg", ["_from", "?"], ["_to", ""]];
    if ((_to == profileName) || {_to == "#ALL"} || {(GVAR(showNotifcations)) && {[] call FUNC(isAuthorized)}}) then {
        systemChat format ["POTATO [%1>%2]: %3", _from, _to, _msg];
    };
    if (isServer) then {
        diag_log text format ["[POTATO] potato_adminMsg EH: %1", _this];
    };
}] call ace_common_fnc_addEventHandler;

if (hasInterface && {alive player}) then {
    _test = [player] call FUNC(isAuthorized);
    diag_log text format ["[POTATO]: Player [%1]: Auth Test: %2 ", player, _test];
};
