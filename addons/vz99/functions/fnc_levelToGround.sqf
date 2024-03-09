/*
 * Author: PabstMirror
 * "Levels" the mortar to account for ground slope
 *
 * Arguments:
 * 0: Mortar Vehicle <OBJECT>
 * 1: Desired Starting Gun Dir (degrees) or false to skip <SCALAR><BOOL><OPTIONAL>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [mortar, 45] call potato_vz99_fnc_levelToGround
 *
 * Public: No
 */
#include "script_component.hpp"

params ["_mortarVeh", ["_desiredAngle", false, [false, 0]]];
TRACE_2("params",_mortarVeh,_desiredAngle);

private _vUp = vectorUp _mortarVeh;
(_vUp call CBA_fnc_vect2Polar) params ["", "_dir", "_elev"];

TRACE_2("",_dir,_elev);

private _angleDiff = ((_dir - (getDir _mortarVeh)) + 180) % 360 - 180;
TRACE_3("dir",_dir,getDir _mortarVeh,_angleDiff);
if (abs(_angleDiff) > 1) then {
    _mortarVeh setDir _dir;
    _mortarVeh setVectorUp _vUp;
};

private _neededElev = (90 - _elev) / 180;
TRACE_2("level",_neededElev,_mortarVeh animationPhase "level");
if ((abs(_neededElev - (_mortarVeh animationPhase "level"))) > 0.01) then {
    _mortarVeh animate ["level", _neededElev, true];
};

if (_desiredAngle isEqualType 0) then {
    private _angDiff = {
        params ["_a", "_b"];
        private _ret = _a - _b;
        while {_ret < -180} do {_ret = _ret + 360};
        while {_ret > 180} do {_ret = _ret - 360};
        _ret
    };
    private _dirFix = [_desiredAngle, (getDir _mortarVeh)] call _angDiff;
    TRACE_3("turretDir",_desiredAngle,(getDir _mortarVeh),_dirFix);
    if ((abs _dirFix) > 1) then {
        _mortarVeh animate ["dirFix", (0.5 - (_dirFix / 360)), true];
    };
};
