#include "script_component.hpp"

// clean up empty groups
{
    if ((units _x) isEqualTo []) then {
        TRACE_2("Deleting Empty Group",_x,groupID _x);
        deleteGroup _x;
    };
} forEach allGroups;

missionNamespace setVariable [QGVAR(groupCleanupRan), true, true];

// normalize HCs to AI's center
[
    {
        // get all active HCs
        private _hcs = [[], [], []];
        {
            (_hcs select 0) pushBack owner _x;
            (_hcs select 1) pushBack [0, [0, 0, 0]]; // group count, position
            (_hcs select 2) pushBack _x;
        } forEach ((entities "HeadlessClient_F") select {isPlayer _x});

        // look through all groups and assoicate them to the HCs
        {
            private _index = (_hcs select 0) find groupOwner _x;
            if (_index > -1) then {
                ((_hcs select 1) select _index) params ["_groupCount", "_position"];

                _groupCount = _groupCount + 1;
                _position = _position vectorAdd (getPos leader _x);

                (_hcs select 1) set [_index, [_groupCount, _position]];
            };
        } forEach allGroups;

        {
            ((_hcs select 1) select _forEachIndex) params ["_groupCount", "_position"];
            if (_groupCount > 0) then {
                _x setPosition (_position vectorMultiply (1 / _groupCount));
            };
        } forEach (_hcs select 2);
    },
    60
] call CBA_fnc_addPerFrameHandler;
