#include "script_component.hpp"
/*
 * Author: PabstMirror
 * Creates the custom module's vehicle on the HC
 *
 * Examples:
 * [[0,0,0], "somevic", west] call potato_zeusHC_fnc_autoModule_createLocal
 */

params ["_posASL", "_vehType", "_side"];
TRACE_3("autoModule_createLocal",_posASL,_vehType,_side);

private _posATL = ASLToATL _posASL;
private _sideUnitConfig = switch (_side) do {
    case west: { configFile >> "CfgVehicles" >> QGVAR(west_rifleman) };
    case east: { configFile >> "CfgVehicles" >> QGVAR(east_rifleman) };
    case resistance: { configFile >> "CfgVehicles" >> QGVAR(ind_rifleman) };
    default {configNull};
};

private _createArg = "NONE";
private _crewType = "";
switch (true) do {
    case (_vehType isKindOf "Air"): {
        _createArg = "FLY"; 
        _crewType = getText (_sideUnitConfig >> QGVAR(crewAir));
    };
    case (_vehType isKindOf "Wheeled_APC");
    case (_vehType isKindOf "Wheeled_APC_F");
    case (_vehType isKindOf "Tank"): {
        _crewType = getText (_sideUnitConfig >> QGVAR(crewArmor));
        };
    default {
        _crewType = (getArray (_sideUnitConfig >> QGVAR(createUnits))) param [0, "#"];
    }
};

private _newVehicle = createVehicle [_vehType, _posATL, [], 0, _createArg];
TRACE_3("Created Vic",_newVehicle,_vehType,_crewType);
_newVehicle setVariable ["F_Gear", "Empty", true]; // Clear gear on these [BWMF]
[_newVehicle] call EFUNC(core,addToCurator);

[_side, _newVehicle, _crewType, true] spawn FUNC(createCrew);
