//potato_adminMenu_fnc_openAdminMenu

#include "script_component.hpp"
TRACE_1("params",_this);

disableSerialization;

if (!([] call EFUNC(core,isAuthorized))) exitWith {
    systemChat "Not Authorized";
};

closeDialog 0;
createDialog QGVAR(adminMenuDialog);


{
    UI_TAB_LISTBOX lbAdd _x;
} forEach UI_TABS_NAMES;
{
    _x ctrlShow false;
} forEach UI_TABS_CONTROLS;

[{
    if (isNull (uiNamespace getVariable [QGVAR(adminMenuDialog), displayNull])) exitWith {
        [_this select 1] call CBA_fnc_removePerFrameHandler;
    };

    //[_cps, diag_fps, _localUnits];
    _monitorTextAry = ["<t size='0.9'>"];
    _monitorTextAry pushBack format ["Elapsed: %1<br/>", ([(time / 3600)] call BIS_fnc_timeToString)];
    _monitorTextAry pushBack format ["Client FPS: %1<br/>", floor diag_fps];

    if (!isNil QEGVAR(serverMonitor,0)) then {
        _monitorTextAry pushBack format ["<br/><t underline='true'>Server:</t><br/>"];
        _monitorTextAry pushBack format ["-Local Units: %1<br/>",     floor (EGVAR(serverMonitor,0) select 0)];
        _monitorTextAry pushBack format ["-FPS: %1<br/>",             floor (EGVAR(serverMonitor,0) select 1)];
        _monitorTextAry pushBack format ["-CPS: %1<br/>",             floor (EGVAR(serverMonitor,0) select 2)];
    };
    if (!isNil QEGVAR(serverMonitor,1)) then {
        _monitorTextAry pushBack format ["<br/><t underline='true'>HC 1:</t><br/>"];
        _monitorTextAry pushBack format ["-Local Units: %1<br/>",     floor (EGVAR(serverMonitor,1) select 0)];
        _monitorTextAry pushBack format ["-FPS: %1<br/>",             floor (EGVAR(serverMonitor,1) select 1)];
        _monitorTextAry pushBack format ["-CPS: %1<br/>",             floor (EGVAR(serverMonitor,1) select 2)];
    };
    if (!isNil QEGVAR(serverMonitor,2)) then {
        _monitorTextAry pushBack format ["<br/><t underline='true'>HC 2:</t><br/>"];
        _monitorTextAry pushBack format ["-Local Units: %1<br/>",     floor (EGVAR(serverMonitor,2) select 0)];
        _monitorTextAry pushBack format ["-FPS: %1<br/>",             floor (EGVAR(serverMonitor,2) select 1)];
        _monitorTextAry pushBack format ["-CPS: %1<br/>",             floor (EGVAR(serverMonitor,2) select 2)];
    };
    _monitorTextAry pushBack "</t>";
    UI_SERVER_MONITOR ctrlSetStructuredText parseText (_monitorTextAry joinString "");

}, 0.25, []] call CBA_fnc_addPerFrameHandler;
