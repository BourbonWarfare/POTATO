#include "..\script_component.hpp"

GVAR(stats_all) = [];
if (!hasInterface) exitWith {};

[QEGVAR(adminMenu,endMission), {
    if (isNil "acex_killTracker_outputText") exitWith {};
    private _killFeed = acex_killTracker_outputText;

    // Add players we wounded (from potato_specate)
    private _wounded = [];
    {
        private _unit = _x;
        private _feed = _unit getVariable [QACEGVAR(killtracker,output), ""];
        private _wounds = _feed regexFind [" from ([^<]*)"];
        {
            private _cause = _x select 1 select 0;
            if (_cause == profileName) exitWith {
                _wounded pushBackUnique ([_unit] call EFUNC(spectate,getName));
            };
        } forEach _wounds;
    } forEach allPlayers;
    if (_wounded isNotEqualTo []) then {
        _killFeed = format ["Caused wounds on players:<br/> %1<br/>%2", _wounded joinString ", ", _killFeed];
    };

    // private _values = [];
    private _stats = GVAR(stats_all) apply {
        _x params ["_stat", "_label", ["_limit", 1]];
        private _val = if (_stat isEqualType "") then { missionNamespace getVariable [_stat, -1] } else {call _stat};
        // _values pushBack _val;
        INFO_2("stat %1: %2",_label,_val);
        if (_val < _limit) then {
            ""
        } else {
            _val = if (_val == round _val) then { _val } else { _val toFixed 2 }; // keep whole numbers
            format ["%1: %2", _label, _val]
        };
    } select {_x != ""} joinString "<br/>";
    if (_stats != "") then {
        _killFeed = format ["%1<br/>%2", _stats, _killFeed];
    };
    // [QGVAR(compareStats), [profileName, _values]] call CBA_fnc_serverEvent;

    GVAR(stats_killFeedOverride) = _killFeed;
    addMissionEventHandler ["EachFrame", { // override kill feed with this output (even if player dies in last 0.5 second)
        acex_killTracker_outputText = GVAR(stats_killFeedOverride);
    }];
}] call CBA_fnc_addEventHandler;



// addMissionEventHandler ["EachFrame", {
//    private _stats = GVAR(stats_all) apply {
//         _x params ["_stat", "_label", ["_limit", 1]];
//         private _val = if (_stat isEqualType "") then { missionNamespace getVariable [_stat, -1] } else {call _stat};
//         if (_val < _limit) then {
//             format ["%1: ---", _label]
//         } else {
//             _val = if (_val == round _val) then { _val } else { _val toFixed 2 }; // keep whole numbers
//             format ["%1: %2", _label, _val]
//         };
//     } joinString "\n";
//     hintSilent _stats;
// }];


GVAR(stats_distanceWalked) = 0;
GVAR(stats_distanceVehicle) = 0;
GVAR(stats_all) pushBack [QGVAR(stats_distanceWalked), "Distance Walked (m)"];
GVAR(stats_all) pushBack [QGVAR(stats_distanceVehicle), "Distance Vehicle (m)"];
GVAR(stats_lastPos) = [];
GVAR(stats_lastVic) = objNull;
DFUNC(stats_distanceFunc) = {
    private _unit = ace_player;
    private _vehicle = vehicle _unit;
    if (!alive _unit) then {
        GVAR(stats_lastPos) = [];
        GVAR(stats_lastVic) = objNull;
    } else {
        private _pos = getPosASL _vehicle;
        if (_vehicle != GVAR(stats_lastVic)) exitWith {
            GVAR(stats_lastPos) = [];
            GVAR(stats_lastVic) = _vehicle;
        };
        if (GVAR(stats_lastPos) isNotEqualTo []) then {
            private _distance = _pos vectorDistance GVAR(stats_lastPos);
            if (_unit isEqualTo _vehicle) then {
                if (_distance > 30) exitWith {};
                GVAR(stats_distanceWalked) = GVAR(stats_distanceWalked) + _distance;
            } else {
                if (_distance > 400) exitWith {};
                GVAR(stats_distanceVehicle) = GVAR(stats_distanceVehicle) + _distance;
            };
        };
        GVAR(stats_lastPos) = _pos;
    };
    [DFUNC(stats_distanceFunc), [], 3] call CBA_fnc_waitAndExecute;
};
call FUNC(stats_distanceFunc);


GVAR(stats_throwablePickedUp) = 0;
GVAR(stats_all) pushBack [QGVAR(stats_throwablePickedUp), "Grenades Re-thrown"];
["ace_throwablePickedUp", {
    params ["_throwable", "_unit", "_attachedTo"];
    if ((_unit != ace_player) || {isNull _throwable}) exitWith {};
    private _hit = getNumber ((configOf _throwable) >> "hit");
    if (_hit <= 1) exitWith {};
    GVAR(stats_throwablePickedUp) = GVAR(stats_throwablePickedUp) + 1;
}] call CBA_fnc_addEventHandler;


GVAR(stats_cargoLoading) = 0;
GVAR(stats_all) pushBack [QGVAR(stats_cargoLoading), "Cargo Loading"];
{ [_x, { GVAR(stats_cargoLoading) = GVAR(stats_cargoLoading) + 1; }] call CBA_fnc_addEventHandler; } forEach ["ace_loadCargo", "ace_unloadCargo"];


GVAR(stats_acre_radioStart) = 0;
GVAR(stats_all) pushBack [QGVAR(stats_acre_radioStart), "ACRE XMIT"];
["acre_startedSpeaking", {
    params ["_unit", "_onRadio", "_radioId", "_speakingType"];
    if (_unit != ace_player) exitWith {};
    if (_onRadio) then {
        GVAR(stats_acre_radioStart) = GVAR(stats_acre_radioStart) + 1;
    };
}] call CBA_fnc_addEventHandler;


GVAR(stats_firedPlayer) = 0;
GVAR(stats_firedVehicle) = 0;
GVAR(stats_all) pushBack [QGVAR(stats_firedPlayer), "Shots Fired"];
GVAR(stats_all) pushBack [QGVAR(stats_firedVehicle), "Shots Fired (Vehicle)"];
["ace_firedPlayer", {
    GVAR(stats_firedPlayer) = GVAR(stats_firedPlayer) + 1;
}] call CBA_fnc_addEventHandler;
["ace_firedPlayerVehicle", {
    GVAR(stats_firedVehicle) = GVAR(stats_firedVehicle) + 1;
}] call CBA_fnc_addEventHandler;


GVAR(stats_medical_wounded) = 0;
GVAR(stats_all) pushBack [QGVAR(stats_medical_wounded), "Wounded"];
["ace_medical_injured", {
    params ["_unit", "_painLevel"];
    if (_unit != ace_player) exitWith {};
    GVAR(stats_medical_wounded) = GVAR(stats_medical_wounded) + 1;
}] call CBA_fnc_addEventHandler;


GVAR(stats_medical_CriticalInjury) = 0;
GVAR(stats_all) pushBack [QGVAR(stats_medical_CriticalInjury), "Critical Injuries"];
["ace_medical_CriticalInjury", {
    params ["_unit", "_painLevel"];
    if (_unit != ace_player) exitWith {};
    GVAR(stats_medical_CriticalInjury) = GVAR(stats_medical_CriticalInjury) + 1;
}] call CBA_fnc_addEventHandler;    


GVAR(stats_medical_Fracture) = 0;
GVAR(stats_all) pushBack [QGVAR(stats_medical_Fracture), "Fractures"];
["ace_medical_Fracture", {
    params ["_unit", "_painLevel"];
    if (_unit != ace_player) exitWith {};
    GVAR(stats_medical_Fracture) = GVAR(stats_medical_Fracture) + 1;
}] call CBA_fnc_addEventHandler;


GVAR(stats_medical_bandaged) = 0;
GVAR(stats_all) pushBack [QGVAR(stats_medical_bandaged), "Player Bandaged"];
["ace_medical_bandaged", {
    params ["_patient"];
    if (_patient != ace_player) exitWith {};
    GVAR(stats_medical_bandaged) = GVAR(stats_medical_bandaged) + 1;
}] call CBA_fnc_addEventHandler;


GVAR(stats_medical_treatmentActions) = 0;
GVAR(stats_medical_treatedUnique) = createHashMap;
GVAR(stats_all) pushBack [QGVAR(stats_medical_treatmentActions), "Medical Actions"];
GVAR(stats_all) pushBack [{count GVAR(stats_medical_treatedUnique)}, "Unique Patients"];
["ace_treatmentSucceded", {
    params ["_medic", "_patient"];
    if (_medic != ace_player) exitWith {};
    GVAR(stats_medical_treatmentActions) = GVAR(stats_medical_treatmentActions) + 1;
    if (_patient == ace_player) exitWith {};
    GVAR(stats_medical_treatedUnique) set [name _patient, true];
}] call CBA_fnc_addEventHandler;


GVAR(stats_medical_ivTaken) = 0;
GVAR(stats_all) pushBack [QGVAR(stats_medical_ivTaken), "IV Taken (Liters)", 0.001];
["ace_medical_consumedIVs", {
    params ["_unit", "_consumedIVs"];
    if (_unit != ace_player) exitWith {};
    {
        _x params ["", "", "_bagChange"];
        GVAR(stats_medical_ivTaken) = GVAR(stats_medical_ivTaken) + _bagChange;
    } forEach _consumedIVs;
}] call CBA_fnc_addEventHandler;


GVAR(stats_fortify_objectPlaced) = 0;
GVAR(stats_all) pushBack [QGVAR(stats_fortify_objectPlaced), "Fortify Objects Placed"];
["acex_fortify_objectPlaced", { // acex is intetional
    params ["_unit"];
    if (_unit != ace_player) exitWith {};
    GVAR(stats_fortify_objectPlaced) = GVAR(stats_fortify_objectPlaced) + 1;
}] call CBA_fnc_addEventHandler;
