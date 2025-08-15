class CfgUIGrids {
    class IGUI {
        class Presets {
            class Arma3 {
                class Variables {// based on grid_hint
                    GVAR(grid)[] = {
                        {
                            SAFESTART_MENU_DEFAULT_X_QUOTE,
                            SAFESTART_MENU_DEFAULT_Y_QUOTE,
                            SAFESTART_MENU_WIDTH,
                            "15.5 * ((safezoneW / safezoneH) min 1.2) / 25"
                        },
                        "((safeZoneW / safeZoneH) min 1.2) / 40",
                        "(((safeZoneW / safeZoneH) min 1.2) / 1.2) / 25"
                    };
                };
            };
        };
        class Variables {
            class GVAR(grid) {
                displayName = "Potato Safe Start";
                description = "Potato Safe start info card location. Adjust what's shown in CBA Settings.";
                preview = QPATHTOF(data\ui\safeStartMenu_ca.paa); // ToDo Make Preview
                saveToProfile[] = {0, 1};
                canResize = 0;
            };
        };
    };
};
