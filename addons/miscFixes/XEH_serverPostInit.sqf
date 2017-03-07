#include "script_component.hpp"

// clean up empty groups
{
    if ((units _x) isEqualTo []) then {
        deleteGroup _x;
    };
} forEach allGroups;

missionNamespace setVariable [QGVAR(groupCleanupRan), true, true];
