#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

if (isServer) then {
    missionNameSpace setVariable [QGVAR(aiTransfered), false, true];
};

ADDON = true;
