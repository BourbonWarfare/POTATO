#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchMELB

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "melb"};
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CfgVehicles {
    class Air;
    class Helicopter: Air {};
    class Helicopter_Base_F: Helicopter {
        class Turrets;
    };
    class Helicopter_Base_H: Helicopter_Base_F {
        class Turrets: Turrets {
            class CopilotTurret;
        };
    };
    class MELB_base: Helicopter_Base_H {
        class Turrets: Turrets {
            class CopilotTurret: CopilotTurret {
                stabilizedInAxes = 3;
                class OpticsIn {
                    class Wide {};
                    class WideT2: Wide {};
                    class MediumT: Wide {
                        // Forces geo-locking for this turret (zoom level 3)
                        opticsDisplayName = "TRK COR";
                        directionStabilized = 1;
                        horizontallyStabilized = 1;
                    };
                    class NarrowT: Wide {
                        // Forces geo-locking for this turret (zoom level 4)
                        opticsDisplayName = "TRK COR";
                        directionStabilized = 1;
                        horizontallyStabilized = 1;
                    };
                    class NarrowT2: Wide {
                        // Forces geo-locking for this turret (zoom level 5)
                        opticsDisplayName = "TRK COR";
                        directionStabilized = 1;
                        horizontallyStabilized = 1;
                    };
                };
            };
        };
    };
};
