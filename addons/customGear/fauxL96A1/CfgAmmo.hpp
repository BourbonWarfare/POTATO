class CfgAmmo {
    class CUP_B_762x51_NoCartridge;
    class potato_bullet_762x51_precision: CUP_B_762x51_NoCartridge {
        ACE_bulletMass = 10.89;
        ACE_ballisticCoefficients[] = {0.249};
        ACE_caliber = 7.823;
        ACE_standardAtmosphere = "ASM";
        cartridge = "FxCartridge_762";
        caliber = 1.8; // NiArms' is 0.348 for equivalent munition
        hit = 17.02;
    };
};
