#include "script_component.hpp"

[QGVAR(resetGear), {
    params [["_unit", objNull, [objNull]]];
    diag_log text format ["[POTATO] Reseting Gear on %1 [%2]", (name _unit), _unit];
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

    diag_log text format ["[POTATO] Reseting spectator on %1 [%2]", (name _unit), _unit];
    if (isNull _unit || {!local _unit} || {alive _unit && !(_unit isKindOf QEGVAR(spectate,spectator))}) exitWith {};

    diag_log text format ["[POTATO] Calling %1", QEFUNC(spectate,exit)];
    [] call EFUNC(spectate,exit);

    diag_log text format ["[POTATO] Calling %1", QEFUNC(spectate,setup)];
    [_unit] call EFUNC(spectate,setup);
}] call CBA_fnc_addEventHandler;

[QGVAR(resetMarkers), {
    params [["_unit", objNull, [objNull]]];

    diag_log text format ["[POTATO] Reseting markers on %1 [%2]", (name _unit), _unit];
    if (isNull _unit || {!local _unit}) exitWith {};

    diag_log text format ["[POTATO] Calling %1", QEFUNC(markers,initMarkerHash)];
    [] call EFUNC(markers,initMarkerHash);
}] call CBA_fnc_addEventHandler;

[QGVAR(missionTestingAddAction), {
    private _displayChecklist = ["displayChecklist", "Testing Menu", "", {[] call EFUNC(missiontesting,displayMenu);}, {}, {}, [], [], 0] call ace_interact_menu_fnc_createAction;
    ["CAManBase", 1, ["ACE_SelfActions"], _displayChecklist, true] call ace_interact_menu_fnc_addActionToClass;
}] call CBA_fnc_addEventHandler;

GVAR(openEndMission) = false;

if (isServer) then {
    GVAR(zeusCenter) = createCenter sideLogic;
};
