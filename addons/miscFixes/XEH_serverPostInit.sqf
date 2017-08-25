// Can eventually remove if this shows no problems
#include "script_component.hpp"

// clean up empty groups
{
    if ((units _x) isEqualTo []) then {
        TRACE_2("Deleting Empty Group",_x,groupID _x);
        deleteGroup _x;
    };
} forEach allGroups;

missionNamespace setVariable [QGVAR(groupCleanupRan), true, true];
