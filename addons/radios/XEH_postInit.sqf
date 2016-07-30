#include "script_component.hpp"

["ace_settingsInitialized", {
    TRACE_3("",GVAR(enabled),hasInterface,EGVAR(assignGear,usePotato));
    if (GVAR(enabled) && {!(missionNamespace getVariable [QEGVAR(assignGear,usePotato), false])}) exitWith {
        diag_log text format ["[POTATO-radios] - ERROR: Radios enabled, but gear assign is not running"];
    };

    if (GVAR(enabled) && hasInterface) then {
        [FUNC(initializeRadios)] call CBA_fnc_execNextFrame;

        [
        {
            GVAR(initialized) && {player getVariable [QEGVAR(assignGear,gearSetup), false]}
        },
        {
            [] call FUNC(addAcreBriefing);
            [{[player] call ACRE_FUNC(isInitialized)}, FUNC(configureRadios)] call CBA_fnc_waitUntilAndExecute;
        }
        ] call CBA_fnc_waitUntilAndExecute;
    };
}] call CBA_fnc_addEventHandler;


//Load 3den mission settings into ace settings on server
if (isServer) then {
    private _val = getMissionConfigValue QGVAR(enabled);
    if (!isNil "_val") then { [QGVAR(enabled), _val, true, true] call ACEFUNC(common,setSetting); };

    diag_log text format ["Setting Enabled to %1", [QGVAR(enabled), _val, true, true]];

    TRACE_1("Mission Config Value",_val);

    _val = getMissionConfigValue QGVAR(radioInterference);
    if (!isNil "_val") then { [QGVAR(radioInterference), _val, true, true] call ACEFUNC(common,setSetting); };

    _val = getMissionConfigValue QGVAR(terrainInterference);
    if (!isNil "_val") then { [QGVAR(terrainInterference), _val, true, true] call ACEFUNC(common,setSetting); };

    _val = getMissionConfigValue QGVAR(addCommonChannelName);
    if (!isNil "_val") then { [QGVAR(addCommonChannelName), _val, true, true] call ACEFUNC(common,setSetting); };

    _val = getMissionConfigValue QGVAR(addCommonChannelNumber);
    if (!isNil "_val") then { [QGVAR(addCommonChannelNumber), _val, true, true] call ACEFUNC(common,setSetting); };

    _val = getMissionConfigValue QGVAR(addCommonChannelAllMR);
    if (!isNil "_val") then { [QGVAR(addCommonChannelAllMR), _val, true, true] call ACEFUNC(common,setSetting); };

    _val = getMissionConfigValue QGVAR(addCommonChannelAllLR);
    if (!isNil "_val") then { [QGVAR(addCommonChannelAllLR), _val, true, true] call ACEFUNC(common,setSetting); };
};
