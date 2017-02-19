/*
 * Author: AACO
 * Function used to show the timer to clients
 *
 * Arguments:
 * 0: Display the timer? <BOOL>
 *
 * Examples:
 * [true] call potato_safeStart_fnc_toggleTimer;
 * [false] call potato_safeStart_fnc_toggleTimer;
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params [["_showTimer", true, [true]]];

if (_showTimer) then {
    if !(isNil QGVAR(timerID)) exitWith { LOG("Tried to start safestart while it was already running") };

    if (GVAR(showTimer)) then {
        [QGVAR(timerRscTitle)] call CFUNC(createRscTitle);
    };

    GVAR(timerID) = [FUNC(updateTimer), 0.2, []] call CBA_fnc_addPerFrameHandler;
} else {
    if (isNil QGVAR(timerID)) exitWith { LOG("Tried to stop safestart while it was already stopped") };

    [GVAR(timerID)] call CBA_fnc_removePerFrameHandler;
    GVAR(timerID) = nil;

    QGVAR(timerRscTitle) cutFadeOut 1;
    [QGVAR(startingRscTitle), true] call CFUNC(createRscTitle);
};
