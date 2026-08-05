#include "script_component.hpp"
#include "\a3\ui_f\hpp\defineDIKCodes.inc"
#include "\a3\ui_f\hpp\defineCommonGrids.inc"
#include "\a3\ui_f\hpp\defineResincl.inc"

#define POS_X(N) ((N) * GUI_GRID_W + GUI_GRID_CENTER_X)
#define POS_Y(N) ((N) * GUI_GRID_H + GUI_GRID_CENTER_Y)
#define POS_W(N) ((N) * GUI_GRID_W)
#define POS_H(N) ((N) * GUI_GRID_H)

params ["_display"];

private _xOffset = ((getResolution select 2) * 0.5 * pixelW) + (140 * 0.5) * (pixelW * pixelGrid * 	0.50);

private _ctrlInfo = _display ctrlCreate ["RscTextMulti", -1];
_ctrlInfo ctrlSetTextColor [0,0,0,1];
_ctrlInfo ctrlSetText "Recommend disabling ace's windSimulation if you want your custom wind settings to take effect";
_ctrlInfo ctrlSetPosition [_xOffset, POS_Y(12), POS_W(10), POS_H(6)];
_ctrlInfo ctrlCommit 0;
_display setVariable [QGVAR(ctrlInfo), _ctrlInfo];

_display setVariable [QGVAR(updateColor), {
    params ["_display"];
    private _ctrlInfo = _display getVariable [QGVAR(ctrlInfo), objNull];
    private _setting = ["ace_weather_windSimulation"] call CBA_settings_fnc_get;

    if (_setting) then {
        _ctrlInfo ctrlSetBackgroundColor [1,0,0,0.4];
    } else {
        _ctrlInfo ctrlSetBackgroundColor [0,1,0,0.4];
    };
}];
_display call (_display getVariable QGVAR(updateColor));

private _ctrlButton = _display ctrlCreate ["RscButton", -1];
_ctrlButton ctrlSetPosition [_xOffset, POS_Y(18), POS_W(10), POS_H(2)];
_ctrlButton ctrlCommit 0;
_ctrlButton ctrlSetText "Disable ace windSimulation";
_ctrlButton ctrlSetTooltip "This is the same as disabling ACE Weather -> Wind Simulation in CBA mission settings";
_ctrlButton ctrlAddEventHandler ["ButtonClick", {
    params ["_ctrlButton"];
    private _display = ctrlParent _ctrlButton;
    ["ace_weather_windSimulation", false, 1, "mission", true] call CBA_settings_fnc_set;
    _display call (_display getVariable QGVAR(updateColor));
}];
