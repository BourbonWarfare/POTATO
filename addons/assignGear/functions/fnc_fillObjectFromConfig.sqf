#include "script_component.hpp"
/*
 * Author: Lambda.Tiger
 * Fills given object based on config, adding either sub containers or
 * filling inventory of the object. It will begin by clearing the objects
 * inventory and then either recursively fill with boxes or just the
 * objects inventory.
 *
 * Arguments:
 * 0: The object ammo or boxes will be added to <OBJECT>
 * 1: The config path to the box contents to fill <CONFIG>
 * 2: Max recusion depth (Default, 1) <SCALAR>
 * 3: Name format string (Default, "%1") <STRING>
 *
 * Return Value:
 * -1 - Either object or path is null
 *  0 - Filled with inventory from config
 *  1 - Filled with ACE Cargo from config
 *
 * Example:
 * [cursorObject, missionConfigFile >> "CfgLoadouts" >> "CustomBox"] call potato_assignGear_fnc_fillObjectFromConfig;
 *
 * Public: No
 */
TRACE_1("",_this);
params [
    ["_theObject", objNull, [objNull]],
    ["_path", configNull, [configNull]],
    ["_maxDepth", 1, [1]],
    ["_formatString", "%1", [""]]
];


if (isNull _theObject || isNull _path) exitWith {
    TRACE_2("Bad object or path",_theObject,_path);
    -1
};
if (_theObject isKindOf "ReammoBox_F") then {
    [_theObject, 1] call ACEFUNC(cargo,setSize);
};

private _addMarkingActions = getNumber (_path >> "addMarkingActions");
if (_addMarkingActions >= 1) then {
    [QGVAR(resupplyBoxAddActions), [_theObject, _addMarkingActions]] call CBA_fnc_globalEventJIP;
};

private _subBoxes = configProperties [_path, "isClass _x"];
if (_subBoxes isNotEqualTo [] && _maxDepth > 0) then {
    TRACE_2("Adding subboxes",_maxDepth,_subBoxes);
    _maxDepth = _maxDepth - 1;
    clearWeaponCargoGlobal _theObject;
    clearMagazineCargoGlobal _theObject;
    clearItemCargoGlobal _theObject;
    clearBackpackCargoGlobal _theObject;
    private _boxName = getText (_path >> "boxCustomName");
    if (_boxName isNotEqualTo "") then {
        _theObject setVariable [QACEGVAR(cargo,customName), format [_formatString, _boxName], true];
    };
    private _objectSpace = (getNumber (_path >> "boxSpace")) max (getNumber (_path >> "minVehicleBoxSpace"));
    _objectSpace = _objectSpace max (
        (_theObject call ACEFUNC(cargo,getCargoSpaceLeft)) +
        count (_theObject getVariable [QACEGVAR(cargo,loaded), []])
    );
    [_theObject, [_objectSpace, 4] select (_objectSpace == 0)] call ACEFUNC(cargo,setSpace);
    TRACE_1("cargoSize",_objectSpace);
    {
        private _subBoxType = configName _x;
        private _boxCount = (getNumber (_x >> "boxCount")) max 1;
        TRACE_3("Adding boxes",_subBoxType,_boxCount,_x);
        for "_i" from 1 to _boxCount do {
            private _subBox = createVehicle [_subBoxType, [0, 0, 0], [], 0, "CAN_COLLIDE"];
            [_subBox, 1] call ACEFUNC(cargo,setSize);
            if !([_subBox, _theObject, true] call ACEFUNC(cargo,loadItem)) exitWith {
                WARNING_3("Failed to create %1 %2 sub-box(es) for %3 - out of space",_subBoxType,"x" + str (_boxCount - _i + 1),typeOf _theObject);
                deleteVehicle _subBox;
            };
            [_subBox, _x, _maxDepth, ["%1", "%1 " + str _i] select (_boxCount > 1)] call FUNC(fillObjectFromConfig);
            _subBox setVariable [QGVAR(initialized), true];
        };
    } forEach _subBoxes;
    if (_theObject isKindOf "ReammoBox_F") then {
        [_theObject, 1] call ACEFUNC(cargo,setSize);
        [_theObject, true, [0, 1, 1], 0, true, true] call ACEFUNC(dragging,setCarryable);
        [_theObject, true, [0, 1.5, 0], 0, true, true] call ACEFUNC(dragging,setDraggable);
        _theObject addMagazineCargoGlobal [QGVAR(reminder), 1];
    };
    0
} else {
    TRACE_2("Adding inventory",_theObject,_path);
    [_theObject, _path] call FUNC(setBoxContentsFromConfig);
    1
}
