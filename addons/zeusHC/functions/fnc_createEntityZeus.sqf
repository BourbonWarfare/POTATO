#include "script_component.hpp"

params ["_logic"];
TRACE_1("params",_logic);
if (isNull _logic) exitWith {};

private _posATL = getPosATL _logic;
private _typeOf = typeOf _logic;
TRACE_2("",_posATL,_typeOf);

if (time > 0) then {
    [FUNC(createEntityServer), [_posATL, _typeOf]] call CBA_fnc_directCall;
} else {
    [{
        (diag_tickTime > (_this select 2)) || {time > 0}
    }, {
        [FUNC(createEntityServer), _this] call CBA_fnc_directCall;
    },
    [_posATL, _typeOf, (diag_tickTime + 10 + random 10)]] call ACEFUNC(common,waitUntilAndExecute);
};

deleteVehicle _logic;
