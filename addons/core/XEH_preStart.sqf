#include "script_component.hpp"

#include "XEH_PREP.hpp"

private _notLoaded = configProperties [configfile >> "potato_notLoaded", "isText _x"];
{
    WARNING_2("[%1] not loaded because %2",configName _x, getText (_x));
} forEach _notLoaded;
