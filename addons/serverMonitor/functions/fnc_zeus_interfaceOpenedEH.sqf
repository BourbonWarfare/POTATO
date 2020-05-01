#include "script_component.hpp"

params ["_display"];
TRACE_1("zeus_InterfaceOpenedEH",_display);

private _fnc_updateInfo = {
    params ["_display"];

    private _nextUpdate = _display getVariable [QGVAR(nextUpdate), -1];
    if (diag_tickTime < _nextUpdate) exitWith {};
    _display setVariable [QGVAR(nextUpdate), diag_tickTime + 5];

    TRACE_1("zeus update tick",diag_tickTime);

    // Update ACRE Spectator Button Color
    if (missionNamespace getVariable ["ACRE_IS_SPECTATOR", false]) then {
        (_display displayCtrl 777550) ctrlSetTextColor [0,1,0,1];
    } else {
        (_display displayCtrl 777550) ctrlSetTextColor [1,1,1,1];
    };

    // Update AI count
    private _aiCount = {!isPlayer _x} count allUnits;
    (_display displayCtrl 777551) ctrlSetText format ["AI: %1", _aiCount];

    private _monitorTextAry = [];
    _monitorTextAry pushBack format ["Elapsed: %1", ([(time / 3600)] call BIS_fnc_timeToString)];
    _monitorTextAry pushBack format ["Client [Units: %1] [FPS: %2]", {local _x} count allUnits, diag_fps toFixed 0];

    if (!isNil QEGVAR(serverMonitor,0)) then {
        _monitorTextAry pushBack format (["Server [Units: %1] [FPS: %2/%3]"] + (EGVAR(serverMonitor,0) apply {_x toFixed 0}));
    };
    if (!isNil QEGVAR(serverMonitor,1)) then {
        _monitorTextAry pushBack format (["HC [Units: %1] [FPS: %2/%3]"] + (EGVAR(serverMonitor,1) apply {_x toFixed 0}));
    };
    if (!isNil QEGVAR(serverMonitor,2)) then {
        _monitorTextAry pushBack format (["HC2 [Units: %1] [FPS: %2/%3]"] + (EGVAR(serverMonitor,2) apply {_x toFixed 0}));
    };
    (_display displayCtrl 777551) ctrlSetTooltip (_monitorTextAry joinString "\n");
};



_display displayAddEventHandler ["MouseMoving", _fnc_updateInfo];
_display displayAddEventHandler ["MouseHolding", _fnc_updateInfo];
