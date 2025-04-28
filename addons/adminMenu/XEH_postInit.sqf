#include "script_component.hpp"

[QGVAR(resetGear), {
    params [["_unit", objNull, [objNull]]];
    diag_log text format ["[POTATO] Resetting Gear on %1 [%2]", (name _unit), _unit];
    if ((isNull _unit) || {!alive _unit} || {!local _unit}) exitWith {};

    removeAllWeapons _unit;
    removeHeadgear _unit;
    removeVest _unit;
    removeUniform _unit;
    removeAllAssignedItems _unit;
    removeBackpack _unit;

    [{
        if (missionNamespace getVariable [QEGVAR(assignGear,usePotato), false]) then {
            diag_log text format ["[POTATO] Calling %1", QEFUNC(assignGear,requestPlayerGear)];
            [_this] call EFUNC(assignGear,requestPlayerGear);
        } else {
            diag_log text format ["[POTATO] Calling F_fnc_assignGearMan"];
            [_this] call F_fnc_assignGearMan;
        };
    }, _unit, 0.5] call CBA_fnc_waitAndExecute;
}] call CBA_fnc_addEventHandler;

[QGVAR(resetSpectator), {
    if !(missionNamespace getVariable [QEGVAR(spectate,enabled), false]) exitWith {};

    params [["_unit", objNull, [objNull]]];

    diag_log text format ["[POTATO] Resetting spectator on %1 [%2]", (name _unit), _unit];
    if (isNull _unit || {!local _unit} || {alive _unit && !(_unit isKindOf QEGVAR(spectate,spectator))}) exitWith {};

    diag_log text format ["[POTATO] Calling %1", QEFUNC(spectate,exit)];
    [] call EFUNC(spectate,exit);

    diag_log text format ["[POTATO] Calling %1", QEFUNC(spectate,setup)];
    [_unit] call EFUNC(spectate,setup);
}] call CBA_fnc_addEventHandler;

[QGVAR(resetMarkers), {
    params [["_unit", objNull, [objNull]]];

    diag_log text format ["[POTATO] Resetting markers on %1 [%2]", (name _unit), _unit];
    if (isNull _unit || {!local _unit}) exitWith {};

    diag_log text format ["[POTATO] Calling %1", QEFUNC(markers,reinitMarkerHash)];
    [] call EFUNC(markers,reinitMarkerHash);
}] call CBA_fnc_addEventHandler;

[QGVAR(missionTestingAddAction), {
    private _displayChecklist = ["displayChecklist", "Testing Menu", "", {[] call EFUNC(missionTesting,displayMenu)}, {!isNull getAssignedCuratorLogic player}, {}, [], [], 0] call ace_interact_menu_fnc_createAction;
    ["CAManBase", 1, ["ACE_SelfActions"], _displayChecklist, true] call ace_interact_menu_fnc_addActionToClass;
    EGVAR(missionTesting,missionTestingActive) = true;
}] call CBA_fnc_addEventHandler;

GVAR(openEndMission) = false;
[QGVAR(endMission), { 
    // delay a frame to allow other scripts to complete
    [FUNC(endMission), _this] call CBA_fnc_execNextFrame;
}] call CBA_fnc_addEventHandler;

if (isServer) then {
    GVAR(zeusCenter) = createCenter sideLogic;
    // check server settings
    [QGVAR(checkSettings), {
        params ["_owner"];
        private _hash = profileNamespace getVariable ["CBA_settings_hash", [] call CBA_fnc_hashCreate]; 
        private _output = []; 
        [_hash, { _output pushBack format ["%1: %2", _key, _value]; }] call CBA_fnc_hashEachPair;
        ["potato_adminMsg", [format ["%1 modified settings", count _output], "Setting"], _owner] call CBA_fnc_ownerEvent; 
        { 
            ["potato_adminMsg", [_x, "Setting"], _owner] call CBA_fnc_ownerEvent; 
        } forEach _output; 
    }] call CBA_fnc_addEventHandler;
};
