#include "script_component.hpp"

params [["_index", lbCurSel BUILD_GROUP_UNITS_IDC]];
TRACE_1("params",_index);

private _newIndex = lbAdd [BUILD_GROUP_TO_ADD_IDC, lbText [BUILD_GROUP_UNITS_IDC, _index]];
lbSetPicture [BUILD_GROUP_TO_ADD_IDC, _newIndex, lbPicture [BUILD_GROUP_UNITS_IDC, _index]];
lbSetData [BUILD_GROUP_TO_ADD_IDC, _newIndex, lbData [BUILD_GROUP_UNITS_IDC, _index]];
