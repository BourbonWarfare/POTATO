#include "script_component.hpp"

params ["_display", "_fncString"];
TRACE_2("canAttach",_display,_fncString);


switch (toLower _fncString) do {
case ("init"): {systemChat "Init";};
case ("uniform"): {
        GVAR(loadout_uniform) = uniform player;
        GVAR(loadout_vest) = vest player;
        GVAR(loadout_backpack) = backpack player;
        GVAR(loadout_headgear) = headgear player;
        systemChat format ["[Set %1]: %2 %3 %4 %5", _fncString, GVAR(loadout_uniform), GVAR(loadout_vest), GVAR(loadout_backpack), GVAR(loadout_headgear)];
    };
case ("rifle"): {
        GVAR(loadout_rifle) = primaryWeapon player;
        GVAR(loadout_rifleMags) = [];
        GVAR(loadout_rifleAttachments) = primaryWeaponItems player;
        {
            if (_x in getArray (configFile >> "CfgWeapons" >> GVAR(loadout_rifle) >> "magazines")) then {
                GVAR(loadout_rifleMags) pushBackUnique _x;
            };
        } forEach (magazines player);
        systemChat format ["[Set %1]: %2 %3 %4", _fncString, GVAR(loadout_rifle), GVAR(loadout_rifleMags), GVAR(loadout_rifleAttachments)];
    };
case ("glrifle"): {
        GVAR(loadout_glrifle) = primaryWeapon player;
        systemChat format ["[Set %1]: %2", _fncString, GVAR(loadout_glrifle)];
    };
case ("carbine"): {
        GVAR(loadout_carbine) = primaryWeapon player;
        systemChat format ["[Set %1]: %2", _fncString, GVAR(loadout_carbine)];
    };
case ("ar"): {
        GVAR(loadout_ar) = primaryWeapon player;
        GVAR(loadout_arMags) = [];
        {
            if (_x in getArray (configFile >> "CfgWeapons" >> GVAR(loadout_ar) >> "magazines")) then {
                GVAR(loadout_arMags) pushBackUnique _x;
            };
        } forEach (magazines player);
        systemChat format ["[Set %1]: %2 %3", _fncString, GVAR(loadout_ar), GVAR(loadout_arMags)];
    };
case ("mmg"): {
        GVAR(loadout_mmg) = primaryWeapon player;
        GVAR(loadout_mmgMags) = [];
        {
            if (_x in getArray (configFile >> "CfgWeapons" >> GVAR(loadout_mmg) >> "magazines")) then {
                GVAR(loadout_mmgMags) pushBackUnique _x;
            };
        } forEach (magazines player);
        systemChat format ["[Set %1]: %2 %3", _fncString, GVAR(loadout_mmg), GVAR(loadout_mmgMags)];
    };
case ("at"): {
        GVAR(loadout_at) = secondaryWeapon player;
        GVAR(loadout_atMags) = [];
        {
            if (_x in getArray (configFile >> "CfgWeapons" >> GVAR(loadout_at) >> "magazines")) then {
                GVAR(loadout_atMags) pushBackUnique _x;
            };
        } forEach (magazines player);
        systemChat format ["[Set %1]: %2 %3", _fncString, GVAR(loadout_at), GVAR(loadout_atMags)];
    };
case ("mat"): {
        GVAR(loadout_mat) = secondaryWeapon player;
        GVAR(loadout_matMags) = [];
        {
            if (_x in getArray (configFile >> "CfgWeapons" >> GVAR(loadout_mat) >> "magazines")) then {
                GVAR(loadout_matMags) pushBackUnique _x;
            };
        } forEach (magazines player);
        GVAR(loadout_matAttachments) = secondaryWeaponItems player;
        systemChat format ["[Set %1]: %2 %3 %4", _fncString, GVAR(loadout_mat), GVAR(loadout_matMags), GVAR(loadout_matAttachments)];
    };
    default {ERROR_1("bad fnc [%1]",_fncString);};
};

{
    private _ctrlText = _x;
    private _output = "";
    {
        _output = _output + format ["%1 ", missionNamespace getVariable [_x, "err"]];
    } forEach (_ctrlText getVariable [QGVAR(vars), []]);
    _ctrlText ctrlSetText _output;
    _ctrlText ctrlSetTooltip _output;
} forEach (_display getVariable [QGVAR(ctrlsToUpdate), []]);
