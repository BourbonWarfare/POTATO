/*
 * Author: PabstMirror
 * 
 *
 * Arguments:
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call 
 *
 * Public: No
 */
#include "script_component.hpp"

params ["_mortarVeh", "_player"];
TRACE_2("params",_mortarVeh,_player);

//If we have a round loaded, exit
private _loadedFull = magazinesAmmoFull _mortarVeh;
if (!(_loadedFull isEqualTo [])) exitWith {TRACE_1("loaded",_loadedFull);};

//Make sure empty mag is removed so it "autoloads"
private _loadedEmpty = _mortarVeh magazinesTurret [0];
if (!(_loadedEmpty isEqualTo [])) then {
    TRACE_1("removing empty mag", _loadedEmpty);
    _mortarVeh removeMagazinesTurret [(_loadedEmpty select 0), [0]];
};

private _magToLoad = GVAR(nextReload);
if (_magToLoad == "") exitWith {};

private _baseMag = getText (configFile >> "CfgMagazines" >> _magToLoad >> QGVAR(base));
TRACE_2("",_magToLoad,_baseMag);

if (!(_baseMag in (magazines _player))) exitWith {TRACE_1("mising base mag",_baseMag);};
_player removeMagazine _baseMag;

TRACE_1("loading",_magToLoad);
_mortarVeh addMagazineTurret [_magToLoad, [0]];
