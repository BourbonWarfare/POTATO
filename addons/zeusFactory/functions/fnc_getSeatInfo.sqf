#include "script_component.hpp"
// getSeatInfo

params ["_type"];

private _config = configFile >> "CfgVehicles" >> _type;

if ((getNumber (_config >> "hasDriver")) != 1) exitWith { WARNING_1("%1 has no driver?",_type); [[], -1] };

private _crewTurrets = [];
private _cargo = getNumber (_config >> "transportSoldier");

private _turrets = [_type, true] call bis_fnc_allTurrets;
{
    private _turretConfig = [_config, _x] call ACEFUNC(common,getTurretConfigPath);
    if ((getNumber (_turretConfig >> "CUP_LockTurret")) == 1) then { continue; }; // ignore Cup Locked Turret
    if ((getNumber (_turretConfig >> "isCopilot")) == 1) then { continue; }; // ignore
    private _weapons = getArray (_turretConfig >> "weapons");
    if (_weapons isEqualTo [] || {(_weapons # 0) == "rhs_weap_DummyLauncher"}) then { // something rhs does for ffv
        _cargo = _cargo + 1;
    } else {
        _crewTurrets pushBack _x;
    };
} forEach _turrets;

if ((count _crewTurrets) > 3) then {
    _crewTurrets resize 3;
};
if ((_type isKindOf "rhs_tigr_sts_vdv") && {(count _crewTurrets) > 1}) then { // RHS LockedTurret stuff
    _crewTurrets resize 1;
};

[_crewTurrets, _cargo]
