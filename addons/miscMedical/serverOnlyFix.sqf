INFO("server only fix running");

[{
    INFO("remoteExecCall: sending");
    {
        INFO("remoteExecCall: recieved");
        [{
            INFO("remoteExecCall: after delay");

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


            // Attempt fixing bad wakeUps
            if (hasInterface) then {
                GVAR(fixUsed) = false;
                ["ace_medical_wakeUp", {
                    if (GVAR(fixUsed)) exitWith {}; // only one attempt, prevent possible endless loop?
                    params ["_unit"];
                    if ((_unit == ACE_player) && {[_unit] call ace_medical_status_fnc_hasStableVitals}) then {
                        TRACE_1("wakeUp2 event",_unit);
                        [{
                            params ["_unit"];
                            private _isUncon = _unit getVariable ["ACE_isUnconscious", -1];
                            private _inputD = missionNamespace getVariable ["ace_common_disableInputPFH", nil];
                            TRACE_3("after wakeup2",_unit,_isUncon,_inputD);
                            if ((!_isUncon) && {!isNil "_inputD"}) then {
                                TRACE_1("cycling ace_medical_fnc_setUnconscious",_unit);
                                [QGVAR(sLog), ["bugged wakeUp - fixing", format ["%1 [Unit:%2] [isUncon: %3] [inputD: %4]", profileName, _unit, _isUncon, _inputD]]] call CBA_fnc_serverEvent;
                                ["potato_adminMsg", [format ["[AUTO] bugged wakeUp - fixing"], profileName]] call CBA_fnc_globalEvent;
                                [_unit, true, 1, true] call ace_medical_fnc_setUnconscious;
                                GVAR(fixUsed) = true;
                            };
                        }, [_unit], 1] call CBA_fnc_waitAndExecute;
                    };
                }] call CBA_fnc_addEventHandler;
            };


        }, [], 1] call CBA_fnc_waitAndExecute;
    } remoteExecCall ["bis_fnc_call", 0, true];
}, [], 1] call CBA_fnc_waitAndExecute;
