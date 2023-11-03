#define COMPONENT bodyCleanup
#include "\z\potato\addons\core\script_mod.hpp"

#define DEBUG_MODE_FULL
#define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#include "\z\potato\addons\core\script_macros.hpp"

// How many times/second event happens
#define CLEANUP_FREQUENCY (10 / 1)
#define UPDATE_FREQUENCY (1 / 1)

// Minimum distance that a cell has to be before it is considered for cleanup
#define MIN_CLEANUP_DISTANCE 500
// Maximum distance that is considered within a units FOV
#define MAX_CLEANUP_DISTANCE 1250
#define TIME_BEFORE_CLEANUP 120

#define CELL_SIZE 300
#define ARMA_DEFAULT_FOV 45
#define MAX_SAMPLE_SIZE (30 / 100)
