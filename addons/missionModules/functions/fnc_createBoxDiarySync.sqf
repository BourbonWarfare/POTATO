#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function is run by a module on init. It takes all the synced
 * objectes of the module and creates resupply entries for them in the
 * players diary. This function can be called on the module later as the
 * module should not be automatically deleted.
 *
 * Arguments:
 * 0: The module being initialized
 * 1: The objects syncronized to the object
 * 2: Whether the module is active
 *
 * Examples:
 * Should be called by module init
 *
 * Public: No
 */
TRACE_1("CreateBoxSync",_this);
params ["_logic", "_objectsToAdd", "_activated", ["_player", ace_player, [objNull]]];
if (!_activated || !hasInterface) exitWith {
    TRACE_3("leaving resup diary early",_logic,_activated,hasInterface);
};

if !(ACEGVAR(common,settingsInitFinished)) exitWith {
    if (isNil QGVAR(resupplyToRun)) then {
        GVAR(resupplyToRun) = [];
    };
    GVAR(resupplyToRun) pushBack [_this, {call FUNC(createBoxDiarySync)}];
};
if (isNull _player) exitWith {};

private _side = switch (_logic getVariable ["side", 0]) do {
    case 1: {west};
    case 2: {east};
    case 3: {resistance};
    case 4: {civilian};
    default {0};
};

if (_side isEqualType west && {side _player != _side}) exitWith {
    TRACE_3("Bad side",_side,side _player,_player);
};

private _baseConfigPath = missionConfigFile >> "CfgLoadouts";
private _boxLoadouts = getNumber (_baseConfigPath >> "setSupplyBoxLoadouts");
private _vicLoadouts = getNumber (_baseConfigPath >> "setVehicleLoadouts");
TRACE_2("Found Loadouts",_boxLoadouts,_vicLoadouts);
if (_boxLoadouts != 0 && _vicLoadouts != 0) exitWith {};

// Function to combine magazine elements
private _fnc_combineInventroy = {
    params [["_inputArray", []]];
    private _itemHash = createHashMap;
    {
        if (_x in _itemHash) then {
            _itemHash set [_x, (_itemHash get _x) + 1];
        } else {
            _itemHash set [_x, 1];
        };
    } forEach _inputArray;
    private _outputArray = [];
    {
        _outputArray pushBack (_x + ":" + str _y);
    } forEach _itemHash;
    _outputArray
};

// Gather all boxes
private _supplyBoxes = _objectsToAdd select {_x isKindOf "ReammoBox_F"};
TRACE_1("Adding supplyboxes",_supplyBoxes);
if (_boxLoadouts == 0) then {
    {
        TRACE_1("Adding",typeName _x);
        [
            _player,
            getText ((configOf _x) >> "displayName"),
            LOADOUT_DIARY_TYPE_BOX, [
                [backpackCargo _x] call _fnc_combineInventroy,
                [weaponCargo _x] call _fnc_combineInventroy,
                [magazineCargo _x] call _fnc_combineInventroy,
                [itemCargo _x] call _fnc_combineInventroy
        ]] call FUNC(createResupplyDiaryEntry);
    } forEach _supplyBoxes;
};

TRACE_1("Adding vehicles",(_objectsToAdd - _supplyBoxes));
if (_vicLoadouts == 0) then {
    {
        TRACE_1("Adding",typeName _x);
        [
            _player,
            getText ((configOf _x) >> "displayName"),
            LOADOUT_DIARY_TYPE_VEHICLE, [
                [backpackCargo _x] call _fnc_combineInventroy,
                [weaponCargo _x] call _fnc_combineInventroy,
                [magazineCargo _x] call _fnc_combineInventroy,
                [itemCargo _x] call _fnc_combineInventroy
        ]] call FUNC(createResupplyDiaryEntry);
    } forEach (_objectsToAdd - _supplyBoxes);
};
