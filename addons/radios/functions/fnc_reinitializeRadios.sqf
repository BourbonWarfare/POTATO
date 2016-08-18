/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

if (time < 1) exitWith {
    systemChat "Please wait until the mission has started to reinitialize your radios";
};

// remove/readd radios
private _radios = [];
{
    if (_x isKindOf [RADIO_SR, configFile >> "CfgWeapons"]
            || {_x isKindOf [RADIO_MR, configFile >> "CfgWeapons"]}
            || {_x isKindOf [RADIO_LR, configFile >> "CfgWeapons"]}) then {
        _radios pushBack _x;
    };
} forEach (items player);

TRACE_1("replacing",_radios);
_radios spawn {
    {
        player removeItem _x;
        sleep 0.5;
        player addItem _x;
        sleep 0.5;
    } forEach _this;

    [] call FUNC(configureRadios);
};
