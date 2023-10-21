#include "script_component.hpp"

[QGVAR(setVelocity), {
    params ["_vehicle", "_velocity"];

    _vehicle setVelocity _velocity;

}] call CBA_fnc_addEventHandler;

