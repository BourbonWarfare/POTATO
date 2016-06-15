#include "script_component.hpp"

params ["_config","_default"];

if (isNumber _config) exitWith { str (getNumber _config) };

str _default
