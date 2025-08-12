#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

#include "initSettings.inc.sqf"

if (isMultiplayer && isServer) then {
    [{getClientStateNumber > 9}, {
        [QGVAR(briefingEnd), CBA_missionTime] call CBA_fnc_globalEvent;
    }];
};

ADDON = true;
