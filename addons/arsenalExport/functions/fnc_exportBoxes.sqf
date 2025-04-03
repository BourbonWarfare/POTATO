#include "script_component.hpp"
#define QQUOTE(var1) QUOTE(QUOTE(var1))

params [["_boxType", "FT", [""]]];
TRACE_1("exportBoxes",_this);

#define RIFLE_ROUNDS 300
#define GLRIFLE_ROUNDS 150
#define CARBINE_ROUNDS 300
#define AR_ROUNDS 600
#define LAT_ROUNDS 2
#define LAT_CRATE_ROUNDS 6
#define LAT_CRATE_MAX_ROUNDS 8
#define MAT_ROUNDS 6
#define HAT_ROUNDS 4
#define MMG_ROUNDS 1000
#define HMG_ROUNDS 800

private _lines = [];
private _transWeaps = [];
private _transMags = [];
private _transItems = [];
private _fnc_dumpBoxType = {
    params ["_boxConfig", "_boxName"];
    _lines pushBack format ["class %1 {", _boxConfig];
    _lines pushBack format ["  boxCustomName = ""%1"";", _boxName];
    // Weapons
    if (_transWeaps isNotEqualTo []) then {
        _lines pushBack "  TransportWeapons[] = {";
        private _count = count _transWeaps - 1;
        {
            _lines pushBack format ["    ""%1""%2", _x, [",", ""] select (_count == _forEachIndex)];
        } forEach _transWeaps;
        _lines pushBack "  };";
        _transWeaps = [];
    };
    // Magazines
    if (_transMags isNotEqualTo []) then {
        _lines pushBack "  TransportMagazines[] = {";
        private _count = count _transMags - 1;
        {
            _lines pushBack format ["    ""%1""%2", _x, [",", ""] select (_count == _forEachIndex)];
        } forEach _transMags;
        _lines pushBack "  };";
        _transMags = [];
    };
    // Items
    if (_transItems isNotEqualTo []) then {
        _lines pushBack "  TransportItems[] = {";
        private _count = count _transItems - 1;
        {
            _lines pushBack format ["    ""%1""%2", _x, [",", ""] select (_count == _forEachIndex)];
        } forEach _transItems;
        _lines pushBack "  };";
        _transItems = [];
    };
    _lines pushBack "};";
};
private _fnc_default = {
    params ["_gvar",["_default",""]];
    if(isNil _gvar) exitWith {_default};
    _gvar
};
private _fnc_getMags = {
    params ["_weapon", "_mags", ["_wantedRounds", -1]];
    if (!(_mags isEqualType [])) exitWith {""};
    private _magRounds = getNumber (configFile >> "CfgMagazines" >> (_mags param [0, ""]) >> "count");
    if (_magRounds == 0) exitWith {"ERROR_no_valid_mags"};
    private _return = "";
    {
        if (_wantedRounds <= 0) then {
            _return = _return + format ["%1:1", _x];
        } else {
            private _magCount = 2;
            if (_forEachIndex == 0) then {_magCount = 1 max ((ceil (_wantedRounds / _magRounds)) - 2 * ((count _mags) - 1));};
            _return = _return + format ["%1:%2", _x, _magCount];
        };
        if (_forEachIndex < ((count _mags) -1)) then {_return = _return + ", ";};
    } forEach _mags;
    TRACE_4("getMags",_weapon,_mags,_wantedRounds,_return);
    _return
};


switch (_boxType) do {
    case "FT": {
        if ((getArray (configFile >> "CBA_DisposableLaunchers" >> GVAR(loadout_at))) isNotEqualTo []) then {
            _transWeaps = [GVAR(loadout_at) + QUOTE(:LAT_ROUNDS)];
        } else {
            {
                _transMags pushBack (_x + QUOTE(:LAT_ROUNDS));
            } forEach GVAR(loadout_atMags);
        };
        // Add hand grenades
        private _grenadeCount = count GVAR(loadout_handGrenade);
        if (_grenadeCount > 1) then {
            private _newCount = floor (6 / _grenadeCount);
            {
                _transMags pushBack (format ["%1:%2", _x, _newCount]);
            } forEach GVAR(loadout_handGrenade);
        } else {
            if (GVAR(loadout_handGrenade) isEqualTo []) then {
                _transMags pushBack ("HandGrenade:6");
            } else {
                _transMags pushBack ((GVAR(loadout_handGrenade)#0) + ":6");
            };
        };
        // Add smoke grenades
        _grenadeCount = count GVAR(loadout_smokeGrenade);
        if (_grenadeCount > 1) then {
            private _newCount = floor (6 / _grenadeCount);
            {
                _transMags pushBack (format ["%1:%2", _x, _newCount]);
            } forEach GVAR(loadout_smokeGrenade);
        } else {
            if (GVAR(loadout_smokeGrenade) isEqualTo []) then {
                _transMags pushBack ("SmokeShell:6");
            } else {
                _transMags pushBack ((GVAR(loadout_smokeGrenade)#0) + ":6");
            };
        };

        private _glMuzzle = (getArray (configFile >> "CfgWeapons" >> GVAR(loadout_glrifle) >> "muzzles")) param [1, "no2ndMuzzle"];
        private _glMags = [configFile >> "CfgWeapons" >> GVAR(loadout_glrifle) >> _glMuzzle] call CBA_fnc_compatibleMagazines;
        switch (true) do {
            case (({"1Rnd_Smoke_Grenade_shell" == _x} count _glMags) > 0): {
                _transMags append [
                    "1Rnd_Smoke_Grenade_shell:4",
                    "1Rnd_SmokeRed_Grenade_shell",
                    "1Rnd_SmokeGreen_Grenade_shell",
                    "potato_1Rnd_40mm_m433_HEDP:6"
                ];
            };
            case (({"rhs_GRD40_White" == _x} count _glMags) > 0): {
                _transMags append [
                    "rhs_GRD40_White:4",
                    "rhs_GRD40_Green",
                    "rhs_GRD40_Red",
                    "rhs_VOG25:6"
                ];
            };
            default {};
        };
        // Lets create as little clutter as possible so we put some effort into merging similar mags
        private _magsToAdd = flatten [
            [GVAR(loadout_ar), GVAR(loadout_arMags), AR_ROUNDS] call _fnc_getMags,
            [GVAR(loadout_rifle), GVAR(loadout_rifleMags), RIFLE_ROUNDS] call _fnc_getMags,
            [GVAR(loadout_glrifle), GVAR(loadout_glRifleMags), GLRIFLE_ROUNDS] call _fnc_getMags,
            [GVAR(loadout_carbine), GVAR(loadout_carbineMags), CARBINE_ROUNDS] call _fnc_getMags
        ];
        _magsToAdd = flatten (_magsToAdd apply {_x splitString ", "});
        private _magHash = createHashMap; // use a hash map to merge the same mags
        {
            (_x splitString ":") params ["_mag", ["_count", "1"]];
            _count = parseNumber _count;
            if (_mag in _magHash) then {
                _magHash set [_mag, _count + (_magHash get _mag)];
            } else {
                _magHash set [_mag, _count];
            };
        } forEach _magsToAdd;
        { // add mags to _transMags
            _transMags pushBack (format ["%1:%2", _x, _y]);
        } forEach _magHash;
        _transItems = [
            "ACE_elasticBandage:25",
            "ACE_packingBandage:10",
            "ACE_splint:6",
            "potato_pkblister:2"
        ];
        ["Box_NATO_Ammo_F", "Fireteam Resupply"] call _fnc_dumpBoxType;
    };
    case "AT": {
        /// LAT Boxes - 6 tubes or 10 rockets
        if ((getArray (configFile >> "CBA_DisposableLaunchers" >> GVAR(loadout_at))) isNotEqualTo []) then {
            _transWeaps = [GVAR(loadout_at) + QUOTE(:LAT_CRATE_ROUNDS)];
        } else {
            private _count = count GVAR(loadout_atMags);
            private _nRounds = floor (LAT_CRATE_MAX_ROUNDS / _count);
            {
                _transMags pushBack format ["%1:%2", _x, _nRounds];
            } forEach GVAR(loadout_atMags);
        };
        ["Box_NATO_WpsLaunch_F", "Launcher Crate"] call _fnc_dumpBoxType;
        if ((getArray (configFile >> "CBA_DisposableLaunchers" >> GVAR(loadout_mat))) isNotEqualTo []) then {
            _transWeaps = [GVAR(loadout_mat) + QUOTE(:MAT_ROUNDS)];
        } else {
            private _count = count GVAR(loadout_matMags);
            private _nRounds = floor (MAT_ROUNDS / _count);
            {
                _transMags pushBack format ["%1:%2", _x, _nRounds];
            } forEach GVAR(loadout_matMags);
        };
        ["Box_NATO_WpsSpecial_F", "MAT Crate"] call _fnc_dumpBoxType;
        if ((getArray (configFile >> "CBA_DisposableLaunchers" >> GVAR(loadout_hat))) isNotEqualTo []) then {
            _transWeaps = [GVAR(loadout_hat) + QUOTE(:HAT_ROUNDS)];
        } else {
            private _count = count GVAR(loadout_hatMags);
            private _nRounds = floor (HAT_ROUNDS / _count);
            {
                _transMags pushBack format ["%1:%2", _x, _nRounds];
            } forEach GVAR(loadout_hatMags);
        };
        ["Box_EAF_WpsSpecial_F", "HAT Crate"] call _fnc_dumpBoxType;
    };
    case "MG": {
        /// MMG Crate
        _transMags = flatten (([GVAR(loadout_mmg), GVAR(loadout_mmgMags), MMG_ROUNDS] call _fnc_getMags) splitString ", ");
        ["Box_NATO_Support_F", "MMG Crate"] call _fnc_dumpBoxType;
        _transMags = flatten (([GVAR(loadout_hmg), GVAR(loadout_hmgMags), HMG_ROUNDS] call _fnc_getMags) splitString ", ");
        if ("ERROR_no_valid_mags" in _transMags) then {
            _transMags = [
                "Could not find relevant mag, may be NSV or M2:",
                "ace_csw_50Rnd_127x108_mag:5",
                "ace_csw_100Rnd_127x99_mag:5"
            ];
        };
        ["Box_NATO_Wps_F",  "HMG Crate"] call _fnc_dumpBoxType;
    };
};

{
    "ace" callExtension ["clipboard:append", [_x + endl]];
} forEach _lines;
"ace" callExtension ["clipboard:complete", []];
switch (_boxType) do {
    case "FT": {
        systemChat format ["Copied fireteam crate @ %1", CBA_missionTime];
    };
    case "AT": {
        systemChat format ["Copied LAT, MAT, & HAT crates @ %1", CBA_missionTime];
    };
    case "MG": {
        systemChat format ["Copied MMG & HMG crates @ %1", CBA_missionTime];
    };
};
