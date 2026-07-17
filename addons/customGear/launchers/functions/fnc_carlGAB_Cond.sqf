#include "\z\potato\addons\customGear\script_component.hpp"
#undef COMPONENT
#define COMPONENT customGear_launchers
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This function handles whether the action exists for the
*
* Arguments:
* ace self interact menu params
*
* Return:
* None
*
* Example:
* [] call potato_customGear_launchers_fnc_carlGAB_Cond;
*//***************************************************************************/
//IGNORE_PRIVATE_WARNING ["_player"];
toLowerANSI secondaryWeapon _player in ["launch_mraws_green_f","launch_mraws_sand_f","launch_mraws_olive_f"]
