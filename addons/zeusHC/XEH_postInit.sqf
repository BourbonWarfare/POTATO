#include "script_component.hpp"

if (isServer) then {
    [false] spawn COMPILE_FILE(functions\fnc_transferGroupsToHC);
};

if (hasInterface) then {
    ["zen_curatorDisplayLoaded", LINKFUNC(autoModule_setup)] call CBA_fnc_addEventHandler;
    // ["zen_editor_treesLoaded", { diag_log text "zen_editor_treesLoaded"; }] call CBA_fnc_addEventHandler; // next vers
};
