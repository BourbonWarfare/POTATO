class CfgVehicles {
    class Logic;
    class Module_F: Logic {
        class AttributesBase {
            class Combo;
        };
    };
    class GVAR(moveHcsToModule): Module_F {
        author = QUOTE(PREFIX);
        scope = 1;
        scopeCurator = 2;
        displayName = "Move headless clients to module";
        category = QEGVAR(core,util);
        function = QFUNC(moveHcsToModule);
        isTriggerActivated = 0;
        isGlobal = 0;
        curatorCost = 0;
        class Arguments {};
        class Attributes {};
    };

    class GVAR(sideMarker): Module_F {
        author = QUOTE(PREFIX);
        category = QEGVAR(core,util);
        scope = 2;
        displayName = "Side Marker";
        icon = QUOTE(PATHTOF(UI\sideMarker_ca.paa));
        isGlobal = 2;
        isTriggerActivated = 0;
        function = QFUNC(sideMarker);

        class Attributes {
            class east {
                displayName = "Show to east:";
                control = "Checkbox";
                property = QGVAR(east);
                expression = "_this setVariable ['%s',_value, true];";
                defaultValue = "(false)";
            };
            class west: east {
                displayName = "Show to west:";
                property = QGVAR(west);
                expression = "_this setVariable ['%s',_value, true];";
            };
            class independent: east {
                displayName = "Show to independent:";
                property = QGVAR(independent);
                expression = "_this setVariable ['%s',_value, true];";
            };
            class civilian: east {
                displayName = "Show to civilians:";
                property = QGVAR(civilian);
                expression = "_this setVariable ['%s',_value, true];";
            };
            class text {
                displayName = "Marker text:";
                control = "Edit";
                property = QGVAR(text);
                expression = "_this setVariable ['%s',_value, true];";
                defaultValue = "''";
            };
            class direction {
                displayName = "Marker direction:";
                control = QGVAR(sideMarkerDir);
                property = QGVAR(direction);
                expression = "_this setVariable ['%s',_value, true];";
                defaultValue = "0";
            };
            class color {
                control = QGVAR(sideMarkerColor);
                property = QGVAR(color);
                expression = "_this setVariable ['%s',_value, true];";
                defaultValue = "'ColorBlack'";
            };
            class icon {
                control = QGVAR(sideMarkerIcon);
                property = QGVAR(icon);
                expression = "_this setVariable ['%s',_value, true];";
                defaultValue = "'mil_dot_noShadow'";
            };
        };
    };

    class GVAR(zeus_resupplyBoxes): Module_F {
        author = QUOTE(PREFIX);
        category = QEGVAR(core,util);
        scope = 1;
        scopeCurator = 2;
        isTriggerActivated = 1;
        displayName = "Create defined resupply boxes";
        function = QFUNC(zeus_resupplyBoxes);
        curatorCost = 0;
    };

    class GVAR(zeus_missionHint): Module_F {
        author = QUOTE(PREFIX);
        category = QEGVAR(core,util);
        scope = 1;
        scopeCurator = 2;
        isTriggerActivated = 1;
        displayName = "Mission Hint";
        function = QFUNC(zeus_missionHint);
        curatorInfoType = QGVAR(RscDisplayAttributes_missionHint);
        curatorCost = 0;
        class Arguments {};
        class Attributes {};
    };

    class GVAR(zeus_globalSetSkill): Module_F {
        author = QUOTE(PREFIX);
        category = QEGVAR(core,util);
        scope = 1;
        scopeCurator = 2;
        isGlobal = 1;
        displayName = "Global Set AI Skill";
        function = QFUNC(setSkillsModule);
        curatorCost = 0;
        class Arguments {};
        class Attributes {};
    };

    class GVAR(zeus_banziCharge): Module_F {
        author = QUOTE(PREFIX);
        category = QUOTE(PREFIX); // TODO: AI Behvaiors cleanup
        scope = 1;
        scopeCurator = 2;
        isTriggerActivated = 0;
        isGlobal = 2;
        displayName = "Banzi Attack!";
        function = QFUNC(zeus_banziCharge);
        curatorCanAttach = 1;
    };

    class GVAR(zeus_bodyBag): Module_F {
        author = QUOTE(PREFIX);
        category = QUOTE(PREFIX);
        scope = 1;
        scopeCurator = 2;
        isTriggerActivated = 0;
        isGlobal = 1;
        displayName = "Body Bag";
        function = QFUNC(zeus_bodyBag);
        curatorCanAttach = 1;
    };
    class GVAR(identity_module): Module_F {
        author = QUOTE(PREFIX);
        category = QEGVAR(core,util);
        scope = 2;
        displayName = "Set AI Identity (Voices)";
        isGlobal = 0;
        isTriggerActivated = 0;
        function = QFUNC(identity_module);
        class Attributes: AttributesBase {
            class Side: Combo {
                displayName = "$STR_eval_typeside";
                property = "side";
                control="Combo";
                typeName = "NUMBER";
                defaultValue = 2;
                class values {
                    class West {
                        name = "$STR_WEST";
                        value = 1;
                    };
                    class East {
                        name = "$STR_east";
                        value = 2;
                    };
                    class Indp {
                        name = "$STR_guerrila";
                        value = 3;
                    };
                    class Civ {
                        name = "$STR_civilian";
                        value = 4;
                    };
                };
            };
            class Speaker: Combo {
                displayName = "$STR_controls_presets";
                property = "speaker";
                defaultValue="'LanguageFRE_F'";
                class values {
                    class LanguageENG_F {
                        name = "American English";
                        value = "LanguageENG_F";
                        picture = "\a3\Ui_f\data\Map\Markers\Flags\usa_ca.paa";
                        data[] = {"Male01ENG","Male02ENG","Male03ENG","Male04ENG","Male05ENG","Male06ENG","Male07ENG","Male08ENG","Male09ENG","Male10ENG","Male11ENG","Male12ENG"};
                    };
                    class LanguageENGB_F {
                        name = "Metric English";
                        value = "LanguageENGB_F";
                        picture = "\a3\Ui_f\data\Map\Markers\Flags\uk_ca.paa";
                        data[] = {"Male01ENGB","Male02ENGB","Male03ENGB","Male04ENGB","Male05ENGB"};
                    };
                    class LanguageGRE_F {
                        name = "Altian English (Greek)";
                        value = "LanguageGRE_F";
                        picture = "\a3\Ui_f\data\Map\Markers\Flags\altis_ca.paa";
                        data[] = {"Male01GRE","Male02GRE","Male03GRE","Male04GRE","Male05GRE","Male06GRE"};
                    };
                    class LanguagePER_F {
                        name = "Farsi";
                        value = "LanguagePER_F";
                        picture = "\a3\Ui_f\data\Map\Markers\Flags\csat_ca.paa";
                        data[] = {"Male01PER","Male02PER","Male03PER"};
                    };
                    class LanguageCHI_F {
                        name = "Chinese";
                        value = "LanguageCHI_F";
                        picture = "\a3\Ui_f\data\Map\Markers\Flags\viper_ca.paa";
                        data[] = {"Male01CHI","Male02CHI","Male03CHI"};
                    };
                    class LanguageFRE_F {
                        name = "French (Syndicat)";
                        value = "LanguageFRE_F";
                        picture = "\a3\Ui_f\data\Map\Markers\Flags\syndicat_ca.paa";
                        data[] = {"Male01FRE","Male02FRE","Male03FRE"};
                    };
                    class LanguageENGFRE_F {
                        name = "French English (Tanoa)";
                        value = "LanguageENGFRE_F";
                        picture = "\a3\Ui_f\data\Map\Markers\Flags\tanoa_ca.paa";
                        data[] = {"Male01ENGFRE","Male02ENGFRE"};
                    };
                    class LanguagePOL_F {
                        name = "Polish";
                        value = "LanguagePOL_F";
                        picture = "\a3\UI_F_Enoch\Data\CfgMarkers\Livonia_CA.paa";
                        data[] = {"Male01POL","Male02POL","Male03POL"};
                    };
                    class LanguageRUS_F {
                        name = "Russian";
                        value = "LanguageRUS_F";
                        picture = "\a3\UI_F_Enoch\Data\CfgMarkers\Russia_CA.paa";
                        data[] = {"Male01RUS","Male02RUS","Male03RUS"};
                    };
                    class CUP_D_Language_TK {
                        name = "Takistan? [CUP]";
                        value = "CUP_D_Language_TK";
                        picture = "\a3\Ui_f\data\Map\Markers\Flags\csat_ca.paa";
                        data[] = {"CUP_D_Male01_TK","CUP_D_Male02_TK","CUP_D_Male03_TK","CUP_D_Male04_TK","CUP_D_Male05_TK"};
                    };
                    class CUP_D_Language_CZ { // merged with CUP_D_Language_CZ_ACR
                        name = "Czech [CUP]";
                        value = "CUP_D_Language_CZ";
                        picture = "\A3\ui_f\data\map\markers\flags\CzechRepublic_ca.paa";
                        data[] = {"CUP_D_Male01_CZ","CUP_D_Male02_CZ","CUP_D_Male03_CZ","CUP_D_Male04_CZ","CUP_D_Male05_CZ", "CUP_D_Male01_CZ_ACR","CUP_D_Male02_CZ_ACR","CUP_D_Male03_CZ_ACR","CUP_D_Male04_CZ_ACR","CUP_D_Male05_CZ_ACR"};
                    };
                    class gm_language_deu_male {
                        name = "German [GM]";
                        value = "gm_language_deu_male";
                        picture = "\A3\Ui_f\data\Map\Markers\Flags\germany_ca.paa";
                        data[] = {"gm_voice_male_deu_01","gm_voice_male_deu_02","gm_voice_male_deu_03","gm_voice_male_deu_04","gm_voice_male_deu_05","gm_voice_male_deu_06","gm_voice_male_deu_07","gm_voice_male_deu_08","gm_voice_male_deu_09"};
                    };
                };
            };
        };
    };

    class GVAR(safeStartTeleport): Module_F {
        author = QUOTE(PREFIX);
        category = QEGVAR(core,util);
        scope = 2;
        scopeCurator = 1;
        isTriggerActivated = 0;
        isGlobal = 2;
        displayName = "Teleport - Map Click";
        icon = "iconModule";
        function = QFUNC(initMapClickTeleport);

        class Attributes {
            class player {
                displayName = "Player Teleport";
                tooltip = "Allow players to teleport themselves within the designated area.";
                control = "Checkbox";
                property = QGVAR(player);
                expression = "_this setVariable ['%s',_value, true];";
                defaultValue = "false";
            };
            class group: player {
                displayName = "Group Teleport";
                tooltip = "Allow group leaders (FTLs, SLs) to teleport their group within the designated area.";
                property = QGVAR(group);
                expression = "_this setVariable ['%s',_value, true];";
            };
            class vehicle: player {
                displayName = "Vehicle Teleport";
                tooltip = "Allow players to teleport their vehicle within the designated area.";
                property = QGVAR(vehicle);
                expression = "_this setVariable ['%s',_value, true];";
            };
            class safeStart: player {
                displayName = "Require Safe Start";
                tooltip = "Require safe-start to be on for teleports to work or appear in ACE self-interact.";
                property = QGVAR(safeStart);
                expression = "_this setVariable ['%s',_value, true];";
                defaultValue = "true";
            };
            class useZones: player {
                displayName = "Restrict Teleports to Marker Zones";
                tooltip = "Should player only be able to teleport within the listed zones.";
                property = QGVAR(useZones);
                expression = "_this setVariable ['%s',_value, true];";
                defaultValue = "true";
            };
            class tpZones {
                displayName = "Array of Area Markers";
                control = "Edit";
                tooltip = "Array of area markers teleports are restricted to/from. Markers will be deleted at the end of safe start.";
                property = QGVAR(tpZones);
                expression = "_this setVariable ['%s',_value, true];";
                defaultValue = "'[''zone_0'']'";
            };
        };
    };

    class GVAR(objectTeleport): Module_F {
        author = QUOTE(PREFIX);
        category = QEGVAR(core,util);
        scope = 2;
        scopeCurator = 1;
        isTriggerActivated = 0;
        isGlobal = 2;
        displayName = "Teleport - Object to Position";
        icon = "iconModule";
        function = QFUNC(initObjectTeleport);

        class Attributes {
            class safeStart {
                displayName = "Require Safe Start";
                tooltip = "Require safe-start to be on for teleports to work or appear in ACE self-interact.";
                control = "Checkbox";
                property = QGVAR(safeStart);
                expression = "_this setVariable ['%s',_value, true];";
                defaultValue = "true";
            };
            class holdLength {
                displayName = "Time to  Hold";
                tooltip = "How long a player must hold down their mouse button before teleporting.";
                control = "Edit";
                property = QGVAR(holdLength);
                expression = "_this setVariable ['%s',_value, true];";
                defaultValue = 2;
                validate = "number";
            };
            class posName {
                displayName = "Position Name";
                control = "Edit";
                tooltip = "What name should the action show.";
                property = QGVAR(posName);
                expression = "_this setVariable ['%s',_value, true];";
                defaultValue = "'Forward Position'";
            };
        };
    };

    class GVAR(boxBrief_cfgLoadouts): Module_F {
        author = QUOTE(PREFIX);
        category = QEGVAR(core,util);
        scope = 2;
        displayName = "Create Resupply Entries (CfgLoadouts)";
        icon = "iconCrate";
        isGlobal = 2;
        isTriggerActivated = 0;
        function = QFUNC(createBoxDiaryCfg);

        class Attributes: AttributesBase {
            class Side: Combo {
                displayName = "$STR_eval_typeside";
                property = QGVAR(side);
                expression = "_this setVariable ['%s', _value, true];";
                control="Combo";
                typeName = "NUMBER";
                defaultValue = 1;
                tooltip = "The side to show the info to";
                class values {
                    class All {
                        name = "All";
                        value = 0;
                    };
                    class West {
                        name = "$STR_WEST";
                        value = 1;
                    };
                    class East {
                        name = "$STR_east";
                        value = 2;
                    };
                    class Indp {
                        name = "$STR_guerrila";
                        value = 3;
                    };
                };
            };
            class Box {
                control = QGVAR(boxBriefCombo);
                defaultValue = 0;
                displayName = "Resupply Crate Classes";
                expression = "_this setVariable ['%s', _value, true];";
                property = QGVAR(boxClass);
                typeName = "STRING";
                tooltip = "The classes to display. If yours is missing make sure your CfgLoadouts is properly configured, save your mission, and try again.";
            };
        };
    };
    class GVAR(boxBrief_sync): Module_F {
        author = QUOTE(PREFIX);
        category = QEGVAR(core,util);
        scope = 2;
        displayName = "Create Resupply Entries (Sync)";
        icon = "iconCrate";
        isGlobal = 2;
        isTriggerActivated = 0;
        function = QFUNC(createBoxDiarySync);
        class Attributes: AttributesBase {
            class Side: Combo {
                displayName = "$STR_eval_typeside";
                property = QGVAR(side);
                expression = "_this setVariable ['%s', _value, true];";
                control="Combo";
                typeName = "NUMBER";
                defaultValue = 1;
                tooltip = "The side to show the info to";
                class values {
                    class All {
                        name = "All";
                        value = 0;
                    };
                    class West {
                        name = "$STR_WEST";
                        value = 1;
                    };
                    class East {
                        name = "$STR_east";
                        value = 2;
                    };
                    class Indp {
                        name = "$STR_guerrila";
                        value = 3;
                    };
                };
            };
        };
    };
};
