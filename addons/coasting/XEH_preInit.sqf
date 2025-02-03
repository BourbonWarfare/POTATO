#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

GVAR(EK_EH) = -2;
GVAR(EK_EH_ACE) = -1;

[
	QGVAR(enabled), "CHECKBOX",
	["Enable vehicle coasting", "Vehicles will continue to drive after the driver dies instead of immediately stopping"],
	["LMD Mods", "Features"],
	[false, true, false, 0] // [min, max, default, trailing decimals]
] call CBA_fnc_addSetting;

#ifdef DEBUG_MODE_FULL
#endif

ADDON = true;
