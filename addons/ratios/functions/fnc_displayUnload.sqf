/*
 * Author: AACO
 * Function used to stop the update to the ratio controls
 * Should only be called from UI events
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

SET_UI_VAR(loaded,false);
