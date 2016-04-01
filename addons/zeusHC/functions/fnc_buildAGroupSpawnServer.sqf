// NO_SIDE -1, EAST 0, WEST 1, RESISTANCE 2, CIVILIAN 3, NEUTRAL 4, ENEMY 5, FRIENDLY 6, LOGIC 7
#include "script_component.hpp"
TRACE_1("params",_this);

_this remoteExecCall [QFUNC(buildAGroupSpawnLocal), [] call FUNC(getSpawnMachineId)];
