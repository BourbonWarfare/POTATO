#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function is run by a module on init. It takes the configured
 * radio parameters, adds relevant events and ACE actions, and configures
 * local variables for marker sharing.
 *
 * Arguments:
 * 0: The module being initialized
 * 2: Whether the module is active
 *
 * Examples:
 * Should be called by module init
 *
 * Public: No
 */
 TRACE_1("create diary entry from config",_this);
params ["_logic", "", "_activated"];
if (!_activated || !hasInterface) exitWith {
    TRACE_3("leaving markerInit early",_logic,_activated,hasInterface);
};

private _disableNetwork = _logic getVariable [QUOTE(disableNetwork), true];
private _enableShare = _logic getVariable [QUOTE(enableShare), true];
private _enableCopyFrom = _logic getVariable [QUOTE(enableCopyFrom), true];
private _enableCopyFromEnemy = _enableCopyFrom && (_logic getVariable [QUOTE(enableCopyFromEnemy), false]);
//private _enableCopyFromCorpse = _enableCopyFrom && (_logic getVariable [QUOTE(enableCopyFromCorpse), false]);
private _shareRadius = 15 min (_logic getVariable [QUOTE(shareRadius), 5]);

[QGVAR(requestMarkers), {
    [_this,  _thisArgs] call FUNC(sendMarks);
    ["Somone copied your map markers.", true, 5] call ACEFUNC(common,displayText);
}, _enableCopyFromEnemy] call CBA_fnc_addEventHandlerArgs;
[QGVAR(recieveMarkers), {call FUNC(recieveMarks)}] call CBA_fnc_addEventHandler;

if (_disableNetwork) then { // handle markers including spec reset of markers
    GVAR(disableNetwork) = true;
    [{!isNil QEGVAR(core,playerAuth)}, {
        private _auth = [] call CFUNC(isAuthorized);
        for "_i" from 0 to 4 do {
            if !(_i == 3 || (_auth && _i == 0)) then {
                _i enableChannel false;
            };
        };
        setCurrentChannel 3;
    }] call CBA_fnc_waitUntilAndExecute;
};

if (_enableShare) then {
    //IGNORE_PRIVATE_WARNING["_target", "_player","_actionParams"];
    private _action = [
        QGVAR(shareMarks),
        format ["Share Markers (%1m)", _shareRadius toFixed 0],
        "\a3\ui_f\data\GUI\Rsc\RscDisplayArsenal\map_ca.paa", {
        _actionParams params ["_shareRadius", "_shareAcrossSides"];
        private _players = (getPosATL _player) nearEntities ["CAManBase", _shareRadius];
        private _side = side _player;
        _players = _players select {
            isPlayer _x && {getNumber ((configOf _target) >> "isPlayableLogic") == 0}
            && {_shareAcrossSides || side _x == _side}
            && _x != _player};
        if (_players isNotEqualTo []) then {
            [format ["Sharing markers in a %1m radius.", _shareRadius], true, 5] call ACEFUNC(common,displayText);
            [_players, _shareAcrossSides] call FUNC(sendMarks);
        };
    }, {true}, {}, [_shareRadius, _enableCopyFromEnemy]] call ACEFUNC(interact_menu,createAction);
    ["CAManBase", 1, ["ACE_SelfActions", "ACE_Equipment"], _action, true] call ACEFUNC(interact_menu,addActionToClass);
};

if (_enableCopyFrom) then { // handle copy from enemy (alive)
    //IGNORE_PRIVATE_WARNING["_target", "_player","_actionParams"];
    private _action = [
        QGVAR(copyFromUnit), "Copy Map Markers",
        "\a3\ui_f\data\GUI\Rsc\RscDisplayArsenal\map_ca.paa", {
        [QGVAR(requestMarkers), [_player], _target] call CBA_fnc_targetEvent;
    }, {side _target == side _player || _actionParams},
    {}, _enableCopyFromEnemy] call ACEFUNC(interact_menu,createAction);
    ["CAManBase", 0, ["ACE_MainActions"], _action, true] call ACEFUNC(interact_menu,addActionToClass);
};
