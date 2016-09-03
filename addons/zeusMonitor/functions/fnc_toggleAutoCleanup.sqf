#include "script_component.hpp"

TRACE_1("params",_this);

#define DISTANCE_MIN 300
#define DISTANCE_MAX 2000

if (GVAR(cleanupPFID) >= 0) exitWith {
    TRACE_1("stopping cleanup",GVAR(cleanupPFID));
    [GVAR(cleanupPFID)] call CBA_fnc_removePerFrameHandler;
    GVAR(cleanupPFID) = -1;
};

GVAR(cleanupPFID) = [{
    params ["_args"];
    _args params ["_deadArray", "_index"];
    TRACE_2("params",_deadArray,_index);

    if (_index >= (count _deadArray)) exitWith {
        // Filter all dead, ignoring players
        private _allDeadNonPlayers = allDead select {
            if (isNil {_x getVariable QGVAR(deadTime)}) then {
                _x setVariable [QGVAR(deadTime), CBA_missionTime];
                TRACE_1("setting deadtime",_x);
            };
            (!(_x getVariable ["isDeadPlayer", false])) && {(CBA_missionTime - (_x getVariable QGVAR(deadTime))) > 120}
        };

        TRACE_1("restarting", count _allDeadNonPlayers);
        _args set [0, _allDeadNonPlayers];
        _args set [1, 0];
    };

    private _deadGuy = _deadArray param [_index, objNull];
    if (isNull _deadGuy) exitwith {TRACE_2("null",_deadGuy,_index);};

    private _clearVision = true;
    {
        private _bodyDistance = _x distance _deadGuy;
        if ((_bodyDistance < DISTANCE_MIN) || {(_bodyDistance < DISTANCE_MAX) && {
                        private _dirTo = (eyePos _x) vectorFromTo (eyePos _deadGuy);
                        private _eyeDir = getCameraViewDirection _x;
                        (_dirTo vectorDotProduct _eyeDir) > 0
                    }}) exitWith {
            // TRACE_3("seen",_x,_deadGuy,_bodyDistance);
            _clearVision = false;
        };
    } forEach allPlayers;

    if (_clearVision) then {
        TRACE_1("deleting",_deadGuy);
        deleteVehicle _deadGuy;
    };

    _args set [1, _index + 1];
}, 0, [[], 0]] call CBA_fnc_addPerFrameHandler;
