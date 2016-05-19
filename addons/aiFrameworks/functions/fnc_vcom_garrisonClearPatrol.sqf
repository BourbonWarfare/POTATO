#include "script_component.hpp"
TRACE_1("params",_this);


params ["_unit","_locations"]

//Stop the AI - and then tell them to move to the house
_unit setVariable [VQGVAR(inCover),true];

while {(count _locations) > 0 && {!([_unit,VQGVAR(activelyClearing),VGVAR(clearingThreshold)] call VFUNC(pastThreshold))}} do {
    sleep (random 2);
    private _location = selectRandom _locations;
    _locations = _locations - [_location];
    _unit doMove _location;

    waitUntil {sleep 0.5; (_unit distance _location) < 2};
};

_unit setVariable [VQGVAR(inCover),false];
