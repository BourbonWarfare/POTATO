#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * Description:
 * This function adds a zeusUtil function to the draw hashmap or update state.
 * Each draw function is provided with the current camera as the
 * "_localCuratorModule" variable. If there currently isn't a draw3D EH, then
 * one is created. The draw 3D EH is removed when the zeus interface is closed.
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

if (GVAR(draw3DEH) < 0) then {
    GVAR(draw3DEH) = addMissionEventHandler ["Draw3D", {
        if (isNull findDisplay 312) then {
            diag_log formatText ["Removing display EH: %1", diag_frameNo];
            removeMissionEventHandler [_thisEvent, _thisEventHandler];
            GVAR(draw3DEH) = -1;
        };
        private _localCuratorModule = curatorCamera;
        {
            call _y
        } forEach GVAR(draw3DFunctions);
    }];
};

switch (_ehType) do {
    case ZEUSUTILS_DEH_FPS: {
        GVAR(draw3DFunctions) set [QGVAR(fpsEH), {call FUNC(drawFPS)}];
    };
    case ZEUSUTILS_DEH_MARKERS: {
        GVAR(draw3DFunctions) set [QGVAR(markerEH), {call FUNC(drawMarkers)}];
    };
    default {};
};
