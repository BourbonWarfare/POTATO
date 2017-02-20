//Add all ACE and CBA macros:
#include "\z\ace\addons\main\script_macros.hpp"

#define ACE_PREFIX ace

#define ACEGVAR(module,var) TRIPLES(ACE_PREFIX,module,var)
#define QACEGVAR(module,var) QUOTE(ACEGVAR(module,var))
#define ACEFUNC(var1,var2) TRIPLES(DOUBLES(ACE_PREFIX,var1),fnc,var2)
#define DACEFUNC(var1,var2) TRIPLES(DOUBLES(ACE_PREFIX,var1),fnc,var2)
#define QACEFUNC(var1,var2) QUOTE(DACEFUNC(var1,var2))

#define CFUNC(var1) EFUNC(core,var1)

#define AUTHORIZED_USERS ["76561197976319415","76561198005847836","76561198089674282","76561198015013044","76561197991686585"]
#define TECH_USERS ["76561197991686585","76561198015013044"]

#define MISSION_HINT_SIDES [1, west, east, resistance, civilian, 0]
#define MISSION_HINT_RANKS [-99,1,2,3]

#define SERVER_CLIENT_ID 2

#define FADE_LENGTH 0.25
#define FADE_ENABLED 0
#define FADE_DISABLED 0.7

// Dev Ony: Enabling this will skip configs from any potato addons that require external mods
// #define POTATO_LEAN_CONFIGS
