#include "..\script_component.hpp"
#include "\z\potato\addons\markers\defaultMarkerDefines.hpp"
/*
 * Author: Lambda.Tiger
 * This function collects information on markers and adds them to a saved
 * array. This array may be sent to the server for storage and later logging.
 * It takes an object to log and a boolean to check whether to send the array
 * of messages.
 *
 * Arguments:
 * 0: The object to check, default player (OBJECT)
 * 1: Whether to send the array of marker info, default false (BOOL)
 *
 * Return Value:
 * None
 *
 * Examples:
 * [] call potato_debug_fnc_addMarkerInfoEvent;
 * [player, true] call potato_debug_fnc_addMarkerInfoEvent;
 *
 * Public: No
 */
params [
    ["_drawObject", player, [objNull]],
    ["_sendQueue", false, [false]]
];
TRACE_2("params",_this);

if (missionNameSpace getVariable [QGVAR(disableOutput), false]) exitWith {
    TRACE_1("enableOutput",missionNameSpace getVariable [QGVAR(disableOutput), false]);
};

if (isNil QGVAR(markerQueue)) then {
    GVAR(markerQueue) = [];
};

private _hashKey = if (_drawObject getVariable [QEGVAR(markers,groupMarker), false]) then {
    GROUP_MARKER_ID_GROUPSTRING_UNIT(_drawObject)
} else {
    GROUP_MARKER_ID_UNITSTRING_UNIT(_drawObject)
};

GVAR(markerQueue) pushBack [
    [diag_tickTime, CBA_missionTime],
    [isGameFocused, isGamePaused, getClientState],
    [_drawObject, name _drawObject, local _drawObject, groupId _drawObject, groupId group _drawObject, roleDescription _drawObject],
    [_hashKey, isNull _drawObject, _drawObject getVariable [QEGVAR(markers,addMarker), false], _hashKey in EGVAR(markers,markerHash), EGVAR(markers,markerHash) getOrDefault [_hashKey, []]], [
        _drawObject getVariable [QEGVAR(markers,markerText), DEFAULT_MARKER_TEXT],
        _drawObject getVariable [QEGVAR(markers,markerTexture), "\z\potato\addons\markers\data\infantry.paa"],
        _drawObject getVariable [QEGVAR(markers,markerColor), DEFAULT_MARKER_COLOR],
        _drawObject getVariable [QEGVAR(markers,markerSize), DEFAULT_MARKER_SIZE]
]];

if (_sendQueue) then {
    [{
        [QGVAR(recieveMessage), [DEBUG_EVENT_NETWORK_MARKERS, clientOwner, GVAR(markerQueue)]] call CBA_fnc_serverEvent;
        GVAR(markerQueue) = nil;
    }, 0, clientOwner] call CBA_fnc_waitAndExecute;
};
