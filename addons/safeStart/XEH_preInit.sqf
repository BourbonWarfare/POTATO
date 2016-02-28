#include "script_component.hpp"

ADDON = false;

PREP(handleFired);
PREP(makeSafe);
PREP(showTimer);

//We Start game safe at preInit
GVAR(safeStartEnabled) = true;
PABST_fnc_safeStart = {
    diag_log text format ["[POTATO] Deprecated call to PABST_fnc_safeStart"];
    [] call FUNC(makeSafe);
};
if (isServer) then {
    missionNamespace setVariable ["PABST_ADMIN_SAFESTART_public_isSafe", true, true];
};

ADDON = true;
