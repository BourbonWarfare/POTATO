#include "script_component.hpp"
TRACE_1("Params",_this);

// set current faction for next run
GVAR(lastGarrisonFactionIndex) = lbCurSel GARRISON_FACTIONS_IDC;

private _faction = lbData [GARRISON_FACTIONS_IDC, lbCurSel GARRISON_FACTIONS_IDC];
private _side = switch (getNumber (configfile >> "CfgFactionClasses" >> _x >> "side")) do { case 0: {east}; case 1: {west}; case 2: {resistance}; default {civilian}; };
private _units = (GVAR(garrisonCache) select 1) select ((GVAR(garrisonCache) select 0) find _faction);

private _occupyRadius = 0;
private _occupyChance = 0;
private _occupyMinNumber = 0;
private _occupyMaxNumber = 0;

private _buildingPositions = [];
{
    if (_occupyChance <= (floor random 100)) then {
        private _positions = (_x buildingPos -1);
        if (_positions >= _occupyMinNumber) then {
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

// last thing, close dialog with success
closeDialog 1;
