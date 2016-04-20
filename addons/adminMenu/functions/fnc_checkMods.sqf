//This is horriblly ineffecient, bad code, but it works
#include "script_component.hpp"

params [["_createOrginalVersionInfo", false]];
TRACE_1("params",_createOrginalVersionInfo);

_getStringFromConfig = {
    _cfgPath = _this select 0;
    _returnValue = switch (true) do
    {
    case (isNumber _cfgPath):     {str getNumber _cfgPath};
    case (isText _cfgPath):     {str getText _cfgPath};
    case (isArray _cfgPath):     {str getArray _cfgPath;};
        default         {""};
    };
    (_returnValue)
};
_modsAndVersionsPairs = [];
{
    _name = configName _x;
    _path = _x;
    _author             = [_path >> "author"] call _getStringFromConfig;
    _version             = [_path >> "version"] call _getStringFromConfig;
    if (_version == "") then {
        _version             = [_path >> "versionStr"] call _getStringFromConfig;
        if (_version == "") then {
            _version             = [_path >> "versionAr"] call _getStringFromConfig;
        };
    };
    _modsAndVersionsPairs pushBack [_name, _version];
} forEach ("true" configClasses (configFile >> "CfgPatches"));

if (_createOrginalVersionInfo) then {
    if (isNil QGVAR(modCheckRun)) then {
        GVAR(pvModVersions) = _modsAndVersionsPairs;
        publicVariable QGVAR(pvModVersions);
        TRACE_1("broadcasting our versions", count GVAR(pvModVersions));
        sleep 1;
    };
    [[false], QFUNC(checkMods), true] call BIS_fnc_MP;
} else {
    if (!isNil QGVAR(modCheckRun)) exitWith {};
    GVAR(modCheckRun) = true;
    systemChat "Verifying mods";

    waitUntil {sleep 1; systemChat "getting versions from server..."; !isNil QGVAR(pvModVersions)};

    _diaryText = format ["Mod Problems for: %1<br/><br/>", profileName];

    //Mods server has but we don't
    {
        _modName = _x select 0;
        _serverVersion = _x select 1;
        _problem = "";
        {
            if ((_x select 0) == _modName) exitWith {
                if (_serverVersion != (_x select 1)) then {        //should always be true, right?
                    _problem = format ["<br/>%1 - <font color='FF9900'>Mismatch</font> [Should be %2, local is %3]", _modName, _serverVersion, (_x select 1)];
                };
            };
        } forEach _modsAndVersionsPairs;
        if (_problem == "") then {
            _problem = format ["<br/>%1 - <font color='#FF3300'>Missing</font>", _modName];
        };

        _diaryText = _diaryText + _problem;
    } forEach (GVAR(pvModVersions) - _modsAndVersionsPairs);

    //mods we have, but server doesn't
    {
        _modName = _x select 0;
        _problem = format ["<br/>%1 - <font color='#CC00CC'>Should Not Have</font>", _modName];
        {
            if ((_x select 0) == _modName) exitWith {
                _problem = "";
            };
        } forEach GVAR(pvModVersions);
        if (_problem != "") then {
            _diaryText = _diaryText + _problem;
        };
    } forEach (_modsAndVersionsPairs - GVAR(pvModVersions));

    [[profileName, _diaryText], QFUNC(checkModsWriteDiary), true] spawn BIS_fnc_MP;
};
