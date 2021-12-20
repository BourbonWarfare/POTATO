#include "script_component.hpp"

if (isServer) then {
    // Setting to sync to ace_fortify        
    ["potato_safeStartOn", {
        if (!GVAR(syncFortify)) exitWith {};
        missionNamespace setVariable [QACEGVAR(fortify,fortifyAllowed), true, true];
    }] call CBA_fnc_addEventHandler;
    ["potato_safeStartOff", {
        if (!GVAR(syncFortify)) exitWith {};
        missionNamespace setVariable [QACEGVAR(fortify,fortifyAllowed), false, true];
    }] call CBA_fnc_addEventHandler;

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
