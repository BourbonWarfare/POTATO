#include "\z\potato\addons\customGear\script_component.hpp"
#undef COMPONENT
#define COMPONENT customGear_launchers
#define CONST_DT (1/60)
#define CONST_G -9.80665
#define CTRL_CA_IGUI_ELEMENTS_GROUP 170
#define CTRL_CA_DISTANCE 198
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This funciton will handle whether and when a carlG round should airburst
*
* Arguments:
* fired EH parameters
*
* Return:
* None
*
* Example:
* [_projectile] call potato_customGear_launchers_fnc_carlGAB_DetonateLaser;
*//***************************************************************************/
params ["", "_weapon", "", "", "_ammo", "", "_projectile", "_unit"];
if (!(_projectile getShotInfo 5) ||
    {!(_unit getVariable [QGVAR(abCGRnd), false])} ||
    {_ammo != QGVARMAIN(R_FFV448_he)} ||
    {!(toLowerANSI _weapon in ["launch_mraws_green_f","launch_mraws_sand_f","launch_mraws_olive_f"])}) exitWith {};
private _distance = parseNumber ctrlText (((uiNamespace getVariable "RscUnitInfo") displayCtrl CTRL_CA_IGUI_ELEMENTS_GROUP) controlsGroupCtrl CTRL_CA_DISTANCE);
if (_distance < 30) exitWith {};
// TBD configurable offset
_distance = _distance + (_unit getVariable [QGVAR(abOffset), 5]);
private _friction = 0.05*-0.002; // Based on config'd vals
private _v = [350, 0]; // Based on config'd vals
private _r = 0;
private _itr = 0;
private _vMag = -1;
private _lastV = [];
private _dr = 0;
while {_itr * CONST_DT < 4 && _r < _distance} do {
    _lastV = _v;
    _vMag = vectorMagnitude _lastV;
    _v = [
        (_lastV#0) + _friction * _vMag * (_lastV#0) * CONST_DT,
        (_lastV#1) + (CONST_G + _friction * _vMag * (_lastV#1)) * CONST_DT
    ];
    _dr = (_lastV#0) * CONST_DT / 2;
    _r = _r + (_v#0) * CONST_DT / 2 + _dr;
    _itr = _itr + 1;
};

[{
    triggerAmmo _this;
}, _projectile, _itr * CONST_DT] call CBA_fnc_waitAndExecute;
