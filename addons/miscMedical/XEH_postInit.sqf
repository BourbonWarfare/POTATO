#define DEBUG_MODE_FULL
#include "script_component.hpp"
LOG("Post init start");


if (isServer) then {
    [QGVAR(sLog), {
        params ["_type", "_msg"];
        INFO_2("SLOG - %1: %2",_type,_msg);
    }] call CBA_fnc_addEventHandler;


    // Determine if TVT or COOP
    [{
        private _sideCounts = [west, east, resistance] apply {
            private _side = _x;
            {((side _x) == _side) && {isPlayer _x}} count allUnits;
        };
        private _sortedCounts = +_sideCounts;
        _sortedCounts sort false;
        private _isTVT = (_sortedCounts select 1) > 8;
        TRACE_2("",_isTVT,_sideCounts);
        missionNamespace setVariable [QGVAR(isTVT), _isTVT, true];
        // can override with global exec: potato_miscMedical_isTVT = false;
    }, [], 1] call CBA_fnc_waitAndExecute;
};

if (hasInterface) then {
    // Increase lethality when taking sustained critical damage to body/head
    [{
        TRACE_1("adding woundRecieved handler",GVAR(isTVT));

        ["ace_medical_woundReceived", {
            params ["_unit", "_bodyPart", "_damage", "_shooter", "_typeOfDamage"];
            if (_unit == ACE_player) then {
                TRACE_3("player wound",_bodyPart,_damage,_typeOfDamage);
                if ((_unit getVariable ["ACE_isUnconscious", false]) && {_damage > 0.5}) then {
                    private _bps = _unit getVariable ["ace_medical_bodyPartDamage", [0,0,0,0,0,0]];
                    if (((_bps select 0) + (_bps select 1)) > ([1.75, 3] select GVAR(isTVT))) then {
                        TRACE_1("manually killing", _bps);
                        _unit setDamage 1;
                    };
                };
            };
        }] call CBA_fnc_addEventHandler;
    }, [], 5] call CBA_fnc_waitAndExecute;

    // debug for uncon:
    ["ace_unconscious", {
        params ["_unit", "_active"];
        if (_unit == ACE_player) then {
            TRACE_2("uncon event",_unit,_active);
            [QGVAR(sLog), ["uncon event", format ["%1 [Unit:%2] [Active:%3]", profileName, _unit, _active]]] call CBA_fnc_serverEvent;
        };
    }] call CBA_fnc_addEventHandler;

    ["ace_medical_wakeUp", {
        params ["_unit"];
        if (_unit == ACE_player) then {
            private _stable = [_unit] call ace_medical_status_fnc_hasStableVitals;
            TRACE_2("wakeUp event",_unit,_stable);
            [QGVAR(sLog), ["wakeUp event", format ["%1 [Unit:%2] [Stable: %3]", profileName, _unit, _stable]]] call CBA_fnc_serverEvent;
            [{
                params ["_unit"];
                private _targetState = [_unit, ACEGVAR(medical,STATE_MACHINE)] call CBA_statemachine_fnc_getCurrentState;
                private _isUncon = _unit getVariable ["ACE_isUnconscious", -1];
                private _anim = animationState _unit;
                private _weap = currentWeapon _unit;
                private _inputD = missionNamespace getVariable ["ace_common_disableInputPFH", nil];
                if (isNil "_inputD") then {_inputD = "nil"};
                TRACE_6("wakeUp check",_unit,_targetState,_isUncon,_anim,_weap,_inputD);
                [QGVAR(sLog), ["wakeUp check", format ["%1 [State:%2] [isUncon:%3] [Anim:%4] [Weap: %5] [InputD: %6]", profileName, _targetState, _isUncon, _anim, _weap, _inputD]]] call CBA_fnc_serverEvent;
            }, [_unit], 5] call CBA_fnc_waitAndExecute;
        };
    }] call CBA_fnc_addEventHandler;
};
