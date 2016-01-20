#include "script_component.hpp"

params ["_unit", "", "", "", "", "", "_bullet"];

if (local _unit) then {
    deleteVehicle _bullet;
};