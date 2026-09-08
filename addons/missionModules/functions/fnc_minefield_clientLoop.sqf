#include "..\script_component.hpp"
/*
 * Client loop for minefield markers
 *
 * Arguments:
 * None
 *
 * Returns:
 * None
 *
 * Examples:
 * call potato_missionModules_fnc_minefield_clientLoop
 */
 
BEGIN_COUNTER(loop);
private _unit = ACE_player;
private _delay = 1.5;
if ((_unit call ace_common_fnc_isAwake)
    && {!(_unit isKindOf "VirtualMan_F")}
    && {private _vehicle = vehicle _unit; isTouchingGround _vehicle && {!(_vehicle isKindOf "Air")}}
) then {
    // get marker we are in, if any
    private _markerIndex = GVAR(minefield_markers) findIf { _unit inArea _x };
    if (_markerIndex == -1) exitWith {};
    private _marker = GVAR(minefield_markers) select _markerIndex;

    private _unitPos = ASLToAGL getPosASL _unit;
    private _markerPos = getMarkerPos _marker;
    // move virtual point inward towards the marker center, so that the mine is never placed on the edge of the minefield
    private _minePos = _unitPos vectorAdd ((_unitPos vectorFromTo _markerPos) vectorMultiply (3 + random 2));
    _minePos set [2, 0];

    [QGVAR(minefield_steppedInIt), [_unit, _minePos]] call CBA_fnc_serverEvent;
    _delay = 10;
} else {
    _delay = 5;
};
END_COUNTER(loop);

[FUNC(minefield_clientLoop), [], _delay] call CBA_fnc_waitAndExecute;
