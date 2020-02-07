#define DEBUG_MODE_FULL
#include "script_component.hpp"
LOG("Post init start");


if (isServer) then {
    [QGVAR(sLog), {
        params ["_type", "_msg"];
        INFO_2("SLOG - %1: %2",_type,_msg);
    }] call CBA_fnc_addEventHandler;

    #include "serverOnlyFix.sqf";

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



// Add ability to examine unconcscious and determine cause of not waking up (should be temporary?)
DFUNC(vitalsStableExamine) = {
    params ["_unit", "_return"];

    private _status = call {
        // based on ace_medical_status_fnc_hasStableVitals
        if ((_unit getVariable ["ace_medical_bloodVolume", 6.0 ]) < 5.100 ) exitWith { "Unstable: Low Blood Volume" };
        if (_unit getVariable ["ace_medical_inCardiacArrest", false]) exitWith { "Unstable: Cardiac Arrest (should not happen)" };

        private _cardiacOutput = [_unit] call ace_medical_status_fnc_getCardiacOutput;
        private _bloodLoss = ([_unit] call ace_medical_status_fnc_getBloodLoss);
        if (_bloodLoss > (0.5  * _cardiacOutput) / 2) exitWith { "Unstable: Bleeding" };

        private _bloodPressure = ([_unit] call ace_medical_status_fnc_getBloodPressure);
        _bloodPressure params ["_bloodPressureL", "_bloodPressureH"];
        if (_bloodPressureL < 50 || {_bloodPressureH < 60}) exitWith { "Unstable: Blood Pressure" };

        private _heartRate = (_unit getVariable ["ace_medical_heartRate", 80]);
        if (_heartRate < 40) exitWith { "Unstable: Heart Rate" };
        "Stable: Should eventually wakeup"
    };

    TRACE_3("vitalsStableExamine",_unit,_return,_status);
    private _name = if (isPlayer _unit) then { name _unit } else { "AI" };
    [QGVAR(sLog), ["_checkUnconc", format ["%1 [VitalsStableExamine: %2] [Checker: %3]", _name, _status, name _return]]] call CBA_fnc_serverEvent;
    ["ace_common_displayTextStructured", [_status, 2, _return], [_return]] call CBA_fnc_targetEvent;
};
DFUNC(checkUnconcStatement) = {
    params ["_target", "_player"];
    TRACE_2("checkUnconcStatement",_target,_player);
    [QGVAR(vitalsStableExamine), [_target, _player], [_target]] call CBA_fnc_targetEvent;
};
DFUNC(checkUnconcCondition) = {
    params ["_target", "_player"];
    (alive _target) && {_target getVariable ["ace_isUnconscious", false]}
};

[QGVAR(vitalsStableExamine), {call FUNC(vitalsStableExamine)}] call CBA_fnc_addEventHandler;
if (hasInterface) then {
    private _action = [QGVAR(checkUncon), "Check why unconcscious","\A3\ui_f\data\igui\cfg\simpleTasks\types\unknown_ca.paa",{call FUNC(checkUnconcStatement)},{call FUNC(checkUnconcCondition)}] call ace_interact_menu_fnc_createAction;
    ["CaManBase", 0, ["ACE_Head"], _action, true] call ace_interact_menu_fnc_addActionToClass;
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
                        // _unit setDamage 1;
                        [_unit, "Fatal Damage"] call ace_medical_status_fnc_setDead; // this should show correct killer instead of "#scripted"
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



    GVAR(readyToMsg) = true;
    [{
        private _unit = ace_player;
        if (!alive _unit) exitWith {};
        private _state = [_unit, ace_medical_STATE_MACHINE] call CBA_statemachine_fnc_getCurrentState;
        private _stableVitals = [_unit] call ace_medical_status_fnc_hasStableVitals;
        private _isUncon = _unit getVariable ["ACE_isUnconscious", false];
        private _anim = animationState _unit;
        private _inputD = missionNamespace getVariable ["ace_common_disableInputPFH", -1];
        private _lastWakeUpCheck = _unit getVariable ["ace_medical_lastWakeUpCheck", -1];
        if (_lastWakeUpCheck > 0) then { _lastWakeUpCheck = CBA_missionTime - _lastWakeUpCheck };
        private _lastTimeUpdated = _unit getVariable ["ace_medical_vitals_lastTimeUpdated", -1];
        if (_lastTimeUpdated > 0) then { _lastTimeUpdated = CBA_missionTime - _lastTimeUpdated };

        INFO_8("Status %1 [%2][stable %3][isUncon %4][anim %5][input %6][WakUpC %7][TimeU %8]",_unit,_state,_stableVitals,_isUncon,_anim,_inputD,_lastWakeUpCheck,_lastTimeUpdated);

        // if ((random 1) < 0.1) then {
        // [QGVAR(sLog), ["LOG", format ["%1 [%2][stable %3][isUncon %4][anim %5][input %6][WakUpC %7][TimeU %8]", profileName,_state,_stableVitals,_isUncon,_anim,_inputD,_lastWakeUpCheck,_lastTimeUpdated]]] call CBA_fnc_serverEvent;
        // };

        switch (toLower _state) do {
        case ("default");
        case ("injured"): {
                if (_isUncon || {_inputD > -1}) then {
                    [QGVAR(sLog), ["bugged A", format ["%1 [%2][isUncon %3][anim %4][input %5]", profileName, _state,_isUncon,_anim,_inputD]]] call CBA_fnc_serverEvent;
                    if (GVAR(readyToMsg)) then {
                        ["potato_adminMsg", [format ["[AUTO] bugged A"], profileName]] call CBA_fnc_globalEvent;
                        GVAR(readyToMsg) = false;
                    };
                };
            };
        case ("unconscious"): {
                if ((!_isUncon) || {_inputD == -1}) then {
                    [QGVAR(sLog), ["bugged B", format ["%1 [%2][isUncon %3][anim %4][input %5]", profileName, _state,_isUncon,_anim,_inputD]]] call CBA_fnc_serverEvent;
                    if (GVAR(readyToMsg)) then {
                        ["potato_adminMsg", [format ["[AUTO] bugged B"], profileName]] call CBA_fnc_globalEvent;
                        GVAR(readyToMsg) = false;
                    };
                };
            };
            default { INFO_1("State: %1",_state); };
        };
    }, 30, []] call CBA_fnc_addPerFrameHandler;
};
