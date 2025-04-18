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
* [] call potato_safeStart_fnc_forceEndSafeStart;
*
* Public: No
*/
private _debugMsg = format ["Group and Unit Brief Test"];
["potato_adminMsg", [_debugMsg, profileName]] call CBA_fnc_globalEvent;

//Needs a player to add to breifing:
if ((isNull player) || {!alive player}) exitWith {};

private _briefs = [];
{
    private _brief = _x getVariable ["potato_briefing_briefing", ""];
    if (_brief != "") then {
        private _name = if (_x isEqualType objNull) then {
            ((roleDescription _x) splitString "@")#0
        } else {
            groupID _x
        };
        _briefs pushBack format ["<font size=""14"" face=""PuristaBold"">%1</font><br/>%2",_name,_brief];
    };
} forEach allGroups + allUnits;

if !(player diarySubjectExists "POTATO") then {
    player createDiarySubject ["POTATO", "POTATO"];
};
player createDiaryRecord ["POTATO", ["Group and Unit Briefs","<font size=20 ace=""PuristaBold"">Group and Unit Briefs</font><br/>" + (_briefs joinString "<br/><br/>")], taskNull, "NONE", false];
