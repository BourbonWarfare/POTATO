class CfgVehicles {
    // Add SMAW box
    class Box_NATO_Support_F;
    class GVAR(smawBox): Box_NATO_Support_F {
        scope = 1;
        displayName = "SMAW Weapon Box";
        transportMaxWeapons = 9001;
        transportMaxMagazines = 9001;
        transportMaxItems = 9001;
        maximumload = 1000;

        class TransportWeapons {
            MACRO_ADDWEAPON(rhs_weap_smaw,1);
        };
        class TransportMagazines {
            MACRO_ADDMAGAZINE(rhs_mag_smaw_HEAA,10);
            MACRO_ADDMAGAZINE(rhs_mag_smaw_HEDP,10);
            MACRO_ADDMAGAZINE(rhs_mag_smaw_SR,8);
        };
        class TransportItems {
            MACRO_ADDITEM(rhs_weap_optic_smaw,1);
        };
        class TransportBackpacks {};
    };
};
