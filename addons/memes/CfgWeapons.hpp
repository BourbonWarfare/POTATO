class CfgWeapons {
    class CBA_MiscItem_ItemInfo;
    class ACE_ItemCore;
    class potato_cheezItBox: ACE_ItemCore {
        scope = 2;
        model = QPATHTOF(data\cheezItBox.p3d);
        picture = QPATHTOF(ui\cheezItBox_ca.paa);
        displayName = "Box of Cheez-It";
        descriptionShort = "Cheddar (Do not view inside EU)";
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 1;
        };
    };
    class potato_serverBox: ACE_ItemCore {
        scope = 2;
        model = QPATHTOF(data\server.p3d);
        picture = QPATHTOF(ui\server_ca.paa);
        displayName = "Dedicated Server";
        descriptionShort = "Server (Do not view inside EU)";
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 1;
        };
    };
    class potato_gamestop: ACE_ItemCore {
        scope = 2;
        model = "\A3\Structures_F\Items\Luggage\Suitcase_F.p3d";
        picture = QPATHTOF(ui\gamestop_ca.paa);
        displayName = "GME Stock";
        descriptionShort = "1 Million Gamestop Bearer Bonds";
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 1;
        };
    };


    class arifle_MX_F;
    class potato_funGun_red: arifle_MX_F {
        author = "Potato";
        scope = 1;
        scopeCurator = 0;
        displayName = "Candy Cane (Red)";
        model = "\z\potato\addons\memes\data\funGun_red.p3d";
        selectionFireAnim = "muzzleFlash";
        handAnim[] = {"OFP2_ManSkeleton","\A3\Weapons_F\Rifles\MX\data\Anim\mx.rtm"};
    };
    class potato_funGun_green: arifle_MX_F {
        author = "Potato";
        scope = 1;
        scopeCurator = 0;
        displayName = "Candy Cane (Green)";
        model = "\z\potato\addons\memes\data\funGun_green.p3d";
        selectionFireAnim = "muzzleFlash";
        handAnim[] = {"OFP2_ManSkeleton","\A3\Weapons_F\Rifles\MX\data\Anim\mx.rtm"};
    };
};
