#define COMPONENT vehiclecoasting
#define COMPONENT_BEAUTIFIED Vehicle_Coasting
#include "\z\potato\addons\core\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DEBUG_MODE_DRAW_EH
// #define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#define COAST_LOOP_INTERVAL 0.2
// 50% chance for cook-off
#define POTATO_VEHICLEC_COASTING_COOKOFF_CHANCE 0.5
// 50% chance with just driver dying
#define POTATO_VEHICLEC_COASTING_DRIVER_CHANCE 0.5
// Combined chance of 75% if both happen

#include "\z\potato\addons\core\script_macros.hpp"
