#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

private _uavBagClassname = _unit getVariable [VQGVAR(staticClassname),""];
if (_uavBagClassname == "") exitWith {};

private _uavClassname = ([_uavBagClassname,0,-11] call BIS_fnc_trimString) + "_F";

private _uav = createVehicle [_uavClassname, position _unit, [], 0,""];
createVehicleCrew _uav;

removeBackpackGlobal _unit;
_unit setVariable [VQGVAR(hasUAV),false];

[_uav] spawn {
    params ["_uav"];
    while { alive _uav } do {
        private _myNearestEnemy = [_uav] call VFUNC(closestEnemy);
        if !(isNull _myNearestEnemy) then {
            (group _uav) move (position _myNearestEnemy);

            private _friendlyUnits = _uav call VFUNC(friendlyUnits);
            private _closestFriendly = [_friendlyUnits,_uav] call VFUNC(closestObject);
            if !(isNull _closestFriendly) then {
                [_uav] joinSilent (group _closestFriendly);

                if ((_myNearestEnemy distance _uav) < VGVAR(maxUAVRevealDistance)) then {
                    {
                        (group _x) reveal [_myNearestEnemy, 4];
                        nil
                    } count _friendlyUnits;
                };
            };
        };

        sleep VGVAR(uavScanTime);
    };
};
