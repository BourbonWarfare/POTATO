#include "script_component.hpp"

TRACE_1("zeus_toggleAcreSepcator",_this);

if (isNil "ACRE_IS_SPECTATOR") exitWith { ERROR("ACRE_IS_SPECTATOR undefined"); };

if (ACRE_IS_SPECTATOR) then {
    ACRE_SPECTATOR_RADIOS = ace_player getVariable [QGVAR(specRadios), []];
    [false] call acre_api_fnc_setSpectator;
} else {
    ace_player setVariable [QGVAR(specRadios), ACRE_SPECTATOR_RADIOS];
    ACRE_SPECTATOR_RADIOS = [] call acre_sys_data_fnc_getPlayerRadioList;
    [true] call acre_api_fnc_setSpectator;
};
