/*
 * Author: AACO
 * Function used to change the active faction in the dialog
 * Clear the vehicle list, repopulates the faction vehicle list
 * Should only be called from UI events
 *
 * Arguments:
 * 0: index of the faction list <NUMBER>
 *
 * Examples:
 * [1] call potato_zeusHC_fnc_spawnAVicDialogFactionChange; //Faction in the first index
 * [5] call potato_zeusHC_fnc_spawnAVicDialogFactionChange; //Faction in the fifth index
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params [["_index", lbCurSel SPAWN_VIC_FACTIONS_IDC]];

// clear list box
lbClear SPAWN_VIC_LIST_IDC;

private _factionIndex = (GVAR(spawnVicCache) select 0) find (lbData [SPAWN_VIC_FACTIONS_IDC, _index]);
if (_factionIndex > -1) then {
    private _unitArray = (GVAR(spawnVicCache) select 1) select _factionIndex;
    {
        _x params ["_classname", "_displayName", "_icon"];
        private _unitIndex = lbAdd [SPAWN_VIC_LIST_IDC, _displayName];
        lbSetPicture [SPAWN_VIC_LIST_IDC, _unitIndex,  _icon];
        lbSetData [SPAWN_VIC_LIST_IDC, _unitIndex, _classname];
        lbSetTooltip [SPAWN_VIC_LIST_IDC, _unitIndex, _classname];
        nil
    } count _unitArray;
};
