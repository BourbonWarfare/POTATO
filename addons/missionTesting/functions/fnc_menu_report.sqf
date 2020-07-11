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
        ["_runTestButton","RscButton",0.98,0.15,"Run Test","",["buttonClick",{[] call FUNC(weaponsReport);}]]
        ,["_missionCBsLine","RscLine",1,0,"",""]
      ],0,0,0,CTRLVERT,CGMAINFRAME
		]
    ,[
      [
        ["_zuesBriefGroup","RscControlsGroup",0.98,0.5,"",CGZBRIEFING]
      ],0,nil,nil,CTRLVERT,CGMAINFRAME
    ]
    ,[
      [
        ["_zuesBriefTitle","RscText",0.98,0.05,"Zues Briefing",TEXT_ORANGE]
        ,["_zuesBrief","RscStructuredText",0.98,0.3,"",""]
      ],0,0,nil,CTRLVERT,CGZBRIEFING
    ]
    ,[
      [
        ["_westButton","RscButton",0.24,0.05,"WEST","",["buttonClick",{[0] call FUNC(changeSideReport);}]]
        ,["_eastButton","RscButton",0.24,0.05,"EAST","",["buttonClick",{[1] call FUNC(changeSideReport);}]]
        ,["_indyButton","RscButton",0.24,0.05,"INDY","",["buttonClick",{[2] call FUNC(changeSideReport);}]]
        ,["_civiButton","RscButton",0.24,0.05,"CIVI","",["buttonClick",{[3] call FUNC(changeSideReport);}]]
      ],0,0.47,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
      [
        ["_sideBriefGroup","RscControlsGroup",0.98,0.4,"",CGSBRIEFING]
      ],0,nil,nil,CTRLHORZ,CGMAINFRAME
    ]
    ,[
      [
        ["_situationBriefTitle","RscText",0.98,0.05,"Situtation Briefing",TEXT_ORANGE]
        ,["_situationBrief","RscStructuredText",0.98,0.3,"",""]
        ,["_missionBriefTitle","RscText",0.98,0.05,"Mission Briefing",TEXT_ORANGE]
        ,["_missionBrief","RscStructuredText",0.98,0.3,"",""]
        ,["_adminBriefTitle","RscText",0.98,0.05,"Administration Briefing",TEXT_ORANGE]
        ,["_adminBrief","RscStructuredText",0.98,0.3,"",""]
      ],0,0,nil,CTRLVERT,CGSBRIEFING
    ]
    ,[
      [
        ["_westButton","RscStructuredText",0.98,5,"Placeholder",""]
      ],0,1.13,nil,CTRLHORZ,CGMAINFRAME
    ]
  ];

{
    _x call FUNC(uiTile);
} forEach _controls;

private _menuOK = MENU_DISPLAY displayCtrl (9990);
_menuOK ctrlSetText "Ok";
_menuOK buttonSetAction "";
_menuOK ctrlCommit 0;
_menuOK buttonSetAction "closeDialog 2;";
_menuOK ctrlCommit 0;
