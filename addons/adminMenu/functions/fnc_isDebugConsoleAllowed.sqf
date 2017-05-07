private _enableDebugConsole = [
    "DebugConsole",
    getMissionConfigValue ["enableDebugConsole", 0]
] call (missionNamespace getVariable "BIS_fnc_getParamValue");

 // Always allowed by mission config or mission param
if (_enableDebugConsole isEqualTo 2 || {hasInterface && isServer}) exitWith { true };

// In single player editor
if (!isMultiplayer && { allDisplays find findDisplay 26 in [0, 1] || allDisplays find findDisplay 313 in [0, 1] }) exitWith { true };

// In multiplayer mode and server host or logged in admin
diag_log format ["serverCommandAvailable '#kick': %1", serverCommandAvailable "#kick"];
if (isMultiplayer && (missionNamespace getVariable ["potato_core_playerTech", false] || serverCommandAvailable "#kick")) exitWith { true };

false
