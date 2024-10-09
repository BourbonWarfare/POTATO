#include "script_component.hpp"
/*
 * Author: PabstMirror
 * Applies a loadout to a vehicle
 * Edited by Bailed to add option 2
 * Edited by Lambda.Tier to add option 3 and move some common code to functions
 *
 * Arguments:
 * 0: Vehicle <OBJECT>
 * 1: Default loadout type <STRING>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [cursorTarget] call potato_assignGear_fnc_assignGearVehicle;
 *
 * Public: Yes
 */
params ["_theVehicle", "_defaultLoadout"];
TRACE_2("assignGearVehicle",_theVehicle,_defaultLoadout);

private _typeOf = typeOf _theVehicle;
private _loadout = _theVehicle getVariable ["F_Gear", _typeOf];
private _faction = toLower faction _theVehicle;

TRACE_2("",GVAR(setVehicleLoadouts),_loadout);

//Leave default gear when "F_Gear" is "Default" or GVAR(setVehicleLoadouts) is 0
if ((GVAR(setVehicleLoadouts) == 0) || {_loadout == "Default"}) exitWith {
    if (GVAR(alwaysAddToolkits)) then { _theVehicle addItemCargoGlobal ["Toolkit", 1]; };
    if (GVAR(alwaysAddLandRopes) && {(_theVehicle isKindOf "Car") || {_theVehicle isKindOf "Tank"}}) then {
        _theVehicle addItemCargoGlobal ["ACE_rope15", 1]; // note: this rope is probably too short to fastrope with, so don't add to air
    };
};

//Clean out starting inventory when "F_Gear" is "Empty" or GVAR(setVehicleLoadouts) is -1
if ((GVAR(setVehicleLoadouts) == -1) || {_loadout == "Empty"}) exitWith {
    clearWeaponCargoGlobal _theVehicle;
    clearMagazineCargoGlobal _theVehicle;
    clearItemCargoGlobal _theVehicle;
    clearBackpackCargoGlobal _theVehicle;
    //Add a Toolkit
    if (GVAR(alwaysAddToolkits)) then { _theVehicle addItemCargoGlobal ["Toolkit", 1]; };
    if (GVAR(alwaysAddLandRopes) && {(_theVehicle isKindOf "Car") || {_theVehicle isKindOf "Tank"}}) then {
        _theVehicle addItemCargoGlobal ["ACE_rope15", 1];
    };
};

private _path = missionConfigFile >> "CfgLoadouts" >> _faction >> _loadout;

if (!isClass _path) then {
    //No CfgLoadouts for exact loadout, try default
    private _vehConfigSide = [_theVehicle, true] call BIS_fnc_objectSide;
    private _vehConfigFactions = switch (_vehConfigSide) do {
        case (west): { ["blu_f", "potato_w"] };
        case (east): { ["opf_f", "potato_e", "potato_msv"] }; // potato_msv is depcrecated but kept for BWC for now
        case (independent): { ["ind_f", "potato_i"] };
        default { ["civ_f"] };
    };

    {
        private _break = false;
        private _loadoutToCheck = _x;

        {
            _path = missionConfigFile >> "CfgLoadouts" >> _x >> _loadoutToCheck;
            if (isClass _path) exitWith { _break = true; };
        } forEach _vehConfigFactions;

        if (_break) exitWith {};
    } forEach [_loadout, _defaultLoadout];
};

if (!isClass _path) exitWith {
    diag_log text format ["[POTATO-assignGear] - No loadout found for %1 (typeOf %2) (kindOf %3) (defaultLoadout: %4)", _theVehicle, typeOf _theVehicle, _loadout, _defaultLoadout];
};

switch (GVAR(setVehicleLoadouts)) do {
    case 1: { // ammo in vehicle inventory
        [_theVehicle, _path] call FUNC(setContainerContentsFromConfig);
    };
    case 2: { // ammo in boxes in vehicle
        clearWeaponCargoGlobal _theVehicle;
        clearMagazineCargoGlobal _theVehicle;
        clearItemCargoGlobal _theVehicle;
        clearBackpackCargoGlobal _theVehicle;
        [_theVehicle, _path,
            getArray(_path >> "TransportMagazines"),
            getArray(_path >> "TransportItems"),
            getArray(_path >> "TransportWeapons"),
            getArray(_path >> "TransportBackpacks")] call FUNC(assignGearVehicle_asBoxes);
    };
    case 3: { // ammo in boxes in vehicle from config
        clearWeaponCargoGlobal _theVehicle;
        clearMagazineCargoGlobal _theVehicle;
        clearItemCargoGlobal _theVehicle;
        clearBackpackCargoGlobal _theVehicle;
        private _boxes = "true" configClasses _path;
        if (_boxes isEqualTo []) exitWith {
            [_theVehicle, _path] call FUNC(setContainerContentsFromConfig);
        };
        private _vehicleSpace = getNumber (_path >> "minVehicleBoxSpace");
        if (_vehicleSpace > 0) then {
            private _currentVehicleSpace = _theVehicle getVariable [
                QACEGVAR(cargo,hasCargo),
                getNumber (configOf _theVehicle >> QACEGVAR(cargo,space))
            ];
            [_theVehicle, _vehicleSpace max _currentVehicleSpace] call ACEFUNC(cargo,setSpace);
        };
        {
            private _boxType = configName _x;
            private _boxCount = (getNumber (_x >> "boxCount")) max 1;
            for "_i" from 1 to _boxCount do {
                private _box = createVehicle [_boxType, [0, 0, 0], [], 0, "CAN_COLLIDE"];
                [_box, _x, ["%1", "%1 " + str _i] select (_boxCount > 1)] call FUNC(setBoxContentsFromConfig);
                [_box, 1] call ACEFUNC(cargo,setSize);
                if !([_box, _theVehicle, true] call ACEFUNC(cargo,loadItem)) exitWith {
                    diag_log text format ["[POTATO-assignGear] - Failed to create %1 supply box(es) for %2 - out of space ", _boxType, typeOf _theVehicle];
                    deleteVehicle _box;
                };
                _box setVariable [QGVAR(initialized), true];
            };
        } forEach _boxes;
    };
};

//Add a Toolkit
if (GVAR(alwaysAddToolkits)) then { _theVehicle addItemCargoGlobal ["Toolkit", 1]; };
if (GVAR(alwaysAddLandRopes) && {(_theVehicle isKindOf "Car") || {_theVehicle isKindOf "Tank"}}) then {
    _theVehicle addItemCargoGlobal ["ACE_rope15", 1];
};
