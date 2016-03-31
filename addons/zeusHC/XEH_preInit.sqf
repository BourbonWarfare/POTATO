#include "script_component.hpp"

ADDON = false;

PREP(createEntityServer);
PREP(createEntityLocal);
PREP(createEntityZeus);

PREP(getSpawnMachineId);

PREP(buildAGroup);
PREP(buildACache);
PREP(buildAGroupDialogAdd);
PREP(buildAGroupSpawnLocal);
PREP(buildAGroupDialogLoad);
PREP(buildAGroupSpawnServer);
PREP(buildAGroupDialogSpawn);
PREP(buildAGroupDialogRemove);
PREP(buildAGroupDialogFactionChange);

PREP(spawnAVic);
PREP(spawnACache);
PREP(spawnAVicSpawnLocal);
PREP(spawnAVicDialogLoad);
PREP(spawnAVicSpawnServer);
PREP(spawnAVicDialogSpawn);
PREP(spawnAVicDialogFactionChange);

PREP(transferSetVar);
PREP(transferGroupsToHC);
PREP(transferAllToHCZeus);

ADDON = true;
