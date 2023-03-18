#include "script_component.hpp"

if (!isServer) exitWith {};
params ["_logic"];
private _typeOf = typeOf _logic;
private _side =  _logic getVariable ["side", -1];
private _voice = _logic getVariable ["speaker", ""];
if (_voice == "") then { _voice = _logic getVariable ["voice", ""]; };
// backward compat for orignal version using "voice" property which is protected//reserved?
// "" Custom attribute "voice" was updated to engine one. ""

deleteVehicle _logic;
TRACE_3("",_typeOf,_side,_voice);

if ((_side <= 0) || {_side > 4}) exitWith { ERROR_1("bad side %1",_side); };

private _voices = (getArray (configFile >> "CfgVehicles" >> _typeOf >> "Attributes" >> "Speaker" >> "values" >> _voice >> "data"));
_voices = _voices select { isClass (configFile >> "CfgVoice" >> _x) }; // check they actually exist
if ((count _voices) < 1) exitWith { WARNING_1("bad voices %1",_voices); };

if (isNil QGVAR(voiceArray)) then { GVAR(voiceArray) = []; };
private _addEH = (GVAR(voiceArray) param [_side, []]) isEqualTo [];
GVAR(voiceArray) set [_side, _voices];

if (!_addEH) exitWith { WARNING_1("duplicate modules for side %1",_side); };

[{
    TRACE_1("adding init EH",_this);
    switch (_this) do {
        case 1: {
            ["potato_w_rifleman" , "Init", { [_this, 1] call FUNC(identity_set) }, true, nil, true] call CBA_fnc_addClassEventHandler;
        };
        case 2: {
            ["potato_e_rifleman" , "Init", { [_this, 2] call FUNC(identity_set) }, true, nil, true] call CBA_fnc_addClassEventHandler;
        };
        case 3: {
            ["potato_i_rifleman" , "Init", { [_this, 3] call FUNC(identity_set) }, true, nil, true] call CBA_fnc_addClassEventHandler;
        };
        case 4: {
            ["Civilian" , "Init", { [_this, 4] call FUNC(identity_set) }, true, nil, true] call CBA_fnc_addClassEventHandler;
        };
    };
}, _side, 1] call CBA_fnc_waitAndExecute;
