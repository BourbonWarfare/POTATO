#include "script_component.hpp"

if (GVAR(enabled)) then {
    GVAR(group) = createGroup sideLogic;
    publicVariable QGVAR(group);
    GVAR(holderUnit) = GVAR(group) createUnit [QGVAR(holder), ZERO_POS, [], 200, "NONE"];
    GVAR(holderUnit) setVariable [QACEGVAR(zeus,addObject), false, true];
    diag_log format ["[POTATO-spectate] Spectate group: %1, spectate unit: %2", GVAR(group), GVAR(holderUnit)];

    // delete old spectator units
    addMissionEventHandler ["HandleDisconnect", {
        if ((_this select 0) isKindOf QGVAR(spectator)) then { deleteVehicle (_this select 0); };
    }];
};
