#include "script_component.hpp"

params ["_idc","_addArray"];
_addArray params ["_westEnabled","_eastEnabled","_indyEnabled","_civEnabled"];

switch (true) do {
    case (_westEnabled): {
        GET_CTRL(_idc) ctrlSetText (str getMissionConfigValue [QGVAR(westRatio), 1]);
        _westEnabled = false;
    };
    case (_eastEnabled): {
        GET_CTRL(_idc) ctrlSetText (str getMissionConfigValue [QGVAR(eastRatio), 1]);
        _eastEnabled = false;
    };
    case (_indyEnabled): {
        GET_CTRL(_idc) ctrlSetText (str getMissionConfigValue [QGVAR(indpRatio), 1]);
        _indyEnabled = false;
    };
    case (_civEnabled): {
        GET_CTRL(_idc) ctrlSetText (str getMissionConfigValue [QGVAR(civRatio), 1]);
        _civEnabled = false;
    };
};

[_westEnabled,_eastEnabled,_indyEnabled,_civEnabled]
