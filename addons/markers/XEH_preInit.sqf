#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

#include "initSettings.inc.sqf"

GVAR(markerHash) = createHashMap;
GVAR(drawHash) = createHashMap;
GVAR(markerPosSync) = createHashMap;
GVAR(nextUpdate) = -9999;
GVAR(nextUpdateDrawHash) = -MARKER_DRAW_HASH_REFRESH_TIME;
GVAR(settingsInitialized) = false;
GVAR(settingsDelayedFunctions) = [];
GVAR(autoclaimGroupMarker) = false;



if (isServer) then {
    missionNamespace setVariable [QGVAR(markerCache), true call CBA_fnc_createNamespace, true];
};

ADDON = true;
