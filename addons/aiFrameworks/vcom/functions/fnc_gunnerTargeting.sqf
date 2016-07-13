#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit","_vehicle","_group"];

_unit setVariable [VQGVAR(gunnerPrioritization),diag_tickTime];

private _side = side _group;

private _lookup = (VGVAR(vehicleWeaponCache) select 0) find _vehicle;

// TODO: do an ammo check
private _weaponArray = if (_lookup > -1) then {
    (VGVAR(vehicleWeaponCache) select 1) select _lookup
} else {
    private _weapons = _vehicle weaponsTurret ((assignedVehicleRole _unit) select 1);

    private _hasCannon = false;
    private _hasMg = false;
    private _hasMissile = false;

    {
        if (_x isKindOf "CannonCore") then {
            _hasCannon = true;
        } else {
            if (_x isKindOf "LauncherCore") then {
                _hasMissile = true;
            } else {
                if (_x isKindOf "MGunCore") then {
                    _hasMg = true;
                };
            };
        };
    } forEach _weapons;

    private _returnArray = [_hasCannon,_hasMissile,_hasMg];
    (VGVAR(vehicleWeaponCache) select 0) pushBack _vehicle;
    (VGVAR(vehicleWeaponCache) select 1) pushBack _returnArray;

    _returnArray
};

_weaponArray params ["_hasCannon","_hasMissile","_hasMg"];

private _nearestArmor = objNull;
private _nearestArmorDistance = -1;
private _nearestVisableArmor = objNull;
private _nearestVisableArmorDistance = -1;

private _nearestSoft = objNull;
private _nearestSoftDistance = -1;
private _nearestVisableSoft = objNull;
private _nearestVisableSoftDistance = -1;

private _nearestOther = objNull;
private _nearestOtherDistance = -1;
private _nearestVisableOther = objNull;
private _nearestVisableOtherDistance = -1;

private _skipArray = [];

{
    private _xSide = side (group _x);
    if (_side != _xSide) then {

        private _xVehicle = vehicle _x;
        if !(_xVehicle in _skipArray) then {
            private _xVehicleType = typeOf _xVehicle;
            private _distance = _vehicle distance _xVehicle;

            // ignore vehicles outside given distance
            if (_distance < VGVAR(maxGunnerPrioritizationDistance)) then {

                private _index = (VGVAR(vehicleTypeCache) select 0) find _xVehicleType;

                private _type = if (_index > -1) then {
                    (VGVAR(vehicleTypeCache) select 1) select _index
                } else {
                    private _cfgType = switch (true) do {
                        case (_xVehicle isKindOf "Tank" || {_xVehicle isKindOf "Wheeled_APC_F"}): {
                            "ARMOR"
                        };
                        case (_xVehicle isKindOf "Car" || {_xVehicle isKindOf "Air"}): {
                            "SOFT"
                        };
                        default {
                            "OTHER"
                        };
                    };

                    (VGVAR(vehicleTypeCache) select 0) pushBack _xVehicleType;
                    (VGVAR(vehicleTypeCache) select 1) pushBack _cfgType;

                    _cfgType
                };

                switch (_type) do {
                    case ("ARMOR"): {
                        if (_nearestArmorDistance > _distance || {isNull _nearestArmor}) then {
                            _nearestArmor = _xVehicle;
                            _nearestArmorDistance = _distance;
                        };

                        if ([_vehicle,_xVehicle] call VFUNC(canSee) && {_nearestVisableArmorDistance > _distance || {isNull _nearestVisableArmor}}) then {
                            _nearestVisableArmor = _xVehicle;
                            _nearestVisableArmorDistance = _distance;
                        };
                    };
                    case ("SOFT"): {
                        if (_nearestSoftDistance > _distance || {isNull _nearestSoft}) then {
                            _nearestSoft = _xVehicle;
                            _nearestSoftDistance = _distance;
                        };

                        if ([_vehicle,_xVehicle] call VFUNC(canSee) && {_nearestVisableSoftDistance > _distance || {isNull _nearestVisableSoft}}) then {
                            _nearestVisableSoft = _xVehicle;
                            _nearestVisableSoftDistance = _distance;
                        };
                    };
                    default {
                        if (_nearestOtherDistance > _distance || {isNull _nearestOther}) then {
                            _nearestOther = _xVehicle;
                            _nearestOtherDistance = _distance;
                        };

                        if ([_vehicle,_xVehicle] call VFUNC(canSee) && {_nearestVisableOtherDistance > _distance || {isNull _nearestVisableOther}}) then {
                            _nearestVisableOther = _xVehicle;
                            _nearestVisableOtherDistance = _distance;
                        };
                    };
                };
            };
        };
    };
    nil
} count allUnits;

// cannon should track all levels, ATGMs should only track vics, MGs should only track soft targets
switch (true) do {
    case ((_hasCannon || {_hasMissile}) && {!(isNull _nearestVisableArmor)}): {
        _unit doFire _nearestVisableArmor;
    };
    case ((_hasCannon || {_hasMissile} || {_hasMg}) && {!(isNull _nearestVisableSoft)}): {
        _unit doFire _nearestVisableSoft;
    };
    case ((_hasCannon || {_hasMg}) && {!(isNull _nearestVisableOther)}): {
        _unit doFire _nearestVisableOther;
    };
    case ((_hasCannon || {_hasMissile}) && {!(isNull _nearestArmor)}): {
        _unit doTarget _nearestArmor;
    };
    case ((_hasCannon || {_hasMissile} || {_hasMg}) && {!(isNull _nearestSoft)}): {
        _unit doTarget _nearestSoft;
    };
    case ((_hasCannon || {_hasMg}) && {!(isNull _nearestOther)}): {
        _unit doTarget _nearestOther;
    };
};
