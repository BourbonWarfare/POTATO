#include "script_component.hpp"

params [["_index", lbCurSel BUILD_GROUP_TO_ADD_IDC]];
TRACE_1("params",_index);

lbDelete [BUILD_GROUP_TO_ADD_IDC, _index];
