/*
 * Author: BadWolf
 *
 *
 * Arguments:
 *
 * Examples:
 * [] call potato_missionTesting_fnc_runWeaponsTest;
 *
 * Public: No
 */

#include "\a3\ui_f\hpp\definedikcodes.inc"
#include "script_component.hpp"
TRACE_1("Params",_this);

private _eh = addMissionEventHandler ["EachFrame", {
    private _unit = ACE_Player;
    private _posUnit = getPos _unit;
    private _beg = eyePos _unit; // Eye position of the player.
    private _end = (_beg vectorAdd (getCameraViewDirection _unit vectorMultiply 1000)); // Draw a line 1000 units long from the camera of the player.
    private _dir = getDir _unit;
    private _ins = terrainIntersectAtASL [_beg, _end]; // Get the position on the terrain where the line from the players camera intersects with the terrain.

    private _emptyPos = GVAR(DummyUnits) select 3;
    _emptyPos setPosASLW _ins; // Set the position of _emptyPos as the intersect point.

    // This section uses vector math to set the direction of the _emptyPos unit to mirror that of the player.
    private _v_unit = vectorDir _unit;
    private _v_vicUnit = vectorDir _emptyPos;
    private _v_diff = _v_vicUnit vectorDiff _v_unit;
    _emptyPos setVectorDir _v_diff;

    _dist = _unit distance _emptyPos;
    _disStr = str round _dist;

    drawIcon3D ["", [1,0,0,0.50], ASLToAGL _ins, 1, 1, 45, _disStr, 1, 0.1, "TahomaB"];
    [] spawn FUNC(updatePositionPID);
}];
