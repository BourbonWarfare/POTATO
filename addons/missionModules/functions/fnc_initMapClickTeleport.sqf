#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function initializes teleports available in the ACE self-interact menu.
 *
 * Arguments:
 * 0: The module being initialized
 *
 * Examples:
 * Should be called by module init
 *
 * Public: No
 */
params ["_logic", "", "_activated"];
if (!_activated || !hasInterface) exitWith {
    TRACE_3("leaving TP actions early",_logic,_activated,hasInterface);
};

if (isNull _logic) exitWith {
    WARNING_1("Attempted to initialize object teleport module at %1",diag_time);
};

private _player = _logic getVariable [QUOTE(player), false];
private _group = _logic getVariable [QUOTE(group), false];
private _vehicle = _logic getVariable [QUOTE(vehicle), false];
if !(_player || _group || _vehicle) exitWith {
    WARNING_1("[%1] Attempte to initialize safe start teleport module, nothing was enabled",_logic);
};

if (GVAR(mapTPActionInit)) exitWith {
    ERROR_MSG_1("[%1] Attempt to initialize group teleport, only one module per mission",_logic);
};
GVAR(mapTPActionInit) = true;
GVAR(safeStartTPClickEH) = -1;

private _safeStart = _logic getVariable [QUOTE(safeStart), true];
private _useTPZones = _logic getVariable [QUOTE(useZones), true];
private _tpZonesText = _logic getVariable [QUOTE(tpZones), "[]"];

GVAR(ssTPZones) = if (_useTPZones) then {
    parseSimpleArray _tpZonesText;
} else {
    []
};

TRACE_7("mapClicKTP",_logic,_player,_group,_vehicle,_safeStart,_useTPZones,_tpZonesText);
private _baseAction = QGVAR(safeStart);
private _action =  if (_safeStart) then {
    [
        _baseAction,
        "Safe Start Actions",
        "\a3\ui_f\data\map\markers\military\flag_ca.paa",
        {},
        {EGVAR(safeStart,safeStartEnabled)}
    ] call ACEFUNC(interact_menu,createAction);
} else {
    _baseAction = QGVAR(tpActions);
    [
        _baseAction,
        "Teleport Actions",
        "\a3\ui_f\data\map\markers\military\flag_ca.paa",
        {},
        {true}
    ] call ACEFUNC(interact_menu,createAction);
};
[
    "CAManBase",
    1,
    ["ACE_SelfActions"],
    _action,
    true
] call ACEFUNC(interact_menu,addActionToClass);

//IGNORE_PRIVATE_WARNING["_player"];
if (_player) then {
    _action = [
        QUOTE(safeStartTPPlayer),
        "Teleport Player",
        "\a3\ui_f\data\gui\rsc\rscdisplaymain\menu_singleplayer_ca.paa", {
            if (!isNull objectParent ace_player) exitWith {};
            removeMissionEventHandler ["MapSingleClick", GVAR(safeStartTPClickEH)];
            openMap [true, false];
            [QGVAR(MapTeleportUnit)] call BIS_fnc_showNotification;
            {_x setMarkerAlphaLocal 1} forEach GVAR(ssTPZones);
            _player setVariable [QGVAR(mapClickWindow), CBA_missionTime + SAFESTART_TELEPORT_TIMER];
            GVAR(safeStartTPClickEH) = addMissionEventHandler ["MapSingleClick", {
                call FUNC(tpUnitHandle);
            }];
        },
        {isNull objectParent _player
        && {private _inZone = [false, true] select (GVAR(ssTPZones) isEqualTo []);
            private _pos = getPosASL _player;
            { _inZone = _inZone || (_pos inArea _x)} forEach GVAR(ssTPZones);
            _inZone}}
    ] call ACEFUNC(interact_menu,createAction);
    [
        "CAManBase",
        1,
        ["ACE_SelfActions", _baseAction],
        _action,
        true
    ] call ACEFUNC(interact_menu,addActionToClass);
};

if (_group) then {
    _action = [
        QUOTE(safeStartTPGroup),
        "Teleport Group",
        "\a3\3den\data\displays\display3den\panelright\modegroups_ca.paa", {
            if (leader _player != _player || !isNull objectParent _player) exitWith {};
            removeMissionEventHandler ["MapSingleClick", GVAR(safeStartTPClickEH)];
            openMap [true, false];
            [QGVAR(MapTeleportGroup)] call BIS_fnc_showNotification;
            {_x setMarkerAlphaLocal 1} forEach GVAR(ssTPZones);
            (group _player) setVariable [QGVAR(mapClickWindow), CBA_missionTime + SAFESTART_TELEPORT_TIMER];
            GVAR(safeStartTPClickEH) = addMissionEventHandler ["MapSingleClick", {
                call FUNC(tpGroupHandle);
            }];
        },
        {leader _player == _player
        && isNull objectParent _player
        && {private _inZone = [false, true] select (GVAR(ssTPZones) isEqualTo []);
            private _pos = getPosASL _player;
            { _inZone = _inZone || (_pos inArea _x)} forEach GVAR(ssTPZones);
            _inZone}},
        {},
        [],
        [0, 0, 0],
        2,
        [false, false, false, false, false], {
            params ["", "_player", "", "_actionData"];
            private _name = groupId group _player;
            private _idx = _name find " ";
            if (_idx < 0) exitWith {};
            _name = _name select [_idx + 1];
            _actionData set [1, "Teleport " + _name];
    }] call ACEFUNC(interact_menu,createAction);
    [
        "CAManBase",
        1,
        ["ACE_SelfActions", _baseAction],
        _action,
        true
    ] call ACEFUNC(interact_menu,addActionToClass);
};

if (_vehicle) then {
    _action = [
        QUOTE(safeStartTPVic),
        "Teleport Vehicle",
        "\a3\ui_f\data\map\vehicleicons\iconcar_ca.paa", {
            if (isNull objectParent _player) exitWith {};
            removeMissionEventHandler ["MapSingleClick", GVAR(safeStartTPClickEH)];
            openMap [true, false];
            [QGVAR(MapTeleportVehicle)] call BIS_fnc_showNotification;
            {_x setMarkerAlphaLocal 1} forEach GVAR(ssTPZones);
            (vehicle _player) setVariable [QGVAR(mapClickWindow), CBA_missionTime + SAFESTART_TELEPORT_TIMER];
            GVAR(safeStartTPClickEH) = addMissionEventHandler ["MapSingleClick", {
                call FUNC(tpVehicleHandle);
            }];
        },
        {leader _player == _player
        && !isNull objectParent _player
        && {private _inZone = [false, true] select (GVAR(ssTPZones) isEqualTo []);
                private _pos = getPosASL _player;
                { _inZone = _inZone || (_pos inArea _x)} forEach GVAR(ssTPZones);
                _inZone}}
    ] call ACEFUNC(interact_menu,createAction);
    [
        "CAManBase",
        1,
        ["ACE_SelfActions", _baseAction],
        _action,
        true
    ] call ACEFUNC(interact_menu,addActionToClass);
};
