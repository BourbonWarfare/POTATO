class CfgVehicles {
    class Item_Base_F;
    class potato_cheezItBoxPlaceable: Item_Base_F {
        scope = 2;
        scopeCurator = 2;
        displayName = "[Potato] Placeable Cheez-It Box";
        author = "Potato";
        vehicleClass = "Items";
        class TransportItems {
            MACRO_ADDITEM(potato_cheezItBox,1);
        };
    };
    class potato_serverPlaceable: Item_Base_F {
        scope = 2;
        scopeCurator = 2;
        displayName = "[Potato] Placeable Dedicated Server";
        author = "Potato";
        vehicleClass = "Items";
        class TransportItems {
            MACRO_ADDITEM(potato_serverBox,1);
        };
    };
    class potato_gamestopPlaceable: Item_Base_F {
        scope = 2;
        scopeCurator = 2;
        displayName = "[Potato] Placeable Gamestop Stock";
        author = "Potato";
        vehicleClass = "Items";
        class TransportItems {
            MACRO_ADDITEM(potato_gamestop,1);
        };
    };
};
