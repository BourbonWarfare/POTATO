#include "script_component.hpp"

if (GVAR(usePotato) && hasInterface) then {
    if (didJIP) then {
        if (time > 0) then {
            INFO("JIP - Ran post start code");
            [FUNC(requestPlayerGear), [player]] call CBA_fnc_execNextFrame;
        } else {
            INFO("JIP - Ran pre start code");
            [{time > 0}, CBA_fnc_execNextFrame, [FUNC(requestPlayerGear), [player]]] call CBA_fnc_waitUntilAndExecute;
        };
    };

    if (GVAR(allowChangeableOptics)) then {
        ["unit", {
            params ["_player"];
            _player setVariable [QGVAR(changeOpticsTimeLimit), CBA_missionTime + 60]; // can change for a minute after jip or respawn
        }, true] call CBA_fnc_addPlayerEventHandler;

        private _baseAction = [
            QGVAR(changeableOptics),
            "Choose Optic",
            QPATHTOF(data\scope.paa),
            {},
            {
                params ["_player"];
                (missionNamespace getVariable [QEGVAR(safeStart,startTime_PV), -1] != -1)  // safe start active
                || {CBA_missionTime < (_player getVariable [QGVAR(changeOpticsTimeLimit), -1])} // respawn/jip and can still change optics
            },
            {call FUNC(changeableOptics_getChildren)}
        ] call ACEFUNC(interact_menu,createAction);

        x1 = [
            "CAManBase", 1,
            ["ACE_SelfActions", "ACE_Equipment"],
            _baseAction, true
        ] call ACEFUNC(interact_menu,addActionToClass);
    };
};
