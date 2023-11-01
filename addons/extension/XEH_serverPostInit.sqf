#include "script_component.hpp"

/*
 * Author: BadWolf
 *
 * Arguments:
 * None
 *
 * Returns: Nothing
 *
 * Public: No
 */

if (hasInterface) exitWith {}; // ignore for mission makers

// Adaptation of Pabst's script for the old webhook
GVAR(recruitsSeen) = [];

[{time > 1}, {
    private _recruits = allUnits select {(alive _x) && {isPlayer _x} && {[_x] call EFUNC(recruits,isNotMember)}};
    GVAR(recruitsSeen) append (_recruits apply {name _x});
    TRACE_1("At mission start",count GVAR(recruitsSeen));
}] call CBA_fnc_waitUntilAndExecute;

[{time > (9 * 60)}, {
    private _recruits = allUnits select {(alive _x) && {isPlayer _x} && {[_x] call EFUNC(recruits,isNotMember)}};
    GVAR(recruitsSeen) append (_recruits apply {name _x});
    GVAR(recruitsSeen) = GVAR(recruitsSeen) arrayIntersect GVAR(recruitsSeen);
    TRACE_1("At 9 min",count GVAR(recruitsSeen));

    private _missionName = getMissionConfigValue ["onLoadName", getMissionConfigValue ["briefingName", "???"]];
    private _authorName = getMissionConfigValue ["author", "???"];
    private _worldName = getText (configFile >> "CfgWorlds" >> worldName >> "description");
    private _playerCount = {isPlayer _x} count allUnits;

    // need the endl (\n not working)
    private _message = format ["**%1** Players At Start%2 - Recruits Present: %3", _playerCount, endl, GVAR(recruitsSeen)];
    private _title = format ["**%1** by **%2** on %3", _missionName, _authorName, _worldName];
    INFO_1("Recruit Status: %1",_message);
    if (_playerCount < 15) exitWith { TRACE_1("skipping test/training",_playerCount); };
    ["staff", "embed", "staff", _message, _title] call FUNC(botMessage);
}] call CBA_fnc_waitUntilAndExecute;

// Anouncement for people waiting for COOP to start.
addMissionEventHandler ["MPEnded", {
    private _missionType = getMissionConfigValue QEGVAR(missionTesting, missionType);
    private _playerCount = {isPlayer _x} count allUnits;

    if (_missionType == 2 && _playerCount < 15) then {
        [
            "potato",
            "embed",
            "arma",
            "TVT is over.\n Slotting for COOP will be starting up immediately",
            "TVT Finished"
        ] call EFUNC(extension, botMessage);
    };
}];

addMissionEventHandler ["ExtensionCallback", {
    params ["_name", "_component", "_data"];
    if ((tolower _name) != "potato_extension_log") exitWith {};
    (parseSimpleArray _data) params ["_level", "_message"];
    TRACE_3("ExtensionCallback", _component, _level, _message);
}];
