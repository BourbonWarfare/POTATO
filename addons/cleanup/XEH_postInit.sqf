#include "script_component.hpp"

if (isServer) then {
    [] call FUNC(cleanupEmptyGroups);
};


if (GVAR(deadCleanupEnabled)) then {
    if (hasInterface) then {
        ["unit", {_this#0 setVariable [QGVAR(wasPlayer), true, true]}, true] call CBA_fnc_addPlayerEventHandler;
    };

    if (isServer) then {
        GVAR(garbageToWatch) = [];
        GVAR(garbageToClean) = [];
        addMissionEventHandler ["EntityKilled", {_this call FUNC(handleKilled)}];
    };
};
