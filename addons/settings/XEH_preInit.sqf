// #define DEBUG_MODE_FULL
#include "script_component.hpp"

// turn off RHS engine startup script
RHS_ENGINE_STARTUP_OFF = 1; // any non-nil value turns this off

// Disable faction based nametag icons (because we just use the base factions for everything)
ace_nametags_useFactionIcons = false;

if (isServer) then {
    private _skip = [];
    private _settings = [];
    #include "BW_Settings.inc.sqf"

    INFO_1("Setting server values for [%1] settings",count _settings);
    if ((count _skip) > 0) then { WARNING_1("skipping %1",_skip) };
    {
        _x params ["_settingName", "_settingValue", ["_force", false]];
        if (isNil _settingName) then { INFO_1("Setting not init yet: %1",_settingName); }; // can just be a mod load order, not an error
        private _ret = [_settingName, _settingValue, [0, 2] select _force, "server"] call CBA_settings_fnc_set;
        TRACE_4("Setting",_settingName,_settingValue,_force,_ret);
    } forEach _settings;

    [{
        params ["_settings"];
        INFO_1("Checking [%1] settings",count _settings);

        // Settings Test:
        {
            _x params ["_settingName", "_settingValue", "", ["_skipWarning", false]];
            TRACE_2("",_settingName,_settingValue);
            if (!((missionNamespace getVariable [_settingName, -999]) isEqualTo _settingValue)) then {
                if (_skipWarning) exitWith {};
                private _log = format ["Warning: Setting [%1] not expected [%2] current [%3]", _settingName, _settingValue, missionNamespace getVariable _settingName];
                ["potato_adminMsg", [_log, "Mission"]] call CBA_fnc_globalEvent;
            };
        } forEach _settings;

        // report specific medical settings
        private _log = format ["[AAA=%1] [aDmgPass=%2]", AAA_VAR_MOD_ENABLED, ace_medical_engine_damagePassThroughEffect toFixed 2];
        ["potato_adminMsg", [_log, "Mission"]] call CBA_fnc_globalEvent;
    }, [_settings], 4] call CBA_fnc_waitAndExecute;

    // Check for settings set in server profileNamespace
    if (isServer && {!hasInterface}) then {
        [{
            private _serverProfile = profileNamespace getVariable ["cba_settings_hash", [] call CBA_fnc_hashCreate];
            private _size = [_serverProfile] call CBA_fnc_hashSize;
            if (_size > 0) then {
                ["potato_adminMsg", [format ["Warning: %1 settings set in profileNamespace", _size], "Mission"]] call CBA_fnc_globalEvent;
            };
        }, [], 5] call CBA_fnc_waitAndExecute;
    };
};
