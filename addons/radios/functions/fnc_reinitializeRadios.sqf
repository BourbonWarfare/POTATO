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
    if ((getNumber (configFile >> "CfgWeapons" >> _x >> "acre_isUnique")) > 0) then {
        private _newBase = getText (configFile >> "CfgWeapons" >> _x >> "acre_baseClass");
        _radios pushBack [_x, _newBase];
    };
} forEach (items ACE_player);

TRACE_1("replacing",_radios);

_radios spawn {
    {
        _x params ["_oldRadio"];
        ACE_player removeItem _oldRadio;
        sleep 0.25;
    } forEach _this;

    sleep 1;
    systemChat "Removed Old Radios";

    [ace_player] call FUNC(setupPlayer);

    waitUntil {GVAR(initState) == 4};
    systemChat "Setup Run";

    {
        _x params ["_oldRadio", "_newRadio"];
        ACE_player addItem _newRadio;
        sleep 0.25;
    } forEach _this;

    sleep 1;
    systemChat "Added New Radios";

    [] call FUNC(configureRadios);

    systemChat "Configured New Radios";
};
