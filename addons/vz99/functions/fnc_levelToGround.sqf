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

systemChat format ["elev %1 - dir %2", _elev, _dir];

_mortarVeh setDir _dir;
_mortarVeh setVectorUp _vUp;
_mortarVeh animate ["level", (90 - _elev) / 180];

TRACE_3("leveled", _vUp, _dir, _elev);
