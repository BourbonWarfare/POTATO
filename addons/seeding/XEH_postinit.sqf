#include "script_component.hpp"

setViewDistance 4000;

PGVAR(artillery,artilleryAmmoTypes) = [];
private _artyMags = PGVAR(artillery,artilleryAmmoTypes);
{
    private _mags = getArray (missionConfigFile >> "CfgLoadouts" >> _x >> "artilleryArray");
    if (_mags isEqualTo []) exitWith {};
    _mags = flatten (_mags apply {_x#1});
    _artyMags append _mags;
} forEach ["potato_e", "potato_i"];

if (isServer) then {
    [] call FUNC(autoEndSession);
    {
        if (local _x && typeOf _x == BW_TP_FLAG_TYPE) then {
            private _respawnIndex = [missionNamespace, _x] call BIS_fnc_addRespawnPosition;
            _x setVariable [QGVAR(respawnIndex), _respawnIndex, true];
        };
    } forEach allMissionObjects "all";

    0 spawn {{ // schedule marker creation to avoid a large lag spike
            private _mk = createMarker ["buildingMOUTMarkers" + str _forEachIndex, getPosATL _x];
            _mk setMarkerColorLocal "ColorGrey";
            _mk setMarkerBrushLocal "SolidFull";
            _mk setMarkerDirLocal (getDir _x);
            _mk setMarkerShapeLocal "Rectangle";
            private _bounds = 0 boundingBoxReal _x;
            _mk setMarkerSize [_bounds#0#0, _bounds#0#1];
            uiSleep 0.001;
        } forEach ((getMissionLayerEntities  "shootHouses")#0);
    };
    /*addMissionEventHandler ["ArtilleryShellFired", {
        params ["_vehicle", "", "", "_gunner"];
        if (side _gunner != west) exitWith {};
        if (isNil QGVAR(cBatHash)) then {
            GVAR(cBatHash) = createHashMap;
            [{call FUNC(counterBattery)}, 0, 30] call CBA_fnc_waitAndExecute;
        };
        private _pos = _vehicle getPos [random 50, random 360];
        private _notFound = true;
        {
            if (_pos inArea [_x, 100, 100, 0, true]) exitWith {
                (_y#0) pushBack _pos;
                _y set [1, CBA_missionTime];
                _notFound = false;
            };
        } forEach GVAR(cBatHash);
        if (_notFound) then {
            GVAR(cBatHash) set [_pos apply {200 * round (_x / 200)}, [[_pos], CBA_missionTime]];
        };
    }];*/
};

[{
    ACEGVAR(fortify,timeCostCoefficient) = 0;
    true
}] call ace_fortify_fnc_addDeployHandler;

[{ // medical testing
    {
        private _damageType = _y#3;
        private _delete = [];
        {
            _x params ["_damageType"];
            switch (_damageType) do {
                case "Abrasion";
                case "Contusion";
                case "ThermalBurn": {
                    _delete pushBack _forEachIndex;
                };
            };
        } forEach _damageType;
        if (_delete isNotEqualTo []) then {
            {
                _damageType deleteAt _x;
            } forEachReversed _delete;
            _damageType pushBack ["Laceration",[[20,10],[4,2],[2,1],[0.3,1],[0,0]],1,1,1,1,1];
        };
    } forEach ACEGVAR(medical_damage,damageTypeDetails);
    ACEGVAR(medical,const_stableVitalsBloodThreshold) = 3;
}, 0, 1] call CBA_fnc_waitAndExecute;

addMissionEventHandler ["EntityCreated", {
	params ["_object"];
    if !(local _object && {(_object isKindOf BW_TP_FLAG_TYPE)}) exitWith {};
    private _pos = getPosATL _object;
    // create a user moveable marker that should delete itself when the flag goes away
    private _mk = createMarkerLocal ["_USER_DEFINED flag_" + (getPlayerID player) + str time, _pos];
    _mk setMarkerColorLocal "colorBLUFOR";
    _mk setMarkerTextLocal "TP Flag";
    _mk setMarkerType "mil_triangle";
    _object setVariable [QGVAR(attachedMarker), _mk, true];
    // respawn position
    private _respawnIndex = [west, _object] call BIS_fnc_addRespawnPosition;
    _object setVariable [QGVAR(respawnIndex), _respawnIndex, true];
}];

if !(hasInterface) exitWith {
    setObjectViewDistance [6000, 200];
    setViewDistance 6000;
};

for "_i" from 0 to BW_MOUT_MAX_CHECK do {
    private _mark = BW_MOUT_BASE_STRING + (str _i);
    if (markerBrush _mark == "Border") then {continue};
    if ((getMarkerPos _mark) isEqualTo [0, 0, 0]) exitWith {};
    _mark setMarkerAlphaLocal 0;
};
for "_i" from 0 to BW_ZONE_MAX_CHECK do {
    private _mark = BW_ZONE_BASE_STRING + (str _i);
    if (markerBrush _mark == "Border") then {continue};
    if ((getMarkerPos _mark) isEqualTo [0, 0, 0]) exitWith {};
    _mark setMarkerAlphaLocal 0;
};

[{
    ["Info_Picture", [
        "Mission Info",
        text "<t color='#FFC000'>ACE self-interact</t> at any Rally Point to access the mission menu.",
        "\z\ace\addons\interaction\ui\Icon_Module_Interaction_ca.paa"
    ]] call BIS_fnc_showNotification;
}, [], 15] call CBA_fnc_waitAndExecute;

private _action = [
    "PotatoSeedActions",
    "Mission Actions",
    "\A3\ui_f\data\map\markers\military\flag_CA.paa", {},
    {
        params ["_player"];
        if ((_player nearObjects [BW_TP_FLAG_TYPE, BW_TP_FLAG_DIST]) isNotEqualTo []) then {
            _player setVariable [QPGVAR(assignGear,changeOpticsTimeLimit), CBA_missionTime + 10];
            true
        } else {
            false
        }
    }
] call ACEFUNC(interact_menu,createAction);
[
    "CAManBase", 1,
    ["ACE_SelfActions"],
    _action,
    true
] call ACEFUNC(interact_menu,addActionToClass);

_action = [
    "tpUnit",
    "Teleport to flag",
    "\a3\ui_f\data\GUI\Rsc\RscDisplayArsenal\map_ca.paa", {
        openMap [true, false];
        ["MapTeleport"] call BIS_fnc_showNotification;
        _player setVariable [QGVAR(mapClickWindow), CBA_missionTime + 20];
        GVAR(safeStartTPClickEH) = addMissionEventHandler ["MapSingleClick", {
            _this call FUNC(teleportUnitHandle);
        }];
    },
    {true}
] call ACEFUNC(interact_menu,createAction);
[
    "CAManBase", 1,
    ["ACE_SelfActions", "PotatoSeedActions"],
    _action,
    true
] call ACEFUNC(interact_menu,addActionToClass);

_action = [
    "InitTasks",
    "Open Mission Menu",
    "\A3\ui_f\data\map\mapcontrol\taskIcon_ca.paa", {
        createDialog "RscMissionSelectMenu";
    },
    {true}
] call ACEFUNC(interact_menu,createAction);
[
    "CAManBase", 1,
    ["ACE_SelfActions", "PotatoSeedActions"],
    _action,
    true
] call ACEFUNC(interact_menu,addActionToClass);

_action = [
    "fullHeal",
    "Full Heal",
    "\a3\ui_f\data\igui\cfg\simpletasks\types\Heal_ca.paa", {
        [_player, _player] call ace_medical_treatment_fnc_fullHeal;
    },
    {true}
] call ACEFUNC(interact_menu,createAction);
[
    "CAManBase", 1,
    ["ACE_SelfActions", "PotatoSeedActions"],
    _action,
    true
] call ACEFUNC(interact_menu,addActionToClass);

_action = [
    "resetGear",
    "Reset Gear",
    "\a3\ui_f\data\igui\cfg\simpletasks\types\rearm_ca.paa", {
        if (((_player nearEntities ["CAManBase", 300]) select {
                alive _x &&
                 (side _x == east ||
                 side _x == resistance)
                 }) isNotEqualTo []) then {
            ["Notif_Picture", [
                "Failed to Rearm",
                "Enemy within 300 meters, you may not rearm.",
                "\a3\ui_f\data\igui\cfg\actions\returnflag_ca.paa"
            ]] call BIS_fnc_showNotification;
        } else {
            [_player] remoteExecCall [QPFUNC(assignGear,assignGearMan), 2];
        };
    },
    {true}
] call ACEFUNC(interact_menu,createAction);
[
    "CAManBase", 1,
    ["ACE_SelfActions", "PotatoSeedActions"],
    _action,
    true
] call ACEFUNC(interact_menu,addActionToClass);

{
    private _cfgName = configName _x;
    _action = [
        "createBox" + _cfgName,
        format ["Create %1", getText (_x >> "boxCustomName")],
        "\a3\weapons_f\ammoboxes\data\ui\icomap_ammo_ca.paa",
        compile format ["createVehicle [""%1"", getPosATL _target, [], 3, ""NONE""];", _cfgName],
        {true}
    ] call ACEFUNC(interact_menu,createAction);
    [
        "CAManBase", 1,
        ["ACE_SelfActions", "PotatoSeedActions", "resetGear"],
        _action,
        true
    ] call ACEFUNC(interact_menu,addActionToClass);
} forEach (configProperties [missionConfigFile >> "CfgLoadouts" >> "SupplyBoxes", "isClass _x"]);

_action = [
    "PotatoAddRally",
    "Place Rally Flag",
    "\a3\ui_f\data\igui\cfg\actions\takeflag_ca.paa", {
        if ((_player nearObjects [BW_TP_FLAG_TYPE, 300]) isNotEqualTo []) exitWith {
            ["Notif_Picture", [
                "Failed to Create Rally",
                "You are currently too close to another rally to place a new one.",
                "\a3\ui_f\data\igui\cfg\simpletasks\types\rearm_ca.paa"
            ]] call BIS_fnc_showNotification;
        };
        if (((_player nearEntities ["CAManBase", 250]) select {
                alive _x &&
                 (side _x == east ||
                 side _x == resistance)
                 }) isNotEqualTo []  &&
                {_player nearObjects [BW_TP_FLAG_TYPE, 1000] isNotEqualTo []}) exitWith {
            ["Notif_Picture", [
                "Failed to Create Rally",
                "Enemy within 250 meters, you may not place a Rally.",
                "\a3\ui_f\data\igui\cfg\actions\returnflag_ca.paa"
            ]] call BIS_fnc_showNotification;
        };
        private _pos = getPosATL _player;
        private _flag = createVehicle [BW_TP_FLAG_TYPE, _pos, [], 0, "NONE"];
        [_flag, true] remoteExecCall ["enableDynamicSimulation", 0, true];
    },
    {leader _player == _player}
] call ACEFUNC(interact_menu,createAction);
[
    "CAManBase", 1,
    ["ACE_SelfActions"],
    _action,
    true
] call ACEFUNC(interact_menu,addActionToClass);

if (GVAR(enableGRADMode) > 0 && getMissionConfigValue ["allowGRADFromFlag", 0] == 1) then {
    _action = [
        "PotatoGRADVehicle",
        "Vehicle Spawner",
        "\a3\ui_f\data\gui\rsc\rscdisplayarsenal\spacegarage_ca.paa", {
            call FUNC(gradVicHandle)
        }, {true}
    ] call ACEFUNC(interact_menu,createAction);
    [
        "CAManBase", 1,
        ["ACE_SelfActions", "PotatoSeedActions"],
        _action,
        true
    ] call ACEFUNC(interact_menu,addActionToClass);
};
_action = [
    "PotatoDeleteRally",
    "Delete Rally Flag",
    "\a3\ui_f\data\igui\cfg\actions\returnflag_ca.paa", {
        private _flags = _player nearObjects [BW_TP_FLAG_TYPE, BW_TP_FLAG_DIST];
        if (_flags isEqualTo []) exitWith {};
        private _flag = _flags#0;
        private _flagMarker = _flag getVariable [QGVAR(attachedMarker), ""];
        if (_flagMarker == "")  exitWith {
            ["Notif_Picture", [
                "Cannot Delete Flag",
                "Current flag is not a placed rally point.",
                "\a3\ui_f\data\gui\rsc\rscdisplayarcademap\icon_exit_cross_ca.paa"
            ]] call BIS_fnc_showNotification;
        };
        private _flagIndex = _flag getVariable [QGVAR(respawnIndex), []];
        if (_flagIndex isNotEqualTo []) then {
            _flagIndex call BIS_fnc_removeRespawnPosition;
        };
        deleteMarker _flagMarker;
        deleteVehicle _flag;
    },
    {leader _player == _player}
] call ACEFUNC(interact_menu,createAction);
[
    "CAManBase", 1,
    ["ACE_SelfActions", "PotatoSeedActions"],
    _action,
    true
] call ACEFUNC(interact_menu,addActionToClass);


["Lambda.Tiger's Infantry Spawner", "Create Circle Spawner", {
    params ["_posASL"];
    [[], false, ASLToATL _posASL] call FUNC(ui_handleCircleSpawnMenu);
}] call zen_custom_modules_fnc_register;
["Lambda.Tiger's Infantry Spawner", "Delete Circle Spawner (200m)", {
    [_this#0, 200] remoteExecCall [QFUNC(removeCircleSpawner)];
}] call zen_custom_modules_fnc_register;

