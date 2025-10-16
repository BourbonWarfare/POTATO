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
    private _magazines = magazines _x;
    _magazines = (_magazines arrayIntersect _magazines) - _magazineCache;
    private _ammos = _magazines apply {_cfgAmmo >> (getText (_cfgMagazines >> _x >> "ammo"))};
    {
        if ([_ammos#_forEachIndex] call _isAT) then {
                _magazineCache pushBackUnique _x;
        };
    } forEach _magazines;
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
	_text pushBack parseText format ["%1: %2", _x, _y];
} forEach _sorted;
hintSilent composeText _text;
