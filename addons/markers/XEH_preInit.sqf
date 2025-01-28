#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

#include "initSettings.inc.sqf"

GVAR(markerHash) = createHashMap;
GVAR(drawHash) = createHashMap;
GVAR(nextUpdate) = -9999;
GVAR(nextUpdateDrawHash) = -9999;
GVAR(settingsInitialized) = false;
GVAR(settingsDelayedFunctions) = [];
GVAR(autoclaimGroupMarker) = false;
[QGVAR(addMarker), LINKFUNC(addMarkerEvent)] call CBA_fnc_addEventHandler;
[QGVAR(deleteMarker), LINKFUNC(deleteMarkerEvent)] call CBA_fnc_addEventHandler;
[QGVAR(transferMarker), LINKFUNC(transferMarkerEvent)] call CBA_fnc_addEventHandler;
[QGVAR(updateMarker), LINKFUNC(updateMarkerEvent)] call CBA_fnc_addEventHandler;

ADDON = true;
