#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function handles adding missions on the server. It parses some basic
 * information from the mission hashmap and then creates a mission entry.
 * The function may delay it's own call by the mission delay. Once an entry
 * is created a call is sent out for every client to report any guns that
 * could participate in the mission for the main handler to take care of.
 * Sometimes mission require multiple states, in this case a secondary mission
 * is created with relevant follow-on missions queued to be called on
 * completion. Finally this function will call the begin mission function after
 * a delay. The current delay is about five seconds, allowing for enough time
 * for all clients to respond.
 *
 * Arguments:
 * _missionID - A unique string for the mission, these are not purged, STRING, default ""
 * _clientID - Numberic client ID of the machine requesting the mission,
 *             values below 1 supress status messages, NUMBER, default 0
 * _missionHashMap - A mission hashmap with a few different settings for the
 *                   the mission, requires at least "position" and "roundType"
 *                   HASHMAP, default createHashMap
 *
 * Example:
 * ["lambda123", clientOwner lambda, _missionHash] call potato_artillery_fnc_addMission;
 *
 * Public: No
 */
params [
    ["_missionID", "", [""]],
    ["_clientID", 0, [0]],
    ["_missionHashMap", createHashMap,  [createHashMap]]
];
TRACE_3("addingMission",_missionID,_clientID,_missionHashMap);
// extract params and check overall system
if (_missionHashMap isEqualTo createHashMap) exitWith {
    if (_clientID > 1 || !isMultiplayer) then {
        ["Invalid artillery mission recieved"] remoteExec ["systemChat", _clientID];
    };
};

private _positionATL = _missionHashMap getOrDefault ["position", [0, 0, 0]];
if (_positionATL isEqualTo [0, 0, 0]) exitWith {
    if (_clientID > 1 || !isMultiplayer) then {
        ["Invalid artillery mission position"] remoteExec ["systemChat", _clientID];
    };
};

private _magazine = _missionHashMap getOrDefault ["roundType", [-1, ""]];
if (_magazine#1 == "")  exitWith {
    if (_clientID > 1 || !isMultiplayer) then {
        ["Invalid artillery mission magazine type"] remoteExec ["systemChat", _clientID];
    };
};

private _missionDelay = _missionHashMap getOrDefault ["missionDelay", ARTILLERY_MISSION_MIN_DELAY];
if (_missionDelay > ARTILLERY_MISSION_MIN_DELAY) exitWith {
    TRACE_1("Delayed Mission",_missionDelay);
    _missionHashMap set ["missionDelay", ARTILLERY_MISSION_MIN_DELAY];
    [{call FUNC(addMission)}, _this,
    (_missionDelay - ARTILLERY_MISSION_MIN_DELAY) max 0] call CBA_fnc_waitAndExecute;
};


if (_missionID == "") then {
    if (isNil QGVAR(artilleryMissionItr)) then {GVAR(artilleryMissionItr) = 0;};
    _missionID = "unknown:" + str GVAR(artilleryMissionItr);
    GVAR(artilleryMissionItr) = GVAR(artilleryMissionItr) + 1;
    TRACE_2("NewID",GVAR(artilleryMissionItr),_missionID);
};

if (isNil QGVAR(artilleryMissionCache)) then {
    GVAR(artilleryMissionCache) = createHashMap;
};
/******** Artillery mission param entries
* 0 - clientID of the caller
* 1 - Possible guns / final guns
* 2 - magazine type
* 3 - Position (ATL) of the missions
* 4 - Gun count
* 5 - Mission type
* 6 - dispersion / length
* 7 - rotation
* 8 - attempt to avoid players
* 9 - mission length (rounds per gun)
* 10 - Mission length (time)
* 11 - parent mission (call mission on complete)
****************************************/
private _gunCount = _missionHashMap getOrDefault ["gunCount", 2];
if (_gunCount == 7) then {_gunCount = 20};
private _missionType = _missionHashMap getOrDefault ["missionType", ARTILLERY_MISSIONTYPE_LAZY];
private _missionInfo = [
    _clientID, [], _magazine, _positionATL,
    _gunCount,
    _missionType,
    _missionHashMap getOrDefault ["dispersion", 100],
    _missionHashMap getOrDefault ["rotation", 0],
    _missionHashMap getOrDefault ["avoidPlayers", true],
    _missionHashMap getOrDefault ["missionLength", 4],
    _missionHashMap getOrDefault ["missionTimeLength", 180], // often ignored
    ""
];
GVAR(artilleryMissionCache) set [_missionID, _missionInfo];

// create a child mission that runs first and switch to it as primary
switch (_missionType) do {
    case ARTILLERY_MISSIONTYPE_SLOW_WITH_WALK: {
        private _parentMission = _missionID;
        _missionID = _missionID + "_lazy";
        _missionType = ARTILLERY_MISSIONTYPE_LAZY_WALK;
        _missionInfo set [5, ARTILLERY_MISSIONTYPE_SLOW_BARRAGE];
        _missionInfo = [
            _clientID, _missionInfo#1, _magazine, _positionATL,
            _missionInfo#4, _missionType, _missionInfo#6, _missionInfo#7,
            true, 1, _missionInfo#10, _parentMission
        ];
        GVAR(artilleryMissionCache) set [_missionID, _missionInfo];
    };
    case ARTILLERY_MISSIONTYPE_LINEAR_WITH_WALK: {
        private _parentMission = _missionID;
        _missionID = _missionID + "_lazy";
        _missionType = ARTILLERY_MISSIONTYPE_LAZY_WALK;
        _missionInfo set [5, ARTILLERY_MISSIONTYPE_LINEAR_BARRAGE];
        _missionInfo = [
            _clientID, _missionInfo#1, _magazine, _positionATL,
            _missionInfo#4, _missionType, _missionInfo#6, _missionInfo#7,
            true, 1, _missionInfo#10, _parentMission
        ];
        GVAR(artilleryMissionCache) set [_missionID, _missionInfo];
    };
    case ARTILLERY_MISSIONTYPE_LAZY: {
        private _parentMission = _missionID;
        _missionID = _missionID + "_lazy";
        _missionType = ARTILLERY_MISSIONTYPE_LAZY_WALK;
        _missionInfo set [5, ARTILLERY_MISSIONTYPE_LAZY_BARRAGE];
        _missionInfo = [
            _clientID, _missionInfo#1, _magazine, _positionATL,
            _missionInfo#4, _missionType, _missionInfo#6, _missionInfo#7,
            true, 1, _missionInfo#10, _parentMission
        ];
        GVAR(artilleryMissionCache) set [_missionID, _missionInfo];
    };
    case ARTILLERY_MISSIONTYPE_BRACKET: {
        private _parentMission = _missionID;
        _missionID = _missionID + "_bracket";
        _missionType = ARTILLERY_MISSIONTYPE_BRACKET_SHOTS;
        _missionInfo set [5, ARTILLERY_MISSIONTYPE_BRACKET_BARRAGE];
        _missionInfo = [
            _clientID, _missionInfo#1, _magazine, _positionATL,
            _missionInfo#4, _missionType, _missionInfo#6, _missionInfo#7,
            true, 1, _missionInfo#10, _parentMission
        ];
        GVAR(artilleryMissionCache) set [_missionID, _missionInfo];
    };
    default {};
};

// calculate target zone bounds []
private _targetBounds = [_positionATL];
switch (_missionType) do { // Add extra points
    case ARTILLERY_MISSIONTYPE_LAZY: {
        private _dir = 180 + _missionInfo#7;
        {
            private _targetPos =  (_positionATL getPos [_x, _dir]);
            _targetPos = [_targetPos, 100, _dir, call CBA_fnc_players] call FUNC(findSafeMortarPos);
            _targetBounds pushBack _targetPos;
        } forEach ARTILLERY_POSITIONS_LAZYADJUST;
    };
    case ARTILLERY_MISSIONTYPE_BRACKET: {
        private _dir = 180 + _missionInfo#7;
        {
            _targetBounds pushBack (_positionATL getPos [_x, _dir]);
        } forEach ARTILLERY_POSITIONS_BRACKET(0);
    };
    case ARTILLERY_MISSIONTYPE_LINEAR: {
        private _dir = 180 + _missionInfo#7;
        {
            _targetBounds pushBack (_positionATL getPos [_x, _dir]);
        } forEach [-(_missionInfo#6), _missionInfo#6];
    };
    default {};
};

// broadcast gun requests
[QGVAR(quereyArty),
[_missionID, _magazine#1, _targetBounds, _missionInfo#4]] call CBA_fnc_globalEvent;

// call addNewMission in 10 seconds (or less?)
[{call FUNC(beginMission)}, [_missionID], ARTILLERY_MISSION_MIN_DELAY] call CBA_fnc_waitAndExecute;
