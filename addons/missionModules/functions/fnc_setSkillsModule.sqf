/*
 * Author: AACO
 * Function used to open the UI from the zeus module
 * should only be called from module scripting
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_logic"];

if (local _logic) then {
    createDialog QGVAR(setSkills);
    deleteVehicle _logic;
};
