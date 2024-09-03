#include "script_component.hpp"
#include "\a3\ui_f\hpp\defineDIKCodes.inc"
#include "\a3\ui_f\hpp\defineCommonGrids.inc"
#include "\a3\ui_f\hpp\defineResincl.inc"

#define POS_X(N) ((N) * GUI_GRID_W + GUI_GRID_CENTER_X)
#define POS_Y(N) ((N) * GUI_GRID_H + GUI_GRID_CENTER_Y)
#define POS_W(N) ((N) * GUI_GRID_W)
#define POS_H(N) ((N) * GUI_GRID_H)

params ["_display"];
TRACE_1("",_display);

if (!is3DEN) exitWith {};

private _infoBar = _display ctrlCreate ["RscText", -1];
_infoBar ctrlSetBackgroundColor [1,0,0,0.25];
_infoBar ctrlSetPosition [POS_X(31.8), POS_Y(0), POS_W(2.5), POS_H(20.3)];
_infoBar ctrlCommit 0;

private _infoText = _display ctrlCreate ["RscText", -1];
_infoText ctrlSetBackgroundColor [1,0,0,0.25];
_infoText ctrlSetTextColor [0,0,0,1];
_infoText ctrlSetText "Mission settings must 'overwrite clients' or they will not take effect!";
_infoText ctrlSetPosition [POS_X(15), POS_Y(-1), POS_W(24), POS_H(1)];
_infoText ctrlCommit 0;

_display setVariable [QGVAR(info), [_infoText, _infoBar]];

private _fnc_update = {
    params ["_display"];
    private _source = uiNamespace getVariable ["cba_settings_source", ""];
    (_display getVariable [QGVAR(info), []]) params ["_infoText", "_infoBar"];

    if (_source == "Mission") then {
        _infoBar ctrlShow true;
        _infoText ctrlSetText "Mission settings must 'overwrite clients' or they will not take effect!";
    } else {
        _infoBar ctrlShow false;
        _infoText ctrlSetText "'Server' settings are just your client and will not have any effect";
    };
};
_display displayAddEventHandler ["MouseMoving", _fnc_update];
_display displayAddEventHandler ["MouseHolding", _fnc_update];

