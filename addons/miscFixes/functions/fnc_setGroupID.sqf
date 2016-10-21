/*
 * Author: AACO
 * Sets callsign (groupID) on a global level. (Hopefully BIS will fix this eventually)
 * Note, depricated shim to CBA call
 *
 * Arguments:
 * 0: Group <GROUP>
 * 1: Value <STRING>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [grp1, "This is Group 1"] call potato_miscFixes_fnc_setGroupID;
 */

#include "script_component.hpp"
TRACE_1("params",_this);

WARNING("This method is depricated, and should be replaced with CBA_fnc_setCallsign");
_this call CBA_fnc_setCallsign;
