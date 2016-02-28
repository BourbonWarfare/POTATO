#include "script_component.hpp"

ADDON = false;

PREP(checkMods);
PREP(checkModsWriteDiary);
PREP(endMission);
PREP(openAdminMenu);
PREP(openRespawn);

PREP(uihook_checkMods);
PREP(uihook_endMission);
PREP(uihook_missionHint);
PREP(uihook_openEndMission);
PREP(uihook_safeStart);
PREP(uihook_tabChange);
PREP(uihook_supplySpawn);
PREP(uihook_teleportButton);
PREP(uihook_weaponTest);
PREP(uihook_zeusConnectPlayer);

PREP(zeusConnectCurator);

ADDON = true;
