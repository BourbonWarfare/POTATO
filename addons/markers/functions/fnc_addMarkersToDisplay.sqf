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
disableSerialization;
#include "script_component.hpp"
TRACE_1("params",_this);

params ["_display","_idc"];
TRACE_2("IDs",_display,_idc);

if !(GVAR(settingsInitialized)) exitWith { GVAR(settingsDelayedFunctions) pushBack [FUNC(addMarkersToDisplay),_this]; };

private _installedVarName = format ["%2_%3",_idc,"EHInstalled"];
if (GVAR(skipInstallingEH) || {_display getVariable [_installedVarName, false]}) exitWith {};
_display setVariable [_installedVarName, true];

(_display displayCtrl _idc) ctrlAddEventHandler ["draw", {_this call FUNC(drawMarkers)}];

TRACE_3("end",_display,_idc,_display displayCtrl _idc);
