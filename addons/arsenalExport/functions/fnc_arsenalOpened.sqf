#include "script_component.hpp"

#define PIXELSCALE  0.25
#define GRID_W (pixelW * pixelGridNoUIScale * PIXELSCALE)


params ["_display", ["_shiftLeft", false]];
TRACE_2("arsenalOpened",_display,_shiftLeft);

if ((count (call BIS_fnc_listPlayers)) > 1) exitWith {INFO_1("hiding export in mp - %1", (count (call BIS_fnc_listPlayers)));};


private _y = 0;
private _ctrlsToUpdate = [];

private _height = (((safezoneW / safezoneH) min 1.2) / 1.2) / 25;
private _xPos = safezoneX + safezoneW - 15 * _height;
if (_shiftLeft) then {
    _xPos = _xPos - 93 * GRID_W;
};
private _yPos = (safezoneY + 1.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + 16 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25);

private _fnc_createButton = {
    params ["_text", "_fncString", "_varsArray"];

    {if (isNil _x) then {missionNamespace setVariable [_x, "NotSet"];}} forEach _varsArray;

    private _rscButton = _display ctrlCreate ["RscButton", -1];
    _rscButton ctrlSetText _text;
    _rscButton ctrlSetEventHandler ["ButtonClick", format ['[ctrlParent (_this select 0), "%1"] call FUNC(buttonClick)', _fncString]];
    _rscButton ctrlSetPosition [_xPos, _yPos + _height * _y, 5 * _height, _height];
    _rscButton ctrlCommit 0.25;
    private _rscText = _display ctrlCreate ["RscText", -1];
    _rscText ctrlSetPosition [_xPos + (5 * _height), _yPos + _height * _y, 7 * _height, _height];
    _rscText ctrlCommit 0.25;
    _rscText setVariable [QGVAR(vars), _varsArray];
    _ctrlsToUpdate pushBack _rscText;
    _y = _y + 1;
};

["Set Uniform", "uniform", [QGVAR(loadout_uniform), QGVAR(loadout_vest), QGVAR(loadout_backpack), QGVAR(loadout_headgear)]] call _fnc_createButton;
["Set Pilot Uniform", "uniform_pilot", [QGVAR(loadout_pilot_uniform), QGVAR(loadout_pilot_vest), QGVAR(loadout_pilot_backpack), QGVAR(loadout_pilot_headgear)]] call _fnc_createButton;
["Set Vic Crew Uniform", "uniform_vicc", [QGVAR(loadout_vicc_uniform), QGVAR(loadout_vicc_vest), QGVAR(loadout_vicc_backpack), QGVAR(loadout_vicc_headgear)]] call _fnc_createButton;
["Set Carrall", "carryall", [QGVAR(loadout_carryall)]] call _fnc_createButton;
["Set Headgear Alt", "headgear_alt", [QGVAR(loadout_headgear_alt)]] call _fnc_createButton;
["Set Rifle", "rifle", [QGVAR(loadout_rifle), QGVAR(loadout_rifleMags), QGVAR(loadout_rifleAttachments)]] call _fnc_createButton;
["Set GL Rifle", "glrifle", [QGVAR(loadout_glrifle), QGVAR(loadout_glRifleMags)]] call _fnc_createButton;
["Set Carbine", "carbine", [QGVAR(loadout_carbine), QGVAR(loadout_carbineMags)]] call _fnc_createButton;
["Set AR", "ar", [QGVAR(loadout_ar), QGVAR(loadout_arMags)]] call _fnc_createButton;
["Set MMG", "mmg", [QGVAR(loadout_mmg), QGVAR(loadout_mmgMags)]] call _fnc_createButton;
["Set AT", "at", [QGVAR(loadout_at), QGVAR(loadout_atMags)]] call _fnc_createButton;
["Set MAT", "mat", [QGVAR(loadout_mat), QGVAR(loadout_matMags), QGVAR(loadout_matAttachments)]] call _fnc_createButton;
["Set HMG", "hmg", [QGVAR(loadout_hmg), QGVAR(loadout_hmgMags)]] call _fnc_createButton;
["Set HMG Tri 1", "hmg_tri_1", [QGVAR(loadout_hmg_tri_1)]] call _fnc_createButton;
["Set HMG Tri 2", "hmg_tri_2", [QGVAR(loadout_hmg_tri_2)]] call _fnc_createButton;
["Set HAT", "hat", [QGVAR(loadout_hat), QGVAR(loadout_hatMags)]] call _fnc_createButton;
["Set HAT Tri 1", "hat_tri_1", [QGVAR(loadout_hat_tri_1)]] call _fnc_createButton;
["Set HAT Tri 2", "hat_tri_2", [QGVAR(loadout_hat_tri_2)]] call _fnc_createButton;
["Set SAM", "sam", [QGVAR(loadout_sam), QGVAR(loadout_samMags)]] call _fnc_createButton;
["Set Sniper", "sniper", [QGVAR(loadout_sniper), QGVAR(loadout_sniperMags), QGVAR(loadout_sniperAttachments)]] call _fnc_createButton;
["Set Spotter", "spotter", [QGVAR(loadout_spotter), QGVAR(loadout_spotterMags), QGVAR(loadout_spotterAttachments)]] call _fnc_createButton;
["Set SMG", "smg", [QGVAR(loadout_smg), QGVAR(loadout_smgMags)]] call _fnc_createButton;
["Set Pistol", "pistol", [QGVAR(loadout_pistol), QGVAR(loadout_pistolMags), QGVAR(loadout_pistolAttachments)]] call _fnc_createButton;

private _rscButton = _display ctrlCreate ["RscButton", -1];
_rscButton ctrlSetText "Export";
_rscButton ctrlSetEventHandler ["ButtonClick", 'call FUNC(export)'];
_rscButton ctrlSetPosition [_xPos + (1 * _height), _yPos + _height * (_y + 0.25), 8 * _height, _height];
_rscButton ctrlCommit 0.25;

// update the display:
_display setVariable [QGVAR(ctrlsToUpdate), _ctrlsToUpdate];
[_display, "init"] call FUNC(buttonClick);

nil
