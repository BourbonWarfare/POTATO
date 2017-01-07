#include "script_component.hpp"

if (GVAR(enabled)) then {
    GVAR(group) = createGroup sideLogic;
    publicVariable QGVAR(group);
    GVAR(group) createUnit [QGVAR(holder), ZERO_POS, [], 200, "NONE"];

    diag_log format ["[POTATO-spectate] Spectate group: %1", GVAR(group)];
};
