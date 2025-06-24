#include "script_component.hpp"

if (!hasInterface) exitWith {};

["ace_unconscious", {
    params ["_unit", "_uncon"];
    if (_unit != ACE_player) exitWith {};
    if (_uncon) then {
        steamGameRecordingEvent [QGVARMAIN(uncon), 0, ["Knocked unconcious", [CBA_missionTime, "M:SS"] call CBA_fnc_formatElapsedTime]];
    } else {
        steamGameRecordingEvent [QGVARMAIN(uncon), 0, ["Woke up", [CBA_missionTime, "M:SS"] call CBA_fnc_formatElapsedTime]];
    };
}] call CBA_fnc_addEventHandler;

[QEGVAR(respawn,localRespawn), {
    steamGameRecordingEvent [QGVARMAIN(reinforce), 0, [[CBA_missionTime, "M:SS"] call CBA_fnc_formatElapsedTime]];
}] call CBA_fnc_addEventHandler;

["ace_throwableThrown", {
    params ["_unit", "_activeThrowable"];
    if (_unit != ACE_player) exitWith {}; // this should always be false
    switch (true) do {
        case (_activeThrowable isKindOf "ACE_G_Handflare_White"): {steamGameRecordingEvent [QGVARMAIN(aceThrow), 0, ["Hand flare"]];};
        case (_activeThrowable isKindOf "SmokeShell"): {steamGameRecordingEvent [QGVARMAIN(aceThrow), 0, ["Smoke grenade"]];};
        case (_activeThrowable isKindOf "ACE_SatchelCharge_Remote_Ammo_Thrown"): {steamGameRecordingEvent [QGVARMAIN(aceThrow), 0, ["Explosive charge"]];};
        default {steamGameRecordingEvent [QGVARMAIN(aceThrow), 0, ["Hand grenade"]];};
    };
}] call CBA_fnc_addEventHandler;

if ([missionConfigFile >> "CfgLoadouts" >> "usePotato"] call CFUNC(getBool)) then {
    ["potato_safeStartOff", {
        steamGameRecordingEvent [QGVARMAIN(safeStart), 0, ["ending", [CBA_missionTime, "M:SS"] call CBA_fnc_formatElapsedTime]];
    }] call CBA_fnc_addEventHandler;
    addMissionEventHandler ["Ended", {
        params ["_endType"];
        steamGameRecordingEvent [QGVARMAIN(missionEnd), 0, [[CBA_missionTime] call CBA_fnc_formatElapsedTime]];
    }];
};