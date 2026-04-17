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

if (getMissionConfigValue [QEGVAR(missionTesting,SSTimeGiven), 60*15] < 60 * 5) then {
    [{time > (9 * 60)}, LINKFUNC(safeStartMessages)] call CBA_fnc_waitUntilAndExecute;
} else {
    GVAR(safeStartEH) = ["potato_safeStartOff", LINKFUNC(safeStartMessages)] call CBA_fnc_addEventHandler;
};


addMissionEventHandler ["ExtensionCallback", {
    params ["_name", "_component", "_data"];
    if ((toLower _name) != "potato_extension_log") exitWith {};
    (parseSimpleArray _data) params ["_level", "_message"];
    INFO_3("ExtensionCallback %1-%2-%3",_component,_level,_message);
}];

// Init connection to bot by calling init on expection
private _return = "potato_extension" callExtension ["init:socket_init", []];
TRACE_1("socket_init",_return);
