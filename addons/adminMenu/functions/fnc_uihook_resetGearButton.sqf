#include "script_component.hpp"

TRACE_1("params",_this);

private _selectedPersonIndex = lbCurSel UI_TAB_FIXGEAR_PERSON;
private _listOfUnits = UI_TAB_FIXGEAR_PERSON getVariable ["listOfUnits", []];

TRACE_2("",_selectedPersonIndex,_listOfUnits);

if ((_selectedPersonIndex < 0) || {_selectedPersonIndex >= (count _listOfUnits)}) exitWith {TRACE_1("bad index?", _selectedPersonIndex);};

private _selectedPerson = _listOfUnits select _selectedPersonIndex;
if (isNull _selectedPerson) exitWith {};

[QGVAR(resetGear), _selectedPerson, [_selectedPerson]] call ACEFUNC(common,objectEvent);
