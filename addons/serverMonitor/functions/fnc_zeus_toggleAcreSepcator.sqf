#include "script_component.hpp"

TRACE_1("zeus_toggleAcreSepcator",_this);

if (isNil "ACRE_IS_SPECTATOR") exitWith { ERROR("ACRE_IS_SPECTATOR undefined"); };

[!ACRE_IS_SPECTATOR] call acre_api_fnc_setSpectator;
