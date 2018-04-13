#include "script_component.hpp"


TRACE_1("params",_this);

if (QGVAR(deadCleanupEnabled)) then {
    _this#0 displayAddEventHandler ["KeyDown", {_this call FUNC(ui_handleCuratorKeyDown)}];
};
