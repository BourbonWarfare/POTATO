#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

GVAR(brief_addCredits) = false;
GVAR(brief_addOrbat) = false;

ADDON = true;
