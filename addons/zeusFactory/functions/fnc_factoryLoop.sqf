#include "script_component.hpp"

params ["_args", "_pfID"];
_args params ["_factory", "_side", "_newGroupParams", "_activeGroups"];
if (isNull _factory) exitWith {
    INFO_1("ending factory loop for logic [%1]",_factory);
    [_pfID] call CBA_fnc_removePerFrameHandler;
};

// Filter groups
_activeGroups = _activeGroups select {
    (!isNull _x) && {({alive _x} count (units _x)) > 0}
};
_args set [3, _activeGroups];

// Fill out current group in progress
if (!(_newGroupParams isEqualTo [])) exitWith {
    _newGroupParams params ["_placeLogic", "_group", "_soldierList"];
    TRACE_3("_newGroupParams",_placeLogic,_group,_soldierList);

    if (_soldierList isEqualTo []) then {
        _args set [2, []]; // clear _newGroupParams
        [_factory, _placeLogic, _group, _side] call FUNC(dispatch);
        _activeGroups pushBack _group;
    } else {
        private _unitType = _soldierList deleteAt 0;
        private _unit = _group createUnit [_unitType, (getPos leader _group), [], 0, "FORM"];
        TRACE_3("added unit",_unit,_unitType,_group);
    };
};

// Check if we can handle a dispatch order
private _dispatchQueue = _factory getVariable [QGVAR(dispatchQueue), []];
if ((count _dispatchQueue) >= 1) exitWith {
    private _placeLogic = _dispatchQueue select 0;
    _newGroupParams = [_factory, _side, _placeLogic] call FUNC(createGroup);
    if (_newGroupParams isEqualTo []) then {
        TRACE_2("could not create new group",_placeLogic,_newGroupParams);
    } else {
        _args set [2, _newGroupParams];
    };
};

// TRACE_1("idle",time);
