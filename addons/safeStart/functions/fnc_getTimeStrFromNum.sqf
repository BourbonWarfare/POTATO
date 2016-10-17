#include "script_component.hpp"

params ["_number"];

if (_number < 10) then {
    format ["0%1", _number]
} else {
    str _number
}
