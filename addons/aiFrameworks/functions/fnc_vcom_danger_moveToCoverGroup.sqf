#include "script_component.hpp"
TRACE_1("params",_this);

{
	if !(_x getVariable "VCOM_MovedRecentlyCover") then
	{
		_x spawn VCOMAI_MoveToCover;
	};
} foreach (units (group _this));
