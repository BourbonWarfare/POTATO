/*
 * Author: BadWolf
 * Function called to populate the side arrays for each side. Will the default display the infromation for west.
 *
 * Arguments:
 * 0: side <INTERGER>
 *
 * Examples:
 * [0] call potato_missionTesting_fnc_weaponsReport;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params["_menu"];
private _controls = [
    [
        [
            ["_intro","RscText",0.98,0.05,"MISSION TESTER CHECKLIST",[]]
        ],0,0,0,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_infoMissionName","RscText",0.15,0.05,"Mission Name:",TEXT_ORANGE]
            ,["_infoMissionMaker","RscText",0.47,0.05,getMissionConfigValue ["onLoadName", getMissionConfigValue ["briefingName","????"]],[]]
            ,["_infoMissionType","RscText",0.15,0.05,"Mission Type:",TEXT_ORANGE]
            ,["_infoMissionTypeSelect","RscCombo",0.15,0.05,A_MISSION_TYPE,""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_infoMissionMaker","RscText",0.15,0.05,"Mission Maker:",TEXT_ORANGE]
            ,["_infoMissionMakerText","RscText",0.15,0.05,getMissionConfigValue ["author","????"],""]
            ,["_infoMissionMap","RscText",0.15,0.05,"Mission Map:",TEXT_ORANGE]
            ,["_infoMissionMapText","RscText",0.15,0.05,getText (configFile >> "CfgWorlds" >> worldName >> "description"),""]
            ,["_infoMissionTester","RscText",0.15,0.05,"Mission Version:",TEXT_ORANGE]
            ,["_infoMissionTesterInput","RscEdit",0.15,0.05,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_infoMissionTags1","RscText",0.15,0.05,"Mission Tag:",TEXT_ORANGE]
            ,["_infoMissionTags1Select","RscCombo",0.15,0.05,A_MISSION_TAGS,""]
            ,["_infoMissionTags2Select","RscCombo",0.15,0.05,A_MISSION_TAGS,""]
            ,["_infoMissionTags3Select","RscCombo",0.15,0.05,A_MISSION_TAGS,""]
            ,["_infoMissionPlayerCountText","RscText",0.15,0.05,"Player Count:",TEXT_ORANGE]
            ,["_infoMissionPlayerCountEdit","RscEdit",0.15,0.05,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_missionCBsLine","RscLine",1,0,"",""]
            ,["_missionCBsDescription","RscText",0.98,0.05,"Check any of the below that apply to this mission.(WIP)",TEXT_RED]
            ,["_missionCBsLine","RscLine",1,0,"",""]
        ],0,nil,nil,CTRLVERT,CGMAINFRAME
    ]
    ,[
        [
            ["_missionCB1Text","RscStructuredText",0.17,0.05,"Custom Scripting",""]
            ,["_missionCB1","RscCheckBox",0.05,0.05,"","",["CheckedChanged",{hint "CB Does nothing at the moment";}]]
            ,["_missionCB2Text","RscStructuredText",0.17,0.05,"Custom Loadout",""]
            ,["_missionCB2","RscCheckBox",0.05,0.05,"","",["CheckedChanged",{hint "CB Does nothing at the moment";}]]
            ,["_missionCB3Text","RscStructuredText",0.17,0.05,"Player Vics",""]
            ,["_missionCB3","RscCheckBox",0.05,0.05,"","",["CheckedChanged",{hint "CB Does nothing at the moment";}]]
            ,["_missionCB4Text","RscStructuredText",0.17,0.05,"Unit Specific Breifings",""]
            ,["_missionCB4","RscCheckBox",0.05,0.05,"","",["CheckedChanged",{hint "CB Does nothing at the moment";}]]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_line","RscLine",1,0,"",""]
            ,["_line","RscLine",1,0,"",""]
            ,["_preMissionChecklistTitle","RscText",0.98,0.04,"PRE-MISSION CHECKLIST",TEXT_RED]
            ,["_preMissionChecklistDescription","RscText",0.98,0.04,"Check the box to confirm that the mission meets the requirement.",""]
            ,["_line","RscLine",1,0,"",""]
        ],0,nil,nil,CTRLVERT,CGMAINFRAME
    ]
    ,[
        [
            ["_preMission1","RscStructuredText",0.92,0.05,"Ensure only slots that are meant to be played are in the mission.",""]
            ,["_preMission1CB","RscCheckBox",0.05,0.05,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_preMission1","RscStructuredText",0.92,0.05,"Do a quick sanity check of the ratio",""]
            ,["_preMission1CB","RscCheckBox",0.05,0.05,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_preMission1","RscStructuredText",0.92,0.05,"Make sure the mission description isn't confusing/vague",""]
            ,["_preMission1CB","RscCheckBox",0.05,0.05,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_preMission1","RscStructuredText",0.92,0.05,"Read the briefings make sure they exist and are clear",""]
            ,["_preMission1CB","RscCheckBox",0.05,0.05,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_preMission1","RscStructuredText",0.92,0.05,"Make sure objectives are marked",""]
            ,["_preMission1CB","RscCheckBox",0.05,0.05,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_preMission1","RscStructuredText",0.92,1,"Take a quick look at the map for terrain imbalances, and make sure the mission maker has taken them into account (I.E. defenders need better gear and/or more people if they're defending a bowl that has sparse cover)",""]
            ,["_preMission1CB","RscCheckBox",0.05,0.05,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_preMission1","RscStructuredText",0.92,0.05,"Ensure there is a signals tab, and the channel names make sense for the mission",""]
            ,["_preMission1CB","RscCheckBox",0.05,0.05,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_preMission1","RscStructuredText",0.92,0.05,"Ensure that if it is a night mission it is tagged as such in the mission description on the slotting screen",""]
            ,["_preMission1CB","RscCheckBox",0.05,0.05,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_line",   "RscLine",1,0,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_preMission1","RscText",0.85,0.05,"Does this mission pass Pre-Mission Checks?",""]
            ,["_preMission1CB","RscCombo",0.12,0.05,A_PASSFAIL,""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_line","RscLine",1,0,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_notesTitle","RscText",0.98,0.05,"Notes For Mission Maker:",""]
            ,["_notesTitle","RscEditMulti",0.98,0.2,"",""]
            ,["_line","RscLine",1,0,"",""]
        ],0,nil,nil,CTRLVERT,CGMAINFRAME
    ]
    ,[
        [
            ["_line","RscLine",1,0,"",""]
            ,["_ChecklistTitle","RscText",0.98,0.04,"GEAR CHECKLIST",TEXT_RED]
            ,["_ChecklistDescription","RscText",0.98,0.04,"Check the box to confirm that the mission meets the requirement.",""]
            ,["_line","RscLine",1,0,"",""]
        ],0,nil,nil,CTRLVERT,CGMAINFRAME
    ]
    ,[
        [
            ["_preMission1","RscStructuredText",0.92,0.05,"Ensure every soldier has the correct number of magazines/rockets.",""]
            ,["_preMission1CB","RscCheckBox",0.05,0.05,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_preMission1","RscStructuredText",0.92,0.05,"Ensure soldiers have the correct radios and they're set to the right channel",""]
            ,["_preMission1CB","RscCheckBox",0.05,0.05,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_preMission1","RscStructuredText",0.92,0.09,"Ensure the uniforms are what they should be. A lot of times updates will break classnames and soldiers will have default A3 uniforms.",""]
            ,["_preMission1CB","RscCheckBox",0.05,0.05,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_preMission1","RscStructuredText",0.92,0.09,"Ensure the uniforms are positive identification friendly. If you can't tell what team is which from 100m, there's probably a problem.",""]
            ,["_preMission1CB","RscCheckBox",0.05,0.05,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_preMission1","RscStructuredText",0.92,0.05,"Ensure every soldier type (I.E. FTL/AR/AAR/AT) has medical supplies.",""]
            ,["_preMission1CB","RscCheckBox",0.05,0.05,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_preMission1","RscStructuredText",0.92,0.09,"Check for soldiers with magnified optics, and make sure the mission maker has both A) Intended this and B) has properly balanced it",""]
            ,["_preMission1CB","RscCheckBox",0.05,0.05,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_line","RscLine",1,0,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_preMission1","RscText",0.85,0.05,"Does this mission pass Gear Checks?",""]
            ,["_preMission1CB","RscCombo",0.12,0.05,A_PASSFAIL,""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_line","RscLine",1,0,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_notesTitle","RscText",0.98,0.05,"Notes For Mission Maker:",""]
            ,["_notesTitle","RscEditMulti",0.98,0.2,"",""]
            ,["_line","RscLine",1,0,"",""]
        ],0,nil,nil,CTRLVERT,CGMAINFRAME
    ]
    ,[
        [
            ["_line","RscLine",1,0,"",""]
            ,["_ChecklistTitle","RscText",0.98,0.04,"VEHICLES CHECKLIST",TEXT_RED]
            ,["_ChecklistDescription","RscText",0.98,0.04,"Check the box to confirm that the mission meets the requirement.",""]
            ,["_line","RscLine",1,0,"",""]
        ],0,nil,nil,CTRLVERT,CGMAINFRAME
    ]
    ,[
        [
            ["_preMission1","RscStructuredText",0.92,0.05,"Ensure vehicle gear is correct for the side using it (Mainly for COOPs), or removed (mainly for TvTs)",""]
            ,["_preMission1CB","RscCheckBox",0.05,0.05,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_preMission1","RscStructuredText",0.92,0.09,"Ensure the vehicles are balanced (I.E. if one team has a BTR, one team has the AT to kill it, or if two teams are racing to an objectives, their vics go about the same speed)",""]
            ,["_preMission1CB","RscCheckBox",0.05,0.05,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_preMission1","RscStructuredText",0.92,0.09,"Ensure vehicles with weapons have their ammo balanced, (I.E. a Little Bird with 32 rockets is overkill vs infantry)",""]
            ,["_preMission1CB","RscCheckBox",0.05,0.05,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_line","RscLine",1,0,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_preMission1","RscText",0.85,0.05,"Does this mission pass Vehicle Checks?",""]
            ,["_preMission1CB","RscCombo",0.12,0.05,A_PASSFAIL,""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_line","RscLine",1,0,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_notesTitle","RscText",0.98,0.05,"Notes For Mission Maker:",""]
            ,["_notesTitle","RscEditMulti",0.98,0.2,"",""]
            ,["_line","RscLine",1,0,"",""]
        ],0,nil,nil,CTRLVERT,CGMAINFRAME
    ]
    ,[
        [
            ["_line","RscLine",1,0,"",""]
            ,["_ChecklistTitle","RscText",0.98,0.04,"COOP CHECKLIST",TEXT_RED]
            ,["_ChecklistDescription","RscText",0.98,0.04,"Check the box to confirm that the mission meets the requirement.",""]
            ,["_line","RscLine",1,0,"",""]
        ],0,nil,nil,CTRLVERT,CGMAINFRAME
    ]
    ,[
        [
            ["_preMission1","RscStructuredText",0.92,0.05,"Talk to the Zeus/mission-maker about their intent.",""]
            ,["_preMission1CB","RscCheckBox",0.05,0.05,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_preMission1","RscStructuredText",0.92,0.05,"Make sure the humans can kill whatever Zeus intends to spawn in.",""]
            ,["_preMission1CB","RscCheckBox",0.05,0.05,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_preMission1","RscStructuredText",0.92,0.05,"Make sure that no heavy scripts are killing server FPS/CPS",""]
            ,["_preMission1CB","RscCheckBox",0.05,0.05,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_preMission1","RscStructuredText",0.92,0.13,"Talk about the objectives and make a call on if they are doable within the time frame of 75-80 minutes. Essentially is it likely that we will have all objectives completed or nearing completion around the 90 minute mark (including Safe Start).",""]
            ,["_preMission1CB","RscCheckBox",0.05,0.05,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_line","RscLine",1,0,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_preMission1","RscText",0.85,0.05,"Does this mission pass COOP Checks?",""]
            ,["_preMission1CB","RscCombo",0.12,0.05,A_PASSFAIL,""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_line","RscLine",1,0,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_notesTitle","RscText",0.98,0.05,"Notes For Mission Maker:",""]
            ,["_notesTitle","RscEditMulti",0.98,0.2,"",""]
            ,["_line","RscLine",1,0,"",""]
        ],0,nil,nil,CTRLVERT,CGMAINFRAME
    ]
    ,[
        [
            ["_line","RscLine",1,0,"",""]
            ,["_ChecklistTitle","RscText",0.98,0.04,"OTHER CONSIDERATIONS CHECKLIST",TEXT_RED]
            ,["_ChecklistDescription","RscText",0.98,0.04,"Check the box to confirm that the mission meets the requirement.",""]
            ,["_line","RscLine",1,0,"",""]
        ],0,nil,nil,CTRLVERT,CGMAINFRAME
    ]
    ,[
        [
            ["_preMission1","RscStructuredText",0.92,0.05,"Ensure you're going to BW spectate on death",""]
            ,["_preMission1CB","RscCheckBox",0.05,0.05,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_line","RscLine",1,0,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_preMission1","RscText",0.85,0.05,"Does this mission pass Other Consideration Checks?",""]
            ,["_preMission1CB","RscCombo",0.12,0.05,A_PASSFAIL,""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_line","RscLine",1,0,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_notesTitle","RscText",0.98,0.05,"Notes For Mission Maker:",""]
            ,["_notesTitle","RscEditMulti",0.98,0.2,"",""]
            ,["_line","RscLine",1,0,"",""]
        ],0,nil,nil,CTRLVERT,CGMAINFRAME
    ]
    ,[
        [
            ["_line","RscLine",1,0,"",""]
        ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
        [
            ["_line","RscLine",1,0,"",""]
            ,["_ChecklistTitle","RscText",0.98,0.04,"GENERAL MISSION FEEDBACK FOR MISSION MAKER",TEXT_RED]
            ,["_ChecklistDescription","RscText",0.98,0.04,"Use this space to provide general feedback for the mission maker.",""]
            ,["_line","RscLine",1,0,"",""]
        ],0,nil,nil,CTRLVERT,CGMAINFRAME
    ]
    ,[
        [
            ["_notesTitle","RscEditMulti",0.98,0.2,"",""]
            ,["_line","RscLine",1,0,"",""]
        ],0,nil,nil,CTRLVERT,CGMAINFRAME
    ]
    ,[
        [
            ["_copyToClipBoard","RscButton",0.98,0.15,"Generate Test Report","",["buttonClick",{[3] call FUNC(generateTestReport);}]]
        ],0,nil,nil,CTRLVERT,CGMAINFRAME
    ]
];

{
    _x call FUNC(uiTile);
} forEach _controls;

[] call FUNC(updateResults);

private _menuOK = MENU_DISPLAY displayCtrl (9990);
_menuOK ctrlSetText "Ok";
_menuOK buttonSetAction "";
_menuOK ctrlCommit 0;
_menuOK ctrlSetText "Save";
_menuOK buttonSetAction "[] call bad_mainMenu_fnc_storeResults";
_menuOK ctrlCommit 0;

