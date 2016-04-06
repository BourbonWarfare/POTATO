#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_faction","_occupyChance","_occupyRadius","_occupyMinNumber","_occupyMaxNumber"];

private _side = switch (getNumber (configfile >> "CfgFactionClasses" >> _faction >> "side")) do { case 0: {east}; case 1: {west}; case 2: {resistance}; default {civilian}; };

// handle EDEN placed module
if (isNil QGVAR(garrisonCache)) {
    [] call FUNC(garrisonCache);
};

private _units = (GVAR(garrisonCache) select 1) select ((GVAR(garrisonCache) select 0) find _faction);

private _buildingPositions = [];
{
    if ((floor random 100) <= _occupyChance) then {
        private _positions = (_x buildingPos -1);
        if ((count _positions) >= _occupyMinNumber) then {
            _buildingPositions pushBack _positions;
        };
    };
    nil
} count (nearestObjects [GVAR(garrisonLocation), ["house"], _occupyRadius]);

if (count _buildingPositions > 0) then {
    [_buildingPositions, _side, _units, _occupyMinNumber, _occupyMaxNumber] remoteExecCall [QFUNC(garrisonServer), SERVER_CLIENT_ID];
} else {
    [objNull, "Did not find any buildings to garrison (is your occupy chance to low, or min occupy units to high?)"] call BIS_fnc_showCuratorFeedbackMessage
};
