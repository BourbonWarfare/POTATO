#include "\a3\3den\UI\macros.inc"
#include "\a3\3den\UI\resincl.inc"
#define SIZE_XXS 1

class ctrlMenuStrip;

// Adds the menu item to the POTATO Drop down in EDEN.
class display3DEN {
    class Controls {
        class MenuStrip: ctrlMenuStrip {
            class Items {
                class PREFIX {
                    items[] += {QGVAR(missionTesting)};
                };
                class GVAR(missionTesting) {
                    text = "Mission Settings";
                    action = QUOTE(edit3DENMissionAttributes QUOTE(QGVAR(missionTestingInfo)););
                };
            };
        };
    };
};

// Attribute dialog in Eden for saving settings.

class Cfg3DEN {
    class Attributes {
        class Default;
        class Title: Default {
        class Controls {
            class Title;
            };
        };
        class TitleWide: Default {
            class Controls {
                class Title;
            };
        };
	};

	class Mission {
		class GVAR(missionTestingInfo) {
			displayName = "Mission Settings";
			display = "Display3DENEditAttributes";
			class AttributeCategories {
				class MissionGeneraInfo {
                    displayName = "General Information";
                    collapsed = 0;
					class Attributes {
						class GVAR(missionType) {
                            displayName = "Mission Type:";
							property = QGVAR(missionType);
                            control = QUOTE(combo);
                            defaultValue = 0;
                            typeName = "NUMBER";
                            class Values {
                                class SELECT {
                                    name = "SELECT";
                                    value = 0;
                                };
                                class COOP {
                                    name = "COOP";
                                    value = 1;
                                };
                                class TVT {
                                    name = "TVT";
                                    value = 2;
                                };
                            };
						};
						class GVAR(missionVersion) {
                            displayName = "Mission Version:";
                            control = QUOTE(EditShort);
							property = QGVAR(missionVersion);
                            defaultValue = 1;
                            typeName = "STRING";
						};
					};
				};
				class MissionTimers {
                    displayName = "Mission Timers";
                    collapsed = 0;
					class Attributes {
						class GVAR(SSTimeGiven) {
                            displayName = "Safe Start Time Length (mins):";
							property = QGVAR(SSTimeGiven);
                            control = QUOTE(EditShort);
                            defaultValue = "15";
                            typeName = "STRING";
						};
						class GVAR(missionTimeLength) {
                            displayName = "Mission Length (mins):";
							property = QGVAR(missionTimeLength);
                            control = QUOTE(EditShort);
                            defaultValue = "-1";
                            typeName = "STRING";
						};
					};
				};
				class VDLimiter {
                    displayName = "View Distance Limit";
                    collapsed = 0;
					class Attributes {
						class GVAR(maxViewDistance) {
                            displayName = "Max View Distance:";
							property = QGVAR(maxViewDistance);
                            control = QUOTE(EditShort);
                            defaultValue = "-1";
                            typeName = "STRING";
						};
					};
				};
				class medicalSystem {
                    displayName = "Medical System";
                    collapsed = 0;
					class Attributes{
						class GVAR(medSystem) {
                            displayName = "Medical System:";
							property = QGVAR(medSystem);
                            control = QUOTE(combo);
							typeName = "NUMBER";
                            defaultValue = 99;
                            expression = "_this setVariable ['%s',_value];";
							class Values {
								class def {
                                    name = "SELECT";
                                    value = 99;
                                };
                                class MEV {
                                    name = "MEV";
                                    value = 0;
                                };
                                class CCP {
                                    name = "CCPs and FHs";
                                    value = 1;
                                };
                            };
						};
					};
				};
				class ForwardDeploy {
                    displayName = "Forward Deploy";
                    collapsed = 0;
					class Attributes {
						class GVAR(forwardDeploy) {
                            displayName = "Enable Forward Deploy:";
							property = QGVAR(forwardDeploy);
                            control = QUOTE(Checkbox);
                            defaultValue = QUOTE(false);
                            expression = "_this setVariable ['%s',_value];";
						};
					};
				};
				class MiniArsenal {
                    displayName = "Mini Arsenal";
                    collapsed = 0;
					class Attributes {
						class GVAR(miniArsenal) {
                            displayName = "Enable Mini Arsenal:";
							property = QGVAR(miniArsenal);
                            control = QUOTE(Checkbox);
                            defaultValue = QUOTE(true);
                            expression = "_this setVariable ['%s',_value];";
						};
						class GVAR(miniArsenalType) {
                            displayName = "Arsenal Type:";
							property = QGVAR(miniArsenalType);
                            control = QUOTE(combo);
							typeName = "NUMBER";
                            defaultValue = 0;
                            expression = "_this setVariable ['%s',_value];";
							class Values {
								class def {
									name = "SELECT";
                                    value = 0;
								};
                                class ROLES {
                                    name = "Normal (Default)";
                                    value = 1;
                                };
                                class GROUPS {
                                    name = "Specialized";
                                    value = 2;
                                };
							};
						};
					};
				};
				class ArmPatches {
                    displayName = "Arm Patches";
                    collapsed = 0;
					class Attributes{
						class GVAR(armPatches) {
                            displayName = "Arm Patch Type:";
							property = QGVAR(armPatches);
                            control = QUOTE(combo);
							typeName = "NUMBER";
                            defaultValue = 1;
                            expression = "_this setVariable ['%s',_value];";
							class Values {
                                class ROLES {
                                    name = "Roles";
                                    value = 0;
                                };
                                class GROUPS {
                                    name = "Groups";
                                    value = 1;
                                };
                                class TEAMS {
                                    name = "Teams";
                                    value = 2;
                                };
								class OFF {
                                    name = "None";
                                    value = -1;
                                };
                            };
						};
					};
				};
				class radioSystem {
                    displayName = "Radio System (Not working yet - use gearscript)";
                    collapsed = 0;
					class Attributes{
						class GVAR(radioSystem) {
                            displayName = "Radio System:";
							property = QGVAR(radioSystem);
                            control = QUOTE(combo);
							typeName = "NUMBER";
                            defaultValue = 1;
                            expression = "_this setVariable ['%s',_value];";
							class Values {
                                class snet {
                                    name = "Squad Nets";
                                    value = 0;
                                };
                                class fnet {
                                    name = "Fireteam Nets";
                                    value = 1;
                                };
                                class lonly {
                                    name = "No Radios for GI";
                                    value = 2;
                                };
                            };
						};
					};
				};
				class MapBrief {
                    displayName = "Map Brief";
                    collapsed = 0;
					class Attributes {
						class GVAR(briefOnMap) {
                            displayName = "Map Brief:";
							property = QGVAR(briefOnMap);
                            control = QUOTE(Checkbox);
                            defaultValue = QUOTE(false);
                            expression = "_this setVariable ['%s',_value];";
						};
					};
				};
				class MissionFlags {
                    displayName = "Mission Flags";
                    collapsed = 0;
					class Attributes{
						class GVAR(missionFlagCustomScripting) {
                            displayName = "Custom Scripting:";
                            control = QUOTE(Checkbox);
							property = QGVAR(missionFlagCustomScripting);
                            defaultValue = QUOTE(false);
                            expression = "_this setVariable ['%s',_value];";
						};
						class GVAR(missionFlagCustomLoadout) {
                            displayName = "Custom Loadout:";
                            control = QUOTE(Checkbox);
							property = QGVAR(missionFlagCustomLoadout);
                            defaultValue = QUOTE(false);
                            expression = "_this setVariable ['%s',_value];";
						};
						class GVAR(missionFlagCustomVicLoadout) {
                            displayName = "Custom Vehicle Loadout:";
                            control = QUOTE(Checkbox);
							property = QGVAR(missionFlagCustomVicLoadout);
                            defaultValue = QUOTE(false);
                            expression = "_this setVariable ['%s',_value];";
						};
						class GVAR(missionFlagUnitSpecificBriefing) {
                            displayName = "Unit Specific Briefings:";
                            control = QUOTE(Checkbox);
							property = QGVAR(missionFlagUnitSpecificBriefing);
                            defaultValue = QUOTE(false);
                            expression = "_this setVariable ['%s',_value];";
						};
					};
				};
				class MissionMakerNotes {
                    displayName = "Mission Maker Notes";
                    collapsed = 0;
					class Attributes{
						class GVAR(missionMakerNotesForTesters) {
                            attributeSave = QUOTE(_value call EFUNC(briefing,convertNewLineToHTML));
                            attributeLoad = QUOTE([ARR_2(_this,_value)] call EFUNC(briefing,convertHTMLToNewLine));
                            displayName = "Any other notes for Mission Testers:";
                            control = QUOTE(EditMulti5);
							property = QGVAR(missionMakerNotesForTesters);
                            defaultValue = "''";
						};
					};
				};
			};
		};
	};
};