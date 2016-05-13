/*
 * Author: AACO
 * Function called by the placed ARES reinforcement module to create the UI
 * to gather the reinforcment configuration, and send that information to the server
 *
 * Arguments:
 * 0: placed logic object <OBJECT>
 *
 * Return Value:
 * True if the logic is local to execution, false otherwise <BOOL>
 *
 * Example:
 * [gameLogic] call potato_reinforceToHC_fnc_reinforcementsDialogLoad;
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
