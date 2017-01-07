/*
 * Author: AACO
 * Function used to
 *
 * Arguments:
 *
 * Examples:
 * [] call potato_spectate_fnc_;
 *
 * Public: No
 */
#define DEBUG_MODE_FULL
#include "script_component.hpp"
TRACE_1("Params",_this);

if (GVAR(uiVisible) && GVAR(showInfo)) then {
    if (isNull GVAR(camTarget)) then {
        [player, EGVAR(miscFixes,eventsArray)]
    } else {
        [GVAR(camTarget), GVAR(camTarget) getVariable [QEGVAR(miscFixes,eventsArray), []]]
    } params ["_unit", "_killFeed"];

    private _name = [_unit] call FUNC(getName);
    private _unitIcon = [_unit] call FUNC(getVehicleIcon);
    private _vehicleIcon = getText (configFile >> "CfgVehicles" >> typeOf (vehicle _unit) >> "Picture");

    if !(ctrlShown FOCUS_GROUP) then {
        FOCUS_GROUP ctrlShow true;
    };

    FOCUS_NAME ctrlSetText _name;

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
        FOCUS_UNIT ctrlSetText _unitIcon;
        FOCUS_UNIT ctrlShow true;

        FOCUS_VEHICLE ctrlSetText "";
        FOCUS_VEHICLE ctrlShow false;
    } else {
        FOCUS_VEHICLE ctrlSetText _vehicleIcon;
        FOCUS_VEHICLE ctrlShow true;

        FOCUS_UNIT ctrlSetText "";
        FOCUS_UNIT ctrlShow false;
    };
} else {
    FOCUS_GROUP ctrlShow false;
};
