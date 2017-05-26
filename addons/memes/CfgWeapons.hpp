class CfgWeapons {
    class InventoryItem_Base_F;
    class ACE_ItemCore;
    class potato_cheezItBox: ACE_ItemCore {
        scope = 2;
        model = QPATHTOF(data\cheezItBox.p3d);
        picture = QPATHTOF(ui\cheezItBox_ca.paa);
        displayName = "Box of Cheez-It";
        descriptionShort = "Cheddar";
        class ItemInfo: InventoryItem_Base_F {
            mass = 1;
        };
    };
    class potato_serverBox: ACE_ItemCore {
        scope = 2;
        model = QPATHTOF(data\server.p3d);
        picture = QPATHTOF(ui\server_ca.paa);
        displayName = "Dedicated Server";
        descriptionShort = "Server";
        class ItemInfo: InventoryItem_Base_F {
            mass = 1;
        };
    };
};
