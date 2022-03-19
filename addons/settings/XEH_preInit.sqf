// #define DEBUG_MODE_FULL
#include "script_component.hpp"

// turn off RHS engine startup script
RHS_ENGINE_STARTUP_OFF = 1; // any non-nil value turns this off

// Disable faction based nametag icons (because we just use the base factions for everything)
ace_nametags_useFactionIcons = false;

if (isServer) then {
    private _settings = [];
    #include "CMF_Settings.sqf"

    INFO_1("Setting server values for [%1] settings", count _settings);
    {
        _x params ["_settingName", "_settingValue", ["_force", false]];
        if (isNil _settingName) then { WARNING_1("Setting not init: %1",_settingName); };
        private _ret = [_settingName, _settingValue, [0, 2] select _force, "server"] call CBA_settings_fnc_set;
        TRACE_4("Setting",_settingName,_settingValue, _force, _ret);
    } forEach _settings;

    // Settings Test:
    [{
        params ["_settings"];
        INFO_1("Checking [%1] settings", count _settings);

        {
            _x params ["_settingName", "_settingValue", "", ["_skipWarning", false]];
            TRACE_2("",_settingName,_settingValue);
            if (!((missionNamespace getVariable [_settingName, -999]) isEqualTo _settingValue)) then {
                if (_skipWarning) exitWith {};
                private _log = format ["Warning: Setting [%1] not expected [%2] current [%3]", _settingName, _settingValue, missionNamespace getVariable _settingName];
                ["potato_adminMsg", [_log, "Mission"]] call CBA_fnc_globalEvent;
            };
        } forEach _settings;
    }, [_settings], 4] call CBA_fnc_waitAndExecute;
};
