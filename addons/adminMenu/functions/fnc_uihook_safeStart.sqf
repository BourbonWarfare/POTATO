#include "script_component.hpp"

params ["_newSetting"];
TRACE_1("params",_this);

[_newSetting] remoteExecCall [QEFUNC(safeStart,toggleSafeStart), 2];

if (!_newSetting) then {
    [QGVAR(sync_checkbox), [IDC_CHECKBOX_SAFESTARTSAFETY, 0, false]] call CBA_fnc_globalEventJIP;
};

[
    "potato_adminMsg",
    [
        ["Turning off SafeStart", "Turning on SafeStart"] select _newSetting,
        profileName
    ]
] call CBA_fnc_globalEvent;
