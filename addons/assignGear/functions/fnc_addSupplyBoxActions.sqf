#include "script_component.hpp"
/*
 * Author: Lambda.Tiger
 * Adds actions to allow a client to mark a supply box using smoke, glow sticks
 * and or map markers. Smoke and glow sticks are enabled with a marking level
 * of 1 or greater, and map markers at level 2 or greater.
 *
 * Arguments:
 * 0: Box <OBJECT>
 * 1: Marking level <SCALAR>
 *    >=1 allows smoke and chem lights to be added
 *    >=2 allows for a map marker to be placed/updated
 *
 * Return Value:
 * None
 *
 * Example:
 * [cursorObject, 2] call potato_assignGear_fnc_addSupplyBoxActions.sqf
 *
 * Public: No
 */
#define LARGE_UNIQUE_MARKER_INDEX 934648
params ["_theBox", "_markingLevel"];

if (_markingLevel < 1 || !hasInterface) exitWith {};

private _action = [
    "markBoxBase",
    "Mark Box",
    "\a3\ui_f\data\igui\cfg\simpletasks\types\move_ca.paa", {
        private _marker = _target getVariable [QGVAR(boxMarker), ""];
        if (getMarkerPos _marker isNotEqualTo [0, 0, 0]) then {
            _marker setMarkerPos (getPosATL _target);
        };
    },
    {true}
] call ACEFUNC(interact_menu,createAction);
[_theBox, 0, ["ACE_MainActions"], _action] call ACEFUNC(interact_menu,addActionToObject);

//IGNORE_PRIVATE_WARNING ["_player", "_target"];
_action = [
    "markBoxSmoke",
    "Smoke",
    "\a3\Modules_F_Curator\Data\portraitSmoke_ca.paa", {
    private _smoke = createVehicle ["SmokeShellYellow", ASLToAGL getPosASL _target, [], 0, "CAN_COLLIDE"];
    _smoke attachTo [_target, [0, 0, 0]];
    _target setVariable [QGVAR(smokeAvailable), false];
    },
    {_target getVariable [QGVAR(smokeAvailable), true]}
] call ACEFUNC(interact_menu,createAction);
[_theBox, 0, ["ACE_MainActions","markBoxBase"], _action] call ACEFUNC(interact_menu,addActionToObject);
_action = [
    "markBoxGlowstick",
    "Glow Stick",
    "\a3\Modules_F_Curator\Data\portraitChemlight_ca.paa", {
    private _glowstick = createVehicle ["ACE_G_Chemlight_HiYellow", ASLToAGL getPosASL _target, [], 0, "CAN_COLLIDE"];
    _glowstick attachTo [_target, [0, 0, 0]];
    _target setVariable [QGVAR(glowStickAvailable), false];
    },
    {_target getVariable [QGVAR(glowStickAvailable), true]}
] call ACEFUNC(interact_menu,createAction);
[_theBox, 0, ["ACE_MainActions","markBoxBase"], _action] call ACEFUNC(interact_menu,addActionToObject);

if (_markingLevel < 2) exitWith {};
_action = [
    "markBoxMapMarker",
    "Map Marker",
    "\a3\ui_f\data\igui\cfg\simpletasks\types\rearm_ca.paa", {
        private _marker = _target getVariable [QGVAR(boxMarker), ""];
        // when a marker name/values are edit, the marker is re-created so it's possible to lose it (often)
        if (getMarkerPos _marker isEqualTo [0, 0, 0]) then {
            _marker = createMarkerLocal [
                format ["_USER_DEFINED #%1/%2/%3ResupplyBoxMarker_%4",
                    clientOwner,
                    LARGE_UNIQUE_MARKER_INDEX,
                    1,
                    GVAR(resupplyBoxMarkerIndex)
                ],
                getPosATL _target,
                1,
                player
            ];
            GVAR(resupplyBoxMarkerIndex) = GVAR(resupplyBoxMarkerIndex) + 1;
            _marker setMarkerColorLocal "ColorYellow";
            private _boxName = _target getVariable [QACEGVAR(cargo,customName), "Resupply Box"];
            _marker setMarkerTextLocal _boxName;
            _marker setMarkerType "loc_rearm";
            _target setVariable [QGVAR(boxMarker), _marker, true];
        } else {
            _marker setMarkerPos (getPosATL _target);
        };
    },
    {true}
] call ACEFUNC(interact_menu,createAction);
[_theBox, 0, ["ACE_MainActions","markBoxBase"], _action] call ACEFUNC(interact_menu,addActionToObject);