#include "script_component.hpp"


// Temp ACE Medical fixes for july2019 (server only)
if (isServer) then {
    [{
        diag_log text format ["[POTATO-Temp Ace Fix] Sending pain blackscreen effect fix"];
        {
            diag_log text format ["[POTATO-Temp Ace Fix] remoteExecCall Pain"];
            [{
                diag_log text format ["[POTATO-Temp Ace Fix] fixing pain blackscreen effect"];
                if (hasInterface && {ace_medical_feedback_painEffectType == 0}) then {
                    ace_medical_feedback_ppPain ppEffectAdjust [1, 1, 0, [1, 1, 1, 0], [1, 1, 1, 1], [0.33, 0.33, 0.33, 0], [0.59, 0.64, 0, 0, 0, 0, 4]];
                    ace_medical_feedback_ppPain ppEffectCommit 0;
                };
            }, [], 1] call CBA_fnc_waitAndExecute;
        } remoteExecCall ["bis_fnc_call", 0, true];


        private _sideCounts = [west, east, resistance] apply {
            private _side = _x;
            {((side _x) == _side) && {isPlayer _x}} count allUnits;
        };
        private _sortedCounts = +_sideCounts;
        _sortedCounts sort false;
        private _isTVT = (_sortedCounts select 1) > 8;
        diag_log text format ["[POTATO-Temp Ace Fix] [isTvt = %1] %2",_isTVT,_sideCounts];


        if (_isTVT) then {
            diag_log text format ["[POTATO-Temp Ace Fix] Sending TVT fatal wound fix"];
            {
                diag_log text format ["[POTATO-Temp Ace Fix] remoteExecCall TVT"];
                [{
                    diag_log text format ["[POTATO-Temp Ace Fix] Running TVT wound fix"];
                    ["ace_medical_woundReceived", {
                        params ["_unit", "_bodyPart", "_damage", "_typeOfDamage"];
                        if ((_unit == ACE_player) && {_unit getVariable ["ACE_isUnconscious", false]} && {_damage > 0.5}) then {
                            private _bps = _unit getVariable ["ace_medical_bodyPartDamage", [0,0,0,0,0,0]];
                            if (((_bps select 0) + (_bps select 1)) > 1.5) then {
                                diag_log text format ["[POTATO-Temp Ace Fix] TVT manually killing: %1", _bps];
                                _unit setDamage 1;
                            };
                        };
                    }] call CBA_fnc_addEventHandler;
                }, [], 1] call CBA_fnc_waitAndExecute;
            } remoteExecCall ["bis_fnc_call", 0, true];
        } else {
            diag_log text format ["[POTATO-Temp Ace Fix] Sending COOP fatal wound fix"];
            {
                diag_log text format ["[POTATO-Temp Ace Fix] remoteExecCall COOP"];
                [{
                    diag_log text format ["[POTATO-Temp Ace Fix] Running COOP wound fix"];
                    ["ace_medical_woundReceived", {
                        params ["_unit", "_bodyPart", "_damage", "_typeOfDamage"];
                        if ((_unit == ACE_player) && {_unit getVariable ["ACE_isUnconscious", false]} && {_damage > 0.5}) then {
                            private _bps = _unit getVariable ["ace_medical_bodyPartDamage", [0,0,0,0,0,0]];
                            if (((_bps select 0) + (_bps select 1)) > 3) then {
                                diag_log text format ["[POTATO-Temp Ace Fix] COOP manually killing: %1", _bps];
                                _unit setDamage 1;
                            };
                        };
                    }] call CBA_fnc_addEventHandler;
                }, [], 1] call CBA_fnc_waitAndExecute;
            } remoteExecCall ["bis_fnc_call", 0, true];
        };
    }, [], 1] call CBA_fnc_waitAndExecute;
};







// clean up empty groups
{
    if ((units _x) isEqualTo []) then {
        TRACE_2("Deleting Empty Group",_x,groupID _x);
        deleteGroup _x;
    };
} forEach allGroups;

missionNamespace setVariable [QGVAR(groupCleanupRan), true, true];

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
