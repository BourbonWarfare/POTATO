#include "script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function handles updating the map timer for both safe start and mission
 * elapsed time.
 *
 * Arguments:
 * None, called by perFrameHandler
 *
 * Public: No
 */
private _ctrl = uiNamespace getVariable QGVAR(missionClock);
_ctrl ctrlShow ACEGVAR(map,hasWatch);
private _time = missionNamespace getVariable [QGVAR(startTime_PV), -1];
_time = if (_time == -1) then {CBA_missionTime - GVAR(endTime)} else {CBA_missionTime - _time};
_ctrl ctrlSetText ([_time] call CFUNC(getTimeText));
