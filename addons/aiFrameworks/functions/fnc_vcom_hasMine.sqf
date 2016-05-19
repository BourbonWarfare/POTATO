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

private _magazines = magazinesAmmo _unit;
{
    private _magazine = _x select 0;
    private _magazineLower = toLower _magazine;

    private _isSatchel = "satchelcharge" in _magazineLower;
    private _isDemo = "democharge" in _magazineLower;
    private _isWiredMine = "wired" in _magazineLower;
    private _isRemoteMine = "remote" in _magazineLower;
    private _isClaymore = "claymore" in _magazineLower;

    switch (true) do {
        case ("satchelcharge" in _magazineLower): {
            [_unit,"SatchelCharge_F",_magazine] call _fnc_setBomb;
            private _bomb = "SatchelCharge_F";
        };
        case ("democharge" in _magazineLower): {
            [_unit,"Democharge_F",_magazine] call _fnc_setBomb;
        };
        case ("wired" in _magazineLower): {
        };
        case ("remote" in _magazineLower): {
        };
        case ("claymore" in _magazineLower): {
        };
    }

    switch (_nameSound) do {
        case ("satchelcharge"): {
            private _isDemo = "democharge" in _magazineLower;
            private _isSatchel = "satchelcharge" in _magazineLower;

        };
        case ("mine"): {
            //code
        };
    };

    if (_value isEqualTo "satchelcharge") then
    {
        _SubtractAmount = 0;
        _DemoCharge = ["DemoCharge",_Magazine,false] call BIS_fnc_inString;
        _SatchelCharge = ["SatchelCharge",_Magazine,false] call BIS_fnc_inString;

        if (_DemoCharge || {_SatchelCharge}) then
        {
        _Bomb = "Democharge_F";

        };

    };
    if (_value isEqualTo "mine") then
    {
        _SubtractAmount = 0;
        _IsWired = ["wire",_Magazine,false] call BIS_fnc_inString;
        _IsRemote = ["remote",_Magazine,false] call BIS_fnc_inString;
        _IsClaymore = ["Claymore",_Magazine,false] call BIS_fnc_inString;
        if (_IsWired) then {_SubtractAmount = -9} else {_SubtractAmount = -10};
        if (_IsRemote) then {_SubtractAmount = -11};
        _MineName = [_Magazine,0,_SubtractAmount] call BIS_fnc_trimString;
        if (_IsClaymore) then {_MineName = "Claymore_F"};
        _Unit setVariable ["Vcom_MineObjectMagazine",_Magazine,false];
        _Unit setVariable ["VCOM_HasMine",true,false];
    };
    nil
} count _magazines;
