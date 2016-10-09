/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

private _group = group ace_player;

private _groupLanguages = _group getVariable [QGVAR(assignedLanguages),GVAR(sideLanguages)];
private _playerLanguages = ace_player getVariable [QGVAR(assignedLanguages), _groupLanguages];

TRACE_1("languages",_playerLanguages);
_playerLanguages call ACRE_FUNC(babelSetSpokenLanguages);

[_group, RADIO_SR, QGVAR(srChannel)] call FUNC(setChannel);
[_group, RADIO_MR, QGVAR(mrChannel)] call FUNC(setChannel);
[_group, RADIO_LR, QGVAR(lrChannel)] call FUNC(setChannel);
