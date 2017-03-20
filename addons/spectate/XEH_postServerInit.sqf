#include "script_component.hpp"

if (GVAR(enabled)) then {
    // delete old spectator units
    addMissionEventHandler ["HandleDisconnect", {
        if ((_this select 0) isKindOf QGVAR(spectator)) then { deleteVehicle (_this select 0); };
    }];

    [
        {
            missionNamespace getVariable [QEGVAR(miscFixes,groupCleanupRan), false] || diag_tickTime > (_this select 0)
        },
        {
            GVAR(group) = createGroup [sideLogic, false]; // explicitly mark for persistence
            publicVariable QGVAR(group);
            GVAR(holderUnit) = GVAR(group) createUnit [QGVAR(holder), ZERO_POS, [], 200, "NONE"];
            GVAR(holderUnit) setVariable [QACEGVAR(zeus,addObject), false, true];
            diag_log format ["[POTATO-spectate] Spectate group: %1, spectate unit: %2", GVAR(group), GVAR(holderUnit)];
        },
        [diag_tickTime + 5]
    ] call CBA_fnc_waitUntilAndExecute;
};
