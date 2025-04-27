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
GVAR(techOnlyTesting) = false; // can set to true to force bot to run (but not post in public)

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
    private _playerAllCount = {!(_x isKindOf "HeadlessClient_F")} count allPlayers; // allPlayers isn't great but should work on server

    if ((!GVAR(techOnlyTesting)) && {(_playerCount < 15) || {"seeding" in (toLower _missionName)}}) exitWith { 
        TRACE_2("skipping test/training",_playerCount,_missionName);
    };
 
    private _recruit_list = if (count GVAR(recruitsSeen) > 0) then {
        GVAR(recruitsSeen) joinString endl;
    } else {
        "None";
    };

    // Message in staff tech showing player count, mission and recruit info.
    private _message = format ["**%1 [%2]** Players At Start%3 **Recruits** Present: %3%4", _playerCount, _playerAllCount, endl, _recruit_list];
    private _title = format ["**%1** by **%2** on %3", _missionName, _authorName, _worldName];
    INFO_1("Recruit Status: %1",_message);
    ["embed", "tech", _message, _title] call FUNC(botMessage);

    // Message in arma general showing player count and mission
    private _message = format ["**%1 [%2]** Players At Start%3", _playerCount, _playerAllCount, endl];
    private _title = format ["**%1** by **%2** on %3", _missionName, _authorName, _worldName];
    if (!GVAR(techOnlyTesting)) then { ["embed", "arma", _message, _title] call FUNC(botMessage); };


    GVAR(orbat) = call FUNC(getOrbat); // simple leadership orbat, for now not handling jips/dc/respawn
    addMissionEventHandler ["Ended", { 
        // Dump orbat at mission conclusion
        params ["_endType"];
        private _missionType = getMissionConfigValue [QEGVAR(missionTesting,missionType), 0];
        if (_missionType == 0) exitWith { INFO_1("ignoring mission type %1",_missionType) };
        private _missionTypeStr = ["Other", "COOP", "TvT"] select _missionType;
        ["embed", "arma", GVAR(orbat), format ["Mission End: %1", _missionTypeStr]] call FUNC(botMessage);
    }];
}] call CBA_fnc_waitUntilAndExecute;


addMissionEventHandler ["ExtensionCallback", {
    params ["_name", "_component", "_data"];
    if ((toLower _name) != "potato_extension_log") exitWith {};
    (parseSimpleArray _data) params ["_level", "_message"];
    INFO_3("ExtensionCallback %1-%2-%3",_component,_level,_message);
}];

// Init connection to bot by calling init on expection
private _return = "potato_extension" callExtension ["init:socket_init", []];
TRACE_1("socket_init",_return);
