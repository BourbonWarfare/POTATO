class CfgVehicles {
    // TPz 1A0 Recon
    class gm_fuchs_base;
    class gm_fuchsa0_base: gm_fuchs_base {
        class Turrets;
    };
    class gm_fuchsa0_reconnaissance_base: gm_fuchsa0_base {
        class MachineGunTurret_base;
        class Turrets: Turrets {
            class MilanTurret_01: MachineGunTurret_base {
                magazines[] = {"gm_1Rnd_milan_heat_dm92_ace_mg","gm_1Rnd_milan_heat_dm92_ace_mg","gm_1Rnd_milan_heat_dm92_ace_mg","gm_1Rnd_milan_heat_dm92_ace_mg"};
            };
        };
    };

    // Iltis with MILAN
    class gm_wheeled_car_base;
    class gm_iltis_base: gm_wheeled_car_base {
        class Turrets;
    };
    class gm_iltis_milan_base: gm_iltis_base {
        class MachineGunTurret_base;
        class Turrets: Turrets {
            class MilanTurret_01: MachineGunTurret_base {
                magazines[] = {"gm_1Rnd_milan_heat_dm92_ace_mg","gm_1Rnd_milan_heat_dm92_ace_mg","gm_1Rnd_milan_heat_dm92_ace_mg","gm_1Rnd_milan_heat_dm92_ace_mg"};
            };
        };
    };
};