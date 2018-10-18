/*
 * Author: AACO
 * Function used on faction or vehicle type change to update the vehicle options
 * Clears and repopulates the vehicle box
 * Should only be called from UI events
 *
 * Example:
 * [] call potato_zeusHC_fnc_reinforcementsDialogChange;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

private _factionIndex = lbCurSel REINFORCEMENT_FACTIONS_IDC;
private _typeIndex = lbCurSel REINFORCEMENT_TYPE_IDC;

if (_factionIndex == -1 || _typeIndex == -1) exitWith {};

lbClear REINFORCEMENT_VEHICLE_IDC;

lbAdd [REINFORCEMENT_VEHICLE_IDC, "Random"];
{
    private _name = getText (configFile >> "CfgVehicles" >> _x >> "displayName");
    private _icon = getText (configFile >> "CfgVehicles" >> _x >> "icon");

    private _vicIndex = lbAdd [REINFORCEMENT_VEHICLE_IDC, _name];
    lbSetPicture [REINFORCEMENT_VEHICLE_IDC, _vicIndex,  _icon];
    lbSetData [REINFORCEMENT_VEHICLE_IDC, _vicIndex, _x];
    lbSetToolTip [REINFORCEMENT_VEHICLE_IDC, _vicIndex, _x];

    nil
} count ((GVAR(validPools) select _factionIndex) select (VEHICLE_POOL_START_INDEX + _typeIndex));

lbSetCurSel [REINFORCEMENT_VEHICLE_IDC, 0];
