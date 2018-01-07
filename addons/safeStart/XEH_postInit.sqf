#define DEBUG_MODE_FULL
#include "script_component.hpp"

if (isServer) then {
    // TODO: BWC, remove this a while after
    if (isClass (missionConfigFile >> "ACE_Settings" >> QGVAR(enabled))) then {
        [QGVAR(enabled), getNumber (missionConfigFile >> "ACE_Settings" >> QGVAR(enabled) >> "value") == 1, 2, "mission"] call CBA_settings_fnc_set;
    };

    [
        {time > 0},
        { [GVAR(enabled)] call FUNC(toggleSafeStart); }
    ] call CBA_fnc_waitUntilAndExecute;
};

if (didJip) then {
    [
        {time > 1},
        {
            if (missionNamespace getVariable [QGVAR(startTime_PV), -1] == -1) then {
                ["potato_safeStartOff"] call CBA_fnc_localEvent;
            } else {
                ["potato_safeStartOn"] call CBA_fnc_localEvent;
            };
        }
    ] call CBA_fnc_waitUntilAndExecute;
};
