#include "script_component.hpp"

ADDON = false;

PREP(createEntityZeus);
PREP(createEntityLocal);
PREP(createEntityDismounts);

PREP(getSpawnMachineId);

PREP(buildACache);
PREP(buildAGroupZeus);
PREP(buildAGroupDialogAdd);
PREP(buildAGroupSpawnLocal);
PREP(buildAGroupDialogLoad);
PREP(buildAGroupSpawnServer);
PREP(buildAGroupDialogSpawn);
PREP(buildAGroupDialogRemove);
PREP(buildAGroupDialogFactionChange);

PREP(spawnACache);
PREP(spawnAVicZeus);
PREP(spawnAVicSpawnLocal);
PREP(spawnAVicDialogLoad);
PREP(spawnAVicSpawnServer);
PREP(spawnAVicDialogSpawn);
PREP(spawnAVicDialogFactionChange);

PREP(transferSetVar);
PREP(transferGroupsToHC);
PREP(transferAllToHCZeus);

PREP(garrisonCache);
PREP(garrisonLocal);
PREP(garrisonSpawn);
PREP(garrisonModule);
PREP(garrisonServer);
PREP(garrisonDialogLoad);
PREP(garrisonDialogSpawn);
PREP(garrisonIsFacingWall);
PREP(garrisonDialogCheckMinMax);
PREP(garrisonDialogControlChange);

ADDON = true;
