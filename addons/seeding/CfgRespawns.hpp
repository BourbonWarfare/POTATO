// Sad respawn noises
#ifndef BW_SEEDING_POTATO_RESPAWN
respawn = 3;
respawnDelay = 15;
respawnOnStart = -1;
respawnTemplates[] = {
  "MenuPosition",
  "Wave",
  QGVAR(resetLoadout)
};
#else
respawnDelay = 5;
#endif

class CfgRespawnTemplates {
    class GVAR(resetLoadout) {
        onPlayerRespawn = QPFUNC(assignGear,requestPlayerGear);
    };
};
