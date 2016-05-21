#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

private _unitSide = side (group _unit);
if (!(_unitSide in VGVAR(movementEnabledSides)) || {isPlayer _unit}) exitWith {};

if (!(_unit getVariable [VQGVAR(allowFlankingUnit), true]) || {_unit getVariable [VGVAR(garrisoned), false]} || {!("ItemRadio" in (assignedItems _unit))}) exitWith {};

{
    if (_x getVariable [VQGVAR(allowFlankingUnit), true] && {!(_x getVariable [VGVAR(garrisoned), false])} && {"ItemRadio" in (assignedItems _x)} && {!(_unit getVariable [VQGVAR(isArtillery),false])}) then {
        private _group = group _x;
        if ((count (waypoints _group)) < 2) then {
            private _index = currentWaypoint _group;
            private _waypointType = waypointType [_group,_index];

            if !(_waypointType in ["HOLD","GUARD","UNLOAD","TR UNLOAD","SENTRY","LOAD"]) then {
                if ((_x distance _unit) <= (_x getVariable [VQGVAR(aiMutualSupportRangeUnit), 0])) then {
                    if ((count (waypoints _unit)) < 3) then {
                        [_unit] call VFUNC(flankManeuver);
                    };

                    _x setVariable [VQGVAR(movingToSupport), diag_ticktime];
                };
            };
        };
    };
    nil
} count ([_unit] call VFUNC(friendlyUnits));
