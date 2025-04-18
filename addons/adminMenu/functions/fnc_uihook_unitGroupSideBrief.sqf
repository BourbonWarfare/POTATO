#include "script_component.hpp"
/*
* Author: Lambda.Tiger
* This function handle the Unit and Group brief testing button that loads
* all group and unit briefs in to the POTATO sub menu in the map diary screen.
*
* Arguments:
* None
*
* Return Value:
* None
*
* Examples:
* [] call potato_adminMenu_fnc_unitGroupSideBrief;
*
* Public: No
*/
private _debugMsg = format ["Group and Unit Brief Test"];
["potato_adminMsg", [_debugMsg, profileName]] call CBA_fnc_globalEvent;

//Needs a player to add to breifing:
if ((isNull player) || {!alive player}) exitWith {};

private _briefs = ["<font size=20 ace=""PuristaBold"">Group and Unit Briefs</font>"];
{
    private _brief = _x getVariable ["potato_briefing_briefing", ""];
    if (_brief != "") then {
        private _name = if (_x isEqualType objNull) then {
            ((roleDescription _x) splitString "@")#0
        } else {
            groupId _x
        };
        _briefs pushBack format ["<font size=14 face=""PuristaBold"">%1</font><br/>%2",_name,_brief];
    };
} forEach allGroups + allUnits;

if !(player diarySubjectExists "POTATO") then {
    player createDiarySubject ["POTATO", "POTATO"];
};
if (count _briefs > 1) then {
    player createDiaryRecord ["POTATO", ["Group and Unit Briefs", _briefs joinString "<br/><br/>"], taskNull, "NONE", false];
};

{
    private _sideText = [format ["<font size=28 face=""PuristaBold"">%1 Brief</font><br/>",_x]];
    private _sideBriefMission = getMissionConfigValue [format [QEGVAR(briefing,brief%1Mission), _x], ""];
    private _sideBriefSituation = getMissionConfigValue [format [QEGVAR(briefing,brief%1Situation), _x], ""];
    private _sideBriefAdministration = getMissionConfigValue [format [QEGVAR(briefing,brief%1Administration), _x], ""];
    if (_sideBriefAdministration != "") then {
        _sideText pushBack "<font size=20 face=""PuristaBold"">Admin</font>";
        _sideText pushBack (_sideBriefAdministration + "<br/>");
    };
    if (_sideBriefMission != "") then {
        _sideText pushBack "<font size=20 face=""PuristaBold"">Mission</font>";
        _sideText pushBack (_sideBriefMission + "<br/>");
    };
    if (_sideBriefSituation != "") then {
        _sideText pushBack "<font size=20 face=""PuristaBold"">Situation</font>";
        _sideText pushBack (_sideBriefSituation + "<br/>");
    };
    if (count _sideText > 1) then {
        player createDiaryRecord [
            "POTATO", [
                format ["%1 Brief", _x],
                _sideText joinString "<br/>"
            ], taskNull,
            "NONE",
            false
        ];
    };
} forEach ["West", "East", "Independent", "Civilian"];
