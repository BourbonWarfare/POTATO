#include "..\script_component.hpp"
/*
 * Client init for minefield markers
 *
 * Arguments:
 * None
 *
 * Returns:
 * None
 *
 * Examples:
 * call potato_missionModules_fnc_minefield_clientInit
 */

private _mineFields = allMapMarkers select {
    private _brush = markerBrush _x;
    _brush == QGVAR(actualMinefieldV1)
};
if (_mineFields isEqualTo []) exitWith {};

GVAR(minefield_markers) = _mineFields;
call FUNC(minefield_clientLoop);
