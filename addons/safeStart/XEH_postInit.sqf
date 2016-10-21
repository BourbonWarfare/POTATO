#include "script_component.hpp"

if (isServer) then {
    [
        { ACEGVAR(common,settingsInitFinished) && {time > 0} },
        { [GVAR(enabled)] call FUNC(toggleSafeStart); }
    ] call CBA_fnc_waitUntilAndExecute;
};

if (didJip) then {
    [
        { ACEGVAR(common,settingsInitFinished) && {time > 1} },
        {
            if (missionNamespace getVariable [QGVAR(startTime_PV), -1] == -1) then {
                ["potato_safeStartOff"] call CBA_fnc_localEvent;
            } else {
                ["potato_safeStartOn"] call CBA_fnc_localEvent;
            };
        }
    ] call CBA_fnc_waitUntilAndExecute;
};
