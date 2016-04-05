#include "script_component.hpp"
TRACE_1("Params",_this);

// set current indexes for next run
GVAR(lastGarrisonFactionIndex) = lbCurSel GARRISON_FACTIONS_IDC;
GVAR(lastGarrisonChanceValue) = sliderPosition GARRISON_CHANCE_SLIDER_IDC;
GVAR(lastGarrisonRadiusValue) = sliderPosition GARRISON_RADIUS_SLIDER_IDC;
GVAR(lastGarrisonMinValue) = sliderPosition GARRISON_MIN_SLIDER_IDC;
GVAR(lastGarrisonMaxValue) = sliderPosition GARRISON_MAX_SLIDER_IDC;

private _faction = lbData [GARRISON_FACTIONS_IDC, GVAR(lastGarrisonFactionIndex)];
private _side = switch (getNumber (configfile >> "CfgFactionClasses" >> _faction >> "side")) do { case 0: {east}; case 1: {west}; case 2: {resistance}; default {civilian}; };
private _units = (GVAR(garrisonCache) select 1) select ((GVAR(garrisonCache) select 0) find _faction);

private _occupyChance = GVAR(lastGarrisonChanceValue);
private _occupyRadius = GVAR(lastGarrisonRadiusValue);
private _occupyMinNumber = GVAR(lastGarrisonMinValue);
private _occupyMaxNumber = GVAR(lastGarrisonMaxValue);

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

// last thing, close dialog with success
closeDialog 1;
