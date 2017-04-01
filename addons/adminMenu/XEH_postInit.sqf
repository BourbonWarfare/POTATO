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
            diag_log text format ["[POTATO] Calling potato_assignGear_fnc_assignGearMan"];
            // set unit loadout overrides our sick shades :(
            private _goggles = goggles _this;
            removeGoggles _this;
            [_this] call potato_assignGear_fnc_assignGearMan;
            _this addGoggles _goggles;
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

    diag_log text format ["[POTATO] Calling potato_spectate_fnc_exit"];
    [] call EFUNC(spectate,exit);

    diag_log text format ["[POTATO] Calling potato_spectate_fnc_init"];
    [_unit] call EFUNC(spectate,setup);
}] call CBA_fnc_addEventHandler;


GVAR(openEndMission) = false;

if (isServer) then {
    GVAR(zeusCenter) = createCenter sideLogic;
};
