#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * Description:
 * This function will either toggle showing FPS or if the control is just being
 * loaded, it will reinit the display EH as needed.
 *
 * Arguments:
 * 0: The control that an event happens to
 * 1: Whether the function is called by a load event (BOOL, default false)
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
    ["_onLoad", false]
];
TRACE_2("",_control,_onLoad);

if !(GVAR(missionFPSEnable)) exitWith {
    _control ctrlSetFade 1;
    _control ctrlSetTextColor [1, 1, 1, 1];
    _control ctrlCommit 0;
};
private _inDrawQueue = QGVAR(fpsEH) in GVAR(draw3DFunctions);
_control ctrlSetFade ([0, 0.2] select _inDrawQueue);

if (_onLoad) then {
    if (_inDrawQueue) then {
        [ZEUSUTILS_DEH_FPS] call FUNC(addDraw3DEH);
        _control ctrlSetTextColor [0, 1, 0, 1];
    };
} else {
    TRACE_1("Toggling diag frame fps: ",CBA_missionTime);
    if (_inDrawQueue) then {
        [QGVAR(ZeusFPSMonitorUpdate), [clientOwner, false]] call CBA_fnc_serverEvent;
        [ZEUSUTILS_DEH_FPS] call FUNC(removeDraw3DEH);
        _control ctrlSetFade 0;
        _control ctrlSetTextColor [1, 1, 1, 1];
        INFORM_USER(Disabled FPS display);
    } else {
        [QGVAR(ZeusFPSMonitorUpdate), [clientOwner, true]] call CBA_fnc_serverEvent;
        [ZEUSUTILS_DEH_FPS] call FUNC(addDraw3DEH);
        _control ctrlSetTextColor [0, 1, 0, 1];
        INFORM_USER(Enabled FPS display);
    };
};
_control ctrlCommit 0;
