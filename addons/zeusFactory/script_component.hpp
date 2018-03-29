#define COMPONENT zeusFactory
#include "\z\potato\addons\core\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_ZEUSFACTORY
    #define DEBUG_MODE_FULL
#endif

#include "\z\potato\addons\core\script_macros.hpp"

#define TRANSPORT_FOOT 0
#define TRANSPORT_CAR_RTB 1
#define TRANSPORT_CAR_FOLLOW 2
#define TRANSPORT_APC_RTB 3
#define TRANSPORT_APC_FOLLOW 4
#define TRANSPORT_HELI 5
#define TRANSPORT_PARADROP 6

#define ORDERS_MOVE 0
#define ORDERS_GARRISION 1
#define ORDERS_PATROL 2
#define ORDERS_SEARCH 3
#define ORDERS_ATTACK 4
