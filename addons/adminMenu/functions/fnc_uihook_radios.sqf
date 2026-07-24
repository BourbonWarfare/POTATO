#include "script_component.hpp"
/*
* Author: Lambda.Tiger
* This calls events to reset or set different radio modes
*
* Arguments:
* 0: New mode to be set
* 1: The control of the button
*
* Return Value:
* None
*
* Examples:
* [] call potato_adminMenu_fnc_uihook_radios;
*
* Public: No
*/
params [["_radioValue", -1, [-1]], ["_ctrl", controlNull, [controlNull]]];

if (isNil QGVAR(radioHoldOff)) exitWith {
    GVAR(radioHoldOff) = [CBA_missionTime + 3, _radioValue];
    private _mode = switch (_radioValue) do {
        case POTATO_RADIO_RESET_TO_DEFAULT: {"restore default radio sim"};
        case POTATO_RADIO_ACRE_ONLY_343: {"switch all but 343 to SQF sim"};
        case POTATO_RADIO_INGAME_ONLY_343: {"switch all to force connection and 343 to SQF sim"};
        case POTATO_RADIO_SWITCH_ARCADE_MODE: {"switch to arcade mode"};
        case POTATO_RADIO_END_RADIO_SIM: {"nuke radios to always work"};
        default {"Err"};
    };
    ["potato_adminMsg", [format ["[RADIO] Preparing to change radio mode to [%1].", _mode], profileName]] call CBA_fnc_globalEvent;
    // Sometimes people need to hit the "fix radio" button and they don't
    hint "You are about to change radio mode, make sure you've tried fixing the radios before reseting simulation";
    _ctrl ctrlSetText format ["Press again in three (3) seconds to %1", _mode];
};
if (10 + GVAR(radioHoldOff)#0 < CBA_missionTime) exitWith {
    GVAR(radioHoldOff) = nil;
};
if (GVAR(radioHoldOff)#0 > CBA_missionTime || GVAR(radioHoldOff)#1 != _radioValue) exitWith {};
GVAR(radioHoldOff) = nil;
_ctrl ctrlSetText "Running";
switch (_radioValue) do {
    case POTATO_RADIO_RESET_TO_DEFAULT: {
        ["potato_adminMsg", ["[RADIO] Resetting ACRE to initial simulation", profileName]] call CBA_fnc_globalEvent;
        [QGVAR(changeRadioSim), _radioValue, QGVAR(radioSimJIPID)] call CBA_fnc_globalEventJIP;
        ["acre_sys_signal_signalModel", 2, 2, "server"] remoteExecCall ["CBA_settings_fnc_set", SERVER_CLIENT_ID]; // reset to LOS Multipath
    };
    case POTATO_RADIO_ACRE_ONLY_343: {
        ["potato_adminMsg", ["[RADIO] Setting all but 343 to SQF sim", profileName]] call CBA_fnc_globalEvent;
        [QGVAR(changeRadioSim), _radioValue, QGVAR(radioSimJIPID)] call CBA_fnc_globalEventJIP;
    };
    case POTATO_RADIO_SWITCH_ARCADE_MODE: {
        ["potato_adminMsg", ["[RADIO] Changing setting to arcade mode", profileName]] call CBA_fnc_globalEvent;
        ["acre_sys_signal_signalModel", 0, 20, "server"] remoteExecCall ["CBA_settings_fnc_set", SERVER_CLIENT_ID]; // Set to Arcade mode
    };
    case POTATO_RADIO_INGAME_ONLY_343: {
        ["potato_adminMsg", ["[RADIO] Disabling sim for all but 343 using SQF sim", profileName]] call CBA_fnc_globalEvent;
        [QGVAR(changeRadioSim), _radioValue, QGVAR(radioSimJIPID)] call CBA_fnc_globalEventJIP;
    };
    case POTATO_RADIO_END_RADIO_SIM: {
        ["potato_adminMsg", ["[RADIO] Killing radio simulation", profileName]] call CBA_fnc_globalEvent;
        [QGVAR(changeRadioSim), _radioValue, QGVAR(radioSimJIPID)] call CBA_fnc_globalEventJIP;

    };
};
