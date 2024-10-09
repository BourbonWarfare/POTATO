#include "script_component.hpp"

params ["_hash", "_weapon", "_op", ["_default", nil]];

if (_op == "in") exitWith {
    if (_hash isEqualType createHashMap) then {
        private _weapon = configName (configFile >> "CfgWeapons" >> _weapon);
        _weapon in _hash
    } else {
        !isNil {_hash getVariable _weapon}
    };
};
if (_op == "get") exitWith {
    if (_hash isEqualType createHashMap) then {
        private _weapon = configName (configFile >> "CfgWeapons" >> _weapon);
        _hash getOrDefault [_weapon, _default]
    } else {
        _hash getVariable [_weapon, _default]
    };
};

ERROR("bad op");
