#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function outputs stored debug infomation, normally at the end of safe start.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Examples:
 * [] call potato_debug_fnc_printLog;
 *
 * Public: No
 */
{
    switch (_x) do {
        case DEBUG_EVENT_NETWORK_MARKERS: {
            diag_log text "[POTATO][DEBUG][NETMARS] Printing network marks";
        };
        default {
            diag_log text "[POTATO][DEBUG][ERR] Unknown type";
        }
    };
    {
        diag_log formatText ["Printing Client: %1", _x];
        {
            diag_log formatText ["%1 %2", _forEachIndex, _x];
        } forEach _y;
    } forEach _y;
} forEach GVAR(messagesToPrint);
GVAR(messagesToPrint) = createHashMap;
GVAR(outPutLogs) = true;
