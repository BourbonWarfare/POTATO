#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

GVAR(fpsDisplayEH) = -1;
diag_log formatText ["InitFPS DISPLAY EH %1", GVAR(fpsDisplayEH)];
#include "initSettings.inc.sqf"

ADDON = true;
