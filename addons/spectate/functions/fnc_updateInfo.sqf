/*
 * Author: AACO
 * Function used to update the info widget
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [] call potato_spectate_fnc_updateInfo;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

if (GVAR(uiVisible) && GVAR(showInfo)) then {
    if (isNull GVAR(camTarget)) then {
        [player, acex_killTracker_outputText]
    } else {
        [GVAR(camTarget), GVAR(camTarget) getVariable [QEGVAR(miscFixes,eventsString), "None"]]
    } params ["_unit", "_killFeed"];
    TRACE_1("Kill Feed", _killFeed);

    if !(ctrlShown FOCUS_GROUP) then {
        FOCUS_GROUP ctrlShow true;
    };

    FOCUS_NAME ctrlSetText ([_unit] call FUNC(getName));
    FOCUS_KILL ctrlSetStructuredText parseText format ["%1%2%3", "<t size='0.75'>", _killFeed, "</t>"];
    private _killPos = ctrlPosition FOCUS_KILL;
    _killPos set [3, ctrlTextHeight FOCUS_KILL];
    FOCUS_KILL ctrlSetPosition _killPos;
    FOCUS_KILL ctrlCommit 0;

    if (vehicle _unit == _unit) then {
        FOCUS_UNIT ctrlSetText ([_unit] call ACEFUNC(common,getVehicleIcon));
        FOCUS_UNIT ctrlShow true;

        FOCUS_VEHICLE ctrlSetText "";
        FOCUS_VEHICLE ctrlShow false;
    } else {
        FOCUS_VEHICLE ctrlSetText (getText (configFile >> "CfgVehicles" >> typeOf (vehicle _unit) >> "Picture"));
        FOCUS_VEHICLE ctrlShow true;

        FOCUS_UNIT ctrlSetText "";
        FOCUS_UNIT ctrlShow false;
    };
} else {
    FOCUS_GROUP ctrlShow false;
};
