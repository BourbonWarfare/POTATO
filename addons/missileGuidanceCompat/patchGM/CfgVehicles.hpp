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

    // Updated 9P133 to SACLOS variant
    class gm_wheeled_base;
    class gm_wheeled_APC_base: gm_wheeled_base {
        class Turrets;
    };
    class gm_brdm2_base: gm_wheeled_APC_base {
        class Turrets: Turrets {
            class MainTurret;
        };
    };
    class gm_brdm2_9p133_base: gm_brdm2_base {
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                magazines[] = {QGVARMAIN(gm_6Rnd_maljutka_heat_9m14p),QGVARMAIN(gm_6Rnd_maljutka_heat_9m14p),QGVARMAIN(gm_6Rnd_maljutka_heat_9m14p)};
                class Components;
                class GunClouds;
                class GunFire;
                class Hitpoints;
                class MGunClouds;
                class OpticsIn;
                class Reflectors;
                class TurnIn;
                class TurnOut;
                class Turrets;
                class TurretSpec;
                class ViewGunner;
                class ViewOptics;
            };
        };
    };
};