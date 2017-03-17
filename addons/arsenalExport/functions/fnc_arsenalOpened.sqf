#include "script_component.hpp"

params ["_display","_toggleSpace"];
TRACE_2("arsenalOpened",_display,isNull _display);

if (isNil QGVAR(loadout_rifle)) then {GVAR(loadout_rifle) = "Not Set";};
if (isNil QGVAR(loadout_carbine)) then {GVAR(loadout_carbine) = "Not Set";};

private _y = 0;

private _height = (((safezoneW / safezoneH) min 1.2) / 1.2) / 25;
private _xPos = safezoneX + safezoneW - 10 * _height;
private _yPos = (safezoneY + 1.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + 16 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25);

private _fnc_createButton = {
    params ["_text", "_fncString"];

    private _idc = 77000 + _y * 10;
    private _rscButton = _display ctrlCreate ["RscButton", (_idc + 0)];
    _rscButton ctrlSetText _text;
    _rscButton ctrlSetEventHandler ["ButtonClick", format ['[ctrlParent (_this select 0), "%1"] call FUNC(buttonClick)', _fncString]];
    _rscButton ctrlSetPosition [_xPos, _yPos + _height * _y, 3 * _height, _height];
    _rscButton ctrlCommit 1;
    private _rscText = _display ctrlCreate ["RscText", (_idc + 1)];
    _rscText ctrlSetPosition [_xPos + (3 * _height), _yPos + _height * _y, 7 * _height, _height];
    _rscText ctrlCommit 1;
    _y = _y + 1;
};

["Set Uniform", "uniform"] call _fnc_createButton; // 77000
["Set Rifle", "rifle"] call _fnc_createButton; // 77010
["Set GL Rifle", "glrifle"] call _fnc_createButton; // 77020
["Set Carbine", "carbine"] call _fnc_createButton; // 77030
["Set AR", "ar"] call _fnc_createButton; // 77040
["Set MMG", "mmg"] call _fnc_createButton; // 77050
["Set AT", "at"] call _fnc_createButton; // 77060
["Set MAT", "mat"] call _fnc_createButton; // 77070

private _rscButton = _display ctrlCreate ["RscButton", 77777];
_rscButton ctrlSetText "Export";
_rscButton ctrlSetEventHandler ["ButtonClick", 'call FUNC(export)'];
_rscButton ctrlSetPosition [_xPos + (1 * _height), _yPos + _height * (_y + 0.25), 8 * _height, _height];
_rscButton ctrlCommit 1;

// update the display:
[_display, "init"] call FUNC(buttonClick);

nil
