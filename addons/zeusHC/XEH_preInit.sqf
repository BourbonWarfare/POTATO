#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

if (isServer) then {
    missionNameSpace setVariable [QGVAR(aiTransfered), false, true];
};

ADDON = true;
