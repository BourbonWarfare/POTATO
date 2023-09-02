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

GVAR(recruitsSeen) = [];

[{time > 1}, {
    private _recruits = allUnits select {(alive _x) && {isPlayer _x} && {[_x] call FUNC(isNotMember)}};
    GVAR(recruitsSeen) append (_recruits apply {name _x});
    TRACE_1("At mission start",count GVAR(recruitsSeen));
}] call CBA_fnc_waitUntilAndExecute;

[{time > (9 * 60)}, {
    private _recruits = allUnits select {(alive _x) && {isPlayer _x} && {[_x] call FUNC(isNotMember)}};
    GVAR(recruitsSeen) append (_recruits apply {name _x});
    GVAR(recruitsSeen) = GVAR(recruitsSeen) arrayIntersect GVAR(recruitsSeen);
    TRACE_1("At 9 min",count GVAR(recruitsSeen));

    private _missionName = getMissionConfigValue ["onLoadName", getMissionConfigValue ["briefingName", "???"]];
    private _authorName = getMissionConfigValue ["author", "???"];
    private _worldName = getText (configFile >> "CfgWorlds" >> worldName >> "description");
    private _playerCount = {isPlayer _x} count allUnits;

    // need the endl (\n not working)
    private _message = format ["[**%1** by **%2** on %3] - **%4** Players At Start%5 - Recruits Present: %6", _missionName, _authorName, _worldName, _playerCount, endl, GVAR(recruitsSeen)];
    INFO_1("Recruit Status: %1",_message);
    if (_playerCount < 15) exitWith { TRACE_1("skipping test/training",_playerCount); };
    private _ret = "potato_webhook" callExtension (_message select [0, 1900]);
    TRACE_1("",_ret);
}] call CBA_fnc_waitUntilAndExecute;
