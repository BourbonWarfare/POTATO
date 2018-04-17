class CfgWeapons {
    class potato_csw_base_carry;
    class banana_carry_weapon: potato_csw_base_carry {
        class ace_csw_options {
            assembleTo = "banana_csw";
            baseTripod = "banana_tripod";
            type = "weapon";
        };
    };
    
    class HMG_Static;
    class banana_weapon: HMG_Static {
        class potato_csw_options {
            deployTime = 10;
            pickupTime = 12;
            ammoLoadTime = 7;
            ammoUnloadTime = 16;
        };
        magazines[] = { banana_ammo, banana_dummy_ammo };
    };
};

