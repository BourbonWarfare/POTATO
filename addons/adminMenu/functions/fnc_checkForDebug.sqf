#include "script_component.hpp"

#define DEBUG_CTRL (((_this select 1) select 0) displayctrl 13184)

private _debug = getMissionConfigValue ["enableDebugConsole", 0];

// if you don't have access to the console, but you're an admin, add it
if (!(_debug == 2 || (_debug == 1 && (isServer || serverCommandAvailable "#shutdown")))
        && [] call CFUNC(isAuthorized)) then {

    DEBUG_CTRL ctrlshow true;
    DEBUG_CTRL ctrlenable true;
    private _allowDebugConsole = true;
    #include "\a3\ui_f\scripts\GUI\RscDebugConsole.sqf";
};
