#include "script_component.hpp"
/*
 * Author: AACO
 * Function used to update the player list
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [] call potato_spectate_fnc_updateList;
 *
 * Public: No
 */


#define ICON_DEAD "a3\Ui_F_Curator\Data\CfgMarkers\kia_ca.paa"
TRACE_1("updateList",_this);

private _newUnits = [];
private _newGroups = [];
private _newList = [
    [west, "west", localize "str_west", []],
    [east, "east", localize "str_east", []],
    [independent, "indy", localize "str_guerrila", []],
    [civilian, "civ", localize "str_civilian", []],
    [sideLogic, "spectators", "Spectators", []]
];

{
    private _group = _x;
    private _groupSide = side _group;
    private _groupInfo = [_group, str _group, groupId _group];
    private _unitsInfo = [];

    {
        if ((_x isKindOf QGVAR(spectator) && {isPlayer _x}) || (simulationEnabled _x && {!isObjectHidden _x} && {simulationEnabled vehicle _x} && {!isObjectHidden vehicle _x})) then {
            _newUnits pushBack ([_x] call BIS_fnc_objectVar);
            _unitsInfo pushBack [
                _x,
                alive _x,
                _x getVariable ["ACE_isUnconscious", false],
                [_x] call FUNC(getName)
            ];
        };

        nil
    } count (units _x); // count used for speed, ensure nil above this line

    if !(_unitsInfo isEqualTo []) then {
        _newGroups pushBack (str _group);
        {
            if (_groupSide == (_newList select _forEachIndex) select 0) exitWith {
                ((_newList select _forEachIndex) select 3) pushBack [_groupInfo, _unitsInfo];
            };
        } forEach _newList;
    };
    nil
} count (allGroups + [GVAR(group)]); // count used for speed, ensure nil above this line

TRACE_1("New List:",_newList);

if !(GVAR(curList) isEqualTo _newList) then {
    // Remove groups/units that are no longer there
    for "_sideIndex" from (LIST tvCount []) to 1 step -1 do {
        for "_groupIndex" from (LIST tvCount [_sideIndex - 1]) to 1  step -1 do {
            for "_unitIndex" from (LIST tvCount [_sideIndex - 1, _groupIndex - 1]) to 1 step -1 do {
                private _lookup = _newUnits find (LIST tvData [_sideIndex - 1, _groupIndex - 1, _unitIndex - 1]);
                if (_lookup < 0) then {
                    LIST tvDelete [_sideIndex - 1, _groupIndex - 1, _unitIndex - 1];
                } else {
                    _newUnits deleteAt _lookup;
                };
            };
            private _lookup = _newGroups find (LIST tvData [_sideIndex - 1, _groupIndex - 1]);
            if (_lookup < 0) then {
                LIST tvDelete [_sideIndex - 1, _groupIndex - 1];
            } else {
                _newGroups deleteAt _lookup;
            };
        };
    };

    // Hash location lookups, note hashing assumes unique group/unit data
    private _groupDataToPathHash = [[], []];
    private _unitDataToPathHash = [[], []];

    for "_sideIndex" from 0 to ((LIST tvCount []) - 1) do {
        for "_groupIndex" from 0 to ((LIST tvCount [_sideIndex]) - 1) do {
            (_groupDataToPathHash select 0) pushBack (LIST tvData [_sideIndex, _groupIndex]);
            (_groupDataToPathHash select 1) pushBack [_sideIndex, _groupIndex];
            for "_unitIndex" from 0 to ((LIST tvCount [_sideIndex, _groupIndex]) - 1) do {
                (_unitDataToPathHash select 0) pushBack (LIST tvData [_sideIndex, _groupIndex, _unitIndex]);
                (_unitDataToPathHash select 1) pushBack [_sideIndex, _groupIndex, _unitIndex];
            };
        };
    };

    // Update/add the values
    {
        _x params ["_side", "_sideStr", "_sideTitle", "_nestedGroupData"];
        private _sideIndex = _forEachIndex;
        private _sideColor = if (_side != sideLogic) then { 
            [_side] call BIS_fnc_sideColor
        } else {
            [0.7,0.6,0,1]
        };

        if (LIST tvCount [] == _sideIndex) then {
            LIST tvAdd [[], _sideTitle];
            LIST tvSetData [[_sideIndex], _sideStr];
        };

        LIST tvExpand [_sideIndex];

        {
            _x params ["_groupInfo", "_nestedUnitData"];
            _groupInfo params ["_group", "_groupStr", "_groupId"];

            private _groupIndex = -1;
            private _lookup = (_groupDataToPathHash select 0) find _groupStr;
            if (_lookup < 0) then {
                _groupIndex = LIST tvAdd [[_sideIndex], _groupId];
                LIST tvSetData [[_sideIndex, _groupIndex], _groupStr];
                LIST tvSetTooltip [[_sideIndex, _groupIndex], _groupId];

                if (_group getVariable [QEGVAR(markers,addMarker), false]) then {
                    LIST tvSetPicture [[_sideIndex, _groupIndex], _group getVariable [QEGVAR(markers,markerTexture), ""]];
                    LIST tvSetPictureColor [[_sideIndex, _groupIndex], _group getVariable [QEGVAR(markers,markerColor), [0,0,0,0]]];
                    LIST tvSetPictureColorSelected [[_sideIndex, _groupIndex], _group getVariable [QEGVAR(markers,markerColor), [0,0,0,0]]];
                } else {
                    private _leader = leader _group;
                    if (_leader getVariable [QEGVAR(markers,addMarker), false]) then {
                        LIST tvSetPicture [[_sideIndex, _groupIndex], _leader getVariable [QEGVAR(markers,markerTexture), ""]];
                        LIST tvSetPictureColor [[_sideIndex, _groupIndex], _leader getVariable [QEGVAR(markers,markerColor), [0,0,0,0]]];
                        LIST tvSetPictureColorSelected [[_sideIndex, _groupIndex], _leader getVariable [QEGVAR(markers,markerColor), [0,0,0,0]]];
                    };
                };

                LIST tvExpand [_sideIndex, _groupIndex];
            } else {
                // pop data out of hash to improve later lookups
                (_groupDataToPathHash select 0) deleteAt _lookup;
                private _path = (_groupDataToPathHash select 1) deleteAt _lookup;
                _groupIndex = _path select 1;

                LIST tvSetText [_path, _groupId];
                LIST tvSetTooltip [_path, _groupId];

                if (_group getVariable [QEGVAR(markers,addMarker), false]) then {
                    LIST tvSetPicture [[_sideIndex, _groupIndex], _group getVariable [QEGVAR(markers,markerTexture), ""]];
                    LIST tvSetPictureColor [[_sideIndex, _groupIndex], _group getVariable [QEGVAR(markers,markerColor), [0,0,0,0]]];
                    LIST tvSetPictureColorSelected [[_sideIndex, _groupIndex], _group getVariable [QEGVAR(markers,markerColor), [0,0,0,0]]];
                } else {
                    private _leader = leader _group;
                    if (_leader getVariable [QEGVAR(markers,addMarker), false]) then {
                        LIST tvSetPicture [[_sideIndex, _groupIndex], _leader getVariable [QEGVAR(markers,markerTexture), ""]];
                        LIST tvSetPictureColor [[_sideIndex, _groupIndex], _leader getVariable [QEGVAR(markers,markerColor), [0,0,0,0]]];
                        LIST tvSetPictureColorSelected [[_sideIndex, _groupIndex], _leader getVariable [QEGVAR(markers,markerColor), [0,0,0,0]]];
                    };
                };
            };

            {
                _x params ["_unit", "_isAlive", "_isIncapacitated", "_name"];

                private _tooltip = format ["%1 - %2", _name, _groupId];
                private _texture = [_isAlive, _isIncapacitated, _unit] call {
                    if !(_this select 0) exitWith { ICON_DEAD };
                    if (_this select 1) exitWith { QPATHTOF(data\revive_icon.paa) };
                    [_this select 2] call ACEFUNC(common,getVehicleIcon)
                };
                private _unitColor = _unit getVariable [QGVAR(oldSideColor), _sideColor];

                private _lookup = (_unitDataToPathHash select 0) find ([_unit] call BIS_fnc_objectVar);
                if (_lookup < 0) then {
                    private _unitIndex = LIST tvAdd [[_sideIndex, _groupIndex], _name];
                    LIST tvSetData [[_sideIndex, _groupIndex, _unitIndex], [_unit] call BIS_fnc_objectVar];
                    LIST tvSetPicture [[_sideIndex, _groupIndex, _unitIndex], _texture];
                    LIST tvSetPictureColor [[_sideIndex, _groupIndex, _unitIndex], _unitColor];
                    LIST tvSetTooltip [[_sideIndex, _groupIndex, _unitIndex], _tooltip];
                } else {
                    // pop data out of hash to improve later lookups
                    (_unitDataToPathHash select 0) deleteAt _lookup;
                    private _path = (_unitDataToPathHash select 1) deleteAt _lookup;
                    LIST tvSetText [_path, _name];
                    LIST tvSetPicture [_path, _texture];
                    LIST tvSetPictureColor [_path, _unitColor];
                    LIST tvSetTooltip [_path, _tooltip];
                };
                nil
            } count _nestedUnitData; // count used for speed, ensure nil above this line
            nil
        } count _nestedGroupData; // count used for speed, ensure nil above this line
    } forEach _newList;

    // set the new list as the current list
    GVAR(curList) = _newList;
};

// Update focus if required
[] call FUNC(updateListFocus);
