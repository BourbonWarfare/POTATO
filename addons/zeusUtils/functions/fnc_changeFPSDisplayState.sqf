#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 *
 *
 *
 * Arguments:
 * 0: The control that an event happens to
 * 1: What mode to change to, either (NUMBER, default 0)
 *   - 0 - Toggle display between on and off
 *   - 1 - Load last value and re-add EH as necessary
 *
 * Return Value:
 * None
 *
 * Examples:
 * [_control, 0] call potato_zeusUtils_fnc_changeFPSDisplayState;
 *
 * Public: No
 */
params [
    "_control",
    ["_toggleMode", 0, [0]]
];
TRACE_2("",_control,_toggleMode);

if !(GVAR(missionFPSEnable)) exitWith {
    _control ctrlSetFade 1;
    _control ctrlCommit 0;
};
_control ctrlSetFade ([0, 0.2] select (GVAR(fpsDisplayEH) > 0));

if (_toggleMode == 1 && GVAR(fpsDisplayEH) == -2) then {
    _toggleMode = 0;
};

if (_toggleMode == 0) then {
    TRACE_1("Toggling diag frame fps, current EH:",GVAR(fpsDisplayEH));
    if (GVAR(fpsDisplayEH) > 0) then {
        [QGVAR(ZeusFPSMonitorUpdate), [clientOwner, false]] call CBA_fnc_serverEvent;
        removeMissionEventHandler ["Draw3D", GVAR(fpsDisplayEH)];
        GVAR(fpsDisplayEH) = -1;
        _control ctrlSetFade 0;
        INFORM_USER(Disabled FPS display);
    } else {
        [QGVAR(ZeusFPSMonitorUpdate), [clientOwner, true]] call CBA_fnc_serverEvent;
        GVAR(fpsDisplayEH) = addMissionEventHandler ["Draw3D",
            {call FUNC(drawFPSHandle)}
        ];
        INFORM_USER(Enabled FPS display);
    };
};
_control ctrlCommit 0;
