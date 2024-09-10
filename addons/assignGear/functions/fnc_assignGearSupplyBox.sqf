#include "script_component.hpp"
/*
 * Author: Bailey
 * Fills supply box with gear for a faction
 * Edit by Lambda.tiger
 * Supports boxes containing other boxes
 *
 * Arguments:
 * 0: Box <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [cursorObject] call potato_assignGear_fnc_assignGearSupplyBox
 *
 * Public: No
 */

params ["_theBox"];

TRACE_1("",GVAR(setSupplyBoxLoadouts));

if (_theBox getVariable [QGVAR(initialized), false]) exitWith {};
_theBox setVariable [QGVAR(initialized), true, true];

//Leave default gear when GVAR(setSupplyBoxLoadouts) is 0
if (GVAR(setSupplyBoxLoadouts) == 0) exitWith {};

//Clean out starting inventory when GVAR(setSupplyBoxLoadouts) is -1
if (GVAR(setSupplyBoxLoadouts) == -1) exitWith {
    clearWeaponCargoGlobal _theBox;
    clearMagazineCargoGlobal _theBox;
    clearItemCargoGlobal _theBox;
    clearBackpackCargoGlobal _theBox;
};

private _path = missionConfigFile >> "CfgLoadouts" >> "SupplyBoxes" >> typeOf _theBox;

if (!isClass _path) exitWith {
    diag_log formatText ["[POTATO-assignGear] - No loadout found for %1 (typeOf %2)", _theBox, typeOf _theBox];
};

private _subBoxes = "true" configClasses _path;
if (_subBoxes isNotEqualTo []) then {
    private _boxName = getText (_path >> "boxCustomName");
    if (_boxName isNotEqualTo "") then {
        _theBox setVariable [QACEGVAR(cargo,customName), _boxName, true];
    };
    clearWeaponCargoGlobal _theBox;
    clearMagazineCargoGlobal _theBox;
    clearItemCargoGlobal _theBox;
    clearBackpackCargoGlobal _theBox;
    private _boxSpace = getNumber (_path >> "boxSpace");
    [_theBox, [_boxSpace, 4] select (_boxSpace == 0)] call ACEFUNC(cargo,setSpace);
    {
        private _subBoxType = configName _x;
        private _boxCount = (getNumber (_x >> "boxCount")) max 1;
        for "_i" from 1 to _boxCount do {
            private _subBox = createVehicle [_subBoxType, [0, 0, 0], [], 0, "CAN_COLLIDE"];
            [_subBox, _x, ["%1", "%1 " + str _i] select (_boxCount > 1)] call FUNC(setBoxContentsFromConfig);
            [_subBox, 1] call ACEFUNC(cargo,setSize);
            if !([_subBox, _theBox, true] call ACEFUNC(cargo,loadItem)) exitWith {
                diag_log formatText [
                    "[POTATO-assignGear] - Failed to create %1 %2 supply box(es) for %3 - out of space ",
                    _subBoxType,
                    "x" + str (_boxCount - _i + 1),
                    typeOf _theBox
                ];
                deleteVehicle _subBox;
            };
            _subBox setVariable [QGVAR(initialized), true];
        };
    } forEach _subBoxes;
    [_theBox, 2] call ACEFUNC(cargo,setSize);
    [_theBox, true, [0, 1, 1], 0, true, true] call ACEFUNC(dragging,setCarryable);
    [_theBox, true, [0, 1.5, 0], 0, true, true] call ACEFUNC(dragging,setDraggable);
} else {
    [_theBox, _path] call FUNC(setBoxContentsFromConfig);
};

private _addMarkingActions = getNumber (_path >> "addMarkingActions");
if (_addMarkingActions >= 1) then {
    [QGVAR(resupplyBoxAddActions), [_theBox, _addMarkingActions]] call CBA_fnc_globalEventJIP;
};
