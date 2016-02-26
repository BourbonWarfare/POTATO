#include "script_component.hpp"

diag_log text format ["HERE", _this];
diag_log text format ["HERE", _this];
diag_log text format ["HERE", _this];
diag_log text format ["HERE", _this];

TRACE_1("badbeef",_this);

["playerChanged", {
    TRACE_1("playerChanged eh",ace_player);
    _this call FUNC(addBriefingToUnit);
}] call ACEFUNC(common,addEventhandler);
