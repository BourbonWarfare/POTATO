#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

private _fnc_addToArray = {
    TRACE_1("inner params",_this);
    params ["_unit","_object","_arrayVar"];

    private _array = _unit getVariable [_arrayVar, []];
    _array pushBack _object;
    _unit setVariable [_arrayVar, _array];
};

{
    private _magazine = _x select 0;

    switch (getText (configfile >> "CfgMagazines" >> _Magazine >> "nameSound")) do {
        case ("satchelcharge"): {
            private _bombName = if (["satchelcharge",_magazine] call BIS_fnc_inString) then {
                "SatchelCharge_F"
            } else {
                "Democharge_F"
            };

            [_unit,[_bombName,_magazine],VQGVAR(bombArray)] call _fnc_addToArray;
        };
        case ("mine"): {
            private _mineName = switch (true) do {
                case (["wired",_magazine] call BIS_fnc_inString): {
                    [_magazine, 0, -9] call BIS_fnc_trimString
                };
                case (["remote",_magazine] call BIS_fnc_inString): {
                    [_magazine, 0, -11] call BIS_fnc_trimString
                };
                case (["claymore",_magazine] call BIS_fnc_inString): {
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

TRACE_2("",_unit getVariable VQGVAR(bombArray),_unit getVariable VQGVAR(mineArray));
