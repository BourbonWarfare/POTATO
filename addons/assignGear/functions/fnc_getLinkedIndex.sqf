/*
 * Author: PabstMirror, AACO
 * Gets the index of the linked item, or sets the binocular weapons array if needed
 *
 * Arguments:
 * 0: Linked item classname <STRING>
 * 1: Binocular weapon array (only used for binocular items) <ARRAY>
 * 2: List of provided magazines (only used for binocular items) <ARRAY>
 *
 * Return Value:
 * Index of the linked item <NUMBER>
 *
 * Example:
 * [_linkedItem, _binocularArray, _configMagazines] call potato_assignGear_fnc_getLinkedIndex;
 *
 * Public: No
 */

#include "script_component.hpp"
#define BINO_INDEX -2
#define UNK_INDEX -1
#define MAP_INDEX 0
#define GPS_INDEX 1
#define RADIO_INDEX 2
#define COMPASS_INDEX 3
#define WATCH_INDEX 4
#define NVG_INDEX 5

TRACE_1("params",_this);
params ["_linkedItem", "_binocularArray", "_configMagazines"];
//IGNORE_PRIVATE_WARNING ["_x"];
private _itemSim = [configFile >> "CfgWeapons" >> _x >> "simulation", "STRING", ""] call CBA_fnc_getConfigEntry;
// Maps
if ("ItemMap" == _itemSim) exitWith {
    MAP_INDEX
};

// GPS/UAV terminals
if (_x isKindOf ["ItemGPS", configFile >> "CfgWeapons"] || {_x isKindOf ["UavTerminal_base", configFile >> "CfgWeapons"]}) exitWith {
    GPS_INDEX
};

// Radios (non TFAR/ACRE)
if ("ItemRadio" == _itemSim) exitWith {
    RADIO_INDEX
};

// Compasses
if ("ItemCompass" == _itemSim) exitWith {
    COMPASS_INDEX
};

// Watches
if ("ItemWatch" == _itemSim) exitWith {
    WATCH_INDEX
};

// Night vision/thermal goggles
if ("NVGoggles" == _itemSim) exitWith {
    NVG_INDEX
};

// Binoculars (not actually treated as a linked item)
if (_x isKindOf ["Binocular", configFile >> "CfgWeapons"]) exitWith {
    private _weaponArray = [_x, [], _configMagazines] call FUNC(getWeaponArray);
    {
        _binocularArray set [_forEachIndex, _x]; // copy to binoc array reference
    } forEach _weaponArray;
    BINO_INDEX
};

diag_log text format ["[POTATO-assignGear] - linkedItems [%1] unknown type", _linkedItem];
UNK_INDEX
