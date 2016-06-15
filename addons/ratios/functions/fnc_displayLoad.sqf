#include "script_component.hpp"

if (!hasInterface) exitWith {};

SET_UI_VAR(loaded,true);
SET_UI_VAR(lastValues,nil);
SET_UI_VAR(nonPlayerTextureCache,nil);
SET_UI_VAR(playerTextureCache,nil);

PREP(skipUpdate);
PREP(displayUpdate);
PREP(getNumberAsString);

private _loadTimeout = diag_tickTime + 60;
waitUntil {
    ctrlEnabled SIDE_CIV
        || {ctrlEnabled SIDE_EAST}
        || {ctrlEnabled SIDE_INDY}
        || {ctrlEnabled SIDE_LOGIC}
        || {ctrlEnabled SIDE_VIRTUAL}
        || {ctrlEnabled SIDE_WEST}
        || {diag_tickTime > _loadTimeout}
};

private _sideArray = [];
private _sideCount = {
    _sideArray pushBack _x;
    _x
} count [ctrlEnabled SIDE_WEST, ctrlEnabled SIDE_EAST, ctrlEnabled SIDE_INDY, ctrlEnabled SIDE_CIV]; //if this order changes, change it in update

private _exit = false;
switch (_sideCount) do {
    case (2): {
        RATIO_INPUT_3 ctrlShow false;
        RATIO_INPUT_4 ctrlShow false;

        RATIO_OUTPUT_3  ctrlShow false;
        RATIO_OUTPUT_4  ctrlShow false;
    };
    case (3): {
        RATIO_INPUT_4 ctrlShow false;
        RATIO_OUTPUT_4  ctrlShow false;
    };
    case (4): {};
    default {
        _exit = true;
        RATIO_TEXT ctrlShow false;

        RATIO_INPUT_1 ctrlShow false;
        RATIO_INPUT_2 ctrlShow false;
        RATIO_INPUT_3 ctrlShow false;
        RATIO_INPUT_4 ctrlShow false;

        RATIO_OUTPUT_1 ctrlShow false;
        RATIO_OUTPUT_2 ctrlShow false;
        RATIO_OUTPUT_3 ctrlShow false;
        RATIO_OUTPUT_4 ctrlShow false;
    };
};

if (_exit) exitWith {};

if ((isNumber (missionConfigFile >> QGVAR(config) >> "blueFor"))
        || {isNumber (missionConfigFile >> QGVAR(config) >> "opFor")}
        || {isNumber (missionConfigFile >> QGVAR(config) >> "indy")}
        || {isNumber (missionConfigFile >> QGVAR(config) >> "civ")}) then {

    private _addCiv = ctrlEnabled SIDE_CIV;
    private _addEast = ctrlEnabled SIDE_EAST;
    private _addIndy = ctrlEnabled SIDE_INDY;
    private _addWest = ctrlEnabled SIDE_WEST;

    if (ctrlEnabled RATIO_INPUT_1) then {
        switch (true) do {
            case (_addWest): {
                RATIO_INPUT_1 ctrlSetText ([missionConfigFile >> QGVAR(config) >> "blueFor", 1] call FUNC(getNumberAsString));
                _addWest = false;
            };
            case (_addEast): {
                RATIO_INPUT_1 ctrlSetText ([missionConfigFile >> QGVAR(config) >> "opFor", 1] call FUNC(getNumberAsString));
                _addEast = false;
            };
            case (_addIndy): {
                RATIO_INPUT_1 ctrlSetText ([missionConfigFile >> QGVAR(config) >> "indy", 1] call FUNC(getNumberAsString));
                _addIndy = false;
            };
            case (_addCiv): {
                RATIO_INPUT_1 ctrlSetText ([missionConfigFile >> QGVAR(config) >> "civ", 1] call FUNC(getNumberAsString));
                _addCiv = false;
            };
        };
    };

    if (ctrlEnabled RATIO_INPUT_2) then {
        switch (true) do {
            case (_addWest): {
                RATIO_INPUT_2 ctrlSetText ([missionConfigFile >> QGVAR(config) >> "blueFor", 1] call FUNC(getNumberAsString));
                _addWest = false;
            };
            case (_addEast): {
                RATIO_INPUT_2 ctrlSetText ([missionConfigFile >> QGVAR(config) >> "opFor", 1] call FUNC(getNumberAsString));
                _addEast = false;
            };
            case (_addIndy): {
                RATIO_INPUT_2 ctrlSetText ([missionConfigFile >> QGVAR(config) >> "indy", 1] call FUNC(getNumberAsString));
                _addIndy = false;
            };
            case (_addCiv): {
                RATIO_INPUT_2 ctrlSetText ([missionConfigFile >> QGVAR(config) >> "civ", 1] call FUNC(getNumberAsString));
                _addCiv = false;
            };
        };
    };

    if (ctrlEnabled RATIO_INPUT_3) then {
        switch (true) do {
            case (_addWest): {
                RATIO_INPUT_3 ctrlSetText ([missionConfigFile >> QGVAR(config) >> "blueFor", 1] call FUNC(getNumberAsString));
                _addWest = false;
            };
            case (_addEast): {
                RATIO_INPUT_3 ctrlSetText ([missionConfigFile >> QGVAR(config) >> "opFor", 1] call FUNC(getNumberAsString));
                _addEast = false;
            };
            case (_addIndy): {
                RATIO_INPUT_3 ctrlSetText ([missionConfigFile >> QGVAR(config) >> "indy", 1] call FUNC(getNumberAsString));
                _addIndy = false;
            };
            case (_addCiv): {
                RATIO_INPUT_3 ctrlSetText ([missionConfigFile >> QGVAR(config) >> "civ", 1] call FUNC(getNumberAsString));
                _addCiv = false;
            };
        };
    };

    if (ctrlEnabled RATIO_INPUT_4) then {
        switch (true) do {
            case (_addWest): {
                RATIO_INPUT_4 ctrlSetText ([missionConfigFile >> QGVAR(config) >> "blueFor", 1] call FUNC(getNumberAsString));
                _addWest = false;
            };
            case (_addEast): {
                RATIO_INPUT_4 ctrlSetText ([missionConfigFile >> QGVAR(config) >> "opFor", 1] call FUNC(getNumberAsString));
                _addEast = false;
            };
            case (_addIndy): {
                RATIO_INPUT_4 ctrlSetText ([missionConfigFile >> QGVAR(config) >> "indy", 1] call FUNC(getNumberAsString));
                _addIndy = false;
            };
            case (_addCiv): {
                RATIO_INPUT_4 ctrlSetText ([missionConfigFile >> QGVAR(config) >> "civ", 1] call FUNC(getNumberAsString));
                _addCiv = false;
            };
        };
    };
};

while {GET_UI_VAR(loaded)} do {
    [_sideCount,_sideArray] call FUNC(displayUpdate);
};
