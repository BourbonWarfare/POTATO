#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchPLA

class CfgPatches {
    class ADDON {
        weapons[] = {};
        units[] = {"O_ZBL09", "O_ZTL11", "O_ZBD04A", "O_ZBD05","O_ZTD05", "O_ZTQ15","O_ZTQ15B","O_ZTZ96A","O_ZTZ96B","O_ZTZ99","O_ZTZ99A"};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"ZBL09_LK", "ZTL11_LK", "ZBD04_LK", "ZBD05_LK", "ZTD05_LK", "ZTQ15_LK", "ZTZ96_c_LK", "ZTZ96A_LK", "ZTZ96B_LK", "ZTZ99_LK", "ZTZ99A_LK"};
        skipWhenMissingDependencies = 1;
        author = "Potato";
        authors[] = {"Chesheire","watermelon"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CfgVehicles {
    class LandVehicle;
    class Car: LandVehicle {};
    class Car_F: Car {
        class HitPoints {
            class HitBody;
            class HitEngine;
            class HitFuel;
            class HitHull;
            class HitLFWheel;
            class HitLBWheel;
            class HitLMWheel;
            class HitLF2Wheel;
            class HitRFWheel;
            class HitRBWheel;
            class HitRMWheel;
            class HitRF2Wheel;
        };
    };
    class Wheeled_APC_F: Car_F {
        class NewTurret;
        class Turrets {
            class MainTurret: NewTurret {
                class ViewOptics;
                class ViewGunner;
                class Turrets {
                    class CommanderOptics;
                };
            };
        };
    };
    class LandVehicle;
    class Tank: LandVehicle {
        class NewTurret;
        class HitPoints;
    };
    class Tank_F: Tank {
        class Turrets {
            class MainTurret: NewTurret {
                class Turrets {
                    class CommanderOptics;
                };
            };
        };
        class HitPoints: HitPoints {
            class HitHull;
            class HitEngine;
            class HitLTrack;
            class HitRTrack;
            class HitFuel;
        };
    };
    class ZBL09_base: Wheeled_APC_F {
        damageResistance = 0.02;
        crewVulnerable = 1; //formerly 0
        armor = 480; //formerly 500 -> 270?
        armorStructural = 5;
        class HitPoints: HitPoints {
            class HitHull: HitHull {
                armor = 2;
                passThrough = 1;
                minimalHit = 0.14;
                explosionShielding = 0.2;
                radius = 0.25;
            };
            class HitEngine: HitEngine {
                armor = 1.25;
                passThrough = 0.1;
                minimalHit = 0.1;
                explosionShielding = 0.5;
                radius = 0.25;
            };
            class HitLFWheel: HitLFWheel {
                radius = 0.33;
                armor = -250; //formerly -250
                minimalHit = -0.016; //formerly -0.016
                explosionShielding = 4;
                passThrough = 0;
            };
            class HitLF2Wheel: HitLF2Wheel {
                radius = 0.33;
                armor = -250;
                minimalHit = -0.016;
                explosionShielding = 4;
                passThrough = 0;
            };
            class HitLMWheel: HitLMWheel {
                radius = 0.33;
                armor = -250;
                minimalHit = -0.016;
                explosionShielding = 4;
                passThrough = 0;
            };
            class HitLBWheel: HitLBWheel {
                radius = 0.33;
                armor = -250;
                minimalHit = -0.016;
                explosionShielding = 4;
                passThrough = 0;
            };
            class HitRFWheel: HitRFWheel {
                radius = 0.33;
                armor = -250;
                minimalHit = -0.016;
                explosionShielding = 4;
                passThrough = 0;
            };
            class HitRF2Wheel: HitRF2Wheel {
                radius = 0.33;
                armor = -250;
                minimalHit = -0.016;
                explosionShielding = 4;
                passThrough = 0;
            };
            class HitRMWheel: HitRMWheel {
                radius = 0.33;
                armor = -250;
                minimalHit = -0.016;
                explosionShielding = 4;
                passThrough = 0;
            };
            class HitRBWheel: HitRBWheel {
                radius = 0.33;
                armor = -250;
                minimalHit = -0.016;
                explosionShielding = 4;
                passThrough = 0;
            };
            class HitFuel: HitFuel {
                armor = 0.75;
                passThrough = 0.5;
                minimalHit = 0.1;
                explosionShielding = 0.6;
                radius = 0.16;
            };
            class HitArmor {
                armor = 0.5; //formerly 10
                passThrough = 0.5; //formerly 0 (0.5 causes tires to transfer dmg to hull/turret?)
                minimalHit = 0.1;
                explosionShielding = 2;
                radius = 0.1;
            };
        };
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                class Turrets: Turrets {
                    class CommanderOptics: CommanderOptics {
                        class HitPoints {
                            class HitTurret {
                                armor = 0.3;
                                passThrough = 0;
                                minimalHit = 0.03;
                                explosionShielding = 0.6;
                                radius = 0.25;
                            };
                        };
                    };
                };
                class HitPoints {
                    class HitTurret {
                        armor = 1.5; //formerly 0.8
                        passThrough = 0; //formerly 0
                        minimalHit = 0.1;
                        explosionShielding = 0.2;
                        radius = 0.3;
                        isTurret = 1;
                    };
                    class HitGun {
                        armor = 1.5;
                        passThrough = 0; //formerly 0
                        minimalHit = 0.1;
                        explosionShielding = 0.4;
                        radius = 0.25;
                        isGun = 1;
                    };
                };
            };
        };
    };
    class O_ZBL09_base: ZBL09_base {};
    class O_ZBL09: O_ZBL09_base {};
    class ZTL11_base: Wheeled_APC_F {
        crewVulnerable = 1; //formerly 0
        armor = 480; //formerly 500 -> 270?
        armorStructural = 5;
        class HitPoints: HitPoints {
            class HitHull: HitHull {
                armor = 2;
                passThrough = 1;
                minimalHit = 0.14;
                explosionShielding = 0.2;
                radius = 0.25;
            };
            class HitEngine: HitEngine {
                armor = 1.25;
                passThrough = 0.1;
                minimalHit = 0.1;
                explosionShielding = 0.5;
                radius = 0.25;
            };
            class HitLFWheel: HitLFWheel {
                radius = 0.33;
                armor = -250; //formerly -250
                minimalHit = -0.016; //formerly -0.016
                explosionShielding = 4;
                passThrough = 0;
            };
            class HitLF2Wheel: HitLF2Wheel {
                radius = 0.33;
                armor = -250;
                minimalHit = -0.016;
                explosionShielding = 4;
                passThrough = 0;
            };
            class HitLMWheel: HitLMWheel {
                radius = 0.33;
                armor = -250;
                minimalHit = -0.016;
                explosionShielding = 4;
                passThrough = 0;
            };
            class HitLBWheel: HitLBWheel {
                radius = 0.33;
                armor = -250;
                minimalHit = -0.016;
                explosionShielding = 4;
                passThrough = 0;
            };
            class HitRFWheel: HitRFWheel {
                radius = 0.33;
                armor = -250;
                minimalHit = -0.016;
                explosionShielding = 4;
                passThrough = 0;
            };
            class HitRF2Wheel: HitRF2Wheel {
                radius = 0.33;
                armor = -250;
                minimalHit = -0.016;
                explosionShielding = 4;
                passThrough = 0;
            };
            class HitRMWheel: HitRMWheel {
                radius = 0.33;
                armor = -250;
                minimalHit = -0.016;
                explosionShielding = 4;
                passThrough = 0;
            };
            class HitRBWheel: HitRBWheel {
                radius = 0.33;
                armor = -250;
                minimalHit = -0.016;
                explosionShielding = 4;
                passThrough = 0;
            };
            class HitFuel: HitFuel {
                armor = 0.75;
                passThrough = 0.5;
                minimalHit = 0.1;
                explosionShielding = 0.6;
                radius = 0.16;
            };
            class HitArmor {
                armor = 0.5; //formerly 10
                passThrough = 0.5; //formerly 0 (0.5 causes tires to transfer dmg to hull/turret?)
                minimalHit = 0.1;
                explosionShielding = 2;
                radius = 0.1;
            };
        };
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                class Turrets: Turrets {
                    class CommanderOptics: CommanderOptics {
                        class HitPoints {
                            class HitTurret {
                                armor = 0.3;
                                passThrough = 0;
                                minimalHit = 0.03;
                                explosionShielding = 0.6;
                                radius = 0.25;
                            };
                        };
                    };
                };
                class HitPoints {
                    class HitTurret {
                        armor = 1.5; //formerly 0.8
                        passThrough = 0; //formerly 0
                        minimalHit = 0.1;
                        explosionShielding = 0.2;
                        radius = 0.3;
                        isTurret = 1;
                    };
                    class HitGun {
                        armor = 1.5;
                        passThrough = 0; //formerly 0
                        minimalHit = 0.1;
                        explosionShielding = 0.4;
                        radius = 0.25;
                        isGun = 1;
                    };
                };
            };
        };
    };
    class O_ZTL11: ZTL11_base {};
    class ZBD04A_base: Tank_F {
        damageResistance = 0.02;
        crewVulnerable = 1;
        armor = 500;
        armorStructural = 6;
        class HitPoints: HitPoints {
            class HitHull: HitHull {
                armor = 1;
                passThrough = 1;
                minimalHit = 0.2;
                explosionShielding = 0.2;
            };
            class HitEngine: HitEngine {
                armor = 0.8;
                passThrough = 0.2;
                minimalHit = 0.2;
                explosionShielding = 0.2;
            };
            class HitLTrack: HitLTrack {
                armor = -400;
                passThrough = 0;
                minimalHit = 0.09;
                explosionShielding = 0.8;
            };
            class HitRTrack: HitRTrack {
                armor = -400;
                passThrough = 0;
                minimalHit = 0.09;
                explosionShielding = 0.8;
            };
            class HitFuel: HitFuel {
                armor = 0.5;
                passThrough = 0.1;
                minimalHit = 0.1;
                explosionShielding = 0.6;
            };
            class HitArmor
            {
                armor = 0.5;
                passThrough = 0.5;
                minimalHit = 0.1;
                explosionShielding = 2;
                isTurret = 0;
            };
        };
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                class Turrets: Turrets {
                    class CommanderOptics: CommanderOptics {
                        class HitPoints {
                            class HitComTurret {
                                armor = 0.08;
                                passThrough = 0.4;
                                minimalHit = 0.1;
                                explosionShielding = 1;
                                isTurret = 1;
                            };
                            class HitComGun {
                                armor = 0.04;
                                passThrough = 0;
                                minimalHit = 0.1;
                                explosionShielding = 1;
                                isGun = 1;
                            };
                        };
                    };
                };
                class HitPoints {
                    class HitTurret {
                        armor = 0.8;
                        passThrough = 0;
                        minimalHit = 0.1;
                        explosionShielding = 0.2;
                        isTurret = 1;
                    };
                    class HitGun {
                        armor = 0.6;
                        passThrough = 0;
                        minimalHit = 0.1;
                        explosionShielding = 0.4;
                        isGun = 1;
                    };
                };
            };
        };
    };
    class O_ZBD04A_base: ZBD04A_base {};
    class O_ZBD04A: O_ZBD04A_base {};
    class ZBD05_base: Tank_F {
        damageResistance = 0.02;
        crewVulnerable = 1;
        armor = 500;
        armorStructural = 6;
        class HitPoints: HitPoints {
            class HitHull: HitHull {
                armor = 1;
                passThrough = 1;
                minimalHit = 0.2;
                explosionShielding = 0.2;
            };
            class HitEngine: HitEngine {
                armor = 0.8;
                passThrough = 0.2;
                minimalHit = 0.2;
                explosionShielding = 0.2;
            };
            class HitLTrack: HitLTrack {
                armor = -400;
                passThrough = 0;
                minimalHit = 0.09;
                explosionShielding = 0.8;
            };
            class HitRTrack: HitRTrack {
                armor = -400;
                passThrough = 0;
                minimalHit = 0.09;
                explosionShielding = 0.8;
            };
            class HitFuel: HitFuel {
                armor = 0.5;
                passThrough = 0.1;
                minimalHit = 0.1;
                explosionShielding = 0.6;
            };
            class HitArmor
            {
                armor = 0.5;
                passThrough = 0.5;
                minimalHit = 0.1;
                explosionShielding = 2;
                isTurret = 0;
            };
        };
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                class Turrets: Turrets {
                    class CommanderOptics: CommanderOptics {
                        class HitPoints {
                            class HitComTurret {
                                armor = 0.08;
                                passThrough = 0.4;
                                minimalHit = 0.1;
                                explosionShielding = 1;
                                isTurret = 1;
                            };
                            class HitComGun {
                                armor = 0.04;
                                passThrough = 0;
                                minimalHit = 0.1;
                                explosionShielding = 1;
                                isGun = 1;
                            };
                        };
                    };
                };
                class HitPoints {
                    class HitTurret {
                        armor = 0.8;
                        passThrough = 0;
                        minimalHit = 0.1;
                        explosionShielding = 0.2;
                        isTurret = 1;
                    };
                    class HitGun {
                        armor = 0.6;
                        passThrough = 0;
                        minimalHit = 0.1;
                        explosionShielding = 0.4;
                        isGun = 1;
                    };
                };
            };
        };
    };
    class O_ZBD05: ZBD05_base {};
    class ZTD05_base: Tank_F {
        damageResistance = 0.02;
        crewVulnerable = 1;
        armor = 500;
        armorStructural = 6;
        class HitPoints: HitPoints {
            class HitHull: HitHull {
                armor = 1;
                passThrough = 1;
                minimalHit = 0.2;
                explosionShielding = 0.2;
            };
            class HitEngine: HitEngine {
                armor = 0.8;
                passThrough = 0.2;
                minimalHit = 0.2;
                explosionShielding = 0.2;
            };
            class HitLTrack: HitLTrack {
                armor = -400;
                passThrough = 0;
                minimalHit = 0.09;
                explosionShielding = 0.8;
            };
            class HitRTrack: HitRTrack {
                armor = -400;
                passThrough = 0;
                minimalHit = 0.09;
                explosionShielding = 0.8;
            };
            class HitFuel: HitFuel {
                armor = 0.5;
                passThrough = 0.1;
                minimalHit = 0.1;
                explosionShielding = 0.6;
            };
            class HitArmor
            {
                armor = 0.5;
                passThrough = 0.5;
                minimalHit = 0.1;
                explosionShielding = 2;
                isTurret = 0;
            };
        };
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                class Turrets: Turrets {
                    class CommanderOptics: CommanderOptics {
                        class HitPoints {
                            class HitComTurret {
                                armor = 0.08;
                                passThrough = 0.4;
                                minimalHit = 0.1;
                                explosionShielding = 1;
                                isTurret = 1;
                            };
                            class HitComGun {
                                armor = 0.04;
                                passThrough = 0;
                                minimalHit = 0.1;
                                explosionShielding = 1;
                                isGun = 1;
                            };
                        };
                    };
                };
                class HitPoints {
                    class HitTurret {
                        armor = 0.8;
                        passThrough = 0;
                        minimalHit = 0.1;
                        explosionShielding = 0.2;
                        isTurret = 1;
                    };
                    class HitGun {
                        armor = 0.6;
                        passThrough = 0;
                        minimalHit = 0.1;
                        explosionShielding = 0.4;
                        isGun = 1;
                    };
                };
            };
        };
    };
    class O_ZTD05_base: ZTD05_base {};
    class O_ZTD05: O_ZTD05_base {};

    // watermelon's addition from here on out
    // list of changes:
    // - ZTQ15 and ZTQ15B uses values of vanilla BTR-K Kamysh
    // - ZTZ96_c, ZTZ96A and ZTZ96B uses values of vanilla T-100 Varsuk
    // - ZTZ99 and ZTZ99A uses values of vanilla Leopard 2SG

    // ZTQ15 & ZTQ15B
    class ZTQ15_base: Tank_F {
        damageResistance = 0.00547; // old value 0.02
        crewVulnerable = 1; // old value 0
        armor = 500; // old value 600
        armorStructural = 6; // old value 6
        class HitPoints: HitPoints {
            class HitHull: HitHull {
                armor = 1; // old value 0.80000001
                passThrough = 1; // old value 0.89999998
                minimalHit = 0.2; // old value 0.14
                explosionShielding = 0.2; // old value 2
            };
            class HitEngine: HitEngine {
                armor = 0.8; // old value 0.5
                passThrough = 0.2; // old value 0.30000001
                minimalHit = 0.2; // old value 0.23999999
                explosionShielding = 0.2; // old value 0.2
            };
            class HitLTrack: HitLTrack {
                armor = -400; // old value 0.5
                minimalHit = 0.09; // old value 0.079999998
                explosionShielding = 0.8; // old value 1.4400001
            };
            class HitRTrack: HitRTrack {
                armor = -400; // old value 0.5
                minimalHit = 0.09; // old value 0.079999998
                explosionShielding = 0.8; // old value 1.4400001
            };
            class HitFuel: HitFuel {
                armor = 0.5;
                passThrough = 0.1; // old value 0.15000001
                minimalHit = 0.1;
                explosionShielding = 0.6;
            };
            class HitArmor {
                armor = 1; // was 0.5
                passThrough = 1; // was 0.5
                minimalHit = 0.2; // was 0.2
                explosionShielding = 0.2; // was 0.2
            };
        };
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                class Turrets: Turrets {
                    class CommanderOptics: CommanderOptics {
                        class HitPoints {
                            class HitComTurret {
                                armor = 0.1; // was 0.3
                                minimalHit = 0.1; // was 0.03
                                explosionShielding = 1; // was 0.6
                            };
                            class HitComGun {
                                armor = 0.1; // was 0.3
                                minimalHit = 0.1; // was 0.02
                                explosionShielding = 1; // was 0.6
                            };
                        };
                    };
                };
                class HitPoints {
                    class HitTurret {
                        armor = 0.8; // old value 1.2
                        minimalHit = 0.1; // old value 0.1
                        explosionShielding = 0.2; // old value 0.30000001
                    };
                    class HitGun {
                        armor = 0.6; // old value 0.80000001
                        minimalHit = 0.1; // old value 0
                        explosionShielding = 0.4; // old value 0.40000001
                    };
                };
            };
        };
    };
    class O_ZTQ15: ZTQ15_base {};
    class O_ZTQ15B: O_ZTQ15 {};

    // ZTZ96A & ZTZ96B
    class ZTZ96A_base: Tank_F {
        damageResistance = 0.00389; // was 0.02
        crewVulnerable = 1;
        armor = 850; // was 700
        armorStructural = 6;
        class HitPoints: HitPoints {
            class HitHull: HitHull {
                armor = 1.2; // old value 0.60000002
                passThrough = 1; // old value 0.5
                minimalHit = 0.2; // old value 0.14
                explosionShielding = 0.2; // old value 2
            };
            class HitEngine: HitEngine {
                armor = 0.55; // old value 0.5
                passThrough = 0.3; // old value 0.30000001
                minimalHit = 0.2; // old value 0.23999999
            };
            class HitLTrack: HitLTrack {
                armor = -650; // old value 0.5
                minimalHit = 0.0738462; // old value 0.079999998
                explosionShielding = 0.8; // old value 1.4400001
            };
            class HitRTrack: HitRTrack {
                armor = -650; // old value 0.5
                minimalHit = 0.0738462; // old value 0.079999998
                explosionShielding = 0.8; // old value 1.4400001
            };
            class HitFuel: HitFuel {};
            class HitArmor {
                armor = 1.6; // was 0.5
                passThrough = 1; // was 0.5
                minimalHit = 0.2; // was 0.1
                explosionShielding = 0.2; // was 2
            };
        };
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                class Turrets: Turrets {
                    class CommanderOptics: CommanderOptics {
                        class HitPoints {
                            class HitComTurret {
                                armor = 0.1; // was 0.3
                                minimalHit = 0.1; // was 0.03
                                explosionShielding = 0.2; // was 0.6
                            };
                            class HitComGun {
                                armor = 0.1; // was 0.3
                                minimalHit = 0.1; // was 0.03
                                explosionShielding = 0.4; // was 0.6
                            };
                        };
                    };
                };
                class HitPoints {
                    class HitTurret {
                        armor = 0.8; // old value 1.2
                        minimalHit = 0.1;
                        explosionShielding = 0.2; // old value 0.30000001
                    };
                    class HitGun {
                        armor = 0.8; // old value 0.80000001
                        minimalHit = 0.1; // old value 0
                        explosionShielding = 0.4;
                    };
                };
            };
        };
    };
    class O_ZTZ96A: ZTZ96A_base {};
    class ZTZ96B_base: Tank_F {
        damageResistance = 0.00389; // was 0.02
        crewVulnerable = 1;
        armor = 850; // was 700
        armorStructural = 6;
        class HitPoints: HitPoints {
            class HitHull: HitHull {
                armor = 1.2; // old value 0.60000002
                passThrough = 1; // old value 0.5
                minimalHit = 0.2; // old value 0.14
                explosionShielding = 0.2; // old value 2
            };
            class HitEngine: HitEngine {
                armor = 0.55; // old value 0.5
                passThrough = 0.3; // old value 0.30000001
                minimalHit = 0.2; // old value 0.23999999
            };
            class HitLTrack: HitLTrack {
                armor = -650; // old value 0.5
                minimalHit = 0.0738462; // old value 0.079999998
                explosionShielding = 0.8; // old value 1.4400001
            };
            class HitRTrack: HitRTrack {
                armor = -650; // old value 0.5
                minimalHit = 0.0738462; // old value 0.079999998
                explosionShielding = 0.8; // old value 1.4400001
            };
            class HitFuel: HitFuel {};
            class HitArmor {
                armor = 1.6; // was 0.5
                passThrough = 1; // was 0.5
                minimalHit = 0.2; // was 0.1
                explosionShielding = 0.2; // was 2
            };
        };
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                class Turrets: Turrets {
                    class CommanderOptics: CommanderOptics {
                        class HitPoints {
                            class HitComTurret {
                                armor = 0.1; // was 0.3
                                minimalHit = 0.1; // was 0.03
                                explosionShielding = 0.2; // was 0.6
                            };
                            class HitComGun {
                                armor = 0.1; // was 0.3
                                minimalHit = 0.1; // was 0.03
                                explosionShielding = 0.4; // was 0.6
                            };
                        };
                    };
                };
                class HitPoints {
                    class HitTurret {
                        armor = 0.8; // old value 1.2
                        minimalHit = 0.1;
                        explosionShielding = 0.2; // old value 0.30000001
                    };
                    class HitGun {
                        armor = 0.8; // old value 0.80000001
                        minimalHit = 0.1; // old value 0
                        explosionShielding = 0.4;
                    };
                };
            };
        };
    };
    class O_ZTZ96B: ZTZ96B_base {};

    // ZTZ99 & ZTZ99A
    class ZTZ99_base: Tank_F {
        damageResistance = 0.00547; // was 0.02
        crewVulnerable = 1; // old value 0
        armor = 800; // old value 600
        class HitPoints: HitPoints {
            class HitHull: HitHull {
                armor = 1.6; // old value 1
                passThrough = 1; // old value 0.75
                minimalHit = 0.2; // old value 0.14
                explosionShielding = 0.2; // old value 2
            };
            class HitEngine: HitEngine {
                armor = 0.6;// old value 0.5
                passThrough = 0.5; // was 0.3
                minimalHit = 0.2; // was 0.3
            };
            class HitLTrack: HitLTrack {
                armor = -650; // was 0.5
                minimalHit = 0.0738462; // was 0.08
                explosionShielding = 0.8; // was 1.44
            };
            class HitRTrack: HitRTrack {
                armor = -650; // was 0.5
                minimalHit = 0.0738462; // was 0.08
                explosionShielding = 0.8; // was 1.44
            };
            class HitFuel: HitFuel {
                passThrough = 0.3; // was 0.15
            };
            class HitArmor {
                armor = 1.6; // was 5
                passThrough = 1; // was 0
                minimalHit = 0.2; // was 0.1
                explosionShielding = 0.2; // was 2
            };
        };
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                class Turrets: Turrets {
                    class CommanderOptics: CommanderOptics {
                        class HitPoints {
                            class HitComTurret {
                                armor = 0.1; // was 0.3
                                minimalHit = 0.1; // was 0.03
                                explosionShielding = 1; // was 0.6
                            };
                            class HitComGun {
                                armor = 0.1; // was 0.3
                                minimalHit = 0.1; // was 0.03
                                explosionShielding = 1; // was 0.6
                            };
                        };
                    };
                };
                class HitPoints {
                    class HitTurret {
                        armor = 0.8; // was 1.2
                        explosionShielding = 0.2; // was 0.3
                    };
                    class HitGun {
                        armor = 0.6; // was 0.8
                        minimalHit = 0.1; // was 0
                    };
                };
            };
        };
    };
    class O_ZTZ99: ZTZ99_base {};
    class ZTZ99A_base: Tank_F {
        damageResistance = 0.00547; // was 0.02
        crewVulnerable = 1; // old value 0
        armor = 800; // old value 600
        class HitPoints: HitPoints {
            class HitHull: HitHull {
                armor = 1.6; // old value 1
                passThrough = 1; // old value 0.75
                minimalHit = 0.2; // old value 0.14
                explosionShielding = 0.2; // old value 2
            };
            class HitEngine: HitEngine {
                armor = 0.6;// old value 0.5
                passThrough = 0.5; // was 0.3
                minimalHit = 0.2; // was 0.3
            };
            class HitLTrack: HitLTrack {
                armor = -650; // was 0.5
                minimalHit = 0.0738462; // was 0.08
                explosionShielding = 0.8; // was 1.44
            };
            class HitRTrack: HitRTrack {
                armor = -650; // was 0.5
                minimalHit = 0.0738462; // was 0.08
                explosionShielding = 0.8; // was 1.44
            };
            class HitFuel: HitFuel {
                passThrough = 0.3; // was 0.15
            };
            class HitArmor {
                armor = 1.6; // was 5
                passThrough = 1; // was 0
                minimalHit = 0.2; // was 0.1
                explosionShielding = 0.2; // was 2
            };
        };
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                class Turrets: Turrets {
                    class CommanderOptics: CommanderOptics {
                        class HitPoints {
                            class HitComTurret {
                                armor = 0.1; // was 0.3
                                minimalHit = 0.1; // was 0.03
                                explosionShielding = 1; // was 0.6
                            };
                            class HitComGun {
                                armor = 0.1; // was 0.3
                                minimalHit = 0.1; // was 0.03
                                explosionShielding = 1; // was 0.6
                            };
                        };
                    };
                };
                class HitPoints {
                    class HitTurret {
                        armor = 0.8; // was 1.2
                        explosionShielding = 0.2; // was 0.3
                    };
                    class HitGun {
                        armor = 0.6; // was 0.8
                        minimalHit = 0.1; // was 0
                    };
                };
            };
        };
    };
    class O_ZTZ99A: ZTZ99A_base {};
    
    class CSK181_base_F: Car_F {
        class HitPoints: HitPoints {
            class HitBody {
                armor = 1.5; // was 6
                minimalHit = 0.1; // was 0.01
            };
            class HitHull {
                minimalHit = 0.1; // was 0.2
            };
        };
    };
};