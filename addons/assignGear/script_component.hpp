#define COMPONENT assignGear
#include "\z\potato\addons\core\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_ASSIGNGEAR
    #define DEBUG_MODE_FULL
#endif

#include "\z\potato\addons\core\script_macros.hpp"

// magnified optic zoom threshold
#define MAG_OPTIC_ZOOM_THRESHOLD 0.25

// loadout array indexes
#define LA_PRIMARY_WEAPON_INDEX 0
#define LA_LAUNCHER_WEAPON_INDEX 1
#define LA_HANDGUN_WEAPON_INDEX 2
#define LA_UNIFORM_INDEX 3
#define LA_VEST_INDEX 4
#define LA_BACKPACK_INDEX 5
#define LA_HELMET_INDEX 6
#define LA_FACEWARE_INDEX 7
#define LA_BINOCULAR_INDEX 8
#define LA_LINKED_ITEMS_INDEX 9

// loadout array weapon indexes
#define LAW_WEAPON_INDEX 0
#define LAW_MUZZLE_INDEX 1
#define LAW_POINTER_INDEX 2
#define LAW_OPTIC_INDEX 3
#define LAW_PRIMARY_MUZZLE_MAG_INDEX 4
#define LAW_SECONDARY_MUZZLE_MAG_INDEX 5
#define LAW_BIPOD_INDEX 6

// allowed slots by container
#define VEST_ALLOWED_SLOTS 701
#define UNIFORM_ALLOWED_SLOTS 801
#define BACKPACK_ALLOWED_SLOTS 901

// item types
#define PRIMARY_TYPE 1
#define HANDGUN_TYPE 2
#define LAUNCHER_TYPE 4
#define MUZZLE_TYPE 101
#define OPTIC_TYPE 201
#define POINTER_TYPE 301
#define BIPOD_TYPE 302
#define BINO_TYPE 4096
