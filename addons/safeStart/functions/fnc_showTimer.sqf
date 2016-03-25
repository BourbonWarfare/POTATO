#include "script_component.hpp"

if (!isNil QGVAR(timerRunning)) exitWith {};
GVAR(timerRunning) = true;

[{
    disableSerialization;

    if (hasInterface) then {
        private _display = uiNamespace getVariable [QGVAR(safeStartRscTitle), displayNull];
        if (GVAR(showTimer) && {isNull _display}) then {
            TRACE_1("Creating display",GVAR(showTimer));
            (QGVAR(safeStartRscTitle) call BIS_fnc_rscLayer) cutRsc [QGVAR(safeStartRscTitle), "PLAIN", 1, false];
        };
        if ((!GVAR(showTimer)) && {!isNull _display}) then {
            TRACE_1("Hiding display",GVAR(showTimer));
            (QGVAR(safeStartRscTitle) call BIS_fnc_rscLayer) cutText ["", "PLAIN"];
        };
    };

    private _display = uiNamespace getVariable [QGVAR(safeStartRscTitle), displayNull];
    private _serverStartTimePV = missionNamespace getVariable [QGVAR(startTime_PV), -1];

    if (_serverStartTimePV != -1) then {
        if (!isNull _display) then {
            private _picture = "<img image='\A3\UI_F\data\IGUI\Cfg\Actions\settimer_ca.paa'/>";
            private _timeStr = [dayTime - _serverStartTimePV] call BIS_fnc_timeToString;
            (_display displayCtrl 1100) ctrlSetStructuredText parseText format ["<t align='center'>Safe Start Enabled<br/>%1 %2</t>", _picture, _timeStr];
        };
    } else {
        GVAR(timerRunning) = nil;
        GVAR(safeStartEnabled) = false;
        TRACE_2("Exiting Timer",GVAR(timerRunning),GVAR(safeStartEnabled));

        if (isServer) then { //backwards compatibilty
            missionNamespace setVariable ["PABST_ADMIN_SAFESTART_public_isSafe", false, true];
        };

        [_this select 1] call CBA_fnc_removePerFrameHandler;
        if (!isNull _display) then {
            (_display displayCtrl 1100) ctrlSetStructuredText parseText format ["<t align='center'>Safe Start Ending<br/><t color='#ff0000'>Start Mission</t></t>"];
            [{
                (QGVAR(safeStartRscTitle) call BIS_fnc_rscLayer) cutText ["", "PLAIN"];
            }, [], 7] call ace_common_fnc_waitAndExecute;
        };
    };
}, 0.2, []] call CBA_fnc_addPerFrameHandler;
