#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

GVAR(open) = false;
GVAR(activeGroups) = [];

if (isServer) then {
    GVAR(groupCount) = 1;
    [] spawn FUNC(readConfigToVariables);
};

ADDON = true;
