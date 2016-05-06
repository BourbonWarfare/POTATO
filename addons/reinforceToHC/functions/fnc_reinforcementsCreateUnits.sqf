/*
 * Author: AACO
 * Function called when the ARES reinforcement module is placed down
 *
 * Arguments:
 * 0: placed logic object <OBJECT>
 *
 * Return Value:
 * Always returns true <BOOL>
 *
 * Example:
 * [gameLogic] call potato_reinforceToHC_fnc_reinforcementsCreateUnits;
 *
 * Public: No
 */

#include "script_component.hpp"

params["_logic"];
TRACE_1("params",_logic);

[format["Starting module code '%1'", _logic]] call Ares_fnc_LogMessage;

// Cleanup the module if the script logic didn't tell us not to.
if ([_logic] call FUNC(setupReinforcements)) then {
    [format["Deleting '%1'", _logic]] call Ares_fnc_LogMessage;
    deleteVehicle _logic;
} else {
    ["Not deleting logic module."] call Ares_fnc_LogMessage;
};

[format["Finished module code '%1'", _logic]] call Ares_fnc_LogMessage;

// Return how happy we are (best practice)
true
