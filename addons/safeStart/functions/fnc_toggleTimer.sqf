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
        [TIMER_LAYER, QGVAR(safeStartTimerRscTitle)] call FUNC(createDisplay);
    };

    GVAR(timerID) = [FUNC(updateTimer), 0.2, []] call CBA_fnc_addPerFrameHandler;
} else {
    if (isNil QGVAR(timerID)) exitWith { LOG("Tried to stop safestart while it was already stopped") };

    [GVAR(timerID)] call CBA_fnc_removePerFrameHandler;
    GVAR(timerID) = nil;

    TIMER_LAYER cutFadeOut 1;

    [START_LAYER, QGVAR(safeStartStartingRscTitle), true] call FUNC(createDisplay);

    ((uiNamespace getVariable [QGVAR(safeStartStartingRscTitle), displayNull]) displayCtrl 1100) ctrlSetStructuredText parseText format ["<t align='center'>Safe Start Ending<br/><t color='#ff0000'>Start Mission</t></t>"];

    [
        { START_LAYER cutFadeOut 1; },
        [],
        7
    ] call CBA_fnc_waitAndExecute;
};
