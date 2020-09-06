/*
 * Author: BadWolf, Pabo
 * Function is called once when the Breifings dialog is opened.
 *
 * Arguments:
 *
 * Examples:
 * [] call potato_missionTesting_fnc_runWeaponsTest;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params [""];

GVAR(westClasses) = [];
GVAR(eastClasses) = [];
GVAR(indyClasses) = [];
GVAR(civiClasses) = [];

if ((isNull player) || {!alive player}) exitWith {};

//if (!isNil QGVAR(TestRan)) exitWith {TRACE_1("Test Ran Already",_this)};

private _handledClasses = [];

private _fncGetWeaponInfo = {
    params ["_weaponClassname"];
    if (_weaponClassname == "") exitWith {};
    if (_weaponClassname == "throw") then {
        _unitText = _unitText + "[Thrown: ";
    };
    private _config = configfile >> "CfgWeapons" >> _weaponClassname;
    private _muzzles = getArray (_config >> "muzzles");
    {
        _muzzleConfig = if (_x == "this") then {
            _config;
        } else {
            _config >> _x
        };
        private _weaponName = getText (_muzzleConfig >> "displayName");
        private _mags = [_muzzleConfig] call CBA_fnc_compatibleMagazines;
        private _weaponPic = getText (_muzzleConfig >> "picture");
        private _muzzleText = if (_weaponClassname == "throw") then {
            format [""];
        } else {
            format ["[<img image='%1' width='40' height='20'/>", _weaponPic];
        };
        if (_x == "this") then {
            private _weaponAttachments = _unit weaponAccessories _weaponClassname;
            private _scope = _weaponAttachments select 2;
            if (_scope != "") then {
                private _scopeConfig = configFile >> "CfgWeapons" >> _scope;
                private _minZoom = 999; //FOV, so smaller is more zoomed in
                {
                    if (isNumber (_x >> "opticsZoomMin")) then {_minZoom = _minZoom min (getNumber (_x >> "opticsZoomMin"));};
                    if (isText (_x >> "opticsZoomMin")) then {_minZoom = _minZoom min (call compile getText (_x >> "opticsZoomMin"));};
                    nil
                } count configProperties [_scopeConfig >> "ItemInfo" >> "OpticsModes"];
                private _scopeImage = getText (_scopeConfig >> "picture");
                _muzzleText = _muzzleText + format ["(<img image='%1' width='20' height='20'/>:%2x) ", _scopeImage, ((floor (2.5 / _minZoom))/10)];
            };
        };
        private _hasMags = false;
        {
            private _magazineClassname = _x;
            private _count = 0;
            {
                if ((_x select 0) == _magazineClassname) then {
                    _hasMags = true;
                    _usedAmmo pushBack _magazineClassname;
                    _count = _count + (_x select 1);
                };
            } forEach (magazinesAmmoFull _unit);
            if (_count > 0) then {
                private _magPic = getText (configFile >> "CfgMagazines" >> _magazineClassname >> "picture");
                _muzzleText = _muzzleText + format ["<img image='%1' width='16' height='16'/>:%2 ", _magPic, _count];
            };
        } forEach _mags;
        if (_weaponClassname == "throw") then {
            if (_hasMags) then {
                _unitText = _unitText + _muzzleText;
            };
        } else {
            _unitText = _unitText + _muzzleText + "]<br/>";
        };
    } forEach _muzzles;
    if (_weaponClassname == "throw") then {
        _unitText = _unitText + "]<br/>";
    };
};

{
    private _unit = _x;
    private _classname = typeOf _unit;

    if (!(_classname in _handledClasses)) then {
        _handledClasses pushBack _classname;

        private _displayName = getText (configfile >> "CfgVehicles" >> _classname >> "displayName");
        private _xIcon = gettext (configfile >> "CfgVehicles" >> _classname >> "icon");
        private _image = gettext (configfile >> "CfgVehicleIcons" >> _xIcon);
        private _color = "";
        private _sideArray = [];

        switch (side _x) do {
        case (west): {
                _color = "#0088EE";
            };
        case (east): {
                _color = "#DD0000";
            };
        case (resistance): {
                _color = "#00DD00";
            };
            default {
                _color = "#880099";
            };
        };
        private _unitText = format ["<t color='%1' size='1'>%2</t> - %3<br/>", _color, _displayName, _classname];
        private _usedAmmo = [];
        [primaryWeapon _unit] call _fncGetWeaponInfo;
        [secondaryWeapon _unit] call _fncGetWeaponInfo;
        [handgunWeapon _unit] call _fncGetWeaponInfo;
        ["throw"] call _fncGetWeaponInfo;

        private _extraAmmo = (magazines _unit) - _usedAmmo;
        if ((count _extraAmmo) > 0) then {
            _unitText = _unitText + "[Extra: ";
            {
                private _magPic = getText (configFile >> "CfgMagazines" >> _x >> "picture");
                _unitText = _unitText + format ["<img image='%1' width='16' height='16'/> ", _magPic];
            } forEach _extraAmmo;
            _unitText = _unitText + "]<br/>";
        };
        private _has343 = [_unit, "ACRE_PRC343"] call acre_api_fnc_hasKindOfRadio;
        private _has148 = [_unit, "ACRE_PRC148"] call acre_api_fnc_hasKindOfRadio;
        _unitText = _unitText + format ["[Radios: %1%2]<BR/>", ["", "343 "] select _has343, ["", "148"] select _has148];

        switch (side _x) do {
        case (west): {
            GVAR(westClasses) pushBack _unitText;
            };
        case (east): {
            GVAR(eastClasses) pushBack _unitText;
            };
        case (resistance): {
            GVAR(indyClasses) pushBack _unitText;
            };
        default {
        GVAR(civiClasses) pushBack _unitText;
        };
    };
    };
} forEach allUnits;
GVAR(TestRan) = true;
