/*
 * Author: Brandon (TCVM)
 * Generates default config data for every weapon in the mod pack
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call potato_weaponCfgFixes_fnc_generateWeapons;
 *
 * Public: Yes
 */
#include "script_component.hpp"
#define LOWEST_BASE_CLASS -2
#define LINE_BREAK toString[13,10]
#define INDENT "    "
#define CFG_WEAPONS_HEADER "class Mode_FullAuto;" + LINE_BREAK + "class Mode_Burst;" + LINE_BREAK + "class Mode_SemiAuto;" + LINE_BREAK + "class CfgWeapons {" + LINE_BREAK
#define CFG_WEAPONS_FOOTER "};" + LINE_BREAK + LINE_BREAK
#define MODE_DATA(dataName, data) INDENT + INDENT + INDENT + dataName + str(data) + ";" + LINE_BREAK
#define DEFAULT_MODE_VALUES INDENT + INDENT + INDENT + "minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;" + LINE_BREAK


private _types = [  ["AssaultRifle", "Rifle"],
                    ["Shotgun"],
                    ["MachineGun"],
                    ["SniperRifle"],
                    ["Handgun"],
                    ["SubmachineGun"]];

private _customModes = [["potato_single", ""], ["potato_burst", ""], ["potato_fullAuto", ""], ["potato_close", ""], ["potato_short", ""], ["potato_medium", ""], ["potato_far1", ""], ["potato_far2", ""], ["potato_mediumOptic", "requiredOpticType = 1;"], ["potato_farOptic", "requiredOpticType = 2;"]];
                    
private _rifleData =        [[-1,1.0,200,0,0.7,200,0.5,500,0.1],[-1,1.0,200,0,0.8,150,0.7,250,0.1],[-1,0.1,50,0,0.9,60,0.7,120,0.1],[],[],[],[],[],[-1,2.0,800,0,0.7,200,0.6,650,0.1],[-1,2.0,800,0,0.7,200,0.6,650,0.1]];
private _shotgunData =      [[-1,1,550,0,0.7,60,0.2,120,0.05],[],[],[],[],[],[],[],[],[]];
private _machineGunData =   [[-1,0.1,50,0,0.9,20,0.7,"30+random 20",0.1],[],[],["5+round random 4",1.0,200,30,0.8,"50+random 50",0.7,"100+random 50",0.1],["4+round random 6",2.0,400,50,0.8,"100+random 50",0.7,"300+random 50",0.1],["4+round random 4",2.0,600,100,0.8,"300+random 50",0.7,"400+random 50",0.1],["2+round random 4",3.0,800,300,0.8,"500+random 50",0.7,"600+random 50",0.1],["8+round random 6",4.0,1000,400,0.8,"700+random 50",0.2,800,0.1],["2+round random 3",3.0,1000,400,0.8,"700+random 50",0.6,800,0.3],["2+round random 3",3.0,1000,400,0.3,"700+random 50",0.6,800,0.5]];
private _sniperData =       [[-1,1.0,200,0,0.7,200,0.5,500,0.1],[],[],[],[],[],[],[],[],[-1,7,1800,1,0.4,500,0.8,1500,0.1]];
private _handgunData =      [[-1,0.6,50,0,0.5,20,0.3,80,0.01],[],[],[],[],[],[],[],[],[]];
private _smgData =          [[-1,1.0,200,0,0.7,75,0.5,150,0.05],[-1,1.0,100,0,0.8,50,0.7,100,0.1],[-1,0.1,50,0,0.9,10,0.7,40,0.1],[],[],[],[],[],[],[]];

// parallel array to _types
private _typeDefines = [_rifleData,
                        _shotgunData,
                        _machineGunData,
                        _sniperData,
                        _handgunData,
                        _smgData];

private _allWeapons = [];

systemChat "Generating...";
{
    private _weaponCfg = _x;
    private _weapon = toLower configName _weaponCfg;
    // Because of how ARMA figures out what type of weapon a weapon is, some weapons (i.e rhs_weap_m107 as of 24/11/17) are defined as "rifles" (cursor="arifle")
    // and as such don't get the proper definitions. Can't figure out better way to determine weapon type so we have to deal with that
    private _weaponType = (_weapon call bis_fnc_itemType);
    private _weaponTypeCategory = _weaponType select 0;
    private _weaponTypeSpecific = _weaponType select 1;
    private _weaponTypeID = -1;
    {
        if (_weaponTypeSpecific in _x) exitwith {_weaponTypeID = _foreachindex};
    } foreach _types;
    
    private _weaponDefinedConfig = configProperties[_weaponCfg, "isClass _x", false];
    private _allModes = getArray(_weaponCfg >> "modes");
    private _hasDefinedMode = {
        if (configName(_x) find "potato" < 0 && configName(_x) in _allModes) exitWith {true};
    } foreach _weaponDefinedConfig;
    
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
                if (getArray(inheritsFrom(_inherited) >> "modes") select 0 == "this" && getArray(_inherited >> "modes") select 0 == "this") exitwith {
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
                    if (_weaponTypeSpecific in _x) exitwith {_weaponTypeID = _foreachindex};
                } foreach _types;
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
    private _definedDefault = False;
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
                    private _inheritMode = "";
                    private _addedModes = [];
                    private _predefinedModes = [];
                    private _allModes = getArray(_weaponCfg >> "modes");
                    {
                        // if the possible config is in the "muzzles" array, that means we have to ignore it. Muzzles and modes are very similar
                        if (count getArray(_x >> "sounds") > 0 && !(configName(_x) in _allModes) && !(configName(_x) in getArray(_weaponCfg >> "muzzles"))) then {
                            private _currentTestModeName = configName _x;
                            // narrow-phase checking to ensure that the mode has not already been defined, even if the wrong capitalization
                            private _modeInside = {
                                if (toLower _x == toLower _currentTestModeName) exitWith {true};
                            } foreach _allModes;
                            if (isNil {_modeInside}) then {
                                _allModes pushBack configName(_x);
                                // we pushBack the mode so we don't add it to the mode list in the next loop
                                // We are sure that this works since we check if the configName is in allModes
                                _addedModes pushBackUnique configName(_x);
                                private _procStr = "Manually Adding '" + configName(_x) + "' to '" + str(_weaponCfg);
                                systemChat _procStr;
                                diag_log _procStr;
                            };
                        };
                    } foreach configProperties[_weaponCfg, "isClass _x", false];
                    
                    {
                        // _x = inherited_classname::modes
                        if (_x find "potato" < 0 && configName(inheritsFrom(_weaponCfg >> _x)) != "") then {
                            private _modeClass = INDENT + INDENT + "class " + _x + ": " + configName(inheritsFrom(_weaponCfg >> _x)) + " {" + LINE_BREAK;
                            // if the parent does not have any modes or the only one defined is 'this', that means that
                            // this is inheriting off of another weapon and we have to inherit the previous mode to get
                            // full data
                            if (_x in getArray(inheritsFrom(_weaponCfg) >> "modes")) then {
                                _modeClass = INDENT + INDENT + "class " + _x + ": " + _x + " {" + LINE_BREAK;
                            } else {
                                private _configClasses = configProperties[inheritsFrom(_weaponCfg), "isClass _x", false];
                                private _modeName = _x;
                                {
                                    if (_modeName == configName(_x)) exitWith {
                                        _modeClass = INDENT + INDENT + "class " + _modeName + ": " + configName(_x) + " {" + LINE_BREAK;
                                        true
                                    };
                                } foreach _configClasses;
                            };
                            private _modeDef = DEFAULT_MODE_VALUES;
                            _predefinedModes pushBack [_x, configName(inheritsFrom(_weaponCfg >> _x)), (_modeClass + _modeDef + INDENT + INDENT + "};" + LINE_BREAK)];
                            private _uniqueIndex = _addedModes pushBackUnique _x;
                            // "Fix" bug where ACE modes would be duplicated endlessly
                            if (_uniqueIndex >= 0) then {
                                _modes = _modes + '"' + _x + '"' + ",";
                            };
                            if (_inheritMode == "") then {
                                // What all of our modes inherit off of. The first mode defined should be the one that works
                                _inheritMode = _x;
                            };
                        };
                    } foreach _allModes;
                    
                    // This next bit is to make sure that all the modes are defined in an order that guarentees that
                    // inheritance will work.
                    reverse _predefinedModes;
                    private _predefinedModesCorrect = [];
                    {
                        for "_index" from (_foreachindex + 1) to (count _predefinedModes) do {
                            if ((_x select 0) == ((_predefinedModes select _index) select 1)) then {
                                _predefinedModesCorrect pushBackUnique ((_predefinedModes select _index) select 2);
                                _predefinedModesCorrect pushBackUnique (_x select 2);
                            };
                        };
                        _predefinedModesCorrect pushBackUnique (_x select 2);
                    } foreach _predefinedModes;
                    
                    reverse _predefinedModesCorrect;
                    _weaponStr = _weaponStr + (_predefinedModesCorrect joinString "");
                    
                    private _customModeDat = _typeDefines select (_x select 0);
                    private _customModeDef = "";
                    
                    {
                        // _x = {burst,rof,rof_dist,minRange,minRangeProb,midRange,midRangeProb,maxRange,maxRangeProb}
                        private _modeData = _x;
                        while {count _modeData < 9} do {
                            _modeData pushBack -1;
                        };
                        
                        private _hasData = {
                            if (str(_x) != "-1") exitWith { true };
                        } foreach _modeData;

                        if (!isNil {_hasData}) then {
                            private _customMode = _customModes select _foreachindex;
                            _modes = _modes + '"' + (_customMode select 0) + '"' + ",";
                            
                            _customModeDef = _customModeDef + INDENT + INDENT + "class " + (_customMode select 0) + ": " + _inheritMode + " {" + LINE_BREAK;
                            _customModeDef = _customModeDef + INDENT + INDENT + INDENT + "showToPlayer = 0;" + LINE_BREAK;
                            if (str(_modeData select 0) != "-1") then { _customModeDef = _customModeDef + MODE_DATA("burst = ",                 _modeData select 0); };
                            if (str(_modeData select 1) != "-1") then { _customModeDef = _customModeDef + MODE_DATA("aiRateOfFire = ",          _modeData select 1); };
                            if (str(_modeData select 2) != "-1") then { _customModeDef = _customModeDef + MODE_DATA("aiRateOfFireDistance = ",  _modeData select 2); };
                            if (str(_modeData select 3) != "-1") then { _customModeDef = _customModeDef + MODE_DATA("minRange = ",              _modeData select 3); };
                            if (str(_modeData select 4) != "-1") then { _customModeDef = _customModeDef + MODE_DATA("minRangeProbab = ",        _modeData select 4); };
                            if (str(_modeData select 5) != "-1") then { _customModeDef = _customModeDef + MODE_DATA("midRange = ",              _modeData select 5); };
                            if (str(_modeData select 6) != "-1") then { _customModeDef = _customModeDef + MODE_DATA("midRangeProbab = ",        _modeData select 6); };
                            if (str(_modeData select 7) != "-1") then { _customModeDef = _customModeDef + MODE_DATA("maxRange = ",              _modeData select 7); };
                            if (str(_modeData select 8) != "-1") then { _customModeDef = _customModeDef + MODE_DATA("maxRangeProbab = ",        _modeData select 8); };
                            _customModeDef = _customModeDef + INDENT + INDENT + "};" + LINE_BREAK;
                        };
                        
                    } foreach _customModeDat;
                    
                    private _modesArr = _modes splitString ",";
                    _modes = _modesArr joinString ",";
                    _modes = INDENT + INDENT + _modes + "};" + LINE_BREAK;
                    
                    _weaponClassStr = _weaponClassStr + LINE_BREAK;
                    _weaponClasses = _weaponClasses + _weaponClassStr + _modes + _weaponStr + _customModeDef + INDENT + "};" + LINE_BREAK;
                } else {
                    // Base class
                    _baseClasses = _baseClasses + _weaponClassStr + "};" + LINE_BREAK;
                };
            };
        };
    } foreach _reversedArray;
} foreach _allWeapons;

private _finalStr = CFG_WEAPONS_HEADER + _baseClasses + _weaponClasses + CFG_WEAPONS_FOOTER;

copyToClipboard _finalStr;
systemChat "Done Generating CfgWeapons";
systemChat "Finished";

