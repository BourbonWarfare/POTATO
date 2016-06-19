#include "script_component.hpp"
TRACE_1("params",_this);
params ["_unit"];

isNil "_unit"
        || {isNull _unit}
        || {!(alive _unit)}
        || {isPlayer _unit}
        || {_unit getVariable ["potato_aiFrameworks_vcom_disabledUnit",false]}
        || {!potato_aiFrameworks_vcom_applyToPlayerLedGroups && {isPlayer (leader _unit)}}
