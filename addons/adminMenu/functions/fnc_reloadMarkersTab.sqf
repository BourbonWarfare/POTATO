#include "script_component.hpp"
/*
 * Author: Lambda.Tiger
 * Reloads the markers  menu admin tab after at least a 0.1s delay
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Examples:
 * [] call potato_adminMenu_reloadMarkersTab;
 *
 * Public: No
 */
 [{
    [0, UI_TABS_INDEX_MARKERS] call FUNC(uihook_tabChange);
}, 0, 0.1] call CBA_fnc_waitAndExecute;
