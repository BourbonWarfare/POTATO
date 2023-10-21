#include "script_component.hpp"

GVAR(logs) = [];

if (hasInterface) then {
    ["potato_adminMsg", {
        if ([] call EFUNC(core,isAuthorized)) then {
            TRACE_1("Adding Log", _this);
            params ["_msg", ["_from", "?"], ["_to", ""]];
            GVAR(logs) pushBack [time, _msg, _from, _to];

            if (!isNull (findDisplay 49)) then {
                //If they have it open, update chat log now:
                [findDisplay 49] call FUNC(mouseCatch);
            };
        };
    }] call CBA_fnc_addEventHandler;
};

if (isServer) then {
    [{
        private _authorName = getMissionConfigValue ["author", "???"];
        private _authorPresent = (allUnits findIf {(name _x) == _authorName}) > -1;
        ["potato_adminMsg", [format ["-Mission Maker [Present: %1]", _authorPresent], _authorName]] call CBA_fnc_globalEvent;
    }, [], 1] call CBA_fnc_waitAndExecute;
};
