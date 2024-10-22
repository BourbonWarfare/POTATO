class CfgVehicles {
    class Item_Base_F;
    class potato_naloxoneItem: Item_Base_F {
        scope = 2;
        scopeCurator = 2;
        displayName = "Naloxone Autoinjector";
        author = "Alablm";
        vehicleClass = "Items";
        class TransportItems {
            MACRO_ADDITEM(potato_naloxone,1);
        };
    };
    class ACE_painkillersItem: Item_Base_F {};
    class potato_pkblisterItem: ACE_painkillersItem {
        author = "AChesheireCat";
        displayName = "Painkiller Blister Pack";
        vehicleClass = "Items";
        class TransportItems {
            MACRO_ADDMAGAZINE(potato_pkblister,1);
        };
    };
};
