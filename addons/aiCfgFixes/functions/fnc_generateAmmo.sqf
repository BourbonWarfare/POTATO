/*
 * Author: Brandon (TCVM)
 * Generates default config data for all ammo in the mod pack
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call potato_weaponCfgFixes_fnc_generateAmmo;
 *
 * Public: Yes
 */
#include "script_component.hpp"
#define LOWEST_BASE_CLASS -2

#define CFG_WEAPONS_HEADER "class Mode_FullAuto;" + LINE_BREAK + "class Mode_Burst;" + LINE_BREAK + "class Mode_SemiAuto;" + LINE_BREAK + "class CfgWeapons {" + LINE_BREAK
#define DEFAULT_MODE_VALUES INDENT + INDENT + INDENT + "minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;" + LINE_BREAK
#define SEARCH_CONFIG "configName(_x) isEqualTo 'audibleFire'"

systemChat "Generating...";

private _ammoToGenerate = [];
private _baseClasses = [];
{
    // _x = ammo_config
    if (count configProperties[_x, SEARCH_CONFIG, false] > 0) then {
        private _inherited = inheritsFrom(_x);
        private _prevInherited = [];
        _prevInherited pushBack [_x, inheritsFrom(_x)];
        while {count _inherited > 0} do {
            if (inheritsFrom(_inherited) isEqualTo "") exitWith {
                _baseClasses pushBackUnique _inherited;
                true
            }
            _prevInherited pushBack [_inherited, inheritsFrom(_inherited)];
            _inherited = inheritsFrom(_inherited);
        };
        _ammoToGenerate append _prevInherited;
    };
} forEach configProperties[configFile >> "CfgAmmo", "isClass _x"];

systemChat "Reversing...";
reverse _ammoToGenerate;
private _ammoToGenerateCorrect = [];
{
    // _x = [ammo_config, ammo_parent]
    for "_index" from (_foreachindex + 1) to (count _ammoToGenerate) do {
        if ((_x select 0) == ((_ammoToGenerate select _index) select 1)) then {
            _ammoToGenerateCorrect pushBackUnique ((_ammoToGenerate select _index) select 0);
            _ammoToGenerateCorrect pushBackUnique (_x select 0);
        };
    };
    _ammoToGenerateCorrect pushBackUnique (_x select 0);
} foreach _ammoToGenerate;

//reverse _ammoToGenerateCorrect;
_ammoToGenerate = _ammoToGenerateCorrect;

systemChat "Creating Config...";
private _finalStr = "class CfgAmmo {" + LINE_BREAK;

{
    _finalStr = _finalStr + INDENT + "class " + configName(_x) + ";" + LINE_BREAK;
} forEach _baseClasses;

{
    // _x = ammo_config
    if (!(configName(_x) isEqualTo "")) then {
        if (configName(inheritsFrom(_x)) isEqualTo "") then {
            _finalStr = _finalStr + INDENT + "class " + configName(_x) + ";" + LINE_BREAK;
            systemChat "Never Encounter This";
        } else {
            private _inherit = ": " + configName(inheritsFrom(_x));
            private _classText = INDENT + "class " + configName(_x) + _inherit + " {" + LINE_BREAK;
            {
                _classText = _classText + CFG_CLASS_DATA(configName(_x), getNumber(_x));
            } forEach configProperties[_x, SEARCH_CONFIG, true];
            _finalStr = _finalStr + _classText + INDENT + "};" + LINE_BREAK;
        };
    };
} forEach _ammoToGenerate;

_finalStr = _finalStr + CFG_FOOTER;

copyToClipboard _finalStr;
systemChat "Done Generating CfgAmmo";
systemChat "Finished";

