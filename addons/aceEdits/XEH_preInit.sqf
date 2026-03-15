#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;
["CBA_settingsInitialized", {
    [{ACEGVAR(medical,const_stableVitalsBloodThreshold) = 4.5;}, 0, 1
    ] call CBA_fnc_waitAndExecute;
}]  call CBA_fnc_addEventHandler;

ADDON = true;
