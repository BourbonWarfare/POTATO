#define DEBUG_MODE_FULL
#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit","_unitGroup"];

if !(VGVAR(loiteringEnabled)) exitWith {};

private _fnc_case3 = {
    params [_unit];
    for "_i" from 0 to 10 do {
        _unit playMoveNow (selectRandom ["AmovPercMstpSnonWnonDnon_exercisePushup","SitDown","AmovPercMstpSnonWnonDnon_SaluteIn","AmovPercMstpSrasWrflDnon_AinvPknlMstpSlayWrflDnon"]);
        sleep (random 7) + 5;
    };
};

while {alive _unit && {_unit getvariable [VQGVAR(loitering),false]}} do {

    private _action = selectRandom ([1,2,3,4] - [_unit getvariable [VQGVAR(loiteringAct),0]]);
    _unit setVariable [VQGVAR(loiteringAct),_action];

    private _distance = (random 25) + 25;
    private _direction = random 360;
    private _unitPosition = getPosWorld _unit;

    private _position = [(_unitPosition select 0) + (sin _direction) * _distance, (_unitPosition select 1) + (cos _direction) * _distance, 0];
    _unit doMove _position;
    switch (_action) do {
        case 1: {
            waitUntil { sleep 2; (_unit distance _positions) < 2 };

            _unit playMoveNow (selectRandom ["AmovPercMstpSnonWnonDnon_exercisePushup","SitDown","AmovPercMstpSnonWnonDnon_SaluteIn","AmovPercMstpSrasWrflDnon_AinvPknlMstpSlayWrflDnon"]);
        };
        case 2: {
            private _closestUnit = [(_unitGroup - [_unit]),_unit] call VFUNC(closestObject);
            _closestUnit setVariable [VQGVAR(loiteringAct),2];

            private _closePosition = [(_position select 0) + 5, (_position select 1) + 5,_position select 2];
            _closestUnit doMove _closePosition;

            waitUntil {sleep 2; (_unit distance _position) < 2 && (_closestUnit distance _closePosition) < 2};

            _unit lookAt _closestUnit;
            _closestUnit lookAt _unit;
            sleep 2;

            [_unit,"Acts_B_hub01_briefing"] remoteExec [VQFUNC(switchMoveLocal),0];
            sleep 2;

            [_closestUnit,"Acts_Kore_TalkingOverRadio_loop"] remoteExec [VQFUNC(switchMoveLocal),0];
            sleep 80;

            [_unit,""] remoteExec [VQFUNC(switchMoveLocal),0];
            [_closestUnit,""] remoteExec [VQFUNC(switchMoveLocal),0];
        };
        case 3: {
            private _closestUnit = [(_unitGroup - [_unit]),_unit] call VFUNC(closestObject);
            _closestUnit setVariable [VQGVAR(loiteringAct),3];
            _closestUnit doMove _position;

            waitUntil {sleep 2; (_unit distance _position) < 5 && (_closestUnit distance _position) < 5};

            private _distance2 = (random 5 + 3);
            private _direction2 = random 360;
            _position2 = [(_position2 select 0) + (sin _direction2) * _distance2, (_position2 select 1) + (cos _direction2) * _distance2, _position2 select 2];
            _closestUnit doMove _positions2;

            sleep 10;

            private _fire = "FirePlace_burning_F" createvehicle _positions2;

            _closestUnit lookAt _fire;
            _unit lookAt _fire;

            private _closestUnitHandle = [_closestUnit] spawn _fnc_case3;
            private _unitHandle = [_unit] spawn _fnc_case3;

            waitUntil {sleep 2; scriptDone _closestUnitHandle && scriptDone _unitHandle};
            deletevehicle _fire;
        };
        case 4: {
            waitUntil {sleep 2; (_unit distance _positions) < 2};

            _unit playActionNow "SitDown";
            sleep 100;

            _unit playActionNow "walkf";
        };
    };

    sleep 120;
};
