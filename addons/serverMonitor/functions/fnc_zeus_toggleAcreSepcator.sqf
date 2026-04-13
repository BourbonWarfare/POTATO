#include "script_component.hpp"

TRACE_1("zeus_toggleAcreSepcator",_this);

if (isNil "ACRE_IS_SPECTATOR") exitWith { ERROR("ACRE_IS_SPECTATOR undefined"); };

if (ACRE_IS_SPECTATOR) then {
    ACRE_SPECTATOR_RADIOS = ace_player getVariable [QGVAR(specRadios), []];
    [false] call acre_api_fnc_setSpectator;
} else {
    ace_player setVariable [QGVAR(specRadios), ACRE_SPECTATOR_RADIOS];
    private _weapons = [ace_player] call acre_sys_core_fnc_getGear;
    private _radioList = _weapons select {_x call acre_sys_radio_fnc_isUniqueRadio && {!(_x call acre_sys_external_fnc_isExternalRadioUsed)}};
    if (ACRE_ACTIVE_RADIO != "") then {
        _radioList pushBackUnique ACRE_ACTIVE_RADIO;
    };
    _radioList append ACRE_EXTERNALLY_USED_PERSONAL_RADIOS;
    _radioList append ACRE_EXTERNALLY_USED_MANPACK_RADIOS;
    _radioList append ACRE_ACTIVE_EXTERNAL_RADIOS;
    _radioList append ACRE_HEARABLE_RACK_RADIOS;
    _radioList append ACRE_ACCESSIBLE_RACK_RADIOS;
    {
        ACRE_SPECTATOR_RADIOS pushBackUnique _x
    } forEach _radioList;
    [true] call acre_api_fnc_setSpectator;
};
