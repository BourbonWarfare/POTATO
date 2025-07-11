// createGroup
#include "script_component.hpp"

params ["_factoryLogic", "_side", "_placeLogic"];
TRACE_3("createGroup",_factoryLogic,_side,_placeLogic);

private _soldierList = getArray (configFile >> "CfgVehicles" >> (typeOf _placeLogic) >> QGVAR(soldierList));

private _transportType = _placeLogic getVariable [QGVAR(transportType), 0];
([_factoryLogic,_transportType,_side] call FUNC(getTransportType)) params ["_vehType"];
private _maxCargoRoom = 20;
if (_vehType != "") then {
    _maxCargoRoom = _maxCargoRoom min (([_vehType] call FUNC(getSeatInfo)) # 1);
};

private _useNoLambs = _placeLogic getVariable [QGVAR(useNoLAMBS), false];
if (_useNoLambs) then {
    switch (_side) do {
        case (west): {_soldierList = _soldierList apply {"potato_noLambs_w_"+_x};};
        case (east): {_soldierList = _soldierList apply {"potato_noLambs_e_"+_x};};
        case (resistance): {_soldierList = _soldierList apply {"potato_noLambs_i_"+_x};};
    };
} else {
    switch (_side) do {
        case (west): {_soldierList = _soldierList apply {"potato_w_"+_x};};
        case (east): {_soldierList = _soldierList apply {"potato_e_"+_x};};
        case (resistance): {_soldierList = _soldierList apply {"potato_i_"+_x};};
    };
};

if ((count _soldierList) > _maxCargoRoom) then {
    TRACE_2("trimming large group to fit in vic",count _soldierList,_maxCargoRoom);
    _soldierList resize _maxCargoRoom
};
if (_soldierList isEqualTo []) exitWith {
    WARNING_3("bad side/size [%1-%2-%3]",_side,_vehType,_maxCargoRoom);
    ["possible factory issue"] call EFUNC(zeusHC,sendCuratorHint);
    []
};
if (!([_side, count _soldierList, false] call EFUNC(zeusHC,canCreateGroup))) exitWith {
    TRACE_2("canCreateGroup was false",_side,_soldierList);
    []
};

private _group = createGroup [_side, true]; // explicitly mark for cleanup

private _unitType = _soldierList deleteAt 0; // Create Leader Now
private _unit = _group createUnit [_unitType, (_factoryLogic getPos [10, random 360]), [], 0, "NONE"];
[_unit] call EFUNC(core,addToCurator);
_group selectLeader _unit;
_unit setDir (_factoryLogic getDir _placeLogic);

if ((isNull _group) || {isNull leader _group}) exitWith {
    ERROR_1("failed to create group [%1]",_group);
    []
};

// Set group ID
private _factoryID = _factoryLogic getVariable [QGVAR(factoryID), -1];
private _groupCount = _factoryLogic getVariable [QGVAR(groupCount), 0];
_groupCount = _groupCount + 1;
_group setGroupIdGlobal [format ["Factory %1-%2", _factoryID, _groupCount]];
_factoryLogic setVariable [QGVAR(groupCount), _groupCount];


// return
[_placeLogic, _group, _soldierList]
