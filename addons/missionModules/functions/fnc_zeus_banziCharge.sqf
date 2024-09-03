/*
 * Author: PabstMirror
 * Function used to trigger a bonzai charge for a group from the zeus module
 * should only be called from module scripting
 *
 * Public: No
 */

#include "script_component.hpp"

params ["_logic"];

if (!local _logic) exitWith {};
private _unit = _logic getVariable ["bis_fnc_curatorAttachObject_object",objNull];
TRACE_2("",_logic,_unit);

if ((!isNull _unit) || {alive _unit} || {_unit isKindOf "CaManBase"}) then {
    [QGVAR(banzi), [group _unit], [leader _unit]] call CBA_fnc_targetEvent;
} else {
    [objNull, "Place on unit"] call BIS_fnc_showCuratorFeedbackMessage;
};

deleteVehicle _logic;
