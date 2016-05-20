#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

if !(local _unit) exitWith {};

if (VGVAR(earsEnabled)) then {
    _unit addEventHandler ["Fired",{_this call VFUNC(hearingAids);}];
};

if (VGVAR(advancedSuppression)) then {
    _unit addEventHandler ["Fired",{_this call VFUNC(suppressingShots);}];
};

if (isPlayer _unit) exitWith {};

if ((side _unit) in VGVAR(executionEnabledSides) && {!(_unit getVariable [VQGVAR(disabledUnit),false])}) then {
    [VFUNC(addToSystemDelayed), [_unit]] call CBA_fnc_execNextFrame; //delay by a single frame for stability
};
