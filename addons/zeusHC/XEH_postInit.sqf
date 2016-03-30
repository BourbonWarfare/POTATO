#include "script_component.hpp"

[QGVAR(createEntity), {_this call FUNC(createEntityLocal)}] call ace_common_fnc_addEventHandler;

[false] spawn FUNC(transferGroupsToHC);
