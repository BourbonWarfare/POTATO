#include "script_component.hpp"
TRACE_1("params",_this);

params ["_list","_object"];

private _fnc_getPosition = {
    params ["_object"];

    private _position = [];

    if (_object isEqualType objNull) then {
        _position = getPosWorld _object;
    } else {
        if (_object isEqualType "STRING") then {
            _position = getMarkerPos _object;
        } else {
            if (_object isEqualType [] && (count _object) == 3) then {
                _position = _object;
            };
        };
    };

    _position
};

private _position = [_object] call _fnc_getPosition;
if ((count _position) != 3) exitWith { objNull };

private _minRange = 0;
private _returnObject = objNull;

{
    private _comparePosition = [_x] call _fnc_getPosition;

    if ((count _comparePosition) == 3) then {
        private _range = _comparePosition distance _position;
        if (_range < _minRange || {isNull _returnObject}) then {
            private _minRange = _range;
            private _returnObject = _x;
        };
    };
    nil
} count _list;

_returnObject
