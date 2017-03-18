#include "script_component.hpp"

LOG("In Post init");

if (!hasInterface) exitWith {};

// disable STHUD menu, if it exists
if (isClass (configFile >> "CfgPatches" >> "ST_STHud_Usermenu")) then {
    LOG("ST Options mod found, waiting on function def");
    [
        {!(isNil "fn_sthud_usermenu_changeMode")},
        {
            LOG("ST Options function found, stubbing");
            fn_sthud_usermenu_changeMode = { WARNING("fn_sthud_usermenu_changeMode called, but ignored"); };
        }
    ] call CBA_fnc_waitUntilAndExecute
};

// wait for settings
["ace_settingsInitialized", {
    // set original value
    [
        {!isNil "STUI_Save_SupervisorH"},
        {
            ST_STHud_ShownUI = GVAR(stHudMode);
            ST_STHud_ShowCompass = GVAR(stHudCompass);
            [] call ST_STHud_UpdateUI;
        }
    ] call CBA_fnc_waitUntilAndExecute;


    // On changing settings, update the view
    ["ace_settingChanged", {
        TRACE_1("params", _this);
        params ["_name","_value"];

        if (_name == QGVAR(stHudMode)) exitWith {
            ST_STHud_ShownUI = _value;
            [] call ST_STHud_UpdateUI;
        };
        if (_name == QGVAR(stHudCompass)) exitWith {
            ST_STHud_ShowCompass = _value;
        };
    }] call CBA_fnc_addEventHandler;
}] call CBA_fnc_addEventHandler;
