/*
 * Author: Brandon (TCVM)
 * Generates default config data for all air vehicles in the mod pack
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call potato_weaponCfgFixes_fnc_generateAir;
 *
 * Public: Yes
 */
#include "script_component.hpp" 
#define SEARCH_CONFIG "configName(_x) isEqualTo 'audible'"

systemChat "Generating...";

private _airToGenerate = [];
private _baseClasses = [];
{
    // _x = air_config
    if (count configProperties[_x, SEARCH_CONFIG, false] > 0) then {
        private _inherited = inheritsFrom(_x);
        private _prevInherited = [];
        _prevInherited pushBack [_x, inheritsFrom(_x)];
        while {count _inherited > 0} do {
            if (configName(inheritsFrom(_inherited)) isEqualTo "") then {
                _baseClasses pushBackUnique _inherited;
            };
            _prevInherited pushBack [_inherited, inheritsFrom(_inherited)];
            _inherited = inheritsFrom(_inherited);
        };
        _airToGenerate append _prevInherited;
    };
} forEach configProperties[configFile >> "CfgVehicles", "isClass _x && configName(_x) isKindOf ['Air', configFile >> 'CfgVehicles']"];

systemChat "Reversing...";
reverse _airToGenerate;
private _airToGenerateCorrect = [];
{
    // _x = [air_config, air_parent]
    for "_index" from (_foreachindex + 1) to (count _airToGenerate) do {
        if ((_x select 0) == ((_airToGenerate select _index) select 1)) then {
            _airToGenerateCorrect pushBackUnique ((_airToGenerate select _index) select 0);
            _airToGenerateCorrect pushBackUnique (_x select 0);
        };
    };
    _airToGenerateCorrect pushBackUnique (_x select 0);
} foreach _airToGenerate;

//reverse _airToGenerateCorrect;
_airToGenerate = _airToGenerateCorrect;

systemChat "Creating Config...";
private _finalStr = "class CfgVehicles {" + LINE_BREAK;

{
    _finalStr = _finalStr + INDENT + "class " + configName(_x) + ";" + LINE_BREAK;
} forEach _baseClasses;

{
    // _x = air_config
    if (!(configName(_x) isEqualTo "")) then {
        if (configName(inheritsFrom(_x)) isEqualTo "") then {
            // nothing
        } else {
            private _inherit = ": " + configName(inheritsFrom(_x));
            private _classText = INDENT + "class " + configName(_x) + _inherit + " {" + LINE_BREAK;
            private _currentAir = _x;
            {
                if (getNumber(_x) > AIR_VEHICLE_MAX_NOISE) then {
                    _classText = _classText + INDENT + INDENT + "audible = " + str(AIR_VEHICLE_MAX_NOISE) + ";" + LINE_BREAK;
                };
            } forEach configProperties[_x, SEARCH_CONFIG, false];
            _finalStr = _finalStr + _classText + INDENT + "};" + LINE_BREAK;
        };
    };
} forEach _airToGenerate;

_finalStr = _finalStr + CFG_FOOTER;

copyToClipboard _finalStr;
systemChat "Done Generating CfgVehicles";
systemChat "Finished";

