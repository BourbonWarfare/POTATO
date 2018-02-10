#include "script_component.hpp"

TRACE_3("", missionNamespace getVariable QGVAR(enabled), hasInterface, EGVAR(assignGear,usePotato));

if (missionNamespace getVariable [QGVAR(enabled), false]) then {
    if !(missionNamespace getVariable [QEGVAR(assignGear,usePotato), false]) exitWith {
        ERROR("Radios enabled, but gear assign is not running");
    };

    // Make sure to create presets all machines;    from ACRE API:
    // Warning All presets must exist and match on all clients and especially the server; regardless of where the presets are used.
    // If you create a preset, copy a preset or modify a presets data information; these changes must occur on all clients and the server.
    // If they do not, ACRE may not work.
    [] call FUNC(initializeRadios);

    if (!hasInterface) exitWith {
        GVAR(initState) = 999;
        INFO_2("%1 - [InitState %2] DONE (Non Interface)", diag_frameNo, GVAR(initState));
    };

    ["unit", {_this call FUNC(setupPlayer)}, true] call CBA_fnc_addPlayerEventHandler;
} else {
    INFO("Disabled");
    if (isServer) then { // Warn if not enabled
        [{
            ["potato_adminMsg", ["Warning: Potato Radios Setting Disabled (This should never happen on a BWMF mission)", "Server"]] call CBA_fnc_globalEvent;
        }, [], 5] call CBA_fnc_waitAndExecute
    };
};

if (hasInterface) then {
    if (isServer) exitWith {}; // Non-Dedicated (probably just mission maker)
    [{
        if (acre_sys_core_ts3id < 0) then {
            QGVAR(cutText) cutText [format ["Check ACRE plugin is running and is version %1", getText (configFile >> "CfgPatches" >> "acre_main" >> "versionStr")], "PLAIN", 2];
        };
    }, [], 10] call CBA_fnc_waitAndExecute;
    [{
        INFO("~~~~~~~~~~~~~~ ACRE Debug ~~~~~~~~~~~~~~");
        INFO_1("[ACRE_MAP_LOADED: %1]",ACRE_MAP_LOADED);
        INFO_1("[ACRE_DATA_SYNCED: %1]",ACRE_DATA_SYNCED);
        INFO_1("[acre_sys_core_ts3id: %1]",acre_sys_core_ts3id);
        INFO_1("[ACRE_CORE_INIT: %1]",ACRE_CORE_INIT);
        INFO_1("[acre_player: %1]",acre_player);
        if (!ACRE_CORE_INIT) then {
            ace_player createDiaryRecord ["diary", ["ACRE ERROR", format ["~~~~~~~~~~~~~~ ACRE Debug ~~~~~~~~~~~~~~<br/>Map: %1<br/>Data: %2<br/>TSID: %3<br/>Core: %4", ACRE_MAP_LOADED, ACRE_DATA_SYNCED, acre_sys_core_ts3id, ACRE_CORE_INIT]]];
        };
    }, [], 20] call CBA_fnc_waitAndExecute;
};
