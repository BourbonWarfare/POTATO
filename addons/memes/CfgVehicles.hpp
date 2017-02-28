class CfgVehicles {
    class Item_Base_F;
    class potato_cheezItBoxPlaceable: Item_Base_F {
        scope = 2;
        scopeCurator = 2;
        displayName = "Placeable Cheez-It Box";
        author = "Potato";
        vehicleClass = "Items";
        class TransportItems {
            MACRO_ADDITEM(potato_cheezItBox,1);
        };
    };
};
