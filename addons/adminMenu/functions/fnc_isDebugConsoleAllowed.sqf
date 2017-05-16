private _enableDebugConsole = [
    "DebugConsole",
    getMissionConfigValue ["enableDebugConsole", 0]
] call (missionNamespace getVariable "BIS_fnc_getParamValue");

 // Always allowed by mission config or mission param or if you're the server
if (_enableDebugConsole isEqualTo 2 || {hasInterface && isServer}) exitWith { true };

// In multiplayer mode and server host or logged in admin
if (isMultiplayer && (missionNamespace getVariable ["potato_core_playerTech", false] || serverCommandAvailable "#kick")) exitWith { true };

false
