#include "script_component.hpp"
/*
 * Author: PabstMirror
 * Called where module is local (zeus), passes vehicle type and side to HC
 *
 * Examples:
 * [[0,0,0], "somevic", west] call potato_zeusHC_fnc_autoModule_module
 */

params ["_posASL", "_vehType", "_side"];
TRACE_3("autoModule_module",_posASL,_vehType,_side);

[[_posASL, _vehType, _side], QFUNC(autoModule_createLocal)] call FUNC(hcPassthrough);
