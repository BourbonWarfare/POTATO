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

params ["_openMap", "_openFullMap"];

// handle minimap
if (GVAR(mapOpen) && {!_openMap}) then {
    MAP_DISPLAY ctrlShow false;
    MAP_GROUP ctrlShow false;

    GVAR(mapOpen) = false;
} else {
    if (_openMap && {!GVAR(mapOpen)}) then {
        MAP_DISPLAY ctrlShow true;
        MAP_GROUP ctrlShow true;

        MAP_TITLE ctrlSetText (getMissionConfigValue ["onLoadName", getMissionConfigValue ["briefingName", "???"]]);
        MAP_SPEC_COUNT ctrlSetText str ({_x isKindOf QGVAR(spectator)} count allPlayers);

        MAP_DISPLAY ctrlMapAnimAdd [0, 0.05, positionCameraToWorld [0,0,0]];
        ctrlMapAnimCommit MAP_DISPLAY;
        ctrlSetFocus MAP_DISPLAY;

        GVAR(cam) camCommand "manual off";
        GVAR(mapOpen) = true;
    };
};


// handle fullmap
if (GVAR(fullMapOpen) && {!_openFullMap}) then {
    FULL_MAP ctrlShow false;

    GVAR(fullMapOpen) = false;
} else {
    if (_openFullMap && {!GVAR(fullMapOpen)}) then {
        FULL_MAP ctrlShow true;
        FULL_MAP ctrlMapAnimAdd [0, 0.05, positionCameraToWorld [0,0,0]];
        ctrlMapAnimCommit FULL_MAP;
        ctrlSetFocus FULL_MAP;

        GVAR(fullMapOpen) = true;
    };
};

if !(_openMap || _openFullMap) then {
    ctrlSetFocus MOUSE;

    if (GVAR(currentCamIndex) == FREE_CAMERA) then {
        GVAR(cam) camCommand "manual on";
    };
} else {
    GVAR(cam) camCommand "manual off";
};

// Reset highlighted object
GVAR(mapHighlighted) = objNull;
