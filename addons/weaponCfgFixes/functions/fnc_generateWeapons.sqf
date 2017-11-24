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
private _br = toString[13,10];
private _indent = "    ";

private _applicableClassnames = [
    "arifle_Katiba_Base_F",
    "mk20_base_F",
    "arifle_MX_Base_F",
    "Tavor_base_F",
    "arifle_MXC_F",
    "arifle_SPAR_01_base_F",
    "rhs_weap_mosin_sbr",
    "rhs_weap_m92",
    "rhs_weap_m70_base",
    "arifle_AK12_base_F",
    "rhs_weap_m4_Base",
    "rhs_weap_m38_Base_F",
    "rhs_weap_hk416d10",
    "arifle_AKM_base_F",
    "arifle_AKS_base_F",
    "arifle_ARX_base_F",
    "hlc_rifle_g3a3",
    "hlc_rifle_g3ka4",
    "hlc_rifle_hk51",
    "hlc_rifle_amt",
    "rhs_weap_ak74m_Base_F",
    "rhs_weap_akm",
    "rhs_weap_ak103_base",
    "rhs_weap_ak103_1",
    "rhs_weap_ak103_2",
    "hlc_rifle_hk53",
    "hlc_g3_base",
    "hlc_rifle_hk33a2",
    "arifle_CTAR_base_F",
    "CUP_arifle_AK_Base",
    "CUP_arifle_AK107_Base",
    "CUP_arifle_AK74",
    "CUP_arifle_AK74M_GL",
    "CUP_arifle_AK107_GL",
    "CUP_arifle_AKM",
    "CUP_arifle_CZ805_Base",
    "CUP_arifle_CZ805_B_Base",
    "CUP_arifle_G36C",
    "CUP_arifle_FNFAL",
    "CUP_arifle_G36_Base",
    "CUP_arifle_G36K",
    "CUP_arifle_XM8_Base",
    "CUP_srifle_M14",
    "CUP_l85a2_base",
    "CUP_srifle_LeeEnfield",
    "CUP_arifle_SCAR_Base",
    "CUP_arifle_Mk16_STD",
    "CUP_arifle_Mk16_SV",
    "CUP_arifle_Sa58_base",
    "arifle_CTARS_base_F",
    "CUP_arifle_Mk16_CQC",
    "CUP_arifle_M16_Base",
    "CUP_arifle_M4_Base",
    "arifle_Katiba_C_F",
    "arifle_Mk20C_F",
    "CUP_arifle_Mk17_STD_FG",
    "CUP_arifle_Mk20",
    "CUP_arifle_XM8_Compact",
    "arifle_TRG21_F",
    "CUP_arifle_AK47",
    "CUP_arifle_AK74M",
    "CUP_arifle_AK107",
    "CUP_arifle_AKS74",
    "CUP_arifle_AK74_GL",
    "CUP_arifle_AKS",
    "CUP_arifle_Mk17_CQC",
    "CUP_arifle_XM8_Railed_Base",
    "rhs_weap_kar98k_Base_F",
    "rhs_weap_savz58_base",
    "rhs_weap_stgw57_base",
    "hlc_STGW_base",
    "rhs_weap_aks74u",
    "CUP_arifle_AKS74U",
    "pdw2000_base_F",
    "SMG_01_Base",
    "SMG_02_base_F",
    "SMG_05_base_F",
    "CUP_smg_bizon",
    "CUP_smg_EVO",
    "CUP_smg_MP5SD6",
    "hlc_MP5_base",
    "hlc_smg_mp5k",
    "hlc_smg_9mmar",
    "hlc_smg_mp510",
    "rhsusf_weap_MP7A1_base_f",
    "CUP_smg_MP5A5",
    "LMG_Mk200_F",
    "LMG_Zafir_F",
    "CUP_arifle_MG36",
    "LMG_03_base_F",
    "rhs_weap_m27iar",
    "rhs_weap_M249_base",
    "rhs_weap_lmg_minimipara",
    "CUP_saw_base",
    "CUP_lmg_L110A1",
    "rhs_weap_rpk74m",
    "arifle_MX_SW_F",
    "arifle_SPAR_02_base_F",
    "CUP_arifle_RPK74",
    "CUP_arifle_xm8_SAW",
    "rhs_weap_saw_base",
    "rhs_weap_m240_base",
    "MMG_01_base_F",
    "MMG_02_base_F",
    "rhs_pkp_base",
    "CUP_M60E4_base",
    "CUP_lmg_M240",
    "CUP_lmg_UK59",
    "CUP_lmg_Mk48_Base",
    "CUP_lmg_PKM",
    "CUP_lmg_Pecheneg",
    "rhs_weap_pkm",
    "rhs_weap_sr25",
    "CUP_arifle_Mk17_Base",
    "rhs_weap_svdp",
    "CUP_srifle_Mk12SPR",
    "DMR_01_base_F",
    "EBR_base_F",
    "DMR_02_base_F",
    "DMR_03_base_F",
    "DMR_04_base_F",
    "DMR_05_base_F",
    "DMR_06_base_F",
    "arifle_MXM_F",
    "DMR_07_base_F",
    "arifle_SPAR_03_base_F",
    "CUP_srifle_M14_DMR",
    "rhs_weap_m76",
    "CUP_srifle_SVD",
    "rhs_weap_m14ebrri",
    "CUP_arifle_xm8_sharpshooter",
    "rhs_weap_svd",
    "rhs_weap_M107_Base_F",
    "hlc_rifle_psg1",
    "rhs_weap_orsis_Base_F",
    "rhs_weap_m21s",
    "rhs_weap_XM2010_Base_F",
    "LRR_base_F",
    "CUP_srifle_AWM_Base",
    "hlc_rifle_psg1A1",
    "CUP_srifle_VSSVintorez",
    "GM6_base_F",
    "CUP_srifle_AS50",
    "CUP_srifle_M107_Base",
    "CUP_srifle_M24_des",
    "CUP_srifle_M110",
    "CUP_srifle_CZ750_Base",
    "CUP_srifle_CZ550_base",
    "CUP_srifle_ksvk",
    "CUP_srifle_L129A1",
    "CUP_srifle_M40A3",
    "rhs_weap_asval",
    "rhs_weap_vss",
    "CUP_hgun_BallisticShield_Armed",
    "CUP_hgun_Glock17",
    "hgun_ACPC2_F",
    "hgun_P07_F",
    "hgun_Pistol_heavy_01_F",
    "hgun_Pistol_heavy_02_F",
    "hgun_Rook40_F",
    "CUP_hgun_M9",
    "CUP_hgun_PB6P9",
    "CUP_hgun_Phantom",
    "CUP_hgun_TaurusTracker455",
    "CUP_hgun_Makarov",
    "hgun_Pistol_01_F",
    "CUP_hgun_Colt1911",
    "CUP_hgun_Compact",
    "CUP_hgun_Duty",
    "rhs_weap_savz61",
    "CUP_hgun_SA61",
    "CUP_smg_SA61",
    "rhs_weap_pp2000",
    "CUP_hgun_MicroUzi",
    "rhs_weap_smaw",
    "rhs_weap_maaws",
    "launch_NLAW_F",
    "launch_RPG32_F",
    "launch_Titan_base",
    "CUP_launch_RPG7V",
    "launch_RPG7_F",
    "CUP_launch_Mk153Mod0",
    "CUP_sgun_Saiga12K",
    "CUP_sgun_AA12",
    "rhs_weap_Izh18",
    "CUP_sgun_M1014",
    "rhs_weap_M590_5RD"
];

private _usedApplicableClassnames = [];
{
    _usedApplicableClassnames pushBack (toLower _x);
} foreach _applicableClassnames;

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

    if (_weapon in _usedApplicableClassnames && _weaponTypeCategory != "VehicleWeapon" && _weaponTypeID >= 0) then {
        private _allModes = getArray(_weaponCfg >> "modes");
        private _procStr = "Processing '" + _weapon;
        systemChat _procStr;
        _procStr = _procStr + "' with modes + [" + str(_allModes) + "].";
        diag_log _procStr;
        if (count _allModes != 0) then {
            private _inherited = inheritsFrom(_weaponCfg);
            private _prevInherited = [];
            _prevInherited pushBack [_weaponTypeID, _weaponCfg];
            while {count _inherited > 0} do {
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
            if (_x select 0 < 0) then {
                // don't define data, just use as a base class
                if (count configName(inheritsFrom(_x select 1)) <= 0) then {
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
