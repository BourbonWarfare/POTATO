#include "script_component.hpp"

GVAR(missionTestingActive) = false;

GVAR(MissionTestingChecklistMaster) = [
    ["PRE-MISSION CHECKLIST",
        [
            ["Ensure only slots that are meant to be played are in the mission.",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
			,["Ensure slots are in the correct order. Nothing below JIPs, out of order, or otherwise.",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
            ,["Does the loading screen description have a ratio?",D_CHECK,MISSION_TYPE_APPLIES_TVT]
			,["If a COTVT, are the OPFOR slots marked for Soldier and above?",D_CHECK,MISSION_TYPE_APPLIES_COTVT]
			,["Are specialities labelled on the slotting screen?",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
            ,["Make sure the mission description isn't confusing/vague",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
			,["Read the Zeus brief. Does it describe clearly the intent of the mission, vehicles to spawn, and enemy contact?",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
            ,["Read the side briefings make sure they exist and are clear.",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
            ,["Make sure objectives are clearly marked and listed in the briefing.",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
			,["Ensure BluForceTracker is assigned to the correct units and are labelled correctly.",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
            
        ],D_PASSFAIL,"",D_NOTEFLAG
    ]
    ,["GEAR CHECKLIST",
        [
            ["Ensure every soldier has the correct number of magazines/rockets.",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
            ,["Ensure soldiers have the correct radios and they're set to the right channel",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
            ,["Ensure all gear contains adequate space for all equipment assigned",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
            ,["Ensure every fireteam member has medical supplies.",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
            ,["Check for soldiers with magnified optics and make sure the mission maker has intended this and has properly balanced it",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
			,["Are opposing uniforms different enough? Ensure PID will not be confusing.",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
			,["Make sure any AI have 3 GP25s/M203s max, and the appropriate AI nods, if needed.",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
			,["Do both sides have a maximum 3 HE GP25/M203?",D_CHECK,MISSION_TYPE_APPLIES_TVT]
			,["Does the armour values for each side have balance in regard to enemy armours/weapons?",D_CHECK,MISSION_TYPE_APPLIES_TVT]
        ],D_PASSFAIL,"",D_NOTEFLAG
    ]
    ,["VEHICLES CHECKLIST",
        [
            ["Ensure vehicle inventory is correct for the side using it or removed.",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
            ,["Ensure the vehicles are balanced for the type of mission.",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
            ,["Ensure vehicles with weapons have their ammo balanced",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
			,["Ensure if rearm/resupply/repair are intended, the tools/vehicles/stations are available.",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
			,["If transport vehicles are assigned, ensure they have a use for the duration of a mission, not just the insertion.",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
        ],D_PASSFAIL,"",D_NOTEFLAG
    ]
    ,["MISSION DESIGN CHECKLIST",
        [
            ["Make sure the players can kill whatever Zeus intends to spawn in.",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
			,["Do all assets or force multipliers have appropriate counters?",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
            ,["Are the objectives conducive to fun game play and doable within 90 minutes to include safestart?",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
			,["When using multiple specialities, do they make sense to be used together and/or fit the mission type?",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
			,["Is the terrain balanced for all sides?",D_CHECK,MISSION_TYPE_APPLIES_TVT]
			,["Can the mission be seen as completable by either side given assets, gear, and numbers ratio?",D_CHECK,MISSION_TYPE_APPLIES_TVT]
        ],D_PASSFAIL,"",D_NOTEFLAG
    ]
    ,["OTHER CONSIDERATIONS CHECKLIST",
        [
            ["Ensure you're going to potato spectator on death",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
			,["Make sure that no heavy scripts are killing server FPS/CPS",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
			,["Make sure all scripts work correctly.",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
			,["Is deploy enabled if being used?",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
			,["Is the FH and FH vehicle setup or disabled as needed?",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
			,["Do both sides have an objective other than 'kill each other'?",D_CHECK,MISSION_TYPE_APPLIES_TVT]
            ,["Ultimately, from every role/perspective, does the mission look fun?",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
        ],D_PASSFAIL,"",D_NOTEFLAG
    ]
];

GVAR(MissionMakerChecklistMaster) = [
    ["MISSION MAKERS CHECKLIST",
        [
            ["Are both player and zeus briefings clear?",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
            ,["Are the objective markers in the right locations and accurate?",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
            ,["Is the gear for both sides correct?",D_CHECK,MISSION_TYPE_APPLIES_TVT]
            ,["Does each class have ammo, radios, and medical gear?",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
			,["Do all AI have the correct ammo, gps, and other gear?",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
			,["Are preplaced AI on HC?",D_CHECK,MISSION_TYPE_APPLIES_COOP]
            ,["Are the objectives concise and not spread too far apart?",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
			,["Are specialities labelled on the slotting screen?",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
			,["Do all assets or force multipliers have appropriate counters?",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
			,["Can the mission be completed without relying on GI to operate vehicles?",D_CHECK,MISSION_TYPE_APPLIES_COOP]
            ,["AI triggers/spawns working ok? How is server FPS?",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
        ],D_PASSFAIL,"",D_NOTEFLAG
    ]
];

GVAR(GeneraMissionNotesForMM) = "";

if (hasInterface) then { // Change briefing map's "Continue" button to red "BRIEF ON MAP" if it has the tag
	_mapBrief = getMissionConfigValue QEGVAR(missionTesting,briefOnMap);
	if (_mapBrief) exitWith { 
		INFO("brief on map");
		[{
			(!isNull findDisplay 37) || {!isNull findDisplay 52} || {!isNull findDisplay 53} || {!isNull findDisplay 12}
		}, {
			{
				if (!isNull findDisplay _x) exitWith {
					private _okButton = (findDisplay _x) displayCtrl 1;
					_okButton ctrlSetText "BRIEF ON MAP";
					_okButton ctrlSetTextColor [1,0,0.2,1];
				};
			} forEach [37,52,53]; // ignore 12
		}] call CBA_fnc_waitUntilAndExecute;
	};
};
