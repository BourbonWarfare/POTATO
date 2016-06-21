/*
 * Author: AACO
 * Function used to add units from the faction unit list to the pending list
 * Should only be called from UI events
 *
 * Arguments:
 * 0: index of the unit in the faction unit list <NUMBER>
 *
 * Examples:
 * [1] call potato_zeusHC_fnc_buildAGroupDialogAdd; //unit in the first index
 * [5] call potato_zeusHC_fnc_buildAGroupDialogAdd; //unit in the fifth index
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_newPlayer"];
private _newPlayerGroup = group _newPlayer;

private _sideArray = switch (playerSide) do {
    case west: { GVAR(viewBluForMarkers) };
    case east: { GVAR(viewOpForMarkers) };
    case resistance: { GVAR(viewIndyMarkers) };
    case civilian: { GVAR(viewCivMarkers) };
    default { [] };
};

if (!(isNull _newPlayerGroup) && {side _newPlayerGroup in _sideArray}) then {
    [_newPlayerGroup] call FUNC(addMarkerInfoToHash);
    [_newPlayer] call FUNC(addMarkerInfoToHash);
};
