/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params [
    ["_changedArray", [false,false,false], [[]], 3],
    ["_srChannels", [], [[]]],
    ["_mrChannels", [], [[]]],
    ["_lrChannels", [], [[]]]
];

_changedArray params [
    ["_srChanged", false, [false]],
    ["_mrChanged", false, [false]],
    ["_lrChanged", false, [false]]
];

private _returnSRChannels = [];
private _returnMRChannels = [];
private _returnLRChannels = [];

if (_srChanged) then {
    _returnSRChannels = _srChannels;
};
if (_mrChanged) then {
    _returnMRChannels = _mrChannels;
};
if (_lrChanged) then {
    _returnLRChannels = _lrChannels;
};

[
    _returnSRChannels,
    _returnMRChannels,
    _returnLRChannels
]
