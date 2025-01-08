#include "script_component.hpp"

if (isServer && isMultiplayer) then {
    [QGVAR(ZeusFPSMonitorUpdate), LINKFUNC(handleZeusFPSRequest)] call CBA_fnc_addEventHandler;
    GVAR(serverUpdateFPSEH) = [{
        {
            _x publicVariableClient QGVAR(playerFPSCache);
        } forEach GVAR(clientsTrackingFPS);
    }, 3] call CBA_fnc_addPerFrameHandler;

};

if !(hasInterface) exitWith {};
["CBA_SettingsInitialized", {
    TRACE_4("CBA_SettingsInitialized EH Client",_this,GVAR(fpsDisplayEH),GVAR(fpsAvgCalcEH),GVAR(fpsAvgCalc));
    if (isMultiplayer) then {
        [] call FUNC(initLocalFPSEH);
    };
}] call CBA_fnc_addEventHandler;
