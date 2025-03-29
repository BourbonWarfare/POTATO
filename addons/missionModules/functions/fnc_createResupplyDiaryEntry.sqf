#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function takes in a unit to add a diary to, the name of the box and
 * arrays of config names for backpacks, weapons, magazines, and items.
 * The function then creates relevant diary entries on the given unit
 *
 * Arguments:
 * 0: The unit to add the diary entries to <OBJECT>
 * 1: The box name to show in the diary entries <STRING>
 * 2: The type of loadout to use whether a supply box, vehicle,
 *      or boxese of boxes <SCALAR>
 * 3: An array containing arrays of ammo contents. Each array is expected to
 *      be formatted as "Magazine:# of magazines", no combining will be done
 *      if magazines are not properly reduced
 *   0: Backapcks <ARRAY>
 *   1: Weapons <ARRAY>
 *   2: Magazines <ARRAY>
 *   3: Items <ARRAY>
 *
 *
 * Examples:
 * [player, "Rifle Box", [[], ["arifle_TRG20_F"], [], []]] call potato_missionModules_fnc_createResupplyDiaryEntry
 *
 * Public: No
*/
TRACE_1("Creating resupply diary entry",_this);
params [
    ["_unit", objNull, [objNull]],
    ["_boxName", "Resupply Box", [""]],
    ["_diaryType", LOADOUT_DIARY_TYPE_BOX, [LOADOUT_DIARY_TYPE_BOX]],
    ["_supplies", [], [[]]]
];

if (isNull _unit || _supplies isEqualTo []) exitWith {
    TRACE_2("Empty supplies or bad unit",_unit,_supplies);
};

if !(_unit diarySubjectExists QGVAR(resupply)) then {
    _unit createDiarySubject [QGVAR(resupply), "Resupply"];
};

private _title = "Resupply Boxes";
private _diaryEntry = switch (_diaryType) do {
    case LOADOUT_DIARY_TYPE_VEHICLE: {
        _title = "Vehicle Infantry Resupply";
        "vicResupply"
    };
    case LOADOUT_DIARY_TYPE_BOXOFBOX: {
        _title = "Resupply Box Heiarchy";
        "boxOfBoxResupply"
    };
    default {
        "boxResupply"
    };
};

// find existing page
private _diaryEntries = _unit allDiaryRecords QGVAR(resupply);
private _recordIdx = -1;
private _diary = "";
{
    _x params ["", "_titleLocal", "", "", "", "", "", "", "_diaryLocal"];
    if (_title == _titleLocal) exitWith {
        _diary = _diaryLocal;
        _recordIdx = _forEachIndex;
    };
} forEach _diaryEntries;

// How many cols of text do we need to keep a "fixed width" look
private _sigFigs = 0;
{
    (_x splitString ":") params ["", ["_count", "1"]];
    _count = parseNumber _count;
    _sigFigs = _sigFigs max (1 + floor log _count);
} forEach (flatten _supplies);

private _newEntry = [format ["<font color=""#FFBF46"" size=""18"">%1</font color>", _boxName]];
// Make a new entry
_supplies params ["_backpacks", "_weapons", "_mags", "_items"];
TRACE_1("Adding backpack types",_backpacks);
{
    (_x splitString ":") params ["_weapon", ["_count", "1"]];
    _count = parseNumber _count;
    private _width = 1 + floor log _count;
    private _string = "0";
    for "_i" from 1 to (_sigFigs - _width) do {
        _string = _string + " ";
    };
    private _backpack = getText (configFile >> "CfgVehicles" >> _weapon >> "displayName");
    if (_backpack == "") then {continue};
    _newEntry pushBack (_string + str _count + " - " + _backpack);
} forEach _backpacks;
TRACE_1("Adding weapon types",_weapons);
{
    (_x splitString ":") params ["_weapon", ["_count", "1"]];
    _count = parseNumber _count;
    private _width = 1 + floor log _count;
    private _string = " ";
    for "_i" from 1 to (_sigFigs - _width) do {
        _string = _string + "0";
    };
    private _wepName = getText (configFile >> "CfgWeapons" >> _weapon >> "displayName");
    if (_wepName == "") then {continue};
    _newEntry pushBack (_string + str _count + " - " + _wepName);
} forEach _weapons;
TRACE_1("Adding magazine types",_mags);
// sort magazines by ammo count
private _cfgMags = configFile >> "CfgMagazines";
_mags = _mags apply {
    (_x splitString ":") params ["_magazine", ["_count", "1"]];

    private _cfg = _cfgMags >> _magazine >> "count";
    [1000 * (getNumber _cfg) + (parseNumber _count), _x]
};
_mags sort false;
{
    (_x splitString ":") params ["_magazine", ["_count", "1"]];
    _count = parseNumber _count;
    private _width = 1 + floor log _count;
    private _string = " ";
    for "_i" from 1 to (_sigFigs - _width) do {
        _string = _string + "0";
    };
    private _magName = getText (_cfgMags >> _magazine >> "displayName");
    if (_magName == "") then {continue};
    _newEntry pushBack (_string + str _count + " - " + _magName);
} forEach (_mags apply {_x#1});
TRACE_1("Adding items types",_items);
{
    (_x splitString ":") params ["_item", ["_count", "1"]];
    _count = parseNumber _count;
    private _width = 1 + floor log _count;
    private _string = " ";
    for "_i" from 1 to (_sigFigs - _width) do {
        _string = _string + "0";
    };
    private _itemName = getText (configFile >> "CfgWeapons" >> _item >> "displayName");
    if (_itemName == "") then {continue};
    _newEntry pushBack (_string + str _count + " - " + _itemName);
} forEach _items;
_newEntry pushBack "<br/>";

// Put it all together
_newEntry = _newEntry joinString "<br/>";
if (_recordIdx >= 0) then {
    _unit setDiaryRecordText [[QGVAR(resupply), _diary], [_title, (_diaryEntries#_recordIdx#2) + _newEntry]];
} else {
    _newEntry = format ["<font size=""24"">%1</font><br/><br/>", _title] + _newEntry;
    _unit createDiaryRecord [QGVAR(resupply), [_title, _newEntry], taskNull, "NONE", false];
};
