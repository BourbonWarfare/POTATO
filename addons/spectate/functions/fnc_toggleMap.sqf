/*
 * Author: AACO
 * Function used to toggle the map
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [] call potato_spectate_fnc_toggleMap;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

if (GVAR(mapOpen)) then {
    MAP_DISPLAY ctrlShow false;
    MAP_GROUP ctrlShow false;

    ctrlSetFocus LIST;

    if (GVAR(currentCamIndex) == FREE_CAMERA) then {
        GVAR(cam) camCommand "manual on";
    };
} else {
    MAP_DISPLAY ctrlShow true;
    MAP_GROUP ctrlShow true;

    MAP_TITLE ctrlSetText (getMissionConfigValue ["onLoadName", getMissionConfigValue ["briefingName", "???"]]);
    MAP_SPEC_COUNT ctrlSetText str ({_x isKindOf QGVAR(spectator)} count allPlayers);

    MAP_DISPLAY ctrlMapAnimAdd [0, 0.05, getPosASLVisual GVAR(cam)];
    ctrlMapAnimCommit MAP_DISPLAY;

    GVAR(cam) camCommand "manual off";
};

// set map open var
GVAR(mapOpen) = !GVAR(mapOpen);

// Reset highlighted object
GVAR(mapHighlighted) = objNull;
