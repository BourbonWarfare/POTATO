/*
 * Author: Lambda.Tiger
 * This function displays the number of AT players have on them.
 *
 * Arguments:
 * 0: The module being initialized
 *
 * Examples:
 * Should be called by module init
 *
 * Public: No
 */
params ["_logic"];
if !(local _logic) exitWith {};
deleteVehicle _logic;

private _count = createHashMap;
private _cfgAmmo = configFile >> "CfgAmmo";
private _cfgMagazines = configFile >> "CfgMagazines";
private _cfgWeapons = configFile >> "CfgWeapons";
private _weaponCache = [];
private _magazineCache = [];
private _isAT = {
    params ["_ammoCfg"];
    if ("heat" in toLowerANSI getText (_ammoCfg >> "warheadName")) exitWith {true};
    if (getText (_ammoCfg >> "submunitionAmmo") != "") then {
        [_cfgAmmo >> (getText (_ammoCfg >> "submunitionAmmo"))] call _isAT;
    } else {
        false
    };
};

{
    private _magazines = magazinesAmmoFull [_x, false];
    private _magazinesUnique = _magazines apply {_x#0};
    _magazinesUnique = (_magazinesUnique arrayIntersect _magazinesUnique) - _magazineCache;
    private _ammos = _magazinesUnique apply {_cfgAmmo >> (getText (_cfgMagazines >> _x >> "ammo"))};
    {
        if ([_ammos#_forEachIndex] call _isAT) then {
                _magazineCache pushBackUnique _x;
        };
    } forEach _magazinesUnique;
    private _weapons = weapons _x;
    private _uniqueWeapons = (_weapons arrayIntersect _weapons) - _weaponCache;
    {
        if (isArray (configFile >> "CBA_DisposableLaunchers" >> (_x + "_loaded")) ||
                isArray (configFile >> "CBA_DisposableLaunchers" >> _x)) then {
            _weaponCache pushBackUnique _x
        };
    } forEach _uniqueWeapons;
    {
        if (_x in _weaponCache) then {_count set [_x, 1 + (_count getOrDefault [_x, 0])]};
    } forEach _weapons;
    {
        if ((_x#0) in _magazineCache) then {_count set [_x#0, (_x#1) + (_count getOrDefault [_x#0, 0])]};
    } forEach magazinesAmmoFull [_x, false];

} forEach (call cba_fnc_players);

private _sorted = createHashMap;
{
	private _displayName = if (isClass (_cfgWeapons >> _x)) then {
		getText (_cfgWeapons >> _x >> "displayName")
	} else {
		getText (_cfgMagazines >> _x >> "displayName")
	};
	_sorted set [_displayName, _y + (_sorted getOrDefault [_displayName, 0])]
} forEach _count;

private _text = [parseText "<t align=""left"" size=""1.4"">Player AT Count</t>"];
{
	_text pushBack lineBreak;
	_text pushBack parseText format ["<t align=""center"" size=""1"">%1: %2</t>", _x, _y];
} forEach _sorted;
[composeText _text, 1 + 0.5 * (0 max ((count _text)/2 - 1)) ] call ace_common_fnc_displayTextStructured;
