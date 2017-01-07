#include "script_component.hpp"

if (GVAR(enabled) && hasInterface) then {
    // setup babel
    GVAR(availableLanguages) = [];
    {
        GVAR(availableLanguages) pushBack (_x select 0);
    } forEach EGVAR(radios,availableLanguages);

    [ // add fired EH to unit
        "CAManBase",
        "init",
        FUNC(handleCreated),
        true, // allow inheritence
        [], // don't exclude classes
        true // run on existing units
    ] call CBA_fnc_addClassEventHandler;

    GVAR(boundingBoxCache) = call CBA_fnc_createNamespace;
    GVAR(vehicleIconCache) = call CBA_fnc_createNamespace;
};
