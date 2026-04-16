#include "..\script_component.hpp"
/*
* Author: Lambda.Tiger
* This function handle outputs all unit and group radio channels for groups
* and units that currently exist in a mission.
*
* Arguments:
* None
*
* Return Value:
* None
*
* Examples:
* [] call potato_radios_fnc_uihook_listRadioChannels.sqf
*
* Public: No
*/
private _debugMsg = format ["Added Potato Radio Channels List"];
["potato_adminMsg", [_debugMsg, profileName]] call CBA_fnc_globalEvent;

// Needs a player to add to breifing:
if ((isNull player) || {!alive player}) exitWith {};

private _diaryBuilder = ["<font size=28 face=""PuristaBold"">Radio Channels</font>"];
{
    private _groups = (groups _x) select {[_x getVariable [QEGVAR(radios,srchannel),-1], _x getVariable [QEGVAR(radios,mrchannel),-1], _x getVariable [QEGVAR(radios,lrchannel),-1]] isNotEqualTo [-1,-1,-1]};
    private _units = (units _x) select {[_x getVariable [QEGVAR(radios,srchannel),-1], _x getVariable [QEGVAR(radios,mrchannel),-1], _x getVariable [QEGVAR(radios,lrchannel),-1]] isNotEqualTo [-1,-1,-1]};
    private _sideStr = "Indy";
    private _color = switch (_x) do {
        case (west): {
            _sideStr = "BluFor";
           "#0088EE" //0,0.45,0.9,1
        };
        case (east): {
            _sideStr = "OpFor";
            "#DD0000" //0,0.45,0.9,1
        };
        case (resistance): {
            "#00DD00" //0,0.45,0.9,1
        };
        default {
            "#880099" //0,0.45,0.9,1
        };
    };
    if (_groups isEqualTo [] && _units isEqualTo []) then {continue};
    _diaryBuilder pushBack format ["<font color=""%1"" size=20 face=""PuristaBold"">%2 Radios Channels</font>", _color, _sideStr];
    _diaryBuilder pushBack "<font size=16 face=""PuristaBold"">Group Default Channels</font>";
    private _groupHash = createHashMap;
    {
        private _channels = [
            _x getVariable [QEGVAR(radios,srchannel),-1],
            _x getVariable [QEGVAR(radios,mrchannel),-1],
            _x getVariable [QEGVAR(radios,lrchannel),-1]
        ];
        {
            if (_x < 10) then {
                _channels set [_forEachIndex, "0" + str _x];
            } else {
                _channels set [_forEachIndex, str _x];
            };
        } forEach _channels;
        _diaryBuilder pushBack format [
            "<font size=12>%1<br/>  SR: %2 | MR: %3 | LR: %4</font>",
            groupID _x,
            _channels#0,
            _channels#1,
            _channels#2
        ];
    } forEach _groups;

    _diaryBuilder pushBack "<font size=16 face=""PuristaBold"">Specific Unit Channels</font>";
    private _unitHash = createHashMap;
    {
        private _channels = [
            _x getVariable [QEGVAR(radios,srchannel),-1],
            _x getVariable [QEGVAR(radios,mrchannel),-1],
            _x getVariable [QEGVAR(radios,lrchannel),-1]
        ];
        {
            if (_x < 10) then {
                _channels set [_forEachIndex, "0" + str _x];
            } else {
                _channels set [_forEachIndex, str _x];
            };
        } forEach _channels;
        _diaryBuilder pushBack format [
            "<font size=12>%1<br/>  SR: %2 | MR: %3 | LR: %4</font>",
            ((roleDescription _x) splitString "@")#0,
            _channels#0,
            _channels#1,
            _channels#2
        ];
    } forEach _units;
} forEach [west, east, resistance];

if !(player diarySubjectExists "POTATO") then {
    player createDiarySubject ["POTATO", "POTATO"];
};
// find the diary
private _diaryEntries = player allDiaryRecords "POTATO";
// find and replace existing orbat pages
private _noOrbatFound = true;
{
    _x params ["_idx", "_title", "", "", "", "", "", "", "_record"];
    if (_title == "Radio Report") then {
        player setDiaryRecordText [["POTATO", _record], ["Radio Report", _diaryBuilder joinString "<br/>"]];
        _noOrbatFound = false;
    };
} forEach _diaryEntries;

// if we didn't find and replace, add one
if (_noOrbatFound) then {
    player createDiaryRecord ["POTATO", ["Radio Report", _diaryBuilder joinString "<br/>"], taskNull, "NONE", false];
};
