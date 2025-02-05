#include "../script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This function draws debug information for post drier death vehicle coasting
*
* Arguments:
* None
*
* Return:
* None
*
* Example:
* [] call potato_vehicleCoasting_fnc_debugDraw;
*//***************************************************************************/
private _time = CBA_missionTime;
{
    _y params ["_vehicle", "_timeStart", "_timeEnd"];
    drawIcon3D ["\A3\ui_f\data\map\markers\military\dot_CA.paa",
        switch (true) do {
            case (_time < _timeStart): {[0, 0, 0.8, 1]};
            case (_time < _timeEnd): {[0, 0.8, 0, 1]};
            default {[0.8, 0, 0, 1]};
        }, [0, 0, 2.5] vectorAdd ASLToAGL getPosWorldVisual _vehicle, 1, 1, 0,
        format ["Time left: %1 | spd: %2", _timeEnd - _time, speed _vehicle], 0, 0.05,
        "RobotoCondensedBold", "right"];
} forEach GVAR(dev_traceHash);
