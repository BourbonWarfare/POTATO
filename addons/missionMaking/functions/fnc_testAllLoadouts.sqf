#include "script_component.hpp"

// [] call compileScript ["\z\potato\addons\missionMaking\functions\fnc_testAllLoadouts.sqf"]
// [-1, [0,3,4]] call compileScript ["\z\potato\addons\missionMaking\functions\fnc_testAllLoadouts.sqf"]

params [["_testIndex", -1, [0]], ["_ignore", [], [[]]]];
private _loadouts = "true" configClasses (missionConfigFile >> "potato_checkLoadouts");

private _checkScopeHidden = !(0 in _ignore);
private _checkBadAttachmentMacro = !(1 in _ignore);
private _checkHaveSomeAmmo = !(2 in _ignore);
private _checkPotatoMags = !(3 in _ignore);
private _checkAttachments = !(4 in _ignore);
private _checkResupply = !(5 in _ignore);




diag_log text "";
diag_log text "";
INFO_1("Found %1 loadouts",count _loadouts);
diag_log text "";
diag_log text "";

private _failingLoadouts = [];

private _cfgWeap = configFile >> "CfgWeapons";
private _cfgVeh = configFile >> "CfgVehicles";
private _cfgMag = configFile >> "CfgMagazines";

private _fnc_error = {
    params ["_error", ["_extraInfo", ""]];
    if (_error in _loadoutErrors) exitWith { false };
    _loadoutErrors pushBack _error;
    diag_log text format ["@%1:%2 - %3 %4", _loadoutName, _unitName, _error, _extraInfo];
    true
};

private _getArrayAndCheck = {
    params ["_name", "_sources"];

    (getArray (_path >> _name)) select {
        if (_x == "") then { continueWith false };
        (_x splitString ":") params ["_classname"];
        if ((_sources findIf { 
            private _config = _x >> _classname;
            if (isClass _config) then {
                if (_checkScopeHidden && {getNumber (_config >> "scope") < 2}) then {
                    if (_name == "launchers") exitWith {}; // ignore disposables
                    [format ["%1 scope<2 (from %2[])", _classname, _name]] call _fnc_error;
                };
                true
            } else {
                false
            }}) == -1) then {
            if (!(_checkBadAttachmentMacro && {"_ATTACHMENTS" in _classname})) then { 
                [format ["%1 does not exist (from %2[])", _classname, _name]] call _fnc_error;
            };
            false
        } else {
            true
        };
    }
};

{
    if ((_testIndex >= 0) && {_testIndex != _forEachIndex}) then { continue };
    private _loadoutBase = _x;
    private _loadoutName = configName _loadoutBase;
    private _loadoutUnits = "isArray (_x >> 'uniform')" configClasses _loadoutBase;
    private _loadoutErrors = [];
    private _loadoutMagReplacements = [];
    diag_log text format ["---- Loadout %1: %2 [%3 units] ----",_forEachIndex, _loadoutName, count _loadoutUnits];

    private _transportMags = (getArray (_loadoutBase >> "Car" >> "TransportMagazines"));
    _transportMags = _transportMags select {_x != ""} apply {(_x splitString ":") # 0} apply { configName (_cfgMag >> _x) } select {_x != ""};
    _transportMags = _transportMags arrayIntersect _transportMags;

    {
        private _path = _x; 
        private _unitName = configName _path;
        private _unitErrors = [];

        private _configUniform =            ["uniform", [_cfgWeap]] call _getArrayAndCheck;
        private _configVest =               ["vest", [_cfgWeap]] call _getArrayAndCheck;
        private _configHeadgear =           ["headgear", [_cfgWeap]] call _getArrayAndCheck;
        private _configBackpack =           ["backpack", [_cfgVeh]] call _getArrayAndCheck;
        private _configBackpackItems =      ["backpackItems", [_cfgWeap, _cfgMag]] call _getArrayAndCheck;
        private _configWeapons =            ["weapons", [_cfgWeap]] call _getArrayAndCheck;
        private _configLaunchers =          ["launchers", [_cfgWeap]] call _getArrayAndCheck;
        private _configHandguns =           ["handguns", [_cfgWeap]] call _getArrayAndCheck;
        private _configMagazines =          ["magazines", [_cfgWeap, _cfgMag]] call _getArrayAndCheck;
        private _configItems =              ["items", [_cfgWeap, _cfgMag]] call _getArrayAndCheck;
        private _configLinkedItems =        ["linkedItems", [_cfgWeap]] call _getArrayAndCheck;
        private _configAttachments =        ["attachments", [_cfgWeap]] call _getArrayAndCheck;
        private _configSecondaryAttachments = ["secondaryAttachments", [_cfgWeap]] call _getArrayAndCheck;
        private _configHandgunAttachments = ["handgunAttachments", [_cfgWeap]] call _getArrayAndCheck;

        private _configAttachments = _configAttachments apply { configName (_cfgWeap >> _x) };
        private _configSecondaryAttachments = _configSecondaryAttachments apply { configName (_cfgWeap >> _x) };
        private _configHandgunAttachments = _configHandgunAttachments apply { configName (_cfgWeap >> _x) };
        private _configMagazines = _configMagazines apply {(_x splitString ":") # 0} apply {configName (_cfgMag >> _x)} select {_x != ""};

        {
            _x params ["_weapons", "_magazines", "_attachments"];
            private _weaponIndex = _forEachIndex;
            
            {
                private _weapon = _x;
                private _weaponItems = compatibleItems _weapon;
                private _weaponMags = compatibleMagazines [_weapon, "this"];
                private _weaponMagsPotato = _weaponMags select {(_x select [0,7]) == "potato_"};

                // Check we haves some ammo (besides launchers)
                if (_checkHaveSomeAmmo && {_weaponIndex != 1} && {_weaponMags isNotEqualTo []} && {(_configMagazines arrayIntersect _weaponMags) isEqualTo []}) then {
                    [format ["%1 has no magazines %2", _weapon, _configMagazines]] call _fnc_error;
                };

                // Check we use potato mags if they exist for the weapon
                if (_checkPotatoMags && {_weaponMagsPotato isNotEqualTo []} && {(_configMagazines arrayIntersect (_weaponMags - _weaponMagsPotato)) isNotEqualTo []}) then {
                    private _currentMags = _configMagazines arrayIntersect _weaponMags;
                    if ([format ["%1 using non-potato mags", _x], _currentMags] call _fnc_error) then {
                        {
                            private _mag = toLower _x;
                            if (_mag in _loadoutMagReplacements) then { continue };
                            _loadoutMagReplacements pushBack _mag;
                            private _magCount = getNumber (_cfgMag >> _mag >> "count");
                            private _magTracers = getNumber (_cfgMag >> _mag >> "tracersEvery");
                            private _magColor = switch (true) do {
                                case ("_red" in _mag): {"_red"};
                                case ("_green" in _mag): {"_green"};
                                case ("_yellow" in _mag): {"_yellow"};
                                default {""};
                            };
                            private _similar = _weaponMagsPotato select {
                                (_magCount == getNumber (_cfgMag >> _x >> "count"))
                                && {_magTracers == getNumber (_cfgMag >> _x >> "tracersEvery")}
                                && {(_magColor == "") || {_magColor in toLower _x}}
                            };
                            if (_similar isEqualTo []) then { 
                                _similar = _weaponMagsPotato select {
                                    (_magCount == getNumber (_cfgMag >> _x >> "count"))
                                    && {(_magColor == "") || {_magColor in toLower _x}}
                                };
                            };
                            if (_similar isEqualTo []) then { _similar = format ["?? none found ?? - %1", _weaponMagsPotato] };
                            diag_log text format ["- replace %1 with %2", _mag, _similar];
                        } forEach _currentMags;
                    };
                };

                // Check core slots have rifle resupply ammo
                if (_checkResupply && {_weaponIndex == 0} && {(toLower _unitName) in ["rifleman", "ftl", "ar", "lat"]}) then {
                    if ((_weaponMags arrayIntersect _transportMags) isEqualTo []) then {
                        [format ["%1 has no resupply %2", _x], _transportMags] call _fnc_error;
                    };
                };

                // Check attachments are valid for gun
                if (_checkAttachments) then {
                    {
                        if (!(_x in _weaponItems)) then {
                            [format ["%1 not compatible with %2", _x, _weapon]] call _fnc_error;
                        };
                    } forEach _attachments;
                };

            } forEach _weapons;
        } forEach [
            [_configWeapons, _configMagazines, _configAttachments],
            [_configLaunchers, _configMagazines, _configSecondaryAttachments],
            [_configHandguns, _configMagazines, _configHandgunAttachments]
        ];

        // private _loadout = [_path, objNull] call potato_assignGear_fnc_getLoadoutFromConfig;
        // diag_log text format ["%1 - %2", _unitName, _loadout];
    } forEach _loadoutUnits;
    if (_loadoutErrors isNotEqualTo []) then {
        _failingLoadouts pushBack _forEachIndex;
    };
} forEach _loadouts;

diag_log text format ["----------"];
diag_log text format ["Failing: %1", _failingLoadouts];
diag_log text format ["----------"];

