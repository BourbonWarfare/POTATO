#include "script_component.hpp"

private _startTime = diag_tickTime;

diag_log text "";
diag_log text "------------------------------------------------------";
diag_log text "[POTATO] Saving - Doing mission test:";
diag_log text "------------------------------------------------------";

private _allMissionObjects = (all3DENEntities select 0);
private _allUnits = _allMissionObjects select {_x isKindOf "CaManBase"};
private _sideCounts = [west, east, resistance] apply {
    private _side = _x;
    {((side _x) == _side) && {(_x get3DENAttribute "ControlMP") isEqualTo [true]}} count _allUnits;
};
private _sortedCounts = +_sideCounts;
_sortedCounts sort false;
private _isTVT = (_sortedCounts select 1) > 10;
INFO_3("Placed on mission: [Units: %1] [Non-unit Objects: %2][Playable Slots: %3]", count _allUnits, (count _allMissionObjects) - (count _allUnits), _sideCounts);

private _bwmfDate = getText (missionConfigFile >> "bwmfDate");
if (_bwmfDate == "") exitWith {
    ["Saving: Non-framework mission (missing description.ext?)"] call BIS_fnc_3DENNotification;
    WARNING("Non-framework mission (missing description.ext?)");
};
if (!(missionNamespace getVariable [QEGVAR(assignGear,usePotato), false])) exitWith {
    ["Saving: Potato Gear is disabled"] call BIS_fnc_3DENNotification;
    WARNING("Potato Gear is disabled");
};

private _problems = [];


// Check briefing/author/onLoad attributies:
private _author = "Scenario" get3DENMissionAttribute "author";
if (_author == "*** Insert author name here. ***") then {
    _problems pushBackUnique ["Need to set author", ["Attributes -> General -> Author"]];
};
private _slottingInfo = "Intel" get3DENMissionAttribute "IntelOverviewText";
if (_slottingInfo == "*** Insert mission description here. ***") then {
    _problems pushBackUnique ["Need to set slotting mission description", ["Attributes -> Multiplayer -> Summary"]];
} else {
    if (_isTVT && {(parseNumber (_slottingInfo select [0,1])) == 0}) then { // very basic ratio detection
        _problems pushBackUnique ["Should add ratio", ["Attributes -> Multiplayer -> Summary"]];
    };
};
private _onLoadName = getText (missionConfigFile >> "onLoadName");
if (_onLoadName == "*** Insert mission name here. ***") then {
    _problems pushBackUnique ["Minor: Need to set loading screen info", ["description.ext -> onLoadName"]];
};


// Floating units / Fall Damage:
private _floatingUnits = [];
{
    if (((getPos _x) select 2) > 0.5) then {
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
            if ((typeOf _x) == "O_helicrew_f") exitWith {}; // todo: fix framework
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
{
    private _unit = _x;
    private _typeOf = toLower typeOf _unit;
    if ((side _unit) != civilian) then { // Ignore all civilians
        // Check all units have a primary weapon:
        if ((primaryWeapon _unit) == "") then {
            if (_typeOf == "potato_msv_pol") exitWith {};
            TRACE_1("no rifle",_typeOf);
            _checkWeapons pushBackUnique format ["%1 has no primaryWeapon", _typeOf];
        };
        // Check AT actualy have some kind of AT
        if ((_typeOf find "soldier_at_f" > -1) || {_typeOf find "soldier_lat_f" > -1} || {_typeOf find "msv_g" > -1} || {_typeOf find "msv_matg" > -1}) then {
            if ((secondaryWeapon _unit) == "") then {
                TRACE_1("no AT",_typeOf);
                _checkWeapons pushBackUnique format ["%1 has no secondaryWeapon", _typeOf];
            };
        };
        {// Check ammo count for all weapons:
            private _weapon = _x;
            if (_x != "") then {
                private _ammoCount = 0;
                private _weaponMags = (getArray (configFile >> "cfgWeapons" >> _weapon >> "magazines")) apply {toLower _x};
                {
                    _x params ["_xMagName", "_xAmmo"];
                    if ((toLower _xMagName) in _weaponMags) then {
                        _ammoCount = _ammoCount + _xAmmo;
                    };
                } forEach (magazinesAmmoFull _unit);
                if (_ammoCount == 0) then {
                    if ((toLower _weapon) in ["rhs_weap_rpg26", "rhs_weap_m136", "launch_nlaw_f"]) then {
                        TRACE_1("ignoring special AT reloads",_weapon);
                    } else {
                        TRACE_2("has zero ammo",_typeOf,_weapon);
                        _checkMagazines pushBackUnique format ["%1 has no ammo for %2", _typeOf, _weapon];
                    };
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
            private _msg = format ["[%1/%2] %3:%4", (_forEachIndex + 1), count _problems, _errorCode, _errorArray];
            systemChat _msg;
            [_msg] call BIS_fnc_3DENNotification;
            INFO_1("%1",_msg);
            uiSleep 1.5;
        } forEach _problems;
    };
};

nil
