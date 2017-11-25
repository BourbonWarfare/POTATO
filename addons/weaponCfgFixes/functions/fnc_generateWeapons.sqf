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

private _br = toString[13,10];
private _indent = "    ";

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
private _sniperData =       [[-1,1.0,200,0,0.7,200,0.5,500,0.1],[],[],[],[],[],[],[],[],[-1,10,1500,1,0.4,500,0.8,1800,0.1]];
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
                _procStr = _indent + "Inherited From: " + str(_inherited);
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
            _procStr = _indent + "Inherit Array: " + str(_prevInherited);
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
            private _weaponClassStr = _indent + "class " + configName(_x select 1) + ": " + configName(inheritsFrom(_x select 1)) + " {";
            // if the index is -1, it is a base class
            if (_x select 0 < 0) then {
                // don't define data, just use as a base class
                if (count configName(inheritsFrom(_x select 1)) <= 0 || _x select 0 == LOWEST_BASE_CLASS) then {
                    _weaponClassStr = _indent + "class " + configName(_x select 1) + ";";
                    _baseClasses = _baseClasses + _weaponClassStr + _br;
                } else {
                    _weaponClassStr = _weaponClassStr + "};";
                    _weaponClasses = _weaponClasses + _weaponClassStr + _br;
                };
            } else {
                if (getArray(_x select 1 >> "modes") select 0 != "this") then {
                    // Not a base class
                    private _weaponCfg = _x select 1;
                    private _modes = "modes[] = {";
                    private _inheritMode = "";
                    private _predefinedModes = [];
                    {
                        if (_x find "potato" < 0 && configName(inheritsFrom(_weaponCfg >> _x)) != "") then {
                            private _modeName = _indent + _indent + "class " + _x + ": " + configName(inheritsFrom(_weaponCfg >> _x)) + " {" + _br;
                            // if the parent does not have any modes or the only one defined is 'this', that means that
                            // this is inheriting off of another weapon and we have to inherit the previous mode to get
                            // full data
                            if (_x in getArray(inheritsFrom(_weaponCfg) >> "modes")) then {
                                _modeName = _indent + _indent + "class " + _x + ": " + _x + " {" + _br;
                            };
                            private _modeDef = _indent + _indent + _indent + "minRangeProbab = 0; midRangeProbab = 0; maxRangeProbab = 0;" + _br;
                            _predefinedModes pushBack [_x, configName(inheritsFrom(_weaponCfg >> _x)), (_modeName + _modeDef + _indent + _indent + "};" + _br)];
                            _modes = _modes + '"' + _x + '"' + ",";
                            if (_inheritMode == "") then {
                                // What all of our modes inherit off of. The first mode defined should be the one that works
                                _inheritMode = _x;
                            };
                        };
                    } foreach getArray(_x select 1 >> "modes");
                    
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
                            
                            _customModeDef = _customModeDef + _indent + _indent + "class " + (_customMode select 0) + ": " + _inheritMode + " {" + _br;
                            _customModeDef = _customModeDef + _indent + _indent + _indent + "showToPlayer = 0;" + _br;
                            if (str(_modeData select 0) != "-1") then { _customModeDef = _customModeDef + _indent + _indent + _indent + "burst = "                   + str(_modeData select 0) + ";" + _br };
                            if (str(_modeData select 1) != "-1") then { _customModeDef = _customModeDef + _indent + _indent + _indent + "aiRateOfFire = "            + str(_modeData select 1) + ";" + _br };
                            if (str(_modeData select 2) != "-1") then { _customModeDef = _customModeDef + _indent + _indent + _indent + "aiRateOfFireDistance = "    + str(_modeData select 2) + ";" + _br };
                            if (str(_modeData select 3) != "-1") then { _customModeDef = _customModeDef + _indent + _indent + _indent + "minRange = "                + str(_modeData select 3) + ";" + _br };
                            if (str(_modeData select 4) != "-1") then { _customModeDef = _customModeDef + _indent + _indent + _indent + "minRangeProbab = "          + str(_modeData select 4) + ";" + _br };
                            if (str(_modeData select 5) != "-1") then { _customModeDef = _customModeDef + _indent + _indent + _indent + "midRange = "                + str(_modeData select 5) + ";" + _br };
                            if (str(_modeData select 6) != "-1") then { _customModeDef = _customModeDef + _indent + _indent + _indent + "midRangeProbab = "          + str(_modeData select 6) + ";" + _br };
                            if (str(_modeData select 7) != "-1") then { _customModeDef = _customModeDef + _indent + _indent + _indent + "maxRange = "                + str(_modeData select 7) + ";" + _br };
                            if (str(_modeData select 8) != "-1") then { _customModeDef = _customModeDef + _indent + _indent + _indent + "maxRangeProbab = "          + str(_modeData select 8) + ";" + _br };
                            _customModeDef = _customModeDef + _indent + _indent + "};" + _br;
                        };
                        
                    } foreach _customModeDat;
                    
                    private _modesArr = _modes splitString ",";
                    _modes = _modesArr joinString ",";
                    _modes = _indent + _indent + _modes + "};" + _br;
                    
                    _weaponClassStr = _weaponClassStr + _br;
                    _weaponClasses = _weaponClasses + _weaponClassStr + _modes + _weaponStr + _customModeDef + _indent + "};" + _br;
                } else {
                    // Base class
                    _baseClasses = _baseClasses + _weaponClassStr + "};" + _br;
                };
            };
        };
    } foreach _reversedArray;
} foreach _allWeapons;

private _finalStr = "class Mode_FullAuto;" + _br + "class Mode_Burst;" + _br + "class Mode_SemiAuto;" + _br + "class CfgWeapons {" + _br + _baseClasses + _weaponClasses + "};" + _br + _br;

copyToClipboard _finalStr;
systemChat "Done Generating CfgWeapons";
systemChat "Finished";

