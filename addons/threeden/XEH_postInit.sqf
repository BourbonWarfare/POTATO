#include "script_component.hpp"

["playerChanged", {
    TRACE_1("playerChanged eh",ace_player);
    _this call FUNC(addBriefingToUnit);
}] call ACEFUNC(common,addEventhandler);
