#include "script_component.hpp"

// fix Error in expression <layer getVariable "concentrationParam") <= 0.15};
if (fileExists "WebKnight_StarWars_Mechanic\bootstrap\XEH_postInit.sqf") then {
    INFO("trying to fix webknight melee popup");
    ["unit", {
        if (isNil {player getVariable "concentrationParam"}) then {
            INFO("fixing webknight melee popup");
            player setVariable ["concentrationParam", 0.5];
        };
    }, true] call CBA_fnc_addPlayerEventHandler;
};
