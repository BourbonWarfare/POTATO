#include "script_component.hpp"
TRACE_1("params",_this);

params [_unit];

//Check if the leader changed formation 10 seconds ago already. If so, exit the script
if ([_unit,VQGVAR(formationChanged),VGVAR(formationChangeThreshold)] call VFUNC(pastThreshold)) exitWith {};

//Grab the group of the unit
private _unitGroup = group _unit;

private _nearestLocations = nearestLocations [position _unit, ["NameCity","NameVillage","Hill","NameLocal"], 500];
if (count _nearestLocations < 1) exitWith {};

private _formationArray = switch (type (_nearestLocations select 0)) do {
    //cases (insertable by snippet)
    case ("NameCity"): {
        ["STAG COLUMN","COLUMN"]
    };
    case ("NameVillage"): {
        ["STAG COLUMN","COLUMN"]
    };
    case ("Hill"): {
        ["LINE","LINE"]
    };
    case ("NameLocal"): {
        ["COLUMN","COLUMN"]
    };
    default {
        ["WEDGE","WEDGE"]
    };
};

_formationArray params ["_vehicleFormation","_infantryFormation"];

if ((vehicle _unit) != _unit) then {
    _unitGroup setFormation _vehicleFormation;
} else {
    _unitGroup setFormation _infantryFormation;
};

//Set the units variable so they dont try changing formations too frequently.
_unit setVariable [VQGVAR(formationChanged),diag_tickTime];
