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
                [] call FUNC(mouseCatch);
            };
        };
    }] call CBA_fnc_addEventHandler;
};
