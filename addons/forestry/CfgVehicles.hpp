class CfgVehicles {
    class Man;
    class CAManBase: Man {
        class ACE_SelfActions {
            class BW_Menu {
                displayName = "Clear Brush";
                condition = "true";
                statement = "";
                icon = "\a3\modules_f\data\hideterrainobjects\icon32_ca.paa";
                exceptions[] = {"isNotSwimming", "isNotInside", "isNotSitting", "isNotOnLadder", "isNotRefueling"};

                class Chop_Tree {
                    displayName = "Chop down tree";
                    icon = QPATHTOF(resources\tree.paa);
                    condition = QUOTE(call FUNC(canChop));
                    statement = QUOTE(call FUNC(doChop));
                    exceptions[] = {};
                };
/*
                class Flatten_Grass  {
                    displayName = "Flatten Grass";
                    icon = QPATHTOF(resources\grass.paa);
                    condition = "insideBuilding player != 1";
                    statement = QUOTE(call FUNC(doFlatten));
                    exceptions[] = {};
                };
*/
            };
        };
    };
};