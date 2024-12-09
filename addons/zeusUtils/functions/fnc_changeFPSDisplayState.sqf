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
diag_log formatText ["_control:%1 _toggleMode:%2", _control, _toggleMode];

if !(GVAR(missionEnable)) exitWith {
    _control ctrlSetFade 1;
    _control ctrlCommit 0;
};
_control ctrlSetFade 0;
_control ctrlCommit 0;

if (_toggleMode == 1 && GVAR(fpsDisplayEH) == -2) then {
    _toggleMode = 0;
};

private _players = allUnits;//call CBA_fnc_players;
_players = _players apply {_x setVariable [QGVAR(playerFPS), random 40]};

if (_toggleMode == 0) then {
    diag_log formatText ["Toggling diag frame fps, current EH:%1", GVAR(fpsDisplayEH)];
    if (GVAR(fpsDisplayEH) > 0) then {
        removeMissionEventHandler ["Draw3D", GVAR(fpsDisplayEH)];
        GVAR(fpsDisplayEH) = -1;
    } else {
        GVAR(fpsDisplayEH) = addMissionEventHandler ["Draw3D",
            {call FUNC(drawFPSHandle)}
        ];
    };
};
