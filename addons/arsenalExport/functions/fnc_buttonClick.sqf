#include "script_component.hpp"

params ["_display", "_fncString"];
TRACE_2("canAttach",_display,_fncString);

private _unit = missionNamespace getVariable ["ace_arsenal_center", player]; /// supports ace arsanal in 3den

switch (toLower _fncString) do {
case ("init"): {systemChat "Init";};
case ("uniform"): {
        GVAR(loadout_uniform) = uniform _unit;
        GVAR(loadout_vest) = vest _unit;
        GVAR(loadout_backpack) = backpack _unit;
        GVAR(loadout_headgear) = headgear _unit;
        systemChat format ["[Set %1]: %2 %3 %4 %5", _fncString, GVAR(loadout_uniform), GVAR(loadout_vest), GVAR(loadout_backpack), GVAR(loadout_headgear)];
    };
case ("rifle"): {
        GVAR(loadout_rifle) = primaryWeapon _unit;
        GVAR(loadout_rifleMags) = ((primaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect ([GVAR(loadout_rifle)] call CBA_fnc_compatibleMagazines);
        GVAR(loadout_rifleAttachments) = primaryWeaponItems _unit;
        systemChat format ["[Set %1]: %2 %3 %4", _fncString, GVAR(loadout_rifle), GVAR(loadout_rifleMags), GVAR(loadout_rifleAttachments)];
    };
case ("glrifle"): {
        GVAR(loadout_glrifle) = primaryWeapon _unit;
        GVAR(loadout_glRifleMags) = ((primaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect ([GVAR(loadout_glrifle)] call CBA_fnc_compatibleMagazines);
        systemChat format ["[Set %1]: %2 %3", _fncString, GVAR(loadout_glrifle), GVAR(loadout_glRifleMags)];
    };
case ("carbine"): {
        GVAR(loadout_carbine) = primaryWeapon _unit;
        GVAR(loadout_carbineMags) = ((primaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect ([GVAR(loadout_carbine)] call CBA_fnc_compatibleMagazines);
        systemChat format ["[Set %1]: %2 %3", _fncString, GVAR(loadout_carbine), GVAR(loadout_carbineMags)];
    };
case ("ar"): {
        GVAR(loadout_ar) = primaryWeapon _unit;
        GVAR(loadout_arMags) = ((primaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect ([GVAR(loadout_ar)] call CBA_fnc_compatibleMagazines);
        systemChat format ["[Set %1]: %2 %3", _fncString, GVAR(loadout_ar), GVAR(loadout_arMags)];
    };
case ("mmg"): {
        GVAR(loadout_mmg) = primaryWeapon _unit;
        GVAR(loadout_mmgMags) = ((primaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect ([GVAR(loadout_mmg)] call CBA_fnc_compatibleMagazines);
        systemChat format ["[Set %1]: %2 %3", _fncString, GVAR(loadout_mmg), GVAR(loadout_mmgMags)];
    };
case ("at"): {
        GVAR(loadout_at) = secondaryWeapon _unit;
        GVAR(loadout_atMags) = ((secondaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect ([GVAR(loadout_at)] call CBA_fnc_compatibleMagazines);
        systemChat format ["[Set %1]: %2 %3", _fncString, GVAR(loadout_at), GVAR(loadout_atMags)];
    };
case ("mat"): {
        GVAR(loadout_mat) = secondaryWeapon _unit;
        GVAR(loadout_matMags) = ((secondaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect ([GVAR(loadout_mat)] call CBA_fnc_compatibleMagazines);
        GVAR(loadout_matAttachments) = secondaryWeaponItems _unit;
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
