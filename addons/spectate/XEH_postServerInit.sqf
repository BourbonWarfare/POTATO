#include "script_component.hpp"

if (GVAR(enabled)) then {
    // delete old spectator units
    addMissionEventHandler ["HandleDisconnect", {
        if ((_this select 0) isKindOf QGVAR(spectator)) then { deleteVehicle (_this select 0); };
    }];

    [
        {
            missionNamespace getVariable [QEGVAR(miscFixes,groupCleanupRan), false] || diag_tickTime > _this
        },
        {
            GVAR(group) = createGroup [sideLogic, false]; // explicitly mark for persistence
            GVAR(group) setGroupIdGlobal ["Spectator Group"];
            publicVariable QGVAR(group);
            GVAR(holderUnit) = GVAR(group) createUnit [QGVAR(holder), ZERO_POS, [], 200, "NONE"];
            GVAR(holderUnit) setVariable [QACEGVAR(zeus,addObject), false, true];
            GVAR(holderUnit) enableSimulationGlobal false;
            GVAR(holderUnit) hideObjectGlobal true;
            diag_log format ["[POTATO-spectate] Spectate group: %1, spectate unit: %2", GVAR(group), GVAR(holderUnit)];
        },
        diag_tickTime + 5
    ] call CBA_fnc_waitUntilAndExecute;

    // add spectator chat channel
    missionNamespace setVariable [
        QGVAR(channel),
        radioChannelCreate [[0.729,0.149,0.098,1], "Spectator", "Spectator (%UNIT_NAME)", []],
        true
    ];
} else {
    [{
        ["potato_adminMsg", ["Warning: Spectate/Respawn Disabled (This should never happen on a BWMF mission)", "Server"]] call CBA_fnc_globalEvent;
    }, [], 5] call CBA_fnc_waitAndExecute
};
