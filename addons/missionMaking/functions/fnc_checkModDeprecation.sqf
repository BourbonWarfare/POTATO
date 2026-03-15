#include "..\script_component.hpp"
(profileNamespace getVariable [QGVAR(modUpdateInfo), [[], "false", 0]]) params ["_terrains", "_selectionCode", "_validDate"];

// quick exit so you don't search for ms at a time for no reason
private _date = systemTimeUTC;
_date = 10000 * _date#0 + 100 * _date#1 + _date#2;
if (_date > _validDate) exitWith {};

private _cfgPatches = _selectionCode configClasses (configFile >> "CfgPatches");
_cfgPatches = _cfgPatches apply {toLowerANSI configName _x};

private _items = [];
if (_cfgPatches isNotEqualTo []) then {
	private _allMissionObjects = all3DENEntities select 0;
	private _allUnits = _allMissionObjects select {(_x isKindOf "CaManBase") && {!((_x isKindOf "B_UAV_AI") || {_x isKindOf "O_UAV_AI"} || {_x isKindOf "UAV_AI_base_F"})}};
	private _allVehicles = _allMissionObjects select {_x isKindOf "LandVehicles" || {_x isKindOf "Air"}};
	private _weapCfg = configFile >> "CfgWeapons";
	private _magCfg = configFile >>  "CfgMagazines";
	private _cfgVic = configFile >> "CfgVehicles";
	private _weapons = [];
	private _magazines = [];
	private _vehicles = [];
	{
		private _configRoot = missionConfigFile >> "CfgLoadouts" >> _x;
		{
			private _gearArray = [];
			{
				{
					(_x splitString ":") params ["_item"];
					_gearArray pushBack _item;
				} forEach (flatten getArray _x) - [""];
			} forEach configProperties [_x, "true", false];
			_gearArray = _gearArray arrayIntersect _gearArray;
			{
				if (isClass (_magCfg >> _x)) then {
					_magazines pushBack _x;
				} else {
					if (isClass (_weapCfg >> _x)) then {
						_weapons pushBack _x;
					} else {
						_vehicles pushBackUnique _x;
					};
				};
			} forEach _gearArray;
		} forEach configProperties [_configRoot, "isClass _x"];
	} forEach ["potato_w", "potato_e", "potato_i", "SupplyBoxes"];

	_weapons = _weapons arrayIntersect _weapons;
	_magazines = flatten _magazines;
	_magazines = _magazines arrayIntersect _magazines;

	{
		private _cfg = _weapCfg >> _x;
		while {"Default" != configName _cfg && !isNull _cfg} do {
			private _patch = configSourceAddonList _cfg;
			if (_patch isEqualTo []) then {_cfg = inheritsFrom _cfg; continue};
			if (toLowerANSI (_patch#0) in _cfgPatches) exitWith {
				_items pushBackUnique [getText (_weapCfg >> _x >> "DisplayName"), _x, _patch#0];
			};
			_cfg = inheritsFrom _cfg;
		};
	} forEach _weapons;
	{
		private _cfg = _magCfg >> _x;
		while {"Default" != configName _cfg && !isNull _cfg} do {
			private _patch = configSourceAddonList _cfg;
			if (_patch isEqualTo []) then {_cfg = inheritsFrom _cfg; continue};
			if (toLowerANSI (_patch#0) in _cfgPatches) exitWith {
				_items pushBackUnique [getText (_magCfg >> _x >> "DisplayName"), _x, _patch#0];
			};
			_cfg = inheritsFrom _cfg;
		};
	} forEach _magazines;
	{
		private _cfg = _cfgVic >> _x;
		while {"Default" != configName _cfg && !isNull _cfg} do {
			private _patch = configSourceAddonList _cfg;
			if (_patch isEqualTo []) then {_cfg = inheritsFrom _cfg; continue};
			if (toLowerANSI  (_patch#0) in _cfgPatches) exitWith {
				_items pushBackUnique [getText (_cfgVic >> _x >> "DisplayName"), _x, _patch#0];
			};
			_cfg = inheritsFrom _cfg;
		};
	} forEach _vehicles;

	{
	private _cfg = configOf _x;
	while {"Default" != configName _cfg && !isNull _cfg} do {
		private _patch = (configSourceAddonList _cfg)#0;
		if (toLowerANSI _patch in _cfgPatches) exitWith {
			_items pushBackUnique [getText (configOf _x >> "DisplayName"), typeOf _x, _patch];
		};
		_cfg = inheritsFrom _cfg;
	};
	} forEach vehicles;
};
[_items, _terrains] spawn {
    params ["_items", "_terrains"];
    uiSleep 1.5;
    if (toLowerANSI worldName in _terrains) then {
        private _msg = "Terrain slated for removal in next BW modset update";
        systemChat _msg;
        [_msg] call BIS_fnc_3DENNotification;
        uiSleep 1.5;
    };
    private _itemCount = count _items;
    if (_itemCount > 0) then {
        private _msg = format ["Mission uses [%1] vehicles, weapons, or items part of mods slated for removal including:", _itemCount];
        systemChat _msg;
        [_msg] call BIS_fnc_3DENNotification;
        uiSleep 2.5;
        for "_i" from 0 to _itemCount - 1 do {
            (_items#_i) params ["_name", "_class", "_patch"];
            private _msg = if (_itemCount > 8 && _i == 4) then {
                format ["[%1/%2] %3 (%4) is part of %5 + %6 more", (_i + 1), _itemCount, _name, _class, _patch, _itemCount - 5];
            } else {
                format ["[%1/%2] %3 (%4) is part of %5", (_i + 1), _itemCount, _name, _class, _patch];
            };
            systemChat _msg;
            if (_i < 5 || ((_itemCount > 10 && _i < 5) || (_i < 10 && _itemCount <= 8))) then {
                [_msg] call BIS_fnc_3DENNotification;
                uiSleep 1.5;
            };
        };
    };
};
