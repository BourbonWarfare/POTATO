#include "script_component.hpp"

if (hasInterface) then {
    [["Potato", "Forestry"],
        "potato_forestry_id_1", //replace with BW specific
        ["Cut Down Tree", "Commit nature abuse"],
        "",
        {
            if !([ACE_player, objNull, ["isNotSwimming", "isNotOnLadder"]] call ACEFUNC(common,canInteractWith)) exitWith { false };
            if !([ACE_player] call FUNC(canChop)) exitWith { false };
            call FUNC(doChop)
        }
    ] call CBA_fnc_addKeybind;
};

// Server Event
[QGVAR(simulationEvent), {
    params ["_object"];

    hideObjectGlobal _object;
    _object enableSimulationGlobal false;

}] call CBA_fnc_addEventHandler;
