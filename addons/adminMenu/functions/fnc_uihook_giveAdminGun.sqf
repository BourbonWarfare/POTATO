#include "script_component.hpp"

TRACE_1("params",_this);

if ([ace_player, QEGVAR(adminGun,gun), false] call CBA_fnc_addItem) then {
    [ace_player, QEGVAR(adminGun,physics), false] call CBA_fnc_addItem;
};

