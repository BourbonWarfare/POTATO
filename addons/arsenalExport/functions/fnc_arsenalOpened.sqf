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
private _yPos = (safezoneY + 1.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + 16 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25);

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

["Set Uniform", "uniform", [QGVAR(loadout_uniform), QGVAR(loadout_vest), QGVAR(loadout_backpack), QGVAR(loadout_headgear)]] call _fnc_createButton;
["Set Rifle", "rifle", [QGVAR(loadout_rifle), QGVAR(loadout_rifleMags), QGVAR(loadout_rifleAttachments)]] call _fnc_createButton;
["Set GL Rifle", "glrifle", [QGVAR(loadout_glrifle), QGVAR(loadout_glRifleMags)]] call _fnc_createButton;
["Set Carbine", "carbine", [QGVAR(loadout_carbine), QGVAR(loadout_carbineMags)]] call _fnc_createButton;
["Set AR", "ar", [QGVAR(loadout_ar), QGVAR(loadout_arMags)]] call _fnc_createButton;
["Set MMG", "mmg", [QGVAR(loadout_mmg), QGVAR(loadout_mmgMags)]] call _fnc_createButton;
["Set AT", "at", [QGVAR(loadout_at), QGVAR(loadout_atMags)]] call _fnc_createButton;
["Set MAT", "mat", [QGVAR(loadout_mat), QGVAR(loadout_matMags)]] call _fnc_createButton;

private _rscButton = _display ctrlCreate ["RscButton", -1];
_rscButton ctrlSetText "Export";
_rscButton ctrlSetEventHandler ["ButtonClick", 'call FUNC(export)'];
_rscButton ctrlSetPosition [_xPos + (1 * _height), _yPos + _height * (_y + 0.25), 8 * _height, _height];
_rscButton ctrlCommit 0.25;

// update the display:
_display setVariable [QGVAR(ctrlsToUpdate), _ctrlsToUpdate];
[_display, "init"] call FUNC(buttonClick);

nil
