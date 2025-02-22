#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * Description:
 * This function removes a specific draw function from the zeus utils draw
 * queue. If there are no actively drawn events, the event handler is removed.
 *
 *
 * Arguments:
 * 0: The eventhandler tpye (SCALAR, default ZEUSUTILS_DEH_INVALID)
 *
 * Return Value:
 * None
 *
 * Examples:
 * [ZEUTUTILS_DEH_FPS, 3] call potato_zeusUtils_fnc_addDraw3DEH;
 *
 * Public: No
 */
//IGNORE_PRIVATE_WARNING["_thisEvent", "_thisEventHandler"];
params [["_ehType", ZEUSUTILS_DEH_INVALID, [ZEUSUTILS_DEH_INVALID]]];

if (_ehType == ZEUSUTILS_DEH_INVALID) exitWith {
    TRACE_1("invalid draw EH",_ehType);
};

switch (_ehType) do {
    case ZEUSUTILS_DEH_FPS: {
        GVAR(draw3DFunctions) deleteAt QGVAR(fpsEH);
    };
    case ZEUSUTILS_DEH_MARKERS: {
        GVAR(draw3DFunctions) deleteAt QGVAR(markerEH);
    };
    default {};
};

if (GVAR(draw3DFunctions) isEqualTo createHashMap) then {
    removeMissionEventHandler ["Draw3D", GVAR(draw3DEH)];
    GVAR(draw3DEH) = -1;
};
