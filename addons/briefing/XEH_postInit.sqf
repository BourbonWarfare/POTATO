#include "script_component.hpp"

if (hasInterface) then {
    ["playerChanged", {
        TRACE_1("playerChanged eh",ace_player);
        _this call FUNC(addBriefingToUnit);
    }] call ACEFUNC(common,addEventhandler);
};
