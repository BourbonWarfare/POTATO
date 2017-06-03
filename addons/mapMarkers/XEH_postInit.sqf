#include "script_component.hpp"

// Load configurations from the missions config file
[missionConfigFile] call FUNC(loadFromConfigFile);

// Start drawCache update using the provided updateInterval
[{[] call FUNC(updateMarkerDrawCache)}, GVAR(updateInterval), []] call CBA_fnc_addPerFrameHandler;
[] call FUNC(updateMarkerDrawCache);

// Start groupMemberDrawCache update
[{[] call FUNC(updateGroupMemberDrawCache)}, 0, []] call CBA_fnc_addPerFrameHandler;

// Wait for briefing or skipped briefing
[
    {(!isNull findDisplay IDD_INTEL_GETREADY) || (!isNull findDisplay IDD_SERVER_GET_READY) || (!isNull findDisplay IDD_CLIENT_GET_READY) || (!isNull findDisplay IDD_MAIN_MAP)},
    {
        if (!isNull findDisplay IDD_MAIN_MAP) exitWith {};

        {
            private _display = findDisplay _x;
            if (!isNull _display) then {
                (_display displayCtrl IDC_MAP) ctrlAddEventHandler ["draw", {_this call FUNC(drawMap)}];
            };
            nil
        } count [IDD_INTEL_GETREADY, IDD_SERVER_GET_READY, IDD_CLIENT_GET_READY];
    },
    []
] call ACEFUNC(common,waitUntilAndExecute);

// Wait for ingame map to be available
[
    {!isNull findDisplay IDD_MAIN_MAP},
    {
        ((findDisplay IDD_MAIN_MAP) displayCtrl IDC_MAP) ctrlAddEventHandler ["draw", {_this call FUNC(drawMap)}];
    },
    []
] call ACEFUNC(common,waitUntilAndExecute);

// Wait for minimap resource to be loaded
[
    {!isNull (uiNamespace getVariable "RscMiniMap")},
    {
        ((uiNamespace getVariable "RscMiniMap") displayctrl 101) ctrlAddEventHandler ["draw", {_this call FUNC(drawMap)}];
    },
    []
] call ACEFUNC(common,waitUntilAndExecute);

// Add renderhook into ACE microDAGR
if (!isNil QACEGVAR(microDAGR,miniMapDrawHandlers)) then {
    ACEGVAR(microDAGR,miniMapDrawHandlers) pushBack {_this call FUNC(drawMap)};
};
