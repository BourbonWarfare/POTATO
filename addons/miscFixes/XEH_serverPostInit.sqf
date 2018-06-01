#include "script_component.hpp"

// normalize HCs positions
DFUNC(updateHCPosition) = {
    if (!(missionNamespace getVariable [QGVAR(updateHCPosition), true])) exitWith {};

    // setup player position tracker
    private _playerPositions = [0, [0, 0, 0]]; // player count, sum of player positions

    // get all active HCs
    private _hcs = [[], [], []];
    {
        (_hcs select 0) pushBack owner _x;
        (_hcs select 1) pushBack [0, [0, 0, 0]]; // group count, sum of group leader positions
        (_hcs select 2) pushBack _x;
    } forEach ((entities "HeadlessClient_F") select {isPlayer _x});

    // look through all groups and assoicate them to the HCs, get player positions
    {
        if (!(_x in (_hcs select 2))) then {
            private _index = (_hcs select 0) find groupOwner _x;

            // ignore non land AI
            if (_index > -1 && {(vehicle leader _x) isKindOf "Land"}) then {
                private _groupPositions = ((_hcs select 1) select _index);
                _groupPositions set [0, (_groupPositions select 0) + 1];
                _groupPositions set [1, (_groupPositions select 1) vectorAdd (getPos leader _x)];
            } else {
                {
                    // make sure it's a player (not a spectator) on the ground
                    if (isPlayer _x && {(vehicle _x) isKindOf "Land"}) then {
                        _playerPositions set [0, (_playerPositions select 0) + 1];
                        _playerPositions set [1, (_playerPositions select 1) vectorAdd (getPos _x)];
                    };
                } forEach (units _x);
            };
        };
    } forEach allGroups;

    private _playerAvgPos = [];
    _playerPositions params ["_playerCount", "_playerPosSum"];
    if (_playerCount > 0) then {
        _playerAvgPos = _playerPosSum vectorMultiply (1 / _playerCount);
    };

    {
        ((_hcs select 1) select _forEachIndex) params ["_groupCount", "_position"];
        if (_groupCount > 0) then {
            private _groupAvgPos = _position vectorMultiply (1 / _groupCount);
            if (!(_playerAvgPos isEqualTo [])) then {
                _groupAvgPos = (_playerAvgPos vectorAdd _groupAvgPos) vectorMultiply 0.5;
            };

            _x setPos _groupAvgPos;
            INFO_2("Moving HC [%1] to pos %2",_x, _groupAvgPos);
        };
    } forEach (_hcs select 2);


    [DFUNC(updateHCPosition), [], missionNamespace getVariable [QGVAR(updateHCPositionDelay), 90]] call CBA_fnc_waitAndExecute;
};

[] call DFUNC(updateHCPosition);
