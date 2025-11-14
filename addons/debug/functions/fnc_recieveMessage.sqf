#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function recieved debug log messages to be plater printed to the
 * server's logfile. it recieves messages and stores params into a hash of
 * debug messages depending on an event enum
 *
 * Arguments:
 * 0: Event enum, default -1 (NUMBER)
 * 1: The client owner number, between 2 and a large number, default 0 (NUMBER)
 * 2: Event params array, default [] (Array)
 *
 * Return Value:
 * None
 *
 * Examples:
 * [DEBUG_EVENT_NETWORK_MARKERS, 2, ["fuck"]] call potato_debug_fnc_recieveMessage;
 *
 * Public: No
*/
params [
    ["_eventEnum", -1, [0]],
    ["_clientOwner", 0, [0]],
    ["_params", [], [[]]]
];

if (_eventEnum < 0 || _clientOwner < 2 || !isServer) exitWith {
    TRACE_4("Bad event or cleint",_eventEnum,_clientOwner,isServer,_params);
};
TRACE_1("Params",_this);
if (isNil QGVAR(messagesToPrint)) then {
    GVAR(messagesToPrint) = createHashMap;
};
private _hash = GVAR(messagesToPrint) getOrDefault [_eventEnum, createHashMap, true];

switch (_eventEnum) do {
    case DEBUG_EVENT_NETWORK_MARKERS: {
        _hash set [_clientOwner, _params];
        if (GVAR(outPutLogs)) then {
            call FUNC(printLog);
        };
    };
    default {};
};
