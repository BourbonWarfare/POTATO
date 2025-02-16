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

[
    QGVAR(enabled), "CHECKBOX",
    ["Enable vehicle coasting", "Vehicles will continue to drive after the driver dies instead of immediately stopping"],
    ["POTATO - Mission Maker", "Vehicle Coasting"],
    [false, true, false, 0] // [min, max, default, trailing decimals]
] call CBA_fnc_addSetting;

#ifdef DEBUG_MODE_FULL
#endif

ADDON = true;
