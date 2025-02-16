#include "..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This function deletes any debug markers
*
* Arguments:
* None
*
* Return:
* None
*
* Example:
* [] call potato_vehicleCoasting_fnc_cleanDraw;
*//***************************************************************************/
GVAR(dev_traceHash) = createHashMap;
