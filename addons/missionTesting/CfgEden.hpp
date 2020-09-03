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
                    text = "Mission Testing Attributes";
                    action = QUOTE(edit3DENMissionAttributes QUOTE(QGVAR(missionTestingInfo)););
                };
            };
        };
    };
};

// Attribute dialog in Eden for saving settings.

class Cfg3DEN{
    class Attributes{
        class Default;
        class Title: Default{
        class Controls{
            class Title;
            };
        };
        class TitleWide: Default{
            class Controls{
                class Title;
            };
        };
	};

	class Mission{
		class GVAR(missionTestingInfo){
			displayName = "Mission Testing Information";
			display = "Display3DENEditAttributes";
			class AttributeCategories{
				class MissionGeneraInfo{
                    displayName = "General Information";
                    collapsed = 0;
					class Attributes{
						class GVAR(missionType){
                            displayName = "Mission Type:";
							property = QGVAR(missionType);
                            control = QUOTE(combo);
                            defaultValue = 1;
                            typeName = "NUMBER";
                            class Values{
                                class COOP{
                                    name = "COOP";
                                    value = 1;
                                };
                                class TVT{
                                    name = "TVT";
                                    value = 2;
                                };
                            };
						};
						class GVAR(missionVersion){
                            displayName = "Mission Version:";
                            control = QUOTE(EditShort);
							property = QGVAR(missionVersion);
                            defaultValue = 1;
                            typeName = "STRING";
						};
					};
				};
				class MissionPlayerCount{
                    displayName = "Player Count";
                    collapsed = 0;
					class Attributes{
						class GVAR(playerCountMinimum){
                            displayName = "Player Count Minimum:";
							property = QGVAR(playerCountMinimum);
                            control = QUOTE(EditShort);
                            defaultValue = "20";
                            typeName = "STRING";
						};
						class GVAR(playerCountRecommended){
                            displayName = "Player Count Recommended:";
							property = QGVAR(playerCountRecommended);
                            control = QUOTE(EditShort);
                            defaultValue = "40";
                            typeName = "STRING";
						};
						class GVAR(playerCountMaximum){
                            displayName = "Player Count Maximum:";
							property = QGVAR(playerCountMaximum);
                            control = QUOTE(EditShort);
                            defaultValue = "60";
                            typeName = "STRING";
						};
					};
				};
				class MissionTags{
                    displayName = "Mission Tags";
                    collapsed = 0;
					class Attributes{
						class GVAR(missionTag1){
                            displayName = "Mission Tag 1:";
                            control = QUOTE(combo);
							property = QGVAR(missionTag1);
                            expression = "_this setVariable ['%s', _value];";
                            typeName = "NUMBER";
                            defaultValue = 0;
                            class Values{
                                class None{
                                    name = "None";
                                    value = 0;
                                };
                                class NIGHT{
                                    name = "NIGHT";
                                    value = 1;
                                };
                                class DASKDAWN{
                                    name = "DUSK/DAWN";
                                    value = 2;
                                };
                                class MSV{
                                    name = "MSV";
                                    value = 3;
                                };
                                class TVT1{
                                    name = "TVT1";
                                    value = 4;
                                };
                                class TVT2{
                                    name = "TVT2";
                                    value = 5;
                                };
                                class AH{
                                    name = "AH";
                                    value = 6;
                                };
                            };
						};
                        class GVAR(missionTag2) : GVAR(missionTag1){
                            displayName = "Mission Tag 2:";
                            property = QGVAR(missionTag2);
                        };
                        class GVAR(missionTag3) : GVAR(missionTag1){
                            displayName = "Mission Tag 3:";
                            property = QGVAR(missionTag3);
                        };
					};
				};
				class MissionFlags{
                    displayName = "Mission Flags";
                    collapsed = 0;
					class Attributes{
						class GVAR(missionFlagCustomScripting){
                            displayName = "Custom Scripting:";
                            control = QUOTE(Checkbox);
							property = QGVAR(missionFlagCustomScripting);
                            defaultValue = QUOTE(false);
						};
						class GVAR(missionFlagCustomLoadout){
                            displayName = "Custom Loadout:";
                            control = QUOTE(Checkbox);
							property = QGVAR(missionFlagCustomLoadout);
						};
						class GVAR(missionFlagCustomVicLoadout){
                            displayName = "Custom Vehicle Loadout:";
                            control = QUOTE(Checkbox);
							property = QGVAR(missionFlagCustomVicLoadout);
						};
						class GVAR(missionFlagUnitSpecificBriefing){
                            displayName = "Unit Specific Briefings:";
                            control = QUOTE(Checkbox);
							property = QGVAR(missionFlagUnitSpecificBriefing);
						};
					};
				};
				class MissionMakerNotes{
                    displayName = "Mission Maker Notes";
                    collapsed = 0;
					class Attributes{
						class GVAR(missionMakerNotesForTesters){
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
