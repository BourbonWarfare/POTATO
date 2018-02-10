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

(_commonChannels splitString ",") params [
    "_commonWestMR",
    "_commonWestLR",
    "_commonEastMR",
    "_commonEastLR",
    "_commonIndyMR",
    "_commonIndyLR",
    "_commonCivMR",
    "_commonCivLR"
];

missionNamespace setVariable [QGVAR(addCommonChannelWestMR), [_commonWestMR] call CFUNC(parseBool), true];
missionNamespace setVariable [QGVAR(addCommonChannelWestLR), [_commonWestLR] call CFUNC(parseBool), true];
missionNamespace setVariable [QGVAR(addCommonChannelEastMR), [_commonEastMR] call CFUNC(parseBool), true];
missionNamespace setVariable [QGVAR(addCommonChannelEastLR), [_commonEastLR] call CFUNC(parseBool), true];
missionNamespace setVariable [QGVAR(addCommonChannelIndyMR), [_commonIndyMR] call CFUNC(parseBool), true];
missionNamespace setVariable [QGVAR(addCommonChannelIndyLR), [_commonIndyLR] call CFUNC(parseBool), true];
missionNamespace setVariable [QGVAR(addCommonChannelCivMR), [_commonCivMR] call CFUNC(parseBool), true];
missionNamespace setVariable [QGVAR(addCommonChannelCivLR), [_commonCivLR] call CFUNC(parseBool), true];

INFO("Setting arrays globaly");

missionNamespace setVariable [QGVAR(westDefaultLanguages), _westLanguages splitString ",", true];
missionNamespace setVariable [QGVAR(eastDefaultLanguages), _eastLanguages splitString ",", true];
missionNamespace setVariable [QGVAR(indyDefaultLanguages), _indyLanguages splitString ",", true];
missionNamespace setVariable [QGVAR(civDefaultLanguages), _civLangauges splitString ",", true];

missionNamespace setVariable [QGVAR(westSRChannelNames), _westSR splitString ",", true];
missionNamespace setVariable [QGVAR(westMRChannelNames), _westMR splitString ",", true];
missionNamespace setVariable [QGVAR(westLRChannelNames), _westLR splitString ",", true];
missionNamespace setVariable [QGVAR(eastSRChannelNames), _eastSR splitString ",", true];
missionNamespace setVariable [QGVAR(eastMRChannelNames), _eastMR splitString ",", true];
missionNamespace setVariable [QGVAR(eastLRChannelNames), _eastLR splitString ",", true];
missionNamespace setVariable [QGVAR(indySRChannelNames), _indySR splitString ",", true];
missionNamespace setVariable [QGVAR(indyMRChannelNames), _indyMR splitString ",", true];
missionNamespace setVariable [QGVAR(indyLRChannelNames), _indyLR splitString ",", true];
missionNamespace setVariable [QGVAR(civSRChannelNames), _civSR splitString ",", true];
missionNamespace setVariable [QGVAR(civMRChannelNames), _civMR splitString ",", true];
missionNamespace setVariable [QGVAR(civLRChannelNames), _civLR splitString ",", true];
