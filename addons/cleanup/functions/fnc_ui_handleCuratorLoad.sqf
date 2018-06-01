/*
 * Author: AACO
 * Function used to register a handler to intercept and handle zeus delete events
 * Should only be called by UI Events
 *
 * Arguments:
 * 0: Display for registration <DISPLAY>
 *
 * Examples:
 * [jnkDsply] call potato_cleanup_fnc_ui_handleCuratorLoad;
 *
 * Public: No
 */

#include "script_component.hpp"

TRACE_1("params",_this);

if (GVAR(deadCleanupEnabled)) then {
    _this#0 displayAddEventHandler ["KeyDown", {_this call FUNC(ui_handleCuratorKeyDown)}];
};
