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
        [player, EGVAR(miscFixes,eventsArray)]
    } else {
        [GVAR(camTarget), GVAR(camTarget) getVariable [QEGVAR(miscFixes,eventsArray), []]]
    } params ["_unit", "_killFeed"];

    if !(ctrlShown FOCUS_GROUP) then {
        FOCUS_GROUP ctrlShow true;
    };

    FOCUS_NAME ctrlSetText ([_unit] call FUNC(getName));

    if !(GVAR(lastKillFeed) isEqualTo _killFeed) then {
        lbClear FOCUS_KILL;
        if (_killFeed isEqualTo []) then {
            FOCUS_KILL ctrlShow false;
            FOCUS_DOWN_BG ctrlShow false;
        } else {
            {
                FOCUS_KILL lbAdd _x;
            } forEach _killFeed;

            FOCUS_KILL ctrlShow true;
            FOCUS_DOWN_BG ctrlShow true;
        };
        GVAR(lastKillFeed) = _killFeed;
    };

    if (vehicle _unit == _unit) then {
        FOCUS_UNIT ctrlSetText ([_unit] call FUNC(getVehicleIcon));
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
