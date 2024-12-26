/*
 * Author: PabstMirror
 * Reloads the weapon with the selected shell type.
 *
 * Arguments:
 * 0: Target (mortar) <OBJECT>
 * 1: Player <OBJECT>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [mortar, player] call potato_vz99_fnc_doReload
 *
 * Public: No
 */
#include "script_component.hpp"

params ["_mortarVeh", "_player"];
TRACE_2("params",_mortarVeh,_player);

//If we have a round loaded, exit
private _loadedFull = magazinesAmmoFull _mortarVeh;
if (_loadedFull isNotEqualTo []) exitWith {TRACE_1("loaded",_loadedFull);};

//Make sure empty mag is removed so it "autoloads"
private _loadedEmpty = _mortarVeh magazinesTurret [0];
if (_loadedEmpty isNotEqualTo []) then {
    TRACE_1("removing empty mag",_loadedEmpty);
    _mortarVeh removeMagazinesTurret [(_loadedEmpty select 0), [0]];
};

private _magToLoad = GVAR(nextReload);
if (_magToLoad == "") exitWith {};

private _baseMag = getText (configFile >> "CfgMagazines" >> _magToLoad >> QGVAR(base));
TRACE_2("",_magToLoad,_baseMag);

//HE - Impact can be done by basic HE shells or the multi-fuze, only use multi if we have no basic
if ((_baseMag == QGVAR(HE)) && {!(_baseMag in (magazines _player))}) then {
    _baseMag = QGVAR(HE_multi);
    _magToLoad = [QGVAR(HE_multi_charge0), QGVAR(HE_multi)] select (_magToLoad == QGVAR(HE));
    TRACE_2("using multi fuze @ impact",_baseMag,_magToLoad);
};

if (!(_baseMag in (magazines _player))) exitWith {
    TRACE_1("mising base mag",_baseMag);
    ["No Ammo"] call ACEFUNC(common,displayTextStructured);
};

_player removeMagazine _baseMag;

TRACE_1("loading",_magToLoad);
_mortarVeh addMagazineTurret [_magToLoad, [0]];
