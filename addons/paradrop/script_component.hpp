#define COMPONENT paradrop
#include "\z\potato\addons\core\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_PARADROP
    #define DEBUG_MODE_FULL
#endif

#include "\z\potato\addons\core\script_macros.hpp"

// Cargo aidrop defines
#define AIRDROP_WP_TEXT "Infil Direction","Drop Begin","Drop Direction","Exfil Direction"
#define AIRDROP_DEF_VEHICLES []
#define AIRDROP_DEFAULT_SIDE west

#define IDD_AIRDROP_DIALOG 20260724
#define IDC_AIRDROP_MAP 3200
#define IDC_AIRDROP_SIDE 2200
#define IDC_AIRDROP_DROPOPTIONS 2400
#define IDC_AIRDROP_ADDVIC 2500
#define IDC_AIRDROP_ADDVIC_PARAFAIL 2600
#define IDC_AIRDROP_REMOVEVIC 2700
#define IDC_AIRDROP_SPAWNVIC 2800
#define IDC_AIRDROP_PLANETYPE 2900

