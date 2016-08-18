/*
 *
 */

#include "script_component.hpp"
TRACE_2("params",_this,_this getVariable QGVAR(setBabel));

if (_this getVariable [QGVAR(setBabel), false]) then {

    private _ctrlBabel = _this controlsGroupCtrl BABEL_LIST_IDC;
    private _selectedIndices = lbSelection _ctrlBabel;

    private _languages = [];
    {
        _languages pushBack (_ctrlBabel lnbText [_x,0]);
    } forEach _selectedIndices;

    _languages joinString ",";
} else {
    true
}
