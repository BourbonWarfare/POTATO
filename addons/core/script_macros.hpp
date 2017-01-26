//Add all ACE and CBA macros:
#include "\z\ace\addons\main\script_macros.hpp"

#define ACE_PREFIX ace

#define ACEGVAR(module,var) TRIPLES(ACE_PREFIX,module,var)
#define QACEGVAR(module,var) QUOTE(ACEGVAR(module,var))
#define ACEFUNC(var1,var2) TRIPLES(DOUBLES(ACE_PREFIX,var1),fnc,var2)
#define DACEFUNC(var1,var2) TRIPLES(DOUBLES(ACE_PREFIX,var1),fnc,var2)
#define QACEFUNC(var1,var2) QUOTE(DACEFUNC(var1,var2))

#define CFUNC(var1) EFUNC(core,var1)

#define AUTHORIZED_USERS ["76561197993419566", "76561197970715242","76561198087419490", "76561197997311964", "76561197985457597", "76561197988968579", "76561197965053565", "76561198004668374"]
#define TECH_USERS ["76561197970715242","76561197993419566","76561198004668374"]

#define MISSION_HINT_SIDES [1, west, east, resistance, civilian, 0]
#define MISSION_HINT_RANKS [-99,1,2,3]

#define SERVER_CLIENT_ID 2

#define FADE_LENGTH 0.25
#define FADE_ENABLED 0
#define FADE_DISABLED 0.7

// Dev Ony: Enabling this will skip configs from any potato addons that require external mods
// #define POTATO_LEAN_CONFIGS
