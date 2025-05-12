#include "script_component.hpp"

GVAR(missionTestingActive) = false;

GVAR(MissionTestingChecklistMaster) = [
    ["PRE-MISSION CHECKLIST",
        [
            ["Ensure only slots that are meant to be played are in the mission.",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
            ,["Do a quick sanity check of the ratio",D_CHECK,MISSION_TYPE_APPLIES_TVT]
            ,["Make sure the mission description isn't confusing/vague",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
            ,["Read the briefings make sure they exist and are clear",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
            ,["Make sure objectives are marked",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
            ,["Check the play area for terrain imbalances and make sure the mission maker has taken them into account (I.E. defenders need better equipment and/or more people if terrain is not in their favour",D_CHECK,MISSION_TYPE_APPLIES_TVT]
            ,["Ensure there is a signals tab, and the channel names make sense for the mission",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
            ,["Ensure that if it is a night mission it is tagged as such in the mission description on the slotting screen",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
            ,["Ensure that if Safe Start ends automatically, it is clear from the slotting screen or a plan exists to inform leadership before mission start",D_CHECK,MISSION_TYPE_APPLIES_COOP]
        ],D_PASSFAIL,"",D_NOTEFLAG
    ]
    ,["GEAR CHECKLIST",
        [
            ["Ensure every soldier has the correct number of magazines/rockets.",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
            ,["Ensure soldiers have the correct radios and they're set to the right channel",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
            ,["Ensure the uniforms are what they should be. A lot of times updates will break classnames and soldiers will have default A3 uniforms.",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
            ,["Ensure the uniforms are positive identification friendly. If you can't tell what team is which from 100m, there's probably a problem.",D_CHECK,MISSION_TYPE_APPLIES_TVT]
            ,["Ensure every soldier type (I.E. FTL/AR/AAR/AT) has medical supplies.",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
            ,["Check for soldiers with magnified optics, and make sure the mission maker has both A) Intended this and B) has properly balanced it",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
        ],D_PASSFAIL,"",D_NOTEFLAG
    ]
    ,["VEHICLES CHECKLIST",
        [
            ["Ensure vehicle gear is correct for the side using it (Mainly for COOPs), or removed (mainly for TvTs)",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
            ,["Ensure the vehicles are balanced (I.E. if one team has a BTR, one team has the AT to kill it, or if two teams are racing to an objectives, their vics go about the same speed)",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
            ,["Ensure names of vehicle roles match Mission Makers' intent for qualifications to apply (ie. - if there's a 'Co-Pilot' role, it requires a Pilot Qual to slot)",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
            ,["Ensure vehicles with weapons have their ammo balanced, (I.E. a Little Bird with 32 rockets is overkill vs infantry)",D_CHECK,MISSION_TYPE_APPLIES_TVT]
        ],D_PASSFAIL,"",D_NOTEFLAG
    ]
    ,["COOP CHECKLIST",
        [
            ["Talk to the Zeus/mission-maker about their intent.",D_CHECK,MISSION_TYPE_APPLIES_COOP]
            ,["Make sure the humans can kill whatever Zeus intends to spawn in.",D_CHECK,MISSION_TYPE_APPLIES_COOP]
            ,["Make sure that no heavy scripts are killing server FPS/CPS",D_CHECK,MISSION_TYPE_APPLIES_COOP]
            ,["Talk about the objectives and make a call on if they are doable within the time frame of 75-80 minutes assuming ideal player conditions. Essentially is it likely that we will have all objectives completed or nearing completion around the 90 minute mark (including Safe Start).",D_CHECK,MISSION_TYPE_APPLIES_COOP]
        ],D_PASSFAIL,"",D_NOTEFLAG
    ]
    ,["OTHER CONSIDERATIONS CHECKLIST",
        [
            ["Check to see if AMA is in use for this mission",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
            ,["Verify that infantry weapon damage is reasonable",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
            ,["Ensure you're going to BW spectate on death",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
        ],D_PASSFAIL,"",D_NOTEFLAG
    ]
];

GVAR(MissionMakerChecklistMaster) = [
    ["MISSION MAKERS CHECKLIST",
        [
            ["Are the briefings clear?",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
            ,["Are the objective markers in the right place so that there won't be confusion?",D_CHECK,MISSION_TYPE_APPLIES_TVT]
            ,["Is the gear for both sides correct? (do a visual scan to make sure uniforms, gear, etc are correct)",D_CHECK,MISSION_TYPE_APPLIES_TVT]
            ,["Test each class on a fireteam. Do I have my ammo, radios, and medical gear?",D_CHECK,MISSION_TYPE_APPLIES_BOTH]
            ,["Are the objectives concise and not spread too far apart?",D_CHECK,MISSION_TYPE_APPLIES_COOP]
            ,["AI triggers/spawns working ok? How is server FPS?",D_CHECK,MISSION_TYPE_APPLIES_COOP]
        ],D_PASSFAIL,"",D_NOTEFLAG
    ]
];

GVAR(GeneraMissionNotesForMM) = "";

if (hasInterface) then { // Change briefing map's "Continue" button to red "BRIEF ON MAP" if it has the tag
    {
        private _missionTagVar = getMissionConfigValue _x;
        private _missionTag = if(isNil QUOTE(_missionTagVar)) then {"NONE"} else {A_MISSION_TAGS select _missionTagVar};
        if (_missionTag == "BRIEF ON MAP") exitWith {
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
    } forEach [QGVAR(missionTag1), QGVAR(missionTag2), QGVAR(missionTag3)];
};

