/*
 * Author: AACO
 * Function used to prep the UI functions, populate/configure the ratio UI,
 * and call the UI update function
 * Should only be called from UI events
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

// display shouldn't load if there's no interface, but belt & suspenders
if (!hasInterface) exitWith { LOG("no interface, exiting"); };

// set defaults for pseduo GVARs
SET_UI_VAR(loaded,true);

// prepare functions used by the calculator
// (using the normal prestart/preinit method does not work in this environment)
PREP(displayUpdate);

// disable control displaying incorrect value
OLD_PLAYER_DISPLAY ctrlShow false;

// while the display is loaded, update the display
waitUntil { [] call FUNC(displayUpdate) };
