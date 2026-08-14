#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * Description:
 * This function will either toggle showing markers, or if the control load in
 * calls the function it will reinit the draw3d. Enabling this function will
 * result in the player entering zeus seeing ALL markers on the map including
 * markers used by other sides not configured to show to the player.
 *
 * Arguments:
 * 0: The control that an event happens to
 * 1: Whether the function is called by a load event (BOOL, default false)
 *
 * Return Value:
 * None
 *
 * Examples:
 * [_control, 0] call potato_zeusUtils_fnc_changeArtyDisplayState;
 *
 * Public: No
 */
params [
    "_control",
    ["_onLoad", false]
];
TRACE_2("",_control,_onLoad);

private _inDrawQueue = QGVAR(artyEH) in GVAR(draw3DFunctions);
_control ctrlSetFade ([0, 0.2] select _inDrawQueue);

if (_onLoad) then {
    if (_inDrawQueue) then {
        [ZEUSUTILS_DEH_ARTY] call FUNC(addDraw3DEH);
        _control ctrlSetTextColor [0, 1, 0, 1];
    };
} else {
    TRACE_1("Toggling Arty display: ",CBA_missionTime);
    if (_inDrawQueue) then {
        [ZEUSUTILS_DEH_ARTY] call FUNC(removeDraw3DEH);
        _control ctrlSetFade 0;
        _control ctrlSetTextColor [1, 1, 1, 1];
        INFORM_USER(Disabled artillery display);
    } else {
        [ZEUSUTILS_DEH_ARTY] call FUNC(addDraw3DEH);
        _control ctrlSetTextColor [0, 1, 0, 1];
        INFORM_USER(Enabled artillery display);
    };
};
_control ctrlCommit 0;
