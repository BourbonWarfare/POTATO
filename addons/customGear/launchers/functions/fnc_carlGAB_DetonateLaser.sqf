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
// We love regression!
private _time = 2e-7 * (_distance^2) + 0.0029 * _distance - 0.0006;

[{
    triggerAmmo _this;
}, _projectile, _time] call CBA_fnc_waitAndExecute;
