#include "script_component.hpp"

#define PIXELSCALE  0.25
#define GRID_W (pixelW * pixelGridNoUIScale * PIXELSCALE)
    
    
params ["_display", ["_shiftLeft", false]];
TRACE_2("arsenalOpened",_display,_shiftLeft);

if ((count (call BIS_fnc_listPlayers)) > 1) exitWith {INFO_1("hiding export in mp - %1", (count (call BIS_fnc_listPlayers)));};


private _y = 0;
private _ctrlsToUpdate = [];

private _height = (((safezoneW / safezoneH) min 1.2) / 1.2) / 25;
private _xPos = safezoneX + safezoneW - 10 * _height;
if (_shiftLeft) then {
    _xPos = _xPos - 93 * GRID_W;
};
private _yPos = (safezoneY + -2 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + 16 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25);

private _fnc_createButton = {
    params ["_text", "_fncString", "_varsArray"];

    {if (isNil _x) then {missionNamespace setVariable [_x, "NotSet"];}} forEach _varsArray;

    private _rscButton = _display ctrlCreate ["RscButton", -1];
    _rscButton ctrlSetText _text;
    _rscButton ctrlSetEventHandler ["ButtonClick", format ['[ctrlParent (_this select 0), "%1"] call FUNC(buttonClick)', _fncString]];
    _rscButton ctrlSetPosition [_xPos, _yPos + _height * _y, 3 * _height, _height];
    _rscButton ctrlCommit 0.25;
    private _rscText = _display ctrlCreate ["RscText", -1];
    _rscText ctrlSetPosition [_xPos + (3 * _height), _yPos + _height * _y, 7 * _height, _height];
    _rscText ctrlCommit 0.25;
    _rscText setVariable [QGVAR(vars), _varsArray];
    _ctrlsToUpdate pushBack _rscText;
    _y = _y + 1;
};

/*
_fnc_AdvDefines = {

GVAR(AdvDefines) = true;
};

_y = _y + 1;
private _rscButton = _display ctrlCreate ["RscButton", -1];
_rscButton ctrlSetText "Adv. Defines";
_rscButton ctrlSetEventHandler ["ButtonClick", 'call _fnc_AdvDefines'];
_rscButton ctrlSetPosition [_xPos + (1 * _height), _yPos + _height * (_y + 0.25), 8 * _height, _height];
_rscButton ctrlCommit 0.25;
_y = _y + 1;
private _rscButton = _display ctrlCreate ["RscButton", -1];
_rscButton ctrlSetText "Export";
_rscButton ctrlSetEventHandler ["ButtonClick", 'call FUNC(export)'];
_rscButton ctrlSetPosition [_xPos + (1 * _height), _yPos + _height * (_y + 0.25), 8 * _height, _height];
_rscButton ctrlCommit 0.25;
_y = _y + 1.25;
*/

private _rscButton = _display ctrlCreate ["RscButton", -1];
_rscButton ctrlSetText "Reset Defines";
_rscButton ctrlAddEventHandler ["ButtonClick", format ['[ctrlParent (_this select 0), "%1"] call FUNC(buttonClick)', "reset"]];
_rscButton ctrlSetPosition [_xPos + (1 * _height), _yPos + _height * (_y + 0.25), 8 * _height, _height];
_rscButton ctrlCommit 0.25;
_y = _y + 1.5;

["Set Uniform", "uniform", [QGVAR(loadout_uniform), QGVAR(loadout_vest), QGVAR(loadout_backpack), QGVAR(loadout_headgear)]] call _fnc_createButton;
["Set Rifle", "rifle", [QGVAR(loadout_rifle), QGVAR(loadout_rifleMags), QGVAR(loadout_rifleAttachments)]] call _fnc_createButton;
["Set GL Rifle", "glrifle", [QGVAR(loadout_glrifle), QGVAR(loadout_glRifleMags)]] call _fnc_createButton;
["Set Carbine", "carbine", [QGVAR(loadout_carbine), QGVAR(loadout_carbineMags)]] call _fnc_createButton;
["Set AR", "ar", [QGVAR(loadout_ar), QGVAR(loadout_arMags), QGVAR(loadout_arAttachments)]] call _fnc_createButton;
["Set MMG", "mmg", [QGVAR(loadout_mmg), QGVAR(loadout_mmgMags)]] call _fnc_createButton;
["Set AT", "at", [QGVAR(loadout_at), QGVAR(loadout_atMags)]] call _fnc_createButton;
["Set MAT", "mat", [QGVAR(loadout_mat), QGVAR(loadout_matMags)]] call _fnc_createButton;
["Set GOG", "gog", [QGVAR(loadout_goggles)]] call _fnc_createButton;
/*
["Set HMG", "hmg", [QGVAR(loadout_hmg), QGVAR(loadout_hmgMags)]] call _fnc_createButton;
["Set HAT", "hat", [QGVAR(loadout_hat), QGVAR(loadout_hatMags)]] call _fnc_createButton;
["Set SAM", "sam", [QGVAR(loadout_sam), QGVAR(loadout_samMags)]] call _fnc_createButton;
["Set Sniper", "sniper", [QGVAR(loadout_sniper), QGVAR(loadout_sniperMags)]] call _fnc_createButton;
["Set Spotter", "spotter", [QGVAR(loadout_spotter), QGVAR(loadout_spotterMags)]] call _fnc_createButton;
["Set SMG", "smg", [QGVAR(loadout_smg), QGVAR(loadout_smgMags)]] call _fnc_createButton;
["Set Pistol", "pistol", [QGVAR(loadout_pistol), QGVAR(loadout_pistolMags)]] call _fnc_createButton;
["Set MTR T", "mtrt", [QGVAR(loadout_mtrt)]] call _fnc_createButton;
["Set MTR B", "mtrb", [QGVAR(loadout_mtrb)]] call _fnc_createButton;
["Set Crew H", "crewh", [QGVAR(loadout_crewh)]] call _fnc_createButton;
["Set Pilot", "pilot", [QGVAR(loadout_puniform), QGVAR(loadout_pvest), QGVAR(loadout_pbackpack), QGVAR(loadout_pheadgear)]] call _fnc_createButton;
["Set NODS", "nods", [QGVAR(loadout_nods)]] call _fnc_createButton;
*/
private _rscButton = _display ctrlCreate ["RscButton", -1];
_rscButton ctrlSetText "Export";
_rscButton ctrlSetEventHandler ["ButtonClick", 'call FUNC(export)'];
_rscButton ctrlSetPosition [_xPos + (1 * _height), _yPos + _height * (_y + 0.25), 8 * _height, _height];
_rscButton ctrlCommit 0.25;

// update the display:
_display setVariable [QGVAR(ctrlsToUpdate), _ctrlsToUpdate];
[_display, "init"] call FUNC(buttonClick);

nil
