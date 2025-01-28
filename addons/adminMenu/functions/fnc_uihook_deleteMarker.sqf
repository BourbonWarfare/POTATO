#include "script_component.hpp"
/*
 * Author: Lambda.Tiger
 * Attach marker to a unit based on currrent selections in the admin menu;
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Examples:
 * [] call potato_adminMenu_uihook_attachMarkerUnit;
 *
 * Public: No
 */

private _markerList = UI_TAB_MARKERS_MARKERS;
private _selectedMarkerIndex = lbCurSel _markerList;
if (_selectedMarkerIndex < 0) exitWith {
    TRACE_1("Marker not selected",_selectedMarkerIndex);
};
private _hashKey = _markerList lbData _selectedMarkerIndex;

TRACE_1("Found marker hash",_hashKey);

[QEGVAR(markers,deleteMarker), [_hashKey]] call CBA_fnc_globalEvent;

["potato_adminMsg", [
    format ["Deleting marker: %1", _hashKey],
    profileName
]] call CBA_fnc_globalEvent;
[0, UI_TABS_INDEX_MARKERS] call FUNC(uihook_tabChange);
