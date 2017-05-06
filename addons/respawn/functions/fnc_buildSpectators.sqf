/*
 * Author: AACO
 * Builds the spectator list from the given spectator array
 *
 * Arguments:
 * 0: Spectators to list <ARRAY>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [[player]] call potato_respawn_fnc_buildSpectators;
 *
 * Public: No
 */

#include "script_component.hpp"
#define ICON_DEAD "a3\Ui_F_Curator\Data\CfgMarkers\kia_ca.paa"
TRACE_1("params",_this);

params [["_newSpectators", [], [[]]]];

private _currentIndex = lbCurSel ADMIN_SPEC_LIST_IDC;
lbClear ADMIN_SPEC_LIST_IDC;

{
    private _deathTime = _x getVariable QEGVAR(spectate,timeOfDeath);
    if (isNil "_deathTime") then {
        _deathTime = CBA_missionTime;
        _x setVariable [QEGVAR(spectate,timeOfDeath), _deathTime, true];
    };

    private _elapsedTime = CBA_missionTime - _deathTime;

    private _index = lbAdd [ADMIN_SPEC_LIST_IDC, [_x] call EFUNC(spectate,getName)];
    lbSetTooltip [ADMIN_SPEC_LIST_IDC, _index, format ["Dead for: %1m %2s", floor (_elapsedTime / 60), floor (_elapsedTime % 60)]];
    lbSetValue [ADMIN_SPEC_LIST_IDC, _index, _elapsedTime];
    lbSetPicture [ADMIN_SPEC_LIST_IDC, _index, ICON_DEAD];
    lbSetData [ADMIN_SPEC_LIST_IDC, _index, [_x] call BIS_fnc_objectVar];
    nil
} count _newSpectators;  // count used here for speed, ensure nil is above this line

// set the number of spectators
private _numberOfSpectators = lbSize ADMIN_SPEC_LIST_IDC;
ctrlSetText [ADMIN_SPEC_FRAME_IDC, format ["Spectators (%1)", _numberOfSpectators]];

// try to reset the list selection
lbSetCurSel [ADMIN_SPEC_LIST_IDC, _currentIndex min _numberOfSpectators];

// set the current spectator array to the new spectator array
GVAR(currentSpectators) = _newSpectators;
