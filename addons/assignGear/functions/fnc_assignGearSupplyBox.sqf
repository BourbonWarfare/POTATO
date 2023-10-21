#include "script_component.hpp"
/*
 * Author: PabstMirror
 * Fills supply box with gear for a faction
 *
 * Arguments:
 * 0: Box <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [cursorObject] call potato_assignGear_fnc_assignGearSupplyBox
 *
 * Public: No
 */

params ["_box"];

private _config = configOf _box;
private _faction = getText (_config >> QGVAR(faction));
private _path = missionConfigFile >> "CfgLoadouts" >> _faction;
private _type = getText (_config >> QGVAR(type)); // 1=squad, 2=platoon
TRACE_3("suppy_initBox",_box,_faction,_type);

private _size = 1; // scaling factor for medical and ammo
private _classes = ["rifleman", "ar", "ar", "lat", "ftl"];
private _checkDisposable = ["lat"];

if (_type == "platoon") then {
    _size = 2;
    _classes append ["mmgg", "matg", "msamg"];
    _checkDisposable pushBack "matg";
};

private _boxWeapons = createHashMap;
private _boxMags = createHashMap;
private _boxItems = createHashMapFromArray [
    ["ACE_elasticBandage", _size * 20],
    ["ACE_packingBandage", _size * 20],
    ["ACE_epinephrine", _size * 10],
    ["ACE_morphine", _size * 10],
    ["ACE_splint", _size * 10],
    ["ACE_salineIV_500", _size * 10]
];

{
    private _loadout = _path >> _x;
    if (_x in _checkDisposable) then {
        private _launcher = (getArray (_loadout >> "launchers")) param [0, "#"];
        private _launcherConfig = configFile >> "CfgWeapons" >> _launcher;
        if (isNull _launcherConfig) then { continue };
        if (((getNumber (_launcherConfig >> "rhs_disposable")) == 1) || {!isNil {cba_disposable_normalLaunchers getVariable _launcher}}) then {
            private _count = _boxWeapons getOrDefault [_launcher, 0];
            _boxWeapons set [_launcher, _count + _size * 2]
        };
    };

    {
        (_x splitString ":") params ["_xClass", ["_xCount", "1", [""]]];
        private _count = _boxMags getOrDefault [_xClass, 0];
        _boxMags set [_xClass, _count + _size * parseNumber _xCount];
    } forEach getArray (_loadout >> "magazines");
} forEach _classes;


{
    TRACE_2("weapons",_x,_y);
    _box addWeaponCargoGlobal [_x, _y];
} forEach _boxWeapons;
{
    TRACE_2("mags",_x,_y);
    _box addMagazineCargoGlobal [_x, _y];
} forEach _boxMags;
{
    TRACE_2("items",_x,_y);
    _box addItemCargoGlobal [_x, _y];
} forEach _boxItems;
