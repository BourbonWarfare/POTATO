#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

_unit setVariable [VQGVAR(movedRecently),diag_tickTime];

private _groupLeader = leader _unit;

if (_groupLeader != _unit && {_groupLeader distance _unit > 150}) then {
    _unit doFollow _groupLeader;
} else {
    private _unitGroup = (group _unit);

    //Pull the waypoint information
    private _index = currentWaypoint _unitGroup;
    private _wpPosition = getWPPos [_unitGroup,_index];

    if !(_wpPosition isEqualTo [0,0,0]) then {
        if (_unit == _groupLeader) then {
            private _units = units _unitGroup;

            {
                [_x,_wpPosition] spawn {
                    params ["_unit","_pos"];
                    sleep (random 10);

                    if (vehicle _unit != _unit) exitWith {
                        _unit forceSpeed -1;
                        _unit doMove _pos;
                    };

                    private _moveToPos = [_unit,_pos] call VFUNC(fragmentMove);

                    private _coverPos = [_unit,_moveToPos] call VFUNC(findCoverPos);
                    if !(isNil "_coverPos") then {
                        _unit setVariable [VQGVAR(inCover),false];

                        private _waitTime = diag_ticktime + 15;
                        while {alive _unit && diag_ticktime < _waitTime && (_unit distance _coverPos) > 2} do {
                            _unit forceSpeed -1;
                            _unit doMove _coverPos;
                            sleep 2;
                        };

                        _unit forcespeed 0;
                        _unit setVariable [VQGVAR(inCover),true];
                    } else {
                        _unit doMove _moveToPos;
                    };
                };
                nil
            } count _units;
        };
    };
};
