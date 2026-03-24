#include "..\..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This fucntion handles opening and closing the mission menu.
*
* Arguments:
* _isClosing - True if dialog is closing
* _eventArgs - Array of arguments depending on state
*
* Only called via callback
*//***************************************************************************/
params ["_isClosing", "_eventArgs"];

if (_isClosing) then {
    _eventArgs params ["_display", ["_exitCode", 0]];
    if (GVAR(mainMenuMapClickEH) >= 0) then {
        removeMissionEventHandler ["MapSingleClick", GVAR(mainMenuMapClickEH)];
        GVAR(mainMenuMapClickEH) = -1;
    };
    for "_i" from 0 to BW_ZONE_MAX_CHECK do {
        private _mark = BW_ZONE_BASE_STRING + (str _i);
        if ((getMarkerPos _mark) isEqualTo [0, 0, 0]) exitWith {};
        if (markerColor _mark != "ColorBlue") then {
            _mark setMarkerAlphaLocal 0;
        };
    };
    for "_i" from 0 to BW_MOUT_MAX_CHECK do {
        private _mark = BW_MOUT_BASE_STRING + (str _i);
        if (getMarkerPos _mark isEqualTo [0, 0, 0]) exitWith {};
        _mark setMarkerAlphaLocal 0;
    };
    if (_exitCode != 1) exitWith {
        deleteMarkerLocal GVAR(missionFirstPositionMarker);
    };
    GVAR(missionSelectedZone) setMarkerPos (markerPos GVAR(missionSelectedZone));
    if (GVAR(missionSelectedZone) != "" ||
        GET_MENU_OPTION(operationType)  == BW_TRAINING_OPERATION_MOUT) then {
        if (GET_MENU_OPTION(operationType) == BW_TRAINING_OPERATION_ZONE_DRAW) then {
            SET_MENU_OPTION(density,BW_TRAINING_DENSITY_UNIFORM);
        };
        private _random = cbChecked (_display displayCtrl IDC_MISSION_RANDOM);
        if (_random) then {
            [GVAR(missionSelectedZone), createHashMapFromArray [
                ["operationType", GET_MENU_OPTION(operationType)],
                ["enemyType", GET_MENU_OPTION(enemyType)],
                ["density", GET_MENU_OPTION(density)],
                ["AIskillMin", 0.25 + random 0.25],
                ["AIskillMax", 0.5 + random 0.1],
                ["option0", 0.4 + random 0.6],
                ["option1", 0.4 + random 0.6],
                ["option2", random 0.3],
                ["option3", 0.6 + random 0.4],
                ["option4", random 1],
                ["option5", random 1],
                ["option6", 0.5 + random 0.5]
            ]] remoteExecCall [QFUNC(handleMissionInit), 2];
        } else {
            [GVAR(missionSelectedZone), GVAR(menuOptions)] remoteExecCall [QFUNC(handleMissionInit), 2];
        };
    } else {
        systemChat "Failed to initialize mission";
    };
    GVAR(missionSelectedZone) = "";
    GVAR(missionFirstPositionMarker) = "";
};
