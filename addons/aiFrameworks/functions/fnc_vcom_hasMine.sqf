#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

private _fnc_addToArray = {
    params ["_unit","_object","_arrayVar"];

    private _array = _unit getVariable [_arrayVar, []];
    _array pushBack _object;
    _unit setVariable [_arrayVar, _array];
};

private _fnc_setBomb = {
    params ["_unit","_bomb","_magazine"];

    [_unit,_bomb,VQGVAR(bombObjectArray)] call _fnc_addToArray;
    [_unit,_magazine,VQGVAR(bombMagazineArray)] call _fnc_addToArray;
};

{
    private _magazine = _x select 0;
    private _magazineLower = toLower _magazine;

    switch (getText (configfile >> "CfgMagazines" >> _Magazine >> "nameSound")) do {
        case ("satchelcharge"): {
            private _bombName = if ("satchelcharge" in _magazineLower) then {
                "SatchelCharge_F"
            } else {
                "Democharge_F"
            };

            [_unit,[_bombName,_magazine],VQGVAR(bombArray)] call _fnc_addToArray;
        };
        case ("mine"): {
            private _mineName = switch (true) do {
                case ("wired" in _magazineLower): {
                    [_magazine, 0, -9] call BIS_fnc_trimString
                };
                case ("remote" in _magazineLower): {
                    [_magazine, 0, -11] call BIS_fnc_trimString
                };
                case ("claymore" in _magazineLower): {
                    "Claymore_F"
                };
                default {
                    [_magazine, 0, -10] call BIS_fnc_trimString
                };
            };

            [_unit,[_mineName,_magazine],VQGVAR(mineArray)] call _fnc_addToArray;
        };
    };

    nil
} count (magazinesAmmo _unit);
