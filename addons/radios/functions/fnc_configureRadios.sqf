/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

private _group = group player;

TRACE_1("languages",GVAR(playerLanguages));
GVAR(playerLanguages) call ACRE_FUNC(babelSetSpokenLanguages);

[_group, RADIO_SR, QGVAR(srChannel)] call FUNC(setChannel);
[_group, RADIO_MR, QGVAR(mrChannel)] call FUNC(setChannel);
[_group, RADIO_LR, QGVAR(lrChannel)] call FUNC(setChannel);
