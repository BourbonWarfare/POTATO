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

lbClear REINFORCEMENT_VEHICLE_IDC;

lbAdd [REINFORCEMENT_VEHICLE_IDC, "Random"];
{
    private _name = getText (configFile >> "CfgVehicles" >> _x >> "displayName");
    private _icon = getText (configFile >> "CfgVehicles" >> _x >> "icon");

    private _vicIndex = lbAdd [REINFORCEMENT_VEHICLE_IDC, _name];
    lbSetPicture [SPAWN_VIC_LIST_IDC, _vicIndex,  _icon];
    lbSetData [SPAWN_VIC_LIST_IDC, _vicIndex, _x];

    nil
} count ((GVAR(validPools) select (lbCurSel REINFORCEMENT_FACTIONS_IDC)) select (lbCurSel REINFORCEMENT_TYPE_IDC));
