class CfgVehicles {
    class Item_Base_F;
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