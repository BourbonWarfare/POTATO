#include "script_component.hpp"

//spawn on remote machine
_this remoteExecCall [QFUNC(spawnReinforcements), [] call FUNC(getSpawnMachineId)];