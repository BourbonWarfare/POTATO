#include "script_component.hpp"
TRACE_1("params",_this);
params ["_unit","_group", ["_exitIfNotServer", false, [false]]];

if (isServer) exitWith {
    [_unit] remoteExecCall [VQFUNC(addToSystemDelayed), groupOwner _group]
};

if (_exitIfNotServer) exitWith {
    ERROR("_exitIfNotServer is true, but not executed on the server");
    nil
};

[_unit, _group, true] remoteExecCall [VQFUNC(transferToNewOwner), SERVER_CLIENT_ID]
