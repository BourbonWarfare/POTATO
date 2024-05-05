/*
 * Author: Dani (TCVM)
 * Generates default config data for all ammo in the mod pack
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * [[], ["potato_bullet", "rhs_", "hlc_", "vn_", "hafm"]] call potato_aiCfgFixes_fnc_generateAmmo
 * [["rhs_", "hlc_", "vn_", "hafm"], ["potato_bullet"]] call potato_aiCfgFixes_fnc_generateAmmo
 *
 * Public: Yes
 */
#include "script_component.hpp"
#define SEARCH_CONFIG "configName(_x) isEqualTo 'audibleFire'"

diag_log text "Generating...";

params [["_filterAllow", []], ["_filterBlock", []]];
_filterAllow = _filterAllow apply { toLower _x };
_filterBlock = _filterBlock apply { toLower _x };
private _fnc_filter = {
    params ["_class"];
    _class = toLower _class;
    private _ret = (_filterAllow isEqualTo []);
    {
        if ((_class find _x) == 0) exitWith { _ret = true; };
    } forEach _filterAllow;
    {
        if ((_class find _x) == 0) exitWith { _ret = false; };
    } forEach _filterBlock;
    _ret
};

private _ammoToGenerate = [];
private _baseClasses = [];
{
    // _x = ammo_config
    if (((toLower configName _x) find "potato_bullet") == 0) then { continue; };
    if (!([toLower configName _x] call _fnc_filter)) then { continue; }; 
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
        _ammoToGenerate append _prevInherited;
    };
} forEach configProperties [configFile >> "CfgAmmo", "isClass _x"];

diag_log text "Reversing...";
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

private _retAmmo = [];
{
    // _x = ammo_config
    if (!(configName(_x) isEqualTo "")) then {
        if (configName(inheritsFrom(_x)) isEqualTo "") then {
            // nothing
        } else {
            private _newValue = [[_x, configName(_x)]];
            private _newData = [];
            
            private _currentAmmo = _x;
            {
                if (count configProperties[_currentAmmo, "configName(_x) isEqualTo 'potato_aiCfgFixes_macroUsed'", false] <= 0) then {
                    _newData pushBack [configName(_x), str(getNumber(_x))];
                } else {
                    private _macro = getText(configProperties[_currentAmmo, "configName(_x) isEqualTo 'potato_aiCfgFixes_macroUsed'", false] select 0);
                    _newData pushBack [configName(_x), _macro];
                    _newData pushBack ["GVAR(macroUsed)", str(_macro)];
                };
            } forEach configProperties[_x, SEARCH_CONFIG, false];
            
            _newValue pushBack _newData;
            _retAmmo pushBack _newValue;
        };
    };
} forEach _ammoToGenerate;
diag_log text format ["_retAmmo = %1", count _retAmmo];

diag_log text "Setting usage flags...";
private _setAiUsageFlags = {
    params["_retAmmo"];
    
    private _setUsageFlags = {
        params["_retAmmo", "_ammo", "_flags", ["_extra", []]];
        
        if (!([toLower _ammo] call _fnc_filter)) exitWith { _retAmmo };

        private _ammoUsageFlags = '"';
        {
            _ammoUsageFlags = _ammoUsageFlags + str(_x);
            if (_foreachindex != (count _flags) - 1) then {
                _ammoUsageFlags = _ammoUsageFlags + " + ";
            };
        } forEach _flags;
        _ammoUsageFlags = _ammoUsageFlags + '"';
        
        private _pos = _retAmmo findIf { ((_x select 0) select 1) isEqualTo _ammo };
        if (_pos < 0) then {
            if ((_retAmmo findIf {((_x select 0) select 1) isEqualTo configName(inheritsFrom(configFile >> "CfgAmmo" >> _ammo)) }) < 0) then {
                _retAmmo pushBack [[inheritsFrom(configFile >> "CfgAmmo" >> _ammo), configName(inheritsFrom(configFile >> "CfgAmmo" >> _ammo))], []];
            };
            _retAmmo pushBack [[configFile >> "CfgAmmo" >> _ammo, _ammo], []];
            _pos = (count _retAmmo) - 1;
        };
                
        ((_retAmmo select _pos) select 1) pushBack ["aiAmmoUsageFlags", _ammoUsageFlags];
        ((_retAmmo select _pos) select 1) pushBack ["allowAgainstInfantry", "1"];
        
        {
            ((_retAmmo select _pos) select 1) pushBack [_x select 0, _x select 1];
        } forEach _extra;
        
        _retAmmo;
    };
    
    _retAmmo = [_retAmmo, "potato_aiCfgFixes_he_rocket",    [64, 128, 512],         [["cost", "100"]]] call _setUsageFlags;
    _retAmmo = [_retAmmo, "CUP_R_70mm_Hydra_HE",            [64, 128, 512],         [["cost", "100"]]] call _setUsageFlags;
    _retAmmo = [_retAmmo, "rhs_rpg26_rocket",               [64, 128, 256, 512],    [["cost", "50"]]] call _setUsageFlags;
    
    _retAmmo = [_retAmmo, "CUP_R_SMAW_HEDP_N",              [64, 128, 256, 512],    [["cost", "50"]]] call _setUsageFlags;
    _retAmmo = [_retAmmo, "CUP_R_RPG18_AT",                 [64, 128, 256, 512],    [["cost", "50"]]] call _setUsageFlags;
    _retAmmo = [_retAmmo, "CUP_R_MEEWS_HEDP",               [64, 128, 256, 512],    [["cost", "150"]]] call _setUsageFlags;
    _retAmmo = [_retAmmo, "CUP_R_M136_AT",                  [64, 128, 256, 512],    [["cost", "50"]]] call _setUsageFlags;
    _retAmmo = [_retAmmo, "CUP_R_SMAW_HEDP",                [64, 128, 256, 512],    [["cost", "50"]]] call _setUsageFlags;
    _retAmmo = [_retAmmo, "CUP_R_OG7_AT",                   [64, 128, 256],         [["cost", "50"]]] call _setUsageFlags;
    _retAmmo = [_retAmmo, "CUP_R_TBG7V_AT",                 [64, 128, 256],         [["cost", "150"]]] call _setUsageFlags;
    _retAmmo = [_retAmmo, "CUP_R_PG7VR_AT",                 [64, 128, 256, 512],    [["cost", "50"]]] call _setUsageFlags;
    _retAmmo = [_retAmmo, "CUP_R_PG7VM_AT",                 [64, 128, 256, 512],    [["cost", "50"]]] call _setUsageFlags;
    _retAmmo = [_retAmmo, "CUP_R_PG7V_AT",                  [64, 128, 256, 512],    [["cost", "50"]]] call _setUsageFlags;
    _retAmmo = [_retAmmo, "CUP_R_PG7VL_AT",                 [64, 128, 256, 512],    [["cost", "50"]]] call _setUsageFlags;
    _retAmmo = [_retAmmo, "CUP_R_57mm_HE",                  [64, 128, 256, 512],    [["cost", "150"]]] call _setUsageFlags;
    _retAmmo = [_retAmmo, "CUP_R_M72A6_AT",                 [64, 128, 256, 512],    [["cost", "50"]]] call _setUsageFlags;
    
    _retAmmo
};

_retAmmo = [_retAmmo] call _setAiUsageFlags;

diag_log text "Creating Config...";
private _finalStr = "class CfgAmmo {" + LINE_BREAK;

diag_log text "Printing base classes...";
{
    _finalStr = _finalStr + INDENT + "class " + configName(_x) + ";" + LINE_BREAK;
} forEach _baseClasses;

diag_log text "Printing modified classes...";
{
    _x params ["_ammoArr", "_printValues"];
    _ammoArr params["_ammoCfg", "_ammoName"];
    
    private _inherit = ": " + configName(inheritsFrom(_ammoCfg));
    private _classText = INDENT + "class " + _ammoName;
    if ((count _printValues) > 0) then {
        _classText = _classText + _inherit + " {" + LINE_BREAK;
        {
            _classText = _classText + CFG_CLASS_DATA((_x select 0),(_x select 1));
        } forEach _printValues;
        _classText = _classText + INDENT + "}";
    };
    _finalStr = _finalStr + _classText + ";" + LINE_BREAK;
} forEach _retAmmo;

_finalStr = _finalStr + CFG_FOOTER;

copyToClipboard _finalStr;
diag_log text "Done Generating CfgAmmo";
diag_log text "Finished";

