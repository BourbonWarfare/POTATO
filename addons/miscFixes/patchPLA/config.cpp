#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchPLA

class CfgPatches {
    class ADDON {
        weapons[] = {};
        units[] = {"O_ZBL09", "O_ZTL11", "O_ZBD04A", "O_ZBD05","O_ZTD05"};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"ZBL09_LK", "ZTL11_LK", "ZBD04_LK", "ZBD05_LK", "ZTD05_LK"};
        skipWhenMissingDependencies = 1;
        author = "Potato";
        authors[] = {"Chesheire"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CfgVehicles {
    class Car;
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
                            class HitComTurret {
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
};