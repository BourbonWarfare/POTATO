/*
 * Author: AACO
 * Function used populate the UI, must be spawned
 * Should only be called from UI events
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

if (isNil QGVAR(garrisonCache)) then {
    [] call FUNC(garrisonCache);
};

waitUntil {dialog}; // wait until the dialog is fully loaded before we do any population

// setup faction dropdown, and populate possible unit list
{
    private _index = lbAdd [GARRISON_FACTIONS_IDC, getText (configFile >> "CfgFactionClasses" >> _x >> "displayName")];
    lbSetData [GARRISON_FACTIONS_IDC, _index, _x];
    lbSetPicture [GARRISON_FACTIONS_IDC, _index, getText (configFile >> "CfgFactionClasses" >> _x >> "icon")];

    nil
} count (GVAR(garrisonCache) select 0);

lbSetCurSel [GARRISON_FACTIONS_IDC, if (isNil QGVAR(lastGarrisonFactionIndex)) then { 0 } else { GVAR(lastGarrisonFactionIndex) }];

private _unitLimit = [] call FUNC(garrisonUnitLimit);

private _unitValue = if (isNil QGVAR(lastGarrisonUnitLimit)) then { _unitLimit } else { GVAR(lastGarrisonUnitLimit) };
private _chanceValue = if (isNil QGVAR(lastGarrisonChanceValue)) then { 50 } else { GVAR(lastGarrisonChanceValue) };
private _radiusValue = if (isNil QGVAR(lastGarrisonRadiusValue)) then { 500 } else { GVAR(lastGarrisonRadiusValue) };
private _minValue = if (isNil QGVAR(lastGarrisonMinValue)) then { 2 } else { GVAR(lastGarrisonMinValue) };
private _maxValue = if (isNil QGVAR(lastGarrisonMaxValue)) then { 5 } else { GVAR(lastGarrisonMaxValue) };

sliderSetRange [GARRISON_UNITS_SLIDER_IDC, 1, _unitLimit];
sliderSetRange [GARRISON_CHANCE_SLIDER_IDC, 0, 100];
sliderSetRange [GARRISON_RADIUS_SLIDER_IDC, 0, 2000];
sliderSetRange [GARRISON_MIN_SLIDER_IDC, 1, 20];
sliderSetRange [GARRISON_MAX_SLIDER_IDC, 1, 20];

sliderSetSpeed [GARRISON_UNITS_SLIDER_IDC,2,10];
sliderSetSpeed [GARRISON_CHANCE_SLIDER_IDC,5,20];
sliderSetSpeed [GARRISON_RADIUS_SLIDER_IDC,100,300];

sliderSetPosition [GARRISON_UNITS_SLIDER_IDC, _unitValue];
sliderSetPosition [GARRISON_CHANCE_SLIDER_IDC, _chanceValue];
sliderSetPosition [GARRISON_RADIUS_SLIDER_IDC, _radiusValue];
sliderSetPosition [GARRISON_MIN_SLIDER_IDC, _minValue];
sliderSetPosition [GARRISON_MAX_SLIDER_IDC, _maxValue];

ctrlSetText [GARRISON_UNITS_EDIT_IDC, str _unitValue];
ctrlSetText [GARRISON_CHANCE_EDIT_IDC, str _chanceValue];
ctrlSetText [GARRISON_RADIUS_EDIT_IDC, str _radiusValue];
ctrlSetText [GARRISON_MIN_EDIT_IDC, str _minValue];
ctrlSetText [GARRISON_MAX_EDIT_IDC, str _maxValue];
