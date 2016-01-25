/*
 * Render element update routine for Groups and Specific units.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 */
#include "script_component.hpp"

private _newDrawCache = [];
private _unitsProcessed = [];
private _shownFactions = [GVAR(factionVisibilitySettings), toLower faction player] call EFUNC(datastructures,map_get);

if (isNil "_shownFactions" || {_shownFactions isEqualTo []}) exitWith {
    GVAR(drawCache) = [];
};

private _fnc_generateDrawCacheElement = {
    params ["_unit", ["_markerSettings", [], [[]]]];
    _markerSettings params [
        ["_icon", "\A3\ui_f\data\map\markers\nato\b_unknown.paa", [""]],
        ["_color", [1, 1, 1, 1], [[]]],
        ["_size", [24, 24], [[]]],
        ["_textLeft", "", [""]],
        ["_textRight", "", [""]]
    ];
    [
        getPos _unit,
        _icon,
        _color,
        _size,
        _textLeft,
        _textRight
    ]
};

{
    private _groupName = groupId _x;
    private _groupLeader = leader _x;
    if ((toLower faction _groupLeader) in _shownFactions) then {
        private _groupMarkerSettings = [GVAR(groupMarkerSettings), _groupName] call EFUNC(datastructures,map_get);
        if (!isNil "_groupMarkerSettings") then {
            _newDrawCache pushBack ([_groupLeader, _groupMarkerSettings] call _fnc_generateDrawCacheElement);
            _unitsProcessed pushBack _groupLeader;
        } else {
            if (!GVAR(drawOnlyDefinedGroups)) then {
                _newDrawCache pushBack ([_groupLeader, [nil, nil, nil, nil, _groupName]] call _fnc_generateDrawCacheElement);
                _unitsProcessed pushBack _groupLeader;
            }
        };
    };
    nil
} count allGroups;

{
    // If already a cached marker for this unit exists, don't cache settings for a unit specific marker
    if (!(_x in _unitsProcessed) && {(toLower faction _x) in _shownFactions}) then {
        private _unitName = vehicleVarName _x;
        private _unitMarkerSettings = [GVAR(unitMarkerSettings), _unitName] call EFUNC(datastructures,map_get);
        if (!isNil "_unitMarkerSettings") then {
            _newDrawCache pushBack ([_x, _unitMarkerSettings] call _fnc_generateDrawCacheElement);
        };
    };
    nil
} count allUnits;

GVAR(drawCache) = _newDrawCache;
