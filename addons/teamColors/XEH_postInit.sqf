#include "script_component.hpp"

if (hasInterface) then {
    player assignTeam (player getVariable [QGVAR(selectedTeam), 'MAIN']);
};
