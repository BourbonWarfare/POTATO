/*
 * Author: AACO
 * Function used to get all the setting from the UI
 * Saves the last run data
 * Should only be called from UI events
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

// set current indexes for next run
GVAR(lastGarrisonFactionIndex) = lbCurSel GARRISON_FACTIONS_IDC;
GVAR(lastGarrisonUnitLimit) = sliderPosition GARRISON_UNITS_SLIDER_IDC;
GVAR(lastGarrisonChanceValue) = sliderPosition GARRISON_CHANCE_SLIDER_IDC;
GVAR(lastGarrisonRadiusValue) = sliderPosition GARRISON_RADIUS_SLIDER_IDC;
GVAR(lastGarrisonMinValue) = sliderPosition GARRISON_MIN_SLIDER_IDC;
GVAR(lastGarrisonMaxValue) = sliderPosition GARRISON_MAX_SLIDER_IDC;
GVAR(lastGarrisonEnableLambs) = cbChecked (GARRISON_DISPLAY displayCtrl GARRISON_ENABLE_LAMBS_IDC);

[
    lbData [GARRISON_FACTIONS_IDC, GVAR(lastGarrisonFactionIndex)],
    GVAR(lastGarrisonUnitLimit),
    GVAR(lastGarrisonChanceValue),
    GVAR(lastGarrisonRadiusValue),
    GVAR(lastGarrisonMinValue),
    GVAR(lastGarrisonMaxValue),
    GVAR(garrisonLocation)
] call FUNC(garrisonSpawn);

// last thing, close dialog with success
closeDialog 1;
