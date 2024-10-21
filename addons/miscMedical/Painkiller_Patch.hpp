// License Attribution req: UI image authored by user grmarcstock via Vecteezy.com

class CfgMagazines {
    class CA_Magazine;
    class ACE_painkillers: CA_Magazine {};
    class potato_pkblister: ACE_painkillers {
        author = "AChesheireCat";
        displayName = "Painkiller Blister Pack";
        descriptionShort = "For physical pain only";
        descriptionUse = "A blister pack containing individualized painkiller tablets, regularly issued in IFAKs";
        picture = QPATHOF(ui\pkblister_ca.paa);
        count = 2;
    };
};
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
class CfgWeapons {
    class ACE_ItemCore;
    class ACE_painkillers_Item: ACE_ItemCore {};
    class potato_pkblister: ACE_painkillers {
        scope = 2;
        author = "AChesheireCat";
        displayName = "Painkiller Blister Pack";
        descriptionShort = "For physical pain only";
        descriptionUse = "A blister pack containing individualized painkiller tablets, regularly issued in IFAKs";
        picture = QPATHOF(ui\pkblister_ca.paa);
    };
};
class ace_medical_treatment {
    class Medication {
        class Painkillers;
        class Pkblister: Painkillers {};
    };
};
