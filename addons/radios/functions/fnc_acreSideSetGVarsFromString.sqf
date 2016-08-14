/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_paramsStrings"];

_paramsStrings params [
    "_commonChannels",
    "_westLanguages",
    "_eastLanguages",
    "_indyLanguages",
    "_civLangauges",
    "_westSR",
    "_westMR",
    "_westLR",
    "_eastSR",
    "_eastMR",
    "_eastLR",
    "_indySR",
    "_indyMR",
    "_indyLR",
    "_civSR",
    "_civMR",
    "_civLR"
];

_commonChannels params [
    "_commonWestMR",
    "_commonWestLR",
    "_commonEastMR",
    "_commonEastLR",
    "_commonIndyMR",
    "_commonIndyLR",
    "_commonCivMR",
    "_commonCivLR"
];

[QGVAR(addCommonChannelWestMR), [_commonWestMR] call CFUNC(parseBool), true, true] call ACEFUNC(common,setSetting);
[QGVAR(addCommonChannelWestLR), [_commonWestLR] call CFUNC(parseBool), true, true] call ACEFUNC(common,setSetting);
[QGVAR(addCommonChannelEastMR), [_commonEastMR] call CFUNC(parseBool), true, true] call ACEFUNC(common,setSetting);
[QGVAR(addCommonChannelEastLR), [_commonEastLR] call CFUNC(parseBool), true, true] call ACEFUNC(common,setSetting);
[QGVAR(addCommonChannelIndyMR), [_commonIndyMR] call CFUNC(parseBool), true, true] call ACEFUNC(common,setSetting);
[QGVAR(addCommonChannelIndyLR), [_commonIndyLR] call CFUNC(parseBool), true, true] call ACEFUNC(common,setSetting);
[QGVAR(addCommonChannelCivMR), [_commonCivMR] call CFUNC(parseBool), true, true] call ACEFUNC(common,setSetting);
[QGVAR(addCommonChannelCivLR), [_commonCivLR] call CFUNC(parseBool), true, true] call ACEFUNC(common,setSetting);

[QGVAR(westDefaultLanguages), _westLanguages splitString ",", true, true] call ACEFUNC(common,setSetting);
[QGVAR(eastDefaultLanguages), _eastLanguages splitString ",", true, true] call ACEFUNC(common,setSetting);
[QGVAR(indyDefaultLanguages), _indyLanguages splitString ",", true, true] call ACEFUNC(common,setSetting);
[QGVAR(civDefaultLanguages), _civLangauges splitString ",", true, true] call ACEFUNC(common,setSetting);

[QGVAR(westSRChannelNames), _westSR splitString ",", true, true] call ACEFUNC(common,setSetting);
[QGVAR(westMRChannelNames), _westMR splitString ",", true, true] call ACEFUNC(common,setSetting);
[QGVAR(westLRChannelNames), _westLR splitString ",", true, true] call ACEFUNC(common,setSetting);
[QGVAR(eastSRChannelNames), _eastSR splitString ",", true, true] call ACEFUNC(common,setSetting);
[QGVAR(eastMRChannelNames), _eastMR splitString ",", true, true] call ACEFUNC(common,setSetting);
[QGVAR(eastLRChannelNames), _eastLR splitString ",", true, true] call ACEFUNC(common,setSetting);
[QGVAR(indySRChannelNames), _indySR splitString ",", true, true] call ACEFUNC(common,setSetting);
[QGVAR(indyMRChannelNames), _indyMR splitString ",", true, true] call ACEFUNC(common,setSetting);
[QGVAR(indyLRChannelNames), _indyLR splitString ",", true, true] call ACEFUNC(common,setSetting);
[QGVAR(civSRChannelNames), _civSR splitString ",", true, true] call ACEFUNC(common,setSetting);
[QGVAR(civMRChannelNames), _civMR splitString ",", true, true] call ACEFUNC(common,setSetting);
[QGVAR(civLRChannelNames), _civLR splitString ",", true, true] call ACEFUNC(common,setSetting);
