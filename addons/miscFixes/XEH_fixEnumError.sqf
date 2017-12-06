// Since 1.78 arma reports a enum error due to ace_movement checking `loadCoef`
// We probably will not be changing this unit trait, so can just pre-fill with the default value

#include "script_component.hpp"

INFO("Add player changed EH for loadCoef");

["unit", {
    LOG("Setting player var ace_movement_loadCoef");
    (_this select 0) setVariable ["ace_movement_loadCoef", 1];
}, true] call CBA_fnc_addPlayerEventHandler;
