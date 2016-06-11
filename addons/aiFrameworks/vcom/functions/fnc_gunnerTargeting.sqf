#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit","_vehicle"];

private _lookup = (VGVAR(vehicleCache) select 0) find _vehicle;

private _weaponArray = if (_lookup < 0) then {
    private _weapons = _vehicle weaponsTurret ((assignedVehicleRole _unit) select 1);

    private _hasCannon = false;
    private _hasMg = false;

    {
        if (_x isKindOf "CannonCore") then {
            _hasCannon = true;
        } else {
            if (_x isKindOf "MGunCore") then {
                _hasMg = true;
            };
        };
    } forEach _weapons;

    private _returnArray = [_hasCannon,_hasMg];
    private _index = (VGVAR(vehicleCache) select 0) pushBack _vehicle;
    (VGVAR(vehicleCache) select 1) pushBack _returnArray;

    _returnArray
} else {
    (VGVAR(vehicleCache) select 1) select _lookup
};

_weaponArray params ["_hasCannon","_hasMg"];

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

{
    switch (true) do {
        private _xVehicle = vehicle _x;
        private _distance = _vehicle distance _xVehicle;

        case (_xVehicle isKindOf "Tank" || {_xVehicle isKindOf "Wheeled_APC_F"}): {
            if (_nearestArmorDistance > _distance || {isNull _nearestArmor}) then {
                _nearestArmor = _xVehicle;
                _nearestArmorDistance = _distance;
            };

            if ([_vehicle,_xVehicle] call VFUNC(canSee)] && {_nearestVisableArmorDistance > _distance || {isNull _nearestVisableArmor}}) then {
                _nearestVisableArmor = _xVehicle;
                _nearestVisableArmorDistance = _distance;
            };
        };
        case (_xVehicle isKindOf "Car" || _xVehicle isKindOf "Air"}): {
            if (_nearestSoftDistance > _distance || {isNull _nearestSoft}) then {
                _nearestSoft = _xVehicle;
                _nearestSoftDistance = _distance;
            };

            if ([_vehicle,_xVehicle] call VFUNC(canSee)] && {_nearestVisableSoftDistance > _distance || {isNull _nearestVisableSoft}}) then {
                _nearestVisableSoft = _xVehicle;
                _nearestVisableSoftDistance = _distance;
            };
        };
        default {
            if (_nearestOtherDistance > _distance || {isNull _nearestOther}) then {
                _nearestOther = _xVehicle;
                _nearestOtherDistance = _distance;
            };

            if ([_vehicle,_xVehicle] call VFUNC(canSee)] && {_nearestVisableOtherDistance > _distance || {isNull _nearestVisableOther}}) then {
                _nearestVisableOther = _xVehicle;
                _nearestVisableOtherDistance = _distance;
            };
        };
    };
    nil
} count allUnits;

if (_hasCannon) then {
    switch (false) do {
        case (isNull _nearestVisableArmor): {
            _unit doFire _nearestVisableArmor;
        };
        case (isNull _nearestVisableSoft): {
            _unit doFire _nearestVisableArmor;
        };
        case (isNull _nearestVisableOther): {
            _unit doFire _nearestVisableArmor;
        };
        case (isNull _nearestArmor): {
            _unit doWatch _nearestArmor;
        };
        case (isNull _nearestSoft): {
            _unit doWatch _nearestSoft;
        };
        case (isNull _nearestOther): {
            _unit doWatch _nearestOther;
        };
    };
} else {
    if (_hasMg) then {
        switch (false) do {
            case (isNull _nearestVisableSoft): {
                _unit doFire _nearestVisableArmor;
            };
            case (isNull _nearestVisableOther): {
                _unit doFire _nearestVisableArmor;
            };
            case (isNull _nearestSoft): {
                _unit doWatch _nearestSoft;
            };
            case (isNull _nearestOther): {
                _unit doWatch _nearestOther;
            };
        };
    };
};
