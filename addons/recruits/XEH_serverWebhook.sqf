#define DEBUG_MODE_FULL
#include "script_component.hpp"
/*
 * Author: PabstMirror
 * Trackers recruits at session (will only run on server and extension only exists on dedi)
 *
 * Arguments:
 * None
 *
 * Returns: Nothing
 *
 * Public: No
 */

private _version = "potato_webhook" callExtension "version";
TRACE_1("serverWebhook",_version);
if (isNil "_version" || {_version == ""}) exitWith {};

GVAR(recruitsSeen) = [];

[{time > 1}, {
    private _recruits = allUnits select {(alive _x) && {isPlayer _x} && {[_x] call FUNC(isNotMember)}};
    GVAR(recruitsSeen) append (_recruits apply {name _x});
    TRACE_1("At mission start",count GVAR(recruitsSeen));
}] call CBA_fnc_waitUntilAndExecute;

[{gameLive}, {
    private _recruits = allUnits select {(alive _x) && {isPlayer _x} && {[_x] call FUNC(isNotMember)}};
    GVAR(recruitsSeen) append (_recruits apply {name _x});
    GVAR(recruitsSeen) = GVAR(recruitsSeen) arrayIntersect GVAR(recruitsSeen);
    TRACE_1("At game start",count GVAR(recruitsSeen));

    private _missionName = getText (missionConfigFile >> "MissionSQM" >> "Mission" >> "Intel" >> "briefingName");
    private _authorName = getMissionConfigValue ["author", "???"];
    private _worldName = getText (configFile >> "CfgWorlds" >> worldName >> "description");
    private _playerCount = {isPlayer _x} count allUnits;

    // need the endl (\n not working)
    private _message = format ["[**%1** by **%2** on %3] - **%4** Players At Start%5 - Recruits/Publics Present: %6", _missionName, _authorName, _worldName, _playerCount, endl, GVAR(recruitsSeen)];
    INFO_1("Recruit Status: %1",_message);
    if (_playerCount < 15) exitWith { TRACE_1("skipping test/training",_playerCount); };
    private _ret = "potato_webhook" callExtension (_message select [0, 1900]);
    TRACE_1("",_ret);
}] call CBA_fnc_waitUntilAndExecute;

addMissionEventHandler ["ExtensionCallback", {
	params ["_name", "_function", "_data"];
    if (_name != "POTATO_webhook") exitWith {};
    INFO_2("dll returned: %1-%2",_function,_data);
}];
