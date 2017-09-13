#define POTATO_PlaceInBodyBag {\
    displayName = "Place body in bodybag";\
    distance = 2.0;\
    condition = QUOTE([ARR_4(_player, _target, 'body', 'BodyBag')] call DACEFUNC(medical,canTreatCached));\
    statement = QUOTE([ARR_2(_player, _target)] call FUNC(treatmentPlaceInBodyBag));\
    exceptions[] = {"isNotSwimming"};\
    showDisabled = 1;\
    priority = 2;\
    enableInside = 1;\
};

class CfgVehicles {
    // create body bag holder
    class ACE_bodyBagObject;
    class POTATO_bodyBagHolderObject: ACE_bodyBagObject { // make body bag function as crate
        maximumLoad = 1500;
        transportMaxWeapons = 4;
        transportMaxMagazines = 8;
        transportMaxBackpacks = 4;
        transportAmmo = 0;
        transportRepair = 0;
        transportFuel = 0;
        supplyRadius = 1.4;
    };

    // removed ACE body bag, add potato
    class Man;
    class CAManBase: Man {
        class ACE_Actions {
            class ACE_MainActions {
                class POTATO_PlaceInBodyBag
            };
            class ACE_Torso {
                delete PlaceInBodyBag;
                class POTATO_PlaceInBodyBag
            };
        };
    };
};
