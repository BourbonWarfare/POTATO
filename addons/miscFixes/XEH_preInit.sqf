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


if (["WBK_ZombieCreatures"] call ACEFUNC(common,isModLoaded)) then {
    private _wbkZombiesBase = ["Zombie_Special_OPFOR_Leaper_1","Zombie_Special_OPFOR_Screamer","Zombie_Special_OPFOR_Boomer","Zombie_O_Crawler_CSAT","Zombie_O_Walker_CSAT","Zombie_O_Shambler_CSAT","Zombie_O_RunnerCalm_CSAT","Zombie_O_RunnerAngry_CSAT","Zombie_O_Shooter_CSAT"];
    {
        [_x, "init", {
            params ["_unit"];
            TRACE_1("disabling lambs on zombie creturd",_unit);
            _unit setVariable ["lambs_danger_disableAI", true];
        }] call CBA_fnc_addClassEventHandler;
    } forEach _wbkZombiesBase;
};
