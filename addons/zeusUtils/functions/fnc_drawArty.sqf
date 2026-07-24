#include "..\script_component.hpp"
#include "\z\potato\addons\artillery\script_macros.hpp"
/*
 * Author: Lambda.Tiger
 * This function is called each frame from a Draw3D EH.
 * It draws all markers in the relevant marker arrays.
 * This function MUST be called through the Draw3D
 * event handler.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Examples:
 * call potato_zeusUtils_fnc_drawArty;
 *
 * Public: No
 */
//IGNORE_PRIVATE_WARNING["_localCuratorModule"];
TRACE_1("diag marker Handle:",diag_frameNo);

private _modulePosASL = getPosASL _localCuratorModule;
if (isNil QEGVAR(artillery,artilleryGunArray)) exitWith {};
if (isNil QGVAR(artyIcons)) then {
    GVAR(artyIcons) = createHashMap;
};
private _iconHashes = GVAR(artyIcons);
private _cfgMagazines = configFile >> "CfgMagazines";
private _size = 4;
private _sizeModifier = _size;
private _textscale = _sizeModifier * 0.8;
{
    if !(alive _x && alive gunner _x  && !isPlayer gunner _x) then {
        _iconHashes deleteAt getObjectID _x;
        continue;
    };
    (_x getVariable [QEGVAR(artillery,artyMission), []]) params [
        ["_missionID", ""],
        ["_status", ARTILLERY_MISSION_STATUS_FREE],
        ["_holdTime", -1],
        ["_missionTypeEnum", ARTILLERY_MISSIONTYPE_UNDEF],
        ["_missionDetails", []]
    ];
    if (_missionID == "" || _missionTypeEnum == ARTILLERY_MISSION_STATUS_FREE) then {
        _iconHashes deleteAt getObjectID _x;
        continue;
    };
    private _timeRemaining = _holdTime - CBA_missionTime;
    private _iconHash = _iconHashes getOrDefaultCall [
        getObjectID _x, {createHashMapFromArray [
            ["@position", [_x, 50]],
            ["@shadow", 4],
            ["@dynamic", true],
            ["@texts", []],
            ["type", ARTILLERY_MISSION_STATUS_FREE]
        ]}, true];
    if (_iconHash get "type" == _missionTypeEnum) then {
        private _texts = _iconHash get "@texts";
        switch (_status) do {
            case ARTILLERY_MISSION_STATUS_WAIT: {
                (_texts#1) set [0, format ["Time held: %1", _timeRemaining toFixed 0]]
            };
            case ARTILLERY_MISSION_STATUS_ASSIGN: {
                (_texts#2) set [0, format ["Time held: %1", _timeRemaining toFixed 0]]
            };
        };
    } else {
        _iconHash set ["type", _missionTypeEnum];
        if (ARTILLERY_MISSION_STATUS_WAIT == _status) then {
            _iconHash set ["@texts", [
                ["Held", _sizeModifier, 0, 0, [1, 0, 0, 0.7], true],
                [format ["Time held: %1", _timeRemaining toFixed 0], 0.7 * _sizeModifier, 0, _textscale * 1, [0.8, 0, 0, 0.7], true]
            ]];
        } else {
            private _missionType = switch (_missionTypeEnum) do {
                case ARTILLERY_MISSIONTYPE_LAZY: {"Lazy adjust fire mission"};
                case ARTILLERY_MISSIONTYPE_LAZY_WALK: {"Slow adjust walk"};
                case ARTILLERY_MISSIONTYPE_QUICK_LAZY: {"Quick lazy adjust fire mission"};
                case ARTILLERY_MISSIONTYPE_QUICK_LAZY_WALK: {"Quick adjust walk"};
                case ARTILLERY_MISSIONTYPE_BRACKET: {"Bracketing rounds fire mission"};
                case ARTILLERY_MISSIONTYPE_BRACKET_SHOTS: {"Bracketing shots"};
                case ARTILLERY_MISSIONTYPE_POINT: {"Point target"};
                case ARTILLERY_MISSIONTYPE_LINEAR: {"Linear target"};
                case ARTILLERY_MISSIONTYPE_LINEAR_WITH_BRACKET: {"Linear mission with bracketing"};
                case ARTILLERY_MISSIONTYPE_CREEPING: {"Creeping barrage"};
                case ARTILLERY_MISSIONTYPE_SLOW: {"Slow supressing barrage"};
                case ARTILLERY_MISSIONTYPE_SLOW_WITH_WALK: {"Slow supressing barrage with walk"};
                case ARTILLERY_MISSIONTYPE_SLOW_QUICK_LAZY: {"Slow supressing barrage with quick lazy walk"};
                default {lmd_err = [_x getVariable [QEGVAR(artillery,artyMission), []], _missionTypeEnum]; "UNDEF"};
            };
            if (_status == ARTILLERY_MISSION_STATUS_ASSIGN) then {
                _iconHash set ["@texts", [
                    ["Waiting", _sizeModifier, 0, 0, [0.8, 0, 0, 0.7], true],
                    [_missionType, 0.7 * _sizeModifier, 0, _textscale, [0.8, 0, 0, 0.7], true],
                    [format ["Time held: %1", _timeRemaining toFixed 0], 0.7 * _sizeModifier, 0, _textscale * 1.7, [0.8, 0, 0, 0.7], true]
                ]];
            } else {
                _missionDetails params ["_magazine", "_rounds", "_length"];
                switch (_missionTypeEnum) do {
                    case ARTILLERY_MISSIONTYPE_LAZY;
                    case ARTILLERY_MISSIONTYPE_LAZY_WALK;
                    case ARTILLERY_MISSIONTYPE_QUICK_LAZY;
                    case ARTILLERY_MISSIONTYPE_QUICK_LAZY_WALK: {_rounds = 3};
                    case ARTILLERY_MISSIONTYPE_BRACKET;
                    case ARTILLERY_MISSIONTYPE_BRACKET_SHOTS;
                    case ARTILLERY_MISSIONTYPE_LINEAR_WITH_BRACKET: {_rounds = 3};
                };
                _iconHash set ["@texts", [
                    [format ["Firing %1", getText (_cfgMagazines >> _magazine >> "displayNameShort")], _sizeModifier, 0, 0, [1, 0, 0, 0.7], true],
                    [_missionType, 0.7 * _sizeModifier, 0, _textscale, [1, 0, 0, 0.7], true],
                    [format ["%1 Rnds", _rounds], 0.5 * _sizeModifier, 0, _textscale * 1.7, [1, 0, 0, 0.7], true]
                ]];
            };
        };
    };
    drawIcon3D _iconHash;
} forEach EGVAR(artillery,artilleryGunArray);
