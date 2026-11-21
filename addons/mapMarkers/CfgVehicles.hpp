class CfgVehicles {
    class Logic;
    class Module_F: Logic {
        class AttributesBase {
            class Checkbox;
            class Edit;
        };
    };
    class GVAR(mapMarkers): Module_F {
        author = QUOTE(PREFIX);
        category = QEGVAR(core,util);
        scope = 2;
        displayName = "Modify Marker Sharing";
        icon = "iconModule";
        isGlobal = 2;
        isTriggerActivated = 0;
        function = QFUNC(module_shareMarkerInit);
        class Attributes: AttributesBase {
            class disableNetwork: Checkbox {
                displayName = "Disable side markers";
                defaultValue = "true";
                property = QGVAR(disableNetwork);
                tooltip = "Disable putting markers into global/side/vehicle channels.";
            };
            class enableShare: Checkbox {
                displayName = "Enable Sharing";
                defaultValue = "true";
                property = QGVAR(enableShare);
                tooltip = "Enable ACE actions to share map markers to those around them and specific players.";
            };
            class enableCopyFrom: Checkbox {
                displayName = "Enable Copying";
                defaultValue = "true";
                property = QGVAR(enableCopyFrom);
                tooltip = "Enable ACE action to share copy map markers from a specific unit.";
            };
            class enableCopyFromEnemy: Checkbox {
                displayName = "Enable Cross Side Copying";
                defaultValue = "false";
                property = QGVAR(enableCopyFromEnemy);
                tooltip = "Enable sharing between different sides (e.g., BluFor to OpFor).";
            };
            /*class enableCopyFromCorpse: Checkbox {
                displayName = "[EXP] Enable Copying from Corpses";
                defaultValue = "false";
                tooltip = "[EXPERIMENTAL] Enable copying infor off of corpses.";
            };*/
            class shareRadius: Edit {
                displayName = "Share Radius (m)";
                defaultValue = "5";
                property = QGVAR(shareRadius);
                tooltip = "The radius in meters markers can be shared in. Max 15m.";
                validate = "number";
            };
        };
    };
    // ACE self interact action
    class Man;
    class CAManBase: Man {
        class ACE_SelfActions {
            class ADDON {
                condition = QUOTE(visibleMap && GVAR(allowImport) && {!(missionNamespace getVariable [ARR_2(QQGVAR(disableNetwork),false)]) && EGVAR(safeStart,safeStartEnabled) && {leader _target == _target}});
                displayName = "Load or Save Markers";
                exceptions[] = {"isNotDragging","notOnMap","isNotInside","isNotSitting"};
                icon = "\a3\ui_f\data\GUI\Rsc\RscDisplayArsenal\map_ca.paa";
                statement = QUOTE(createDialog [QQGVAR(saveMarkersDialog)]);
            };
        };
    };
};
