/*
 * Author: Dani (TCVM)
 * Generates default config data for every weapon in the mod pack
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * [[], [ "rhs_", "hlc_", "vn_", "hafm", "WBK_", "DSA_", "sp_fwa_sig510_base"]] call potato_aiCfgFixes_fnc_generateWeapons
 * [["rhs_", "hlc_", "vn_", "hafm"], ["WBK_", "DSA_"]] call potato_aiCfgFixes_fnc_generateWeapons
 *
 * Public: Yes
 */
#include "script_component.hpp"
#define LOWEST_BASE_CLASS -2
#define CFG_WEAPONS_HEADER "class Mode_FullAuto;" + LINE_BREAK + "class Mode_Burst;" + LINE_BREAK + "class Mode_SemiAuto;" + LINE_BREAK + "class CfgWeapons {" + LINE_BREAK
#define DEFAULT_MODE_VALUES INDENT + INDENT + INDENT + "minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;" + LINE_BREAK

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

private _types = [  ["AssaultRifle", "Rifle"],
                    ["Shotgun"],
                    ["MachineGun"],
                    ["SniperRifle"],
                    ["Handgun"],
                    ["SubmachineGun"]];

private _allWeapons = [];

private _removeDuplicates = {
    params["_array"];
    private _newArray = _array;
    for "_i" from 0 to (count _array) - 1 do {
        for "_j" from (_i + 1) to (count _array) - 1 do {
            if ((_array select _i) == (_array select _j)) exitWith {
                _newArray deleteAt _i;
            };
        };
    };
    _newArray
};

systemChat "Generating...";
{
    private _weaponCfg = _x;
    private _weapon = toLower configName _weaponCfg;
    if (!([_weapon] call _fnc_filter)) then { continue; }; 
    // Because of how ARMA figures out what type of weapon a weapon is, some weapons (i.e rhs_weap_m107 as of 24/11/17) are defined as "rifles" (cursor="arifle")
    // and as such don't get the proper definitions. Can't figure out better way to determine weapon type so we have to deal with that
    private _weaponType = (_weapon call bis_fnc_itemType);
    private _weaponTypeCategory = _weaponType select 0;
    private _weaponTypeSpecific = _weaponType select 1;
    private _weaponTypeID = -1;
    {
        if (_weaponTypeSpecific in _x) exitWith {_weaponTypeID = _foreachindex};
    } forEach _types;

    private _weaponDefinedConfig = configProperties[_weaponCfg, "isClass _x", false];
    private _allModes = [getArray(_weaponCfg >> "modes")] call _removeDuplicates;
    private _hasDefinedMode = {
        if (configName(_x) in _allModes) exitWith {true};
    } forEach _weaponDefinedConfig;

    if (!isNil {_hasDefinedMode} && _weaponTypeCategory != "VehicleWeapon" && _weaponTypeID >= 0) then {
        private _procStr = "Processing '" + _weapon;
        systemChat _procStr;
        _procStr = _procStr + "' with modes + [" + str(_allModes) + "].";
        diag_log _procStr;
        if (count _allModes != 0) then {
            private _inherited = inheritsFrom(_weaponCfg);
            private _prevInherited = [];
            _prevInherited pushBack [_weaponTypeID, _weaponCfg];
            while {count _inherited > 0} do {
                // If the immediate class above this one does not have any modes defined, that means that it is a base of a base class and we can
                // ignore it
                if (getArray(inheritsFrom(_inherited) >> "modes") select 0 == "this" && getArray(_inherited >> "modes") select 0 == "this") exitWith {
                    // we flag this as the lowest base class
                    _prevInherited pushBack [LOWEST_BASE_CLASS, _inherited];
                    true
                };
                _procStr = INDENT + "Inherited From: " + str(_inherited);
                diag_log _procStr;
                _weaponCfg = _inherited;
                _weapon = toLower configName _weaponCfg;
                _weaponTypeSpecific = (_weapon call bis_fnc_itemType) select 1;
                _weaponTypeID = -1;
                {
                    if (_weaponTypeSpecific in _x) exitWith {_weaponTypeID = _foreachindex};
                } forEach _types;
                _prevInherited pushBack [_weaponTypeID, _inherited];
                _inherited = inheritsFrom(_inherited);
            };
            _procStr = INDENT + "Inherit Array: " + str(_prevInherited);
            diag_log _procStr;
            _allWeapons pushBack _prevInherited;
        };
    };
} forEach configProperties [configFile >> "cfgWeapons","isClass _x"];

systemChat "Done Finding All Configs";
systemChat "Generating CfgWeapons";

// Classes without any mode property
private _baseClasses = "";
// All weapons defined
private _weaponClasses = "";

// _allWeapons = {{{index, inherited_classname}, ...}, ...}
private _alreadyDefined = [];
{
    // _x = {{index, inherited_classname}, ...}
    private _reversedArray = _x;
    private _definedDefault = false;
    reverse _reversedArray;
    {
        // _x = {index, inherited_classname}
        private _alreadyDefinedIndex = _alreadyDefined pushBackUnique (_x select 1);
        if (_alreadyDefinedIndex >= 0) then {
            private _weaponStr = "";
            private _weaponClassStr = INDENT + "class " + configName(_x select 1) + ": " + configName(inheritsFrom(_x select 1)) + " {";
            // if the index is -1, it is a base class
            if (_x select 0 < 0) then {
                // don't define data, just use as a base class
                if (count configName(inheritsFrom(_x select 1)) <= 0 || _x select 0 == LOWEST_BASE_CLASS) then {
                    _weaponClassStr = INDENT + "class " + configName(_x select 1) + ";";
                    _baseClasses = _baseClasses + _weaponClassStr + LINE_BREAK;
                } else {
                    _weaponClassStr = _weaponClassStr + "};";
                    _weaponClasses = _weaponClasses + _weaponClassStr + LINE_BREAK;
                };
            } else {
                if (getArray(_x select 1 >> "modes") select 0 != "this") then {
                    // Not a base class
                    private _weaponCfg = _x select 1;
                    private _modes = "modes[] = {";
                    private _addedModes = [];
                    private _predefinedModes = [];
                    private _allModes = [getArray(_weaponCfg >> "modes")] call _removeDuplicates;
                    {
                        // if the possible config is in the "muzzles" array, that means we have to ignore it. Muzzles and modes are very similar
                        // We don't generate any values for a config that has the word "optic" in it, because scopes are harder to generate valeus for and arent used in our sessions
                        if (count getArray(_x >> "sounds") > 0 && !(configName(_x) in _allModes) && !(configName(_x) in getArray(_weaponCfg >> "muzzles"))) then {
                            private _currentTestModeName = configName _x;
                            // narrow-phase checking to ensure that the mode has not already been defined, even if the wrong capitalization
                            private _modeInside = {
                                if (toLower _x == toLower _currentTestModeName) exitWith {true};
                            } forEach _allModes;
                            if (isNil {_modeInside}) then {
                                _allModes pushBack configName(_x);
                                // we pushBack the mode so we don't add it to the mode list in the next loop
                                // We are sure that this works since we check if the configName is in allModes
                                _addedModes pushBackUnique (toLower configName(_x));
                                private _procStr = "Manually Adding '" + configName(_x) + "' to '" + str(_weaponCfg);
                                systemChat _procStr;
                                diag_log _procStr;
                            };
                        };
                    } forEach configProperties[_weaponCfg, "isClass _x", false];

                    {
                        // _x = inherited_classname::modes (string)
                        if (configName(inheritsFrom(_weaponCfg >> _x)) != "") then {
                            private _modeClass = INDENT + INDENT + "class " + _x + ": " + configName(inheritsFrom(_weaponCfg >> _x)) + " {" + LINE_BREAK;
                            // if the parent does not have any modes or the only one defined is 'this', that means that
                            // this is inheriting off of another weapon and we have to inherit the previous mode to get
                            // full data
                            if (_x in getArray(inheritsFrom(_weaponCfg) >> "modes")) then {
                                diag_log text format [" ~%1 - %2 Skipping Redefine A", _weaponCfg, _x];
                                // _modeClass = INDENT + INDENT + "class " + _x + ": " + _x + " {" + LINE_BREAK;
                            } else {
                                // If the mode does not exist in the array, create a new one
                                private _configClasses = configProperties[inheritsFrom(_weaponCfg), "isClass _x", false];
                                private _modeName = _x;
                                {
                                    if (_modeName == configName(_x)) exitWith {
                                        diag_log text format [" ~%1 - %2 Skipping Redefine B", _weaponCfg, _x];
                                        // _modeClass = INDENT + INDENT + "class " + _modeName + ": " + configName(_x) + " {" + LINE_BREAK;
                                        true
                                    };
                                } forEach _configClasses;
                            };

                            private _configCheck = 'configName(_x) == "burst" ||
                                                    configName(_x) == "aiRateOfFire" ||
                                                    configName(_x) == "aiRateOfFireDistance" ||
                                                    configName(_x) == "minRange" ||
                                                    configName(_x) == "minRangeProbab" ||
                                                    configName(_x) == "midRange" ||
                                                    configName(_x) == "midRangeProbab" ||
                                                    configName(_x) == "maxRange" ||
                                                    configName(_x) == "maxRangeProbab" ||
                                                    configName(_x) == "showToPlayer"';
                            if (!isNull(_weaponCfg >> _x >> "showToPlayer") && { getNumber(_weaponCfg >> _x >> "showToPlayer") == 1 }) then {
                                _configCheck = 'configName(_x) == "aiRateOfFire" ||
                                                configName(_x) == "aiRateOfFireDistance" ||
                                                configName(_x) == "minRange" ||
                                                configName(_x) == "minRangeProbab" ||
                                                configName(_x) == "midRange" ||
                                                configName(_x) == "midRangeProbab" ||
                                                configName(_x) == "maxRange" ||
                                                configName(_x) == "maxRangeProbab" ||
                                                configName(_x) == "showToPlayer"';
                            };

                            private _modeDef = "";
                            {
                                if ((isText _x && getText(_x) != "") || isNumber(_x)) then {
                                    if (isNumber(_x)) then {
                                        _modeDef = _modeDef + CFG_CLASS_DATA(INDENT + configName(_x),str(getNumber(_x)));
                                    } else {
                                        _modeDef = _modeDef + CFG_CLASS_DATA(INDENT + configName(_x),str(getText(_x)));
                                    };
                                };
                            } forEach configProperties[_weaponCfg >> _x, _configCheck, true];

                            private _uniqueIndex = _addedModes pushBackUnique (toLower _x);
                            // "Fix" bug where ACE modes would be duplicated endlessly
                            if (_uniqueIndex >= 0) then {
                                _modes = _modes + '"' + _x + '"' + ",";
                            } else {
                                _modeDef = LINE_BREAK;
                            };

                            if ((toLower _x) find "optic" >= 0) then {
                                _modeDef = LINE_BREAK;
                            };

                            // Skip if not actually defined:
                            private _modeName = _x;
                            if ((configProperties [_weaponCfg, "isClass _x && {configName _x == _modeName}", false]) isEqualTo []) exitWith {};

                            _predefinedModes pushBack [_x, configName(inheritsFrom(_weaponCfg >> _x)), (_modeClass + _modeDef + INDENT + INDENT + "};" + LINE_BREAK)];
                        };
                    } forEach _allModes;

                    // This next bit is to make sure that all the modes are defined in an order that guarentees that
                    // inheritance will work.


                    private _predefinedModesCorrect = [];
                    private _definedModesLower = ["mode_fullauto", "mode_burst", "mode_semiauto"];
                    private _possibleInherit = _predefinedModes apply {toLower (_x select 0)};


                    while {
                        {
                            _x params ["_xMode", "_xInherit"];
                            if ((_xMode == _xInherit) || {(toLower _xInherit) in _definedModesLower} || {!((toLower _xInherit) in _possibleInherit)}) exitWith {
                                _predefinedModes deleteAt _foreachindex;
                                _predefinedModesCorrect pushBack (_x select 2);
                                _definedModesLower pushBack toLower _xMode;
                                true
                            };
                            false
                        } forEach _predefinedModes;
                    } do {};
                    {
                        _x params ["_xMode", "_xInherit"];
                            _predefinedModesCorrect pushBack (_x select 2);
                            diag_log text format ["%3 backup Adding %1: %2", _xMode, _xInherit, _weaponClassStr];
                    } forEach _predefinedModes;

                    _weaponStr = _weaponStr + (_predefinedModesCorrect joinString "");

                    private _modesArr = _modes splitString ",";
                    _modes = _modesArr joinString ",";
                    _modes = INDENT + INDENT + _modes + "};" + LINE_BREAK;

                    _weaponClassStr = _weaponClassStr + LINE_BREAK;
                    _weaponClasses = _weaponClasses + _weaponClassStr + _modes + _weaponStr + INDENT + "};" + LINE_BREAK;
                } else {
                    // Base class
                    _baseClasses = _baseClasses + _weaponClassStr + "};" + LINE_BREAK;
                };
            };
        };
    } forEach _reversedArray;
} forEach _allWeapons;

private _finalStr = CFG_WEAPONS_HEADER + _baseClasses + _weaponClasses + CFG_FOOTER;

copyToClipboard _finalStr;
systemChat "Done Generating CfgWeapons";
systemChat "Finished";

