/*
 * Author: AACO
 * Function used try to "unstick" groups that have become unresponsive
 *
 * Arguments:
 * 0: group you want to try to fix <GROUP>
 *
 * Return Value: Nothing
 *
 * Examples:
 * [group player] call potato_zeusHC_fnc_fixGroup;
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params [
    ["_group", grpNull, [grpNull]]
];

// if the group is not local, exit
if (isNull _group || !(local _group)) exitWith { ERROR("Group is null/not local, can not even try to fix"); };

_this spawn {
    params [
        ["_group", grpNull, [grpNull]]
    ];

    private _newGroup = createGroup [side _group, true]; // explicitly mark for cleanup
    _newGroup copyWaypoints _group;

    private _index = (count (units _group)) - 1;
    while {count (units _group) > 0} do {
        private _unit = (units _group) select _index;
        private _newUnit = _newGroup createUnit [typeOf _unit, [0,0,0], [], 50, "NONE"];

        if (leader _group == _unit) then {
            _newGroup selectLeader _newUnit;
        };

        sleep 1;

        _newUnit setDir direction _unit;
        switch (stance _unit) do {
            case ("PRONE"): {
                _newUnit setUnitPos "DOWN";
            };
            case ("CROUCH"): {
                _newUnit setUnitPos "MIDDLE";
            };
            default {
                _newUnit setUnitPos "UP";
            };
        };
        private _unitPosition = position _unit;
        deleteVehicle _unit;
        _newUnit setPos _unitPosition;
        _newUnit setUnitPos "AUTO";

        if (_index > 0) then {
            DEC(_index);
            sleep 2;
        };
    };

    deleteGroup _group;
};
