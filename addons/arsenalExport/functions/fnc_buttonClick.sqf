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
            private _mag = _x;
            if (({_mag == _x} count getArray (configFile >> "CfgWeapons" >> GVAR(loadout_rifle) >> "magazines")) > 0) then {
                GVAR(loadout_rifleMags) pushBackUnique _mag;
            };
        } forEach (magazines player);
        systemChat format ["[Set %1]: %2 %3 %4", _fncString, GVAR(loadout_rifle), GVAR(loadout_rifleMags), GVAR(loadout_rifleAttachments)];
    };
case ("glrifle"): {
        GVAR(loadout_glrifle) = primaryWeapon player;        
        GVAR(loadout_glRifleMags) = [];
        {
            private _mag = _x;
            if (({_mag == _x} count getArray (configFile >> "CfgWeapons" >> GVAR(loadout_glrifle) >> "magazines")) > 0) then {
                GVAR(loadout_glRifleMags) pushBackUnique _mag;
            };
        } forEach (magazines player);
        systemChat format ["[Set %1]: %2 %3", _fncString, GVAR(loadout_glrifle), GVAR(loadout_glRifleMags)];
    };
case ("carbine"): {
        GVAR(loadout_carbine) = primaryWeapon player;
        GVAR(loadout_carbineMags) = [];
        {
            private _mag = _x;
            if (({_mag == _x} count getArray (configFile >> "CfgWeapons" >> GVAR(loadout_carbine) >> "magazines")) > 0) then {
                GVAR(loadout_carbineMags) pushBackUnique _mag;
            };
        } forEach (magazines player);
        systemChat format ["[Set %1]: %2 %3", _fncString, GVAR(loadout_carbine), GVAR(loadout_carbineMags)];
    };
case ("ar"): {
        GVAR(loadout_ar) = primaryWeapon player;
        GVAR(loadout_arMags) = [];
        {
            private _mag = _x;
            if (({_mag == _x} count getArray (configFile >> "CfgWeapons" >> GVAR(loadout_ar) >> "magazines")) > 0) then {
                GVAR(loadout_arMags) pushBackUnique _mag;
            };
        } forEach (magazines player);
        systemChat format ["[Set %1]: %2 %3", _fncString, GVAR(loadout_ar), GVAR(loadout_arMags)];
    };
case ("mmg"): {
        GVAR(loadout_mmg) = primaryWeapon player;
        GVAR(loadout_mmgMags) = [];
        {
            private _mag = _x;
            if (({_mag == _x} count getArray (configFile >> "CfgWeapons" >> GVAR(loadout_mmg) >> "magazines")) > 0) then {
                GVAR(loadout_mmgMags) pushBackUnique _mag;
            };
        } forEach (magazines player);
        systemChat format ["[Set %1]: %2 %3", _fncString, GVAR(loadout_mmg), GVAR(loadout_mmgMags)];
    };
case ("at"): {
        GVAR(loadout_at) = secondaryWeapon player;
        GVAR(loadout_atMags) = [];
        {
            private _mag = _x;
            if (({_mag == _x} count getArray (configFile >> "CfgWeapons" >> GVAR(loadout_at) >> "magazines")) > 0) then {
                GVAR(loadout_atMags) pushBackUnique _mag;
            };
        } forEach (magazines player);
        systemChat format ["[Set %1]: %2 %3", _fncString, GVAR(loadout_at), GVAR(loadout_atMags)];
    };
case ("mat"): {
        GVAR(loadout_mat) = secondaryWeapon player;
        GVAR(loadout_matMags) = [];
        {
            private _mag = _x;
            if (({_mag == _x} count getArray (configFile >> "CfgWeapons" >> GVAR(loadout_mat) >> "magazines")) > 0) then {
                GVAR(loadout_matMags) pushBackUnique _mag;
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
