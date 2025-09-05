#include "script_component.hpp"

if (hasInterface) then {
    [["Potato", "Forestry"],
        "potato_forestry_id_1", //replace with BW specific
        ["Cut Down Tree", "Commit nature abuse"],
        "",
        {call FUNC(doChop)}
    ] call CBA_fnc_addKeybind;

/*
    [["Potato", "Forestry"],
        "potato_forestry_id_2", //replace with BW specific
        ["Flatten Grass", "Commit nature abuse"],
        "",
        {call FUNC(doFlatten)}
    ] call CBA_fnc_addKeybind;
*/
};

// Server Event
[QGVAR(simulationEvent), {
    params ["_object"];

    hideObjectGlobal _object;
    _object enableSimulationGlobal false;

}] call CBA_fnc_addEventHandler;