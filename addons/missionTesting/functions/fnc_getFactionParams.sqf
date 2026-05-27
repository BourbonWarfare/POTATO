#include "..\script_component.hpp"
#define CONST_SIDE_OPF 0
#define CONST_SIDE_BLU 1
#define CONST_SIDE_IND 2
#define CONST_SIDE_CIV 3
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
*
*
* Arguments:
* _faction - The faction to get the parameters for (STRING, default "potato_w")
*
* Return:
* none
*
* Example:
* ["potato_w"] call potato_missionTesting_fnc_getFactionParams;
*//***************************************************************************/
params [["_faction", "potato_w", [""]]];
private _cfgFaction = missionConfigFile >> "CfgLoadouts" >> _faction;
private _cfgFactions = configFile >> "CfgFactionClasses";
if (_faction == "" || !isClass _cfgFaction || !isClass (_cfgFactions >> _faction)) exitWith {
    //WARNING_1("Bad class armor testing init [%1]", _faction);
    []
};
if (isNil QGVAR(factionParams)) then {
    GVAR(factionParams) = createHashMap;
};

GVAR(factionParams) getOrDefaultCall [_faction, {
    // Gather initial testing pairs
    private _unitTypes = "inheritsFrom (_x >> ""weapons"") == _x" configClasses _cfgFaction;
    private _testPairs = [];
    {
        private _weapons = getArray (_x >> "weapons");
        private _magazines = getArray (_x >> "magazines");
        _magazines = _magazines apply {toLowerANSI ((_x splitString ":")#0)};
        if (count _weapons == 1) then {
            private _weapon = _weapons#0;
            private _validMags = (((compatibleMagazines [_weapon, "this"]) apply {toLowerANSI _x}) arrayIntersect _magazines);
            _testPairs pushBackUnique [toLowerANSI _weapon, _validMags#0];
        } else {
            {
                _testPairs pushBackUnique [toLowerANSI (_x#0), toLowerANSI (((_x#1#0) splitString ":")#0)];
            } forEach _weapons;
        };
    } forEach _unitTypes;
    // Remove test pairs that are simulation identical (same initSpeed, damage, airfriction)
    private _finalWeaponPairs = [];
    private _omitClassName = [];
    {
        private _params = _x call FUNC(getWeaponParams);
        private _paramsOmit = +_params;
        _paramsOmit deleteAt 0;
        _paramsOmit deleteAt 0;
        if (_omitClassName pushBackUnique _paramsOmit >=0) then {
            _finalWeaponPairs pushBack _params;
        };
    } forEach _testPairs;
    // check if we're using AMA or if we have to use classes
    private _side = switch (getNumber (_cfgFactions >> _faction >> "side")) do {
        case CONST_SIDE_OPF: {east};
        case CONST_SIDE_BLU: {west};
        case CONST_SIDE_IND: {resistance};
        default {civilian};
    };
    private _armor = EGVAR(armor_modifier_ace,armorValueHash) getOrDefault [_side, EGVAR(armor_modifier_ace,defaultArmorHash)];
    private _hitDiaphragm = _armor getOrDefault ["hitdiaphragm", [1,0,0]];
    private _unitClasses = [format ["%1_rifleman",_faction]];
    if (0 == _hitDiaphragm#1 && 0 == _hitDiaphragm#2) then { // skip if we can
        _unitClasses = [];
        // find all the vests and make sure they're unique
        _unitTypes = "inheritsFrom (_x >> ""vest"") == _x" configClasses _cfgFaction;
        private _vests = flatten (_unitTypes apply {getArray (_x >> "vest")});
        _vests = _vests apply {toLowerANSI _x};
        private _finalVests = [];
        _omitClassName = [];
        { // filter out vests with the same armor
            private _armor = [_x] call FUNC(getVestArmor);
            if (_omitClassName pushBackUnique _armor >= 0) then {
                _finalVests pushBack _x;
            };
        } forEach (_vests arrayIntersect _vests);
        _unitTypes = _unitTypes apply {configName _x};
        {
            private _unitClass = "rifleman";
            private _itr = 0;
            private _cnt = count _unitTypes;
            while {
                private _vests = (getArray (_cfgFaction >> _unitClass >> "vest")) apply {toLowerANSI _x};
                _itr < _cnt && !(_x in _vests)} do {
                _unitClass = _unitTypes#_itr;
                _itr = _itr + 1;
            };
            // Creates a corner case with random vests if one vest has none-armor, hopefully 5 samples is enough to get the outlier
            _unitClasses pushBackUnique (format ["%1_%2",_faction,_unitClass]);
        } forEach _finalVests;
    };
   [_unitClasses, _finalWeaponPairs, _side]
}, true]
