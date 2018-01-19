/*
 * Author: AACO
 * Function used to toggle the briefing
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [] call potato_spectate_fnc_toggleBriefing;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

disableSerialization;
private _currentlyShown = ctrlShown BRIEFING_GROUP;

if (_currentlyShown) then {
    BRIEFING_GROUP ctrlShow false;
} else {
    BRIEFING_GROUP ctrlShow true;

    if (GVAR(needToAddBriefings)) then {
        private _heightOffset = 0;
        GVAR(needToAddBriefings) = false;

        {
            _x params ["_displayName", "_lookupVar"];
            private _briefing = getMissionConfigValue [_lookupVar, ""];
            if (_briefing != "") then {
                private _briefingNameCtrl = OVERLAY ctrlCreate ["RscText", -1, BRIEFINGS_GROUP];
                _briefingNameCtrl ctrlSetText _displayName;
                _briefingNameCtrl ctrlSetPosition [0, _heightOffset, 0.98, 0.075];
                _briefingNameCtrl ctrlCommit 0;
                _heightOffset = _heightOffset + 0.075;

                private _briefingCtrl = OVERLAY ctrlCreate ["RscStructuredText", -1, BRIEFINGS_GROUP];
                _briefingCtrl ctrlSetStructuredText parseText _briefing;
                _briefingCtrl ctrlSetPosition [0, 0, 0.98, 1]; // just set width for ctrlTextHeight
                _briefingCtrl ctrlCommit 0;

                private _textHeight = ctrlTextHeight _briefingCtrl;
                _briefingCtrl ctrlSetPosition [0, _heightOffset, 0.98, _textHeight];
                _briefingCtrl ctrlCommit 0;
                _heightOffset = _heightOffset + _textHeight + 0.05;
            };
        } forEach [
            ["West Mission", QEGVAR(briefing,briefWestMission)],
            ["West Situation", QEGVAR(briefing,briefWestSituation)],
            ["West Administration", QEGVAR(briefing,briefWestAdministration)],
            ["East Mission", QEGVAR(briefing,briefEastMission)],
            ["East Situation", QEGVAR(briefing,briefEastSituation)],
            ["East Administration", QEGVAR(briefing,briefEastAdministration)],
            ["Independent Mission", QEGVAR(briefing,briefIndependentMission)],
            ["Independent Situation", QEGVAR(briefing,briefIndependentSituation)],
            ["Independent Administration", QEGVAR(briefing,briefIndependentAdministration)],
            ["Civilian Mission", QEGVAR(briefing,briefCivilianMission)],
            ["Civilian Situation", QEGVAR(briefing,briefCivilianSituation)],
            ["Civilian Administration", QEGVAR(briefing,briefCivilianAdministration)]
        ];
    };
};
