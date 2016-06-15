#include "script_component.hpp"

params ["_idc","_addArray"];
_addArray params ["_westEnabled","_eastEnabled","_indyEnabled","_civEnabled"];

switch (true) do {
    case (_westEnabled): {
        GET_CTRL(_idc) ctrlSetText ([missionConfigFile >> QGVAR(config) >> "blueFor", 1] call FUNC(getNumberAsString));
        _westEnabled = false;
    };
    case (_eastEnabled): {
        GET_CTRL(_idc) ctrlSetText ([missionConfigFile >> QGVAR(config) >> "opFor", 1] call FUNC(getNumberAsString));
        _eastEnabled = false;
    };
    case (_indyEnabled): {
        GET_CTRL(_idc) ctrlSetText ([missionConfigFile >> QGVAR(config) >> "indy", 1] call FUNC(getNumberAsString));
        _indyEnabled = false;
    };
    case (_civEnabled): {
        GET_CTRL(_idc) ctrlSetText ([missionConfigFile >> QGVAR(config) >> "civ", 1] call FUNC(getNumberAsString));
        _civEnabled = false;
    };
};

[_westEnabled,_eastEnabled,_indyEnabled,_civEnabled]
