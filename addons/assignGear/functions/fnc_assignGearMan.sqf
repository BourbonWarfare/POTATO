/*
 * Author: PabstMirror
 * Applies a loadout to a unit (cached)
 *
 * Arguments:
 * 0: Unit <OBJECT>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [player] call potato_assignGear_fnc_assignGearMan;
 *
 * Public: Yes
 */
#include "script_component.hpp"

params ["_unit"];
TRACE_3("assignGearMan",_unit, local _unit, typeOf _unit);

BEGIN_COUNTER(assignGearMan);

private _faction = faction _unit;
private _typeOf = typeOf _unit;
private _unitClassname = [_typeOf] call FUNC(cleanPrefix);
private _loadout = _unit getVariable ["F_Gear", _unitClassname]; //Check variable f_gear, otherwise default to typeof

private _factionPath = missionConfigFile >> "CfgLoadouts" >> _faction;
private _staticLoadoutName = getText (_factionPath >> "using"); // refernce to a static potato loadout
if (_staticLoadoutName != "") then {
    _factionPath = configFile >> "potato_loadouts" >> _faction >> _staticLoadoutName;
    if (!isClass _factionPath) then { ERROR_2("_faction %1 using bad _staticLoadoutName %2",_faction,_staticLoadoutName); };
};

private _path = _factionPath >> _loadout;

if ((!isClass(_path)) && GVAR(useFallback)) then {
    _path = _factionPath >> "fallback";
};

// Temp? BWC for older missions
if ((!isClass _path) && {(_typeOf select [0,7]) == "potato_"}) then {
    private _converstionType = 0;
    if (_faction =="potato_w" && {isClass (missionConfigFile >> "CfgLoadouts" >> "blu_f")}) then {
        _faction ="blu_f";
        _converstionType = 1;
    };
    if (_faction =="potato_i" && {isClass (missionConfigFile >> "CfgLoadouts" >> "ind_f")}) then {
        _faction ="ind_f";
        _converstionType = 1;
    };
    if (_faction =="potato_e" && {isClass (missionConfigFile >> "CfgLoadouts" >> "opf_f")}) then {
        _faction ="opf_f";
        _converstionType = 1;
    };
    if (_faction =="potato_e" && {isClass (missionConfigFile >> "CfgLoadouts" >> "potato_msv")}) then {
        _faction ="potato_msv";
        _converstionType = 2;
    };
    if (_converstionType == 0) exitWith { INFO_1("No BWC Factions %1",_typeOf); };
    private _unitRole = toLower _typeOf select [9]; // simple because potato_x_ is const length
    switch (_converstionType) do {
        case (1): {
            _loadout = switch (_unitRole) do {
                case"rifleman": {"Soldier_F"};
                case"ftl": {"Soldier_TL_F"};
                case"coy";
                case"xo";
                case"plt";
                case"sgt": {"officer_F"};
                case"mmgl";
                case"matl";
                case"mtrl";
                case"msaml";
                case"sl": {"Soldier_SL_F"};
                case"ar": {"Soldier_AR_F"};
                case"aar": {"Soldier_AAR_F"};
                case"lat": {"Soldier_LAT_F"};
                case"cm";
                case"plm";
                case"sm": {"medic_F"};
                case"mmgg": {"support_MG_F"};
                case"mmgag": {"soldier_A_F"};
                case"matg": {"soldier_AT_F"};
                case"matag": {"Soldier_AAT_F"};
                case"pilot": {"Helipilot_F"};
                case"demo": {"soldier_exp_F"};
                case"vicc";
                case"vicl": {"crew_F"};
                case"cc";
                case"vicd": {"soldier_Repair_F"};
                case"helicrew": {"helicrew_F"};
                case"spotter": {"spotter_F"};
                case"sniper": {"sniper_F"};
                case"demo";
                case"demol": {"soldier_EXP_F"};
                case"engl";
                case"eng";
                case"mine": {"engineer_F"};
                default { WARNING("Untranslated type");  "Soldier_F" };
            };
            INFO_2("Convert non-msv %1->%2",_unitRole,_loadout);
        };
        case (2): {
            _loadout = switch (_unitRole) do {
                case"rifleman": {"potato_msv_rifleman"};
                case"ftl": {"potato_msv_sr"};
                case"coy";
                case"xo";
                case"sl": {"potato_msv_plt"};
                case"coy": {"potato_msv_coy"};
                case"ar": {"potato_msv_ar"};
                case"aar": {"potato_msv_ar"};
                case"lat": {"potato_msv_g"};
                case"cm";
                case"sm": {"potato_msv_sm"};
                case"matg": {"potato_msv_matg"};
                case"matag": {"potato_msv_matag"};
                case"pilot": {"potato_msv_pilot"};
                case"demo": {"potato_msv_eng"};
                case"vicc";
                case"vicd": {"potato_msv_vicd"};
                case"uav": {"soldier_UAV_F"};
                default { WARNING("Untranslated type");  "potato_msv_rifleman" };
            };
            INFO_2("Convert msv %1:%2",_unitRole,_loadout);
        };
    };
    _path = missionConfigFile >> "CfgLoadouts" >> _faction >> _loadout;
    if (!isClass(_path)) then { WARNING_3("No bwc class found %1=%2:%3", _typeOf,_faction,_loadout); };
};


if (!isClass(_path)) exitWith {
    TRACE_2("No Class Found",_unit,_typeOf);
    _unit setVariable [QGVAR(gearSetup), true, true];
};

private _randomIndex = floor (random GVAR(maxRandomization));
private _loadoutKey = format ["%1:%2", _path, _randomIndex];

private _loadoutArray = GVAR(loadoutCache) getVariable _loadoutKey;

if (isNil "_loadoutArray") then {
    TRACE_1("compiling new",_loadoutKey);
    BEGIN_COUNTER(getLoadoutFromConfig);
    _loadoutArray = [_path, _unit] call FUNC(getLoadoutFromConfig);
    END_COUNTER(getLoadoutFromConfig);
    TRACE_1("", _loadoutArray);
    GVAR(loadoutCache) setVariable [_loadoutKey, _loadoutArray];
};

// set unit loadout overrides our sick shades :(
_loadoutArray set [LA_FACEWARE_INDEX, goggles _unit];
_unit setUnitLoadout _loadoutArray;

if (isText (_path >> "init")) then {
    TRACE_1("calling init code", getText (_path >> "init"));
    _unit call compile ("this = _this;"+ getText (_path >> "init"));
};

_unit setVariable [QGVAR(gearSetup), true, true];

END_COUNTER(assignGearMan);
