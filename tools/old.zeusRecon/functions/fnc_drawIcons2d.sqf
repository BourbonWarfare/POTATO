#include "script_component.hpp"

params ["_mapCtrl"];

{
    _x params ["_isInfantry", "_grpPositionAverage", "", "_spotTimeString", "", "_icon"];

    if (_isInfantry) then {
        _mapCtrl drawIcon ["\A3\ui_f\data\map\markers\nato\o_inf.paa", [1,0.4,0.1,1], _grpPositionAverage, 32, 32, 0, ""];
        _mapCtrl drawIcon [_icon, [1,1,1,0.75], _grpPositionAverage, 50, 50, 0, ""]; // size icon
    } else {
        _mapCtrl drawIcon [_icon, [1,0.4,0.1,0.75], _grpPositionAverage, 32, 32, 0, ""];
    };
    _mapCtrl drawIcon ["#(argb,8,8,3)color(0,0,0,0)", [0,0,0,1], _grpPositionAverage, 32, 32, 0, _spotTimeString, 1, 0.03, "TahomaB", "right"];
} forEach GVAR(targetGroups);
