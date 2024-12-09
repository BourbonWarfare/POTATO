#include "script_component.hpp"

if (isServer && isMultiplayer) then {
};

if !(hasInterface) exitWith {};
["CBA_SettingsInitialized", {
    TRACE_4("CBA_SettingsInitialized EH Client",_this,GVAR(fpsDisplayEH),GVAR(fpsAvgCalcEH),GVAR(fpsAvgCalc));
    if (isMultiplayer) then {
        [] call FUNC(initLocalFPSEH);
    };
}] call CBA_fnc_addEventHandler;
