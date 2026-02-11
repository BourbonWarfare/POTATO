#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

#include "initSettings.inc.sqf"

if (GVAR(enable)) then {
    ["CBA_settingsInitialized", {
        [QGVAR(quereyArty), {call FUNC(quereyArtilleryHandler)}] call CBA_fnc_addEventHandler;
        [QGVAR(issueArty), {call FUNC(localArtilleryHandler)}] call CBA_fnc_addEventHandler;
        if (isServer) then {
            [QGVAR(missionComplete), {
                params [["_missionID", "", [""]],["_cancelMission", false, [false]]];
                if (isNil QGVAR(artilleryMissionCache)) then {
                    GVAR(artilleryMissionCache) = createHashMap;
                };
                (GVAR(artilleryMissionCache) getOrDefault [_missionID, []]) params [
                    "", "", "", "", "", "", "", "", "", "", "", ["_parentMission", "", [""]]
                ];
                // Free guns if cancelled
                if (_cancelMission) exitWith {
                     (GVAR(artilleryMissionCache) getOrDefault [_parentMission, []]) params [
                        "", ["_viableGuns", [], [[]]]
                    ];
                    [QGVAR(issueArty), [
                        _parentMission,
                        _viableGuns,
                        ARTILLERY_MISSION_STATUS_FREE
                    ], _viableGuns] call CBA_fnc_targetEvent;
                };
                if (_parentMission != "") then {
                    [_parentMission] call FUNC(beginMission);
                };
            }] call CBA_fnc_addEventHandler;
            [QGVAR(addMission), {call FUNC(addMission)}] call CBA_fnc_addEventHandler;
            [QGVAR(addPossiblePieces), {
                params ["_missionID", "_newPieces"];
                if (isNil QGVAR(artilleryMissionCache)) then {
                    GVAR(artilleryMissionCache) = createHashMap;
                };
                private _baseArray = GVAR(artilleryMissionCache) getOrDefault [_missionID, [2, [], ""]];
                if (_baseArray#2#1 == "") exitWith {};
                (_baseArray#1) append _newPieces;
            }] call CBA_fnc_addEventHandler;
        };
    }] call CBA_fnc_addEventHandler;
};

ADDON = true;
