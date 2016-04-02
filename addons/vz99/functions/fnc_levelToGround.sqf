/*
 * Author: PabstMirror
 *
 *
 * Arguments:
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call
 *
 * Public: No
 */
#include "script_component.hpp"

params ["_mortarVeh"];
TRACE_1("params", _mortarVeh);

private _vUp = vectorUp _mortarVeh;
(_vUp call CBA_fnc_vect2Polar) params ["", "_dir", "_elev"];

TRACE_3("",_dir,_elev);

private _angleDiff = ((_dir - (getDir _mortarVeh)) + 180) % 360 - 180;
TRACE_3("dir",_dir,getDir _mortarVeh,_angleDiff);
if (abs(_angleDiff) > 1) then {
    _mortarVeh setDir _dir;
    _mortarVeh setVectorUp _vUp;
};

private _neededElev = (90 - _elev) / 180;
TRACE_2("level",_neededElev,_mortarVeh animationPhase "level");
if ((abs(_neededElev - (_mortarVeh animationPhase "level"))) > 0.01) then {
    _mortarVeh animate ["level", _neededElev];
};
