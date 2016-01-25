#define COMPONENT mapMarkers
#include "\z\potato\addons\core\script_mod.hpp"

#define DEBUG_MODE_FULL
#define DISABLE_COMPILE_CACHE
#define CBA_DEBUG_SYNCHRONOUS

#ifdef DEBUG_ENABLED_MAPMARKERS
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_MAPMARKERS
    #define DEBUG_SETTINGS DEBUG_SETTINGS_MAPMARKERS
#endif

#include "\z\potato\addons\core\script_macros.hpp"

#define IDD_MAIN_MAP 12
#define IDD_INTEL_GETREADY 37
#define IDD_SERVER_GET_READY 52
#define IDD_CLIENT_GET_READY 53

#define IDC_MAP 51
