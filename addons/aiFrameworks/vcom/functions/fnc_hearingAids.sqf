#include "script_component.hpp"
TRACE_1("params",_this);

//Helps the AI recognize people firing from a better distance
params ["_unit","","_muzzle"];

if (diag_tickTime - (_unit getVariable [VQGVAR(firedTimeHearing),0]) > 10) then {
    _unit setVariable [VQGVAR(firedTimeHearing),diag_tickTime];

    private _silenced = if (_muzzle == "") then {
        false
    } else {
        private _lookup = (VGVAR(suppressorCache) select 0) find _muzzle;

        private _loudness = if (_lookup > -1) then {
             (VGVAR(suppressorCache) select 1) select _lookup
        } else {
            private _cfgLoud = [(configFile >> "CfgWeapons" >> _muzzle >> "ItemInfo" >> "AmmoCoef"), "audibleFire", 1] call BIS_fnc_returnConfigEntry;
            (VGVAR(suppressorCache) select 0) pushBack _muzzle;
            (VGVAR(suppressorCache) select 1) pushBack _cfgLoud;
            _cfgLoud
        };
        _loudness < 1
    };

    if (_silenced) exitWith {TRACE_1("shot is suppressed, ignore", _muzzle)};

    {
        if ((_x distance _unit) <= VGVAR(gunshotDetectionRange) && !(_x getVariable [VQGVAR(shotsFired),false])) then {
            _x setVariable [VQGVAR(shotsFired),true,true];
        };
        nil
    } count ([_unit] call VFUNC(enemyUnits));
};
