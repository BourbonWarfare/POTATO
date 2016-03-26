#include "script_component.hpp"

TRACE_1("params",_this);

//spawn on remote machine
_this remoteExecCall [QFUNC(spawnReinforcements), [] call FUNC(getSpawnMachineId)];