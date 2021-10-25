#include "script_component.hpp"

private _startTime = diag_tickTime;

diag_log text "";
diag_log text "------------------------------------------------------";
diag_log text "[POTATO] Saving - Doing mission test:";
diag_log text "------------------------------------------------------";

private _allMissionObjects = (all3DENEntities select 0);
private _allUnits = _allMissionObjects select {(_x isKindOf "CaManBase") && {!((_x isKindOf "B_UAV_AI") || {_x isKindOf "O_UAV_AI"} || {_x isKindOf "UAV_AI_base_F"})}};
private _sideCounts = [west, east, resistance] apply {
    private _side = _x;
    {((side _x) == _side) && {(_x get3DENAttribute "ControlMP") isEqualTo [true]}} count _allUnits;
};
private _sortedCounts = +_sideCounts;
_sortedCounts sort false;
private _isTVT = (_sortedCounts select 1) > 10;
INFO_3("Placed on mission: [Units: %1] [Non-unit Objects: %2][Playable Slots: %3]", count _allUnits, (count _allMissionObjects) - (count _allUnits), _sideCounts);

private _cmfVers = getText (missionConfigFile >> "cmfVers");
if (_cmfVers == "") exitWith {
    ["Saving: Non-framework mission (missing description.ext?)"] call BIS_fnc_3DENNotification;
    WARNING("Non-framework mission (missing description.ext?)");
};
if (!(missionNamespace getVariable [QEGVAR(assignGear,usePotato), false])) exitWith {
    ["Saving: Potato Gear is disabled"] call BIS_fnc_3DENNotification;
    WARNING("Potato Gear is disabled");
};

private _problems = [];
private _cfgW = configFile >> "CfgWeapons";
private _cfgV = configFile >> "CfgVehicles";


// Tag Slots that use Premium DLC content (disabled because too many false positives)
/*
private _premiumMods = (configProperties [configFile >> "CfgMods", "isClass _x && {((getText (_x >> 'popupMsgText')) find 'premium') > -1}", true]) apply {configName _x};
_premiumMods = _premiumMods - ["Expansion"]; // ignore tanoa
INFO_1("Checking premium DLC %1",_premiumMods);
private _dlcSeen = [];
private _tagsChanged = [];
{
    private _mp = _x get3DENAttribute "ControlMP";
    if (_mp param [0]) then {
        private _originalDescription = (_x get3DENAttribute "description") param [0];
        private _newDescription = _originalDescription;
        if ((_newDescription select [0,1]) == "*") then { // cleanup old description
            private _lastStar = 0;
            for "_i" from 1 to (-1 + count _newDescription) do {
                if ((_newDescription select [_i, 1]) == "*") then {
                    _lastStar = _i;
                };
            };
            _newDescription = _newDescription select [_lastStar + 1];
        };
        private _unitDLC = [];
        private _unitItems = [];
        {
            private _itemDLC = getText (_x >> "DLC");
            if ((_itemDLC != "") && {(_premiumMods findIf {_itemDLC == _x}) > -1}) then {
                _dlcSeen pushBackUnique _itemDLC;
                _unitDLC pushBackUnique _itemDLC;
                _unitItems pushBackUnique [configName _x, _itemDLC];
            };
        } forEach [
        _cfgW >> uniform _x, _cfgW >> vest _x, _cfgV >> backpack _x, _cfgW >> headGear _x,
        _cfgW >> primaryWeapon _x, _cfgW >> secondaryWeapon _x, _cfgW >> handgunWeapon _x
        ];
        if ((count _unitDLC) > 0) then {
            private _prefix = "*";
            {
                _prefix = _prefix + (_x select [0, 5]) + "*";
            } forEach _unitDLC;
            _newDescription = _prefix + _newDescription;
        };
        if (_newDescription != _originalDescription) then {
            diag_log text format ["dlc description %1 - %2 %3 because of %4",_x,_originalDescription,_newDescription, _unitItems];
            _tagsChanged pushBack _x;
            _x set3DENAttribute ["description", _newDescription];
        };
    };
} forEach _allUnits;
if ((count _tagsChanged) > 0) then {
    systemChat "Save again to confim changes to descriptions";
    _problems pushBack [format ["Auto-Tagging DLC %1<br/>SAVE AGAIN to confirm!", _dlcSeen],_tagsChanged];
};
INFO_1("DLC Used: %1",_dlcSeen);
 */


// Check weather:
("Intel" get3DENMissionAttribute "IntelFogStart") params ["_fog"];
if (_fog > 0.25) then {
    _problems pushBackUnique [(format ["Verify visibility in high fog (%1%2)", (_fog * 100) toFixed 1, "%"]), ["Attributes -> Enviroment"]];
};


// Check briefing/author/onLoad attributies:
private _author = "Scenario" get3DENMissionAttribute "author";
if (_author == "*** Insert Author Name ***") then {
    _problems pushBackUnique ["Need to set author", ["Attributes -> General -> Author"]];
};
private _slottingInfo = "Intel" get3DENMissionAttribute "IntelOverviewText";
if (_slottingInfo == "COOP40 - [Attack/Defend] | [Explain faction and gear type] | [Specialties] | [Zeus is/not Required]") then {
    _problems pushBackUnique ["Need to set slotting mission description", ["Attributes -> Multiplayer -> Summary"]];
} else {
    if (_isTVT && {(parseNumber (_slottingInfo select [0,1])) == 0}) then { // very basic ratio detection
        _problems pushBackUnique ["Should add ratio", ["Attributes -> Multiplayer -> Summary"]];
    };
};
private _onLoadName = "Scenario" get3DENMissionAttribute "IntelBriefingName";
if (_onLoadName == "*** Insert Mission Name ***") then {
    _problems pushBackUnique ["Minor: Need to set loading screen info", ["Attributes -> General"]];
};

private _missionType = (getMissionConfigValue QEGVAR(missionTesting,missionType));
if (_missionType == 0) then {
    _problems pushBackUnique ["Need to select mission type", ["POTATO -> Mission Testing Attributes -> Mission Type"]];
};

private _missionLength = getMissionConfigValue QEGVAR(missionTesting,missionTimeLength);
if (_missionLength == -1) then {
    _problems pushBackUnique ["Verify mission time limit. Currently it's set to no time limit.", ["POTATO -> Mission Testing Attributes -> Mission Length"]];
};

private _vdLimit = getMissionConfigValue QEGVAR(missionTesting,maxViewDistance);
if (_vdLimit == -1) then {
    _problems pushBackUnique ["Verify mission view distance. Currently it's set to no limit.", ["POTATO -> Mission Testing Attributes -> View Distance Limit"]];
};

// Floating units / Fall Damage:
private _floatingUnits = [];
{
    if (((getPos vehicle _x) select 2) > 0.5) then {
        WARNING_3("[%1:%2] is floating %3", _x, typeOf _x, getPos _x);
        _floatingUnits pushBack _x;
    };
} forEach _allUnits;
if (!(_floatingUnits isEqualTo [])) then {
    _problems pushBack ["Possible Fall Damage (Soldier placed above ground level)", _floatingUnits];
};


// Verify loadouts exist for all units:
private _classesFallback = [];
private _classesNone= [];
{
    private _faction = toLower faction _x;
    private _unitClassname = [typeOf _x] call EFUNC(assignGear,cleanPrefix);
    private _path = missionConfigFile >> "CfgLoadouts" >> _faction >> _unitClassname;

    if ((!isClass(_path)) && EGVAR(assignGear,useFallback)) then {
        _path = missionConfigFile >> "CfgLoadouts" >> _faction >> "fallback";
        if (isClass _path) then {
            if (getText (configFile >> "CfgVehicles" >> typeOf _x >> "simulation") == "UAVPilot") exitWith {}; // Ignore UAV
            TRACE_1("using fallback",typeOf _x);
            _classesFallback pushBackUnique (typeOf _x);
        } else {
            TRACE_1("has no fallback",typeOf _x);
            _classesNone pushBackUnique (typeOf _x);
        };
    };
    if (!isClass(_path)) exitWith {};
} forEach _allUnits;
if (!(_classesFallback isEqualTo [])) then {
    _problems pushBack ["Minor: Unit placed that are using fallback", _classesFallback];
};
if (!(_classesNone isEqualTo [])) then {
    _problems pushBack ["Unit placed that have no loadout", _classesNone];
};


// Verify units have weapons and enough magazines:
private _checkWeapons = [];
private _checkMagazines = [];
private _checkMedical = [];
private _checkDeprecatedGear = [];
{
    private _unit = _x;
    private _typeOf = toLower typeOf _unit;
    if ((side _unit) != civilian) then { // Ignore all civilians
        // Check all units have a primary weapon:
        if ((primaryWeapon _unit) == "") then {
            TRACE_1("no rifle",_typeOf);
            _checkWeapons pushBackUnique format ["%1 has no primaryWeapon", _typeOf];
        };
        // Check AT actualy have some kind of AT
        if ((_typeOf find "matg" > -1) || {_typeOf find "lat" > -1} || {_typeOf find "msv_g" > -1} || {_typeOf find "msv_matg" > -1}) then {
            if ((secondaryWeapon _unit) == "") then {
                TRACE_1("no AT",_typeOf);
                _checkWeapons pushBackUnique format ["%1 has no secondaryWeapon", _typeOf];
            };
        };
        {// Check ammo count for all weapons:
            private _weapon = _x;
            if (_x != "") then {
                private _ammoCount = 0;
                private _weaponMags = [_weapon] call CBA_fnc_compatibleMagazines;
                {
                    _x params ["_xMagName", "_xAmmo"];
                    if (_xMagName in _weaponMags) then {
                        _ammoCount = _ammoCount + _xAmmo;
                    };
                } forEach (magazinesAmmoFull _unit);
                if (_ammoCount == 0) then {
                    TRACE_3("has zero ammo",_typeOf,_weapon,magazines _unit);
                    _checkMagazines pushBackUnique format ["%1 has no ammo for %2", _typeOf, _weapon];
                };
                if (_weapon == (primaryWeapon _unit)) then {
                    private _desiredAmmo = call {
                        // allow low ammo count for long range gunners
                        if ((_typeOf find "marksman" > -1) || {_typeOf find "spotter" > -1} || {_typeOf find "sniper" > -1}) exitWith { 20 };
                        // suggest hight ammo count for MGs
                        if ((_typeOf find "_ar" > -1) || {_typeOf find "_mg" > -1} || {_typeOf find "_mmgg" > -1}) exitWith { 250 };
                        // default rifleman case
                        100
                    };
                    if (_ammoCount <= _desiredAmmo) then {
                        TRACE_4("limited rifle ammo",_typeOf,_weapon,_ammoCount,_desiredAmmo);
                        _checkMagazines pushBackUnique format ["%1 only has %2", _typeOf, _ammoCount];
                    };
                };
            };
        } forEach [primaryWeapon _x, secondaryWeapon _x, handgunWeapon _x];

        // Check medical gear:
        private _bandageCount = {(_x == "ACE_fieldDressing") || {_x == "ACE_packingBandage"} || {_x == "ACE_elasticBandage"}} count (items _unit);
        if ((getNumber (configFile >> "CfgVehicles" >> _typeOf >> "attendant")) > 0) then {
            if (_bandageCount < 15) then {
                TRACE_1("no bandages (medic)",_typeOf);
                _checkMedical pushBackUnique format ["%1", _typeOf];
            };
        } else {
            if (_bandageCount < 1) then {
                TRACE_1("no bandages (soldier)",_typeOf);
                _checkMedical pushBackUnique format ["%1", _typeOf];
            };
        };
    };

    // Check deprecated gear:
    /*
    private _gear = (weapons _unit);
    _gear append [uniform _unit, vest _unit, backpack _unit];
    {
        if ((_x select [0, 5]) == "XXX_") then {
            _checkDeprecatedGear pushBackUnique _x;
        };
    } forEach _gear;
    */

} forEach _allUnits;

if (!(_checkWeapons isEqualTo [])) then {
    _problems pushBack ["Units missing weapons", _checkWeapons];
};
if (!(_checkMagazines isEqualTo [])) then {
    _problems pushBack ["Units missing magazines", _checkMagazines];
};
if (!(_checkMedical isEqualTo [])) then {
    _problems pushBack ["Units missing medical", _checkMedical];
};
if (!(_checkDeprecatedGear isEqualTo [])) then {
    _problems pushBack ["Units using gear from mod we will drop", _checkDeprecatedGear];
};

private _fortifies = (all3DENEntities select 3) select {_x isKindOf "potato_fortify_setupModule"};
{
    if ((_x getVariable ["Budget", -1]) < 0) then {
        _problems pushBack ["Highly recommended to set budget for fortify", [_x]];
    };
} forEach _fortifies;

TRACE_1("",_problems);
INFO_2("Finished test with %1 problems in %2 ms:", count _problems, ((diag_ticktime - _startTime) * 1000) toFixed 1);

if (_problems isEqualTo []) then {
    private _msg = "Saved: No Problems Detected!";
    systemChat _msg;
    [_msg] call BIS_fnc_3DENNotification;
    INFO_1("%1",_msg);
} else {
    [_problems] spawn {
        params ["_problems"];
        disableSerialization;
        {
            _x params ["_errorCode", "_errorArray"];
            private _errorCount = count _errorArray;
            if (_errorCount > 5) then {
                _errorArray reSize 5;
                _errorArray pushBack format [" + %1 more", _errorCount - 5];
            };
            private _msg = format ["[%1/%2] %3:%4", (_forEachIndex + 1), count _problems, _errorCode, _errorArray];
            systemChat _msg;
            [_msg] call BIS_fnc_3DENNotification;
            INFO_1("%1",_msg);
            uiSleep 1.5;
        } forEach _problems;
    };
};

nil
