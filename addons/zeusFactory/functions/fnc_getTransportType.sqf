// getTransportType
#include "script_component.hpp"

params ["_factoryLogic", "_transportType", "_side"];
TRACE_3("getTransportType",_factoryLogic,_transportType,_side);

private _vehType = "";
switch (_transportType) do {
case TRANSPORT_CAR_RTB;
case TRANSPORT_CAR_FOLLOW: {_vehType = _factoryLogic getVariable [QGVAR(carType), ""]};
case TRANSPORT_APC_RTB;
case TRANSPORT_APC_FOLLOW: {_vehType = _factoryLogic getVariable [QGVAR(apcType), ""]};
case TRANSPORT_HELI;
case TRANSPORT_PARADROP: {_vehType = _factoryLogic getVariable [QGVAR(heliType), ""]};
};

private _crewType = ["vicd", "pilot"] select (_vehType isKindOf "Air");
_crewType = switch (_side) do {
case (west): {"potato_w_" + _crewType};
case (east): {"potato_e_" + _crewType};
case (resistance): {"potato_i_" + _crewType};
};

private _maxCargoRoom = 99;
private _addGunner = false;

if (_vehType != "") then {
    _maxCargoRoom = ([_vehType, true] call BIS_fnc_crewCount) - 1;
    if (_transportType in [TRANSPORT_APC_RTB, TRANSPORT_APC_FOLLOW]) then {
        _addGunner = true;
        _maxCargoRoom = _maxCargoRoom - 1;
    };
};

// Return:
[_vehType, _crewType, _maxCargoRoom, _addGunner]
