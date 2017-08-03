/*
 * Author: PabstMirror, AACO
 * Add items to a container array (only if they have space)
 *
 * Arguments:
 * 0: Array of items to add to the given container <ARRAY>
 * 1: Array of all containers and their free space <ARRAY>
 * 2: Index of the given container <NUMBER>
 *
 * Return Value:
 * Array of items that couldn't be added to the given container <ARRAY>
 *
 * Example:
 * [_configItems, _containersArray, UNIFORM_INDEX] call potato_assignGear_addItemsToContainer;
 *
 * Public: No
 */

#include "script_component.hpp"
#define VEST_ALLOWED_SLOTS 701
#define UNIFORM_ALLOWED_SLOTS 801
#define BACKPACK_ALLOWED_SLOTS 901
#define PRIMARY_TYPE 1
#define HANDGUN_TYPE 2
#define LAUNCHER_TYPE 4
#define BINO_TYPE 4096

TRACE_1("params",_this);
params ["_itemsToAddArray", "_containersArray", "_containerIndex"];

// if there's no work do be done, quit early
if (_itemsToAddArray isEqualTo []) exitWith { _itemsToAddArray };

private _indexSlotNum = [UNIFORM_ALLOWED_SLOTS, VEST_ALLOWED_SLOTS, BACKPACK_ALLOWED_SLOTS] select _containerIndex; // for the "allowedSlots" check
(_containersArray select _containerIndex) params ["_sizeLeft", ["_array", []]];
TRACE_4("Adding Items To Container",_itemsToAddArray,_containerIndex,_sizeLeft,_array);

private _returnArray = [];
{
    private _itemToAdd = _x;
    private _itemLeft = [] call {
        // exit if there's no room left in the container
        if (_sizeLeft <= 0) exitWith { TRACE_1("no room",_itemToAdd); _itemToAdd };
        if (_itemToAdd == "") exitWith {TRACE_1("empty string - ignoring",_itemToAdd); ""};

        (_itemToAdd splitString ":") params ["_classname", ["_amountToAdd", "1", [""]]];
        _amountToAdd = parseNumber _amountToAdd;

        if (_amountToAdd < 1) exitWith {TRACE_1("item count is zero - ignoring",_itemToAdd); ""};

        if (isClass (configFile >> "CfgMagazines" >> _classname)) then {
            [
                getNumber (configFile >> "CfgMagazines" >> _classname >> "mass"),
                getNumber (configFile >> "CfgMagazines" >> _classname >> "count"),
                getArray (configFile >> "CfgMagazines" >> _classname >> "allowedSlots"),
                false
            ]
        } else {
            if (isClass (configFile >> "CfgWeapons" >> _classname)) then {
                [
                    getNumber (configFile >> "CfgWeapons" >> _classname >> "ItemInfo" >> "mass"),
                    -1,
                    getArray (configFile >> "CfgWeapons" >> _classname >> "ItemInfo" >> "allowedSlots"),

                    (getNumber (configFile >> "CfgWeapons" >> _classname >> "type") in [PRIMARY_TYPE, HANDGUN_TYPE, LAUNCHER_TYPE]) ||
                    {(_itemToAdd isKindOf ["Binocular", configFile >> "CfgWeapons"]) && {!(_itemToAdd isKindOf ["NVGoggles", configFile >> "CfgWeapons"])}}
                ]
            } else {
                [-1, -1, [], false]
            }
        } params ["_mass", "_count", "_allowedSlots", "_isWeapon"];

        if (_mass < 0) exitWith {
            diag_log text format ["[POTATO-assignGear] Item Not Found [%1]", _itemToAdd];
            ERROR_MSG_1("[%1] Bad Item Classname", _itemToAdd);
            ""
        };

        if (!((_allowedSlots isEqualTo []) || {_indexSlotNum in _allowedSlots})) exitWith {
            TRACE_3("not allowed in slot",_classname,_allowedSlots,_indexSlotNum);
            _itemToAdd
        };

        private _ammountThatWillFit = if (_mass == 0) then { 9999 } else { floor (_sizeLeft / _mass) };
        private _ammountAdded = _ammountThatWillFit min _amountToAdd;
        TRACE_6("",_classname,_mass,_count,_amountToAdd,_ammountThatWillFit,_ammountAdded);

        if (_ammountAdded == 0) exitWith { _itemToAdd };

        if (_count > 0) then {
            (_array select 1) pushBack [_classname, _ammountAdded, _count];
        } else {
            private _classnameToAdd = _classname;
            if (_isWeapon) then {
                _classnameToAdd = [_classname, [], []] call FUNC(getWeaponArray);
            };
            (_array select 1) pushBack [_classnameToAdd, _ammountAdded];
        };

        _sizeLeft = _sizeLeft - (_ammountAdded * _mass);
        (_containersArray select _containerIndex) set [0, _sizeLeft];

        if (_ammountAdded == _amountToAdd) exitWith { "" };
        (format ["%1:%2",_classname, (_amountToAdd - _ammountAdded)])
    };

    if (_itemLeft != "") then { _returnArray pushBack _itemLeft };
    nil
} count _itemsToAddArray; // count used here for speed, make sure nil is above this line

_returnArray
