#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

#ifdef DEBUG_MODE_DRAW_EH
GVAR(dev_traceHash) = createHashMap;
#endif

GVAR(loopRunning) = false;
GVAR(activeVehicles) = createHashMap;

#ifdef DEBUG_MODE_FULL
#endif

ADDON = true;
