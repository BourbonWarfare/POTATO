#include "script_component.hpp"
TRACE_1("Params",_this);

params [["_index", lbCurSel BUILD_GROUP_TO_ADD_IDC]];

lbDelete [BUILD_GROUP_TO_ADD_IDC, _index];
