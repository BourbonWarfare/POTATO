/*
 * Author: AACO
 * Function called by the placed ARES reinforcement module to create the UI
 * to gather the reinforcment configuration, and send that information to the server
 *
 * Arguments:
 * 0: placed logic object <OBJECT>
 *
 * Example:
 * [gameLogic] call potato_reinforceToHC_fnc_reinforcementsDialogLoad;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

if (isNil QGVAR(reinforceUnits)
    || typeName GVAR(reinforceUnits) != typeName []
    || count GVAR(reinforceUnits) == 0) exitWith {
    ["Unable to load unit pools. Is your unit pool corrupt?"] call EFUNC(zeusHC,sendCuratorHint);
    closeDialog 0;
};

private _allUnitPools = if (isNil "Ares_Reinforcement_Mission_Unit_Pools") then {
    GVAR(reinforceUnits)
} else {
    GVAR(reinforceUnits) + Ares_Reinforcement_Mission_Unit_Pools
};

private _allLzsUnsorted = allMissionObjects "Ares_Module_Reinforcements_Create_Lz";
if (count _allLzsUnsorted == 0) exitWith {
    ["You must have at least one LZ for the transport to head to."] call EFUNC(zeusHC,sendCuratorHint);
    closeDialog 0;
};
GVAR(allLzs) = [_allLzsUnsorted, [], { _x getVariable ["SortOrder", 0]; }, "ASCEND"] call BIS_fnc_sortBy;

private _allRpsUnsorted = allMissionObjects "Ares_Module_Reinforcements_Create_Rp";
GVAR(allRps) = [_allRpsUnsorted, [], { _x getVariable ["SortOrder", 0]; }, "ASCEND"] call BIS_fnc_sortBy;

waitUntil {dialog}; // wait until the dialog is fully loaded before we do any population

// Setup faction list
private GVAR(validPools) = [];
{
    if ((_x select ADDON_CLASS_INDEX) == "" || isClass(configFile >> "CfgPatches" >> (_x select ADDON_CLASS_INDEX))) then {
        lbAdd [REINFORCEMENT_FACTIONS_IDC, _x select DISPLAY_NAME_INDEX];
        GVAR(validPools) pushBack _x;
    };
    nil
} count _allUnitPools;

lbSetCurSel [REINFORCEMENT_FACTIONS_IDC, if (isNil QGVAR(lastFactionIndex)) then { 0 } else { GVAR(lastFactionIndex) }];

// Generate list of vehicle types to let user choose from
{
    lbAdd [REINFORCEMENT_TYPE_IDC, _x];
    nil
} count ["Unarmed Light Vehicles + Scouts", "Armed Light Vehicles", "Dedicated Troop Trucks", "APC's & Heavy Troop Transports", "Unarmed Aircraft", "Light Armed Aircraft", "Unarmed Boats", "Armed Boats"];

lbSetCurSel [REINFORCEMENT_TYPE_IDC, if (isNil QGVAR(lastTypeIndex)) then { 0 } else { GVAR(lastTypeIndex) }];

// Setup the specific vehicle box
[] call FUNC(reinforcementsDialogChange);
lbSetCurSel [REINFORCEMENT_VEHICLE_IDC, if (isNil QGVAR(lastVehicleIndex)) then { 0 } else { GVAR(lastVehicleIndex) }];

{
    lbAdd [REINFORCEMENT_VEHICLE_BEHAVIOR_IDC, _x];
    nil
} count ["RTB and Despawn", "Stay at LZ"];
lbSetCurSel [REINFORCEMENT_VEHICLE_BEHAVIOR_IDC, if (isNil QGVAR(lastVehicleBehaviorIndex)) then { 0 } else { GVAR(lastVehicleBehaviorIndex) }];

// Setup LZs/RPs
{
    lbAdd [REINFORCEMENT_VEHICLE_LZ_IDC, _x];
    lbAdd [REINFORCEMENT_UNIT_RP_IDC, _x];
    nil
} count ["Random", "Nearest", "Farthest", "Least Used"];

{
    lbAdd [REINFORCEMENT_VEHICLE_LZ_IDC, name _x];
    nil
} count GVAR(allLzs);

{
    lbAdd [REINFORCEMENT_UNIT_RP_IDC, name _x];
    nil
} count GVAR(allRps);

lbSetCurSel [REINFORCEMENT_VEHICLE_LZ_IDC, if (isNil QGVAR(lastVehicleLZIndex)) then { 0 } else { GVAR(lastVehicleLZIndex) }];
lbSetCurSel [REINFORCEMENT_UNIT_RP_IDC, if (isNil QGVAR(lastUnitRPIndex)) then { 0 } else { GVAR(lastUnitRPIndex) }];

// Setup unit behavior
{
    lbAdd [REINFORCEMENT_UNIT_BEHAVIOR_IDC, _x];
    nil
} count ["Default", "Relaxed", "Cautious", "Combat"];
lbSetCurSel [REINFORCEMENT_UNIT_BEHAVIOR_IDC, if (isNil QGVAR(lastUnitBehaviorIndex)) then { 0 } else { GVAR(lastUnitBehaviorIndex) }];
